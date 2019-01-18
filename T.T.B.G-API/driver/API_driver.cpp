#include "API_driver.h"

void API_driver::Init() { _db = new DB(); }

void API_driver::LoadDB(string filepath) {
    std::ifstream in(filepath);
    json db;
    in >> db;

    _raw_db = new json();
    _raw_db = &db;

    Parse(*_raw_db);
}

void API_driver::UnLoadDB() {
    if (_db) delete _db;
    if (_raw_db) delete _raw_db;
}

void API_driver::CreateEmptyDB(string filePath, DB data, bool auto_load) {
    createFile(filePath);
    *_db = data;
    Save(filePath);

    if (auto_load)
        LoadDB(filePath);
    else
        UnLoadDB();
}

void API_driver::Save(string filePath) {
    auto db = DeParse();
    ofstream out(filePath);
    out << std::setw(4) << db;
    out.close();
}

Report *API_driver::GetReportByID(int id) {
    for (int i = 0; i < _db->_db_reports.size(); i++)
        if (_db->_db_reports[i]._ID == id) return &_db->_db_reports[i];
    return nullptr;
}

int API_driver::CreateReport(string name) {
    Report report;
    report._name = name;
    _db->_db_reports.push_back(report);
    return _db->_db_reports.size() - 1;
}

void API_driver::StartGenerateReport(int outputRprt_ID, Gen_DBInfo info,
                                     int pop, float min) {
    Report *output = GetReportByID(outputRprt_ID);

    ga = new _GA();
    ga->Init(info._in_teachers, info._in_subjects, info._in_levels, pop,
             info._in_tables.size());
    ga->Start(min, true);
}

void API_driver::Parse(json raw) {
    auto db = ParseDBAttribs(raw);
    _db->_db_name = db._db_name;

    auto tchrs = ParseTeachers(raw, "db_teachers");
    auto subjs = ParseSubjects(raw, "db_subjects");
    auto lvls = ParseLevels(raw, "db_levels");
    auto tbls = ParseTables(raw, "db_tables");
    auto rprts = ParseReports(raw, "db_reports");

    _db->_db_teachers = tchrs;
    _db->_db_subjects = subjs;
    _db->_db_levels = lvls;
    _db->_db_tables = tbls;
    _db->_db_reports = rprts;
}
DB API_driver::ParseDBAttribs(json raw) {
    DB db;
    db._db_name = raw["db_name"];
    return db;
}
vector<Teacher> API_driver::ParseTeachers(json raw, string pToken) {
    vector<Teacher> tchrs;
    for (auto &teacher : raw[pToken]) {
        Teacher temp_tchr;
        temp_tchr._ID = teacher["_id"];
        temp_tchr._name = teacher["_name"];
        temp_tchr._subjects = ParseSubjects(teacher, "_subjects");
        temp_tchr._levels = ParseLevels(teacher, "_levels");
        tchrs.push_back(temp_tchr);
    }
    return tchrs;
}
vector<Level> API_driver::ParseLevels(json raw, string pToken) {
    vector<Level> lvls;
    for (auto &level : raw[pToken]) {
        Level lvl;
        lvl._ID = level["_id"];
        lvl._value = level["_value"];
        lvls.push_back(lvl);
    }
    return lvls;
}
vector<Subject> API_driver::ParseSubjects(json raw, string pToken) {
    vector<Subject> subjs;
    for (auto &subject : raw[pToken]) {
        Subject subj;
        subj._ID = subject["_id"];
        subj._name = subject["_value"];
        subjs.push_back(subj);
    }
    return subjs;
}
vector<Table> API_driver::ParseTables(json raw, string pToken) {
    vector<Table> tbls;
    for (auto &table : raw[pToken]) {
        Table temp;  // slots are not used
        temp._info._ID = table["_id"];
        temp._level._ID = table["_level"]["_id"];
        temp._level._value = table["_level"]["_id"];
        tbls.push_back(temp);
    }
    return tbls;
}
vector<Report> API_driver::ParseReports(json raw, string pToken) {
    vector<Report> reports;
    for (auto &report : raw[pToken]) {
        Report rprt;
        rprt._ID = report["_id"];
        rprt._name = report["_name"];
        rprt._isGenerated = report["_isGenerated"];
        rprt._levels = ParseLevels(report, "_levels");
        rprt._teachers = ParseTeachers(report, "_teachers");
        rprt._subjects = ParseSubjects(report, "_subjects");
        rprt._tables = ParseTables(report, "_tables");

        for (auto &row : report["_data"]) {
            vector<string> temp;
            for (auto &item : row) temp.push_back(item);
            rprt._raw_data.push_back(temp);
        }
    }
}

json API_driver::DeParse() {
    json raw;
    DeParseDBAttribs(&raw);
    DeParseTeachers(&raw, _db->_db_teachers, "db_teachers");
    DeParseLevels(&raw, _db->_db_levels, "db_levels");
    DeParseSubjects(&raw, _db->_db_subjects, "db_subjects");
    DeParseTables(&raw, _db->_db_tables, "db_tables");
    DeParseReports(&raw, _db->_db_reports, "db_reports");
    return raw;
}
void API_driver::DeParseDBAttribs(json *raw) {
    (*raw)["db_name"] = _db->_db_name;
}
void API_driver::DeParseTeachers(json *raw, vector<Teacher> data,
                                 string pToken) {
    for (int i = 0; i < data.size(); i++) {
        auto sub = &(*raw)[pToken];
        (*sub)["_teacher_" + to_string(i + 1)]["_id"] = data[i]._ID;
        (*sub)["_teacher_" + to_string(i + 1)]["_name"] = data[i]._name;

        DeParseSubjects(&(*sub)["_teacher_" + to_string(i + 1)],
                        data[i]._subjects, "_subjects");
        DeParseLevels(&(*sub)["_teacher_" + to_string(i + 1)], data[i]._levels,
                      "_levels");
    }
}
void API_driver::DeParseLevels(json *raw, vector<Level> data, string pToken) {
    for (int i = 0; i < data.size(); i++) {
        auto sub = &(*raw)[pToken];
        (*sub)["_level_" + to_string(i + 1)]["_id"] = data[i]._ID;
        (*sub)["_level_" + to_string(i + 1)]["_value"] = data[i]._value;
    }
}
void API_driver::DeParseSubjects(json *raw, vector<Subject> data,
                                 string pToken) {
    for (int i = 0; i < data.size(); i++) {
        auto sub = &(*raw)[pToken];
        (*sub)["_subject_" + to_string(i + 1)]["_id"] = data[i]._ID;
        (*sub)["_subject_" + to_string(i + 1)]["_value"] = data[i]._name;
    }
}
void API_driver::DeParseTables(json *raw, vector<Table> data, string pToken) {
    for (int i = 0; data.size(); i++) {
        auto sub = &(*raw)[pToken];
        (*sub)["_table_" + to_string(i + 1)]["_id"] = data[i]._info._ID;
        (*sub)["_table_" + to_string(i + 1)]["_name"] = data[i]._info._name;

        (*sub)["_table_" + to_string(i)]["_level"]["_id"] = data[i]._level._ID;
        (*sub)["_table_" + to_string(i)]["_level"]["_value"] =
            data[i]._level._value;
    }
}
void API_driver::DeParseReports(json *raw, vector<Report> data, string pToken) {
    for (int i = 0; data.size(); i++) {
        auto sub = &(*raw)[pToken];
        (*sub)["_report_" + to_string(i + 1)]["_id"] = data[i]._ID;
        (*sub)["_report_" + to_string(i + 1)]["_name"] = data[i]._name;
        (*sub)["_report_" + to_string(i + 1)]["_isGenerated"] =
            data[i]._isGenerated;
        DeParseLevels(&(*sub)["_report_" + to_string(i + 1)], data[i]._levels,
                      "_levels");
        DeParseTeachers(&(*sub)["_report_" + to_string(i + 1)],
                        data[i]._teachers, "_teachers");
        DeParseSubjects(&(*sub)["_report_" + to_string(i + 1)],
                        data[i]._subjects, "_subjects");
        DeParseTables(&(*sub)["_report_" + to_string(i + 1)], data[i]._tables,
                      "_tables");

        for (int j = 0; j < data[i]._raw_data.size(); j++)
            for (int m = 0; m < data[i]._raw_data[j].size(); m++)
                (*sub)["_report_" + to_string(i + 1)]["_row" + to_string(j + 1)]
                    .push_back(data[i]._raw_data[j][m]);
    }
}