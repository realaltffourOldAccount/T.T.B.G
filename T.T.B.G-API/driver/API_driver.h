#ifndef API_DRIVER_H
#define API_DRIVER_H

#include <string>
#include <vector>
#include "../core/utils/include_bundles/all_bundle.h"

using json = nlohmann::json;

typedef struct {
    string _db_name;
    vector<Teacher> _db_teachers;
    vector<Level> _db_levels;
    vector<Subject> _db_subjects;
    vector<Table> _db_tables;
    vector<Report> _db_reports;
} DB;

typedef struct {
    Report* _output_rprt = nullptr;
    vector<Teacher> _in_teachers;
    vector<Subject> _in_subjects;
    vector<Level> _in_levels;
    vector<Table> _in_tables;
} Gen_DBInfo;

class API_driver {
   public:
    void Init();
    void LoadDB(string filepath);
    void UnLoadDB();

    void CreateEmptyDB(string filepath, DB data, bool auto_load = true);

    void Save(string filePath);

    int CreateReport(string name);
    void StartGenerateReport(int outputRprt_ID, Gen_DBInfo info, int pop = 300,
                             float min = 1.0f);
    _GA* GetAlgo() { return ga; };
    void StopGeneratingReport() { ga->Stop(); };

    DB* GetDB() { return _db; }

   private:
    _GA* ga = nullptr;

    Report* GetReportByID(int id);
    DB* _db = nullptr;
    json* _raw_db = nullptr;

    void Parse(json raw);
    DB ParseDBAttribs(json raw);
    vector<Teacher> ParseTeachers(json raw, string pToken);
    vector<Level> ParseLevels(json raw, string pToken);
    vector<Subject> ParseSubjects(json raw, string pToken);
    vector<Table> ParseTables(json raw, string pToken);
    vector<Report> ParseReports(json raw, string pToken);

    json DeParse();
    void DeParseDBAttribs(json* raw);
    void DeParseTeachers(json* raw, vector<Teacher> data, string pToken);
    void DeParseLevels(json* raw, vector<Level> data, string pToken);
    void DeParseSubjects(json* raw, vector<Subject> data, string pToken);
    void DeParseTables(json* raw, vector<Table> data, string pToken);
    void DeParseReports(json* raw, vector<Report> data, string pToken);
};

#endif

/*
   <file_name>.json :
   {
       "db_name":"<db_name>",
       "db_teachers": {
               "_teacher_<ID>": {
                       "_id": <ID>,
                       "_name": "Name",
                       "_subjects": {
                               "_subject_<ID>": {
                                        "_id": <ID>,
                                        "_value": "Maths"
                                }
                        },
                       "_levels": {
                                "_level_<ID>": {
                                "_id": <ID>,
                                "_value": "8A"
                                }
                        }
               }
       },
       "db_levels": {
               "_level_<ID>": {
                       "_id": <ID>,
                       "_value": "9A"
                },
               "_level_<ID>": {
                       "_id": <ID>,
                       "_value": "8A"
                }
        },
       "db_subjects": {
               "_subject_<ID>": {
                       "_id": <ID>,
                       "_value": "English"
               },
               "_subject_<ID>": {
                       "_id": <ID>,
                       "_value": "Maths"
               }
        },
       "db_tables": {
               "_table_<ID>": {
                       "_id": <ID>,
                       "_name": "Name",
                       "_level": {
                                "_id": <ID>,
                                "_value": "8A"
                        }
               }
       },
       "db_reports": {
               "_report_<ID>": {
                        "_id": <ID>,
                        "_name": "Name",
                        "_isGenerated": true,
                        "_tables": {
                                "_table_<ID>": {
                                        "_id": <ID>,
                                        "_name": "Name",
                                        "_level": {
                                                "_id": <ID>,
                                                "_value": "8A"
                                                }
                                        }
                        },
                        "_levels": {
                                "_level_<ID>": {
                                        "_id": <ID>,
                                        "_value": "8A"
                                }
                         },
                        "_teachers": {
                                "_teacher_<ID>": {
                                        "_id": <ID>,
                                        "_name": "Name",
                                        "_subjects": {
                                                "_subject_<ID>": {
                                                        "_id": <ID>,
                                                        "_value": "Maths"
                                                }
                                        },
                                        "_levels": {
                                                "_level_<ID>": {
                                                "_id": <ID>,
                                                "_value": "8A"
                                                }
                                        }
                                }
                        },
                        "_subjects": {
                                "_subject_<ID>": {
                                        "_id": <ID>,
                                        "_value": "English"
                                },
                                "_subject_<ID>": {
                                        "_id": <ID>,
                                        "_value": "Maths"
                                }
                        },
                        "_data": {
                                "_row1": {"item1", "item2", "item3"},
                                "_row2": {"item2", "item3", "item1"}
                        }
                }
       }
   }
*/