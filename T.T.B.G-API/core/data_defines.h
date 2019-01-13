#ifndef DATA_DEFS_H
#define DATA_DEFS_H
#include "utils/include_bundles/utils_bundle.h"

#include <map>
#include <string>
#include <vector>

// Subject Type
struct Subject {
    int _ID;
    string _name;
    // Clears the subject var
    void clear() {
        _ID = 0;
        _name = "";
    }
    bool operator==(const Subject &subj) const {
        if (subj._ID == _ID && subj._name == _name) return true;
        return false;
    }
};
// Level Type
struct Level {
    int _ID;
    string _value;
    // clears the level var
    void clear() {
        _ID = 0;
        _value = "";
    }
    bool operator==(const Level &level) const {
        if (_ID == level._ID && _value == level._value) return true;
        return false;
    }
    // Returns the level number
    int LevelNumber() { return atoi(_value.c_str()); }
    // Returns the level string, or letter in other words.
    string LevelStr() {
        int num = this->LevelNumber();
        string numstr = to_string(num);
        return ExtractFromStr(numstr, this->_value);
    }
};
// Teacher Type
struct Teacher {
    int _ID;
    string _name;
    vector<Subject> _subjects;
    vector<Level> _levels;

    bool operator==(const Teacher &tchr) const {
        if (_ID == tchr._ID && _name == tchr._name &&
            tchr._subjects == _subjects && _levels == tchr._levels)
            return true;
        return false;
    }

    // for stl map container, may be used in future teacher prioritization
    bool operator<(const Teacher &tchr) const { return _ID < tchr._ID; }
};
// TableInfo Type
struct TableInfo {
    int _ID;
    string _name;
    Level _level;
};
// Gets the subjects list from teachers, not used.
// TODO: CHECK CORRECTNESS
static vector<Subject> GetSubjectsFromVecTeachers(vector<Teacher> *tchrs) {
    vector<Subject> *result = new vector<Subject>;
    for (auto teacher : *tchrs)
        for (auto subj : teacher._subjects)
            if (isNotInVec(*result, subj)) result->push_back(subj);
    return *result;
}
// Returns a random teacher of the subject
// TODO: MORE OPTIMIZATION
static Teacher GetTeacherOfSubject(vector<Teacher> *mTeachers,
                                   vector<Subject> *mSubjects, Subject subj) {
    Teacher tchr;
    while (true) {
        auto teacher = (*mTeachers)[random(0, mTeachers->size() - 1)];
        for (auto subject : (*mSubjects))
            if (findInVec(teacher._subjects, subject) != -1) {
                tchr = teacher;
                return tchr;
            }
    }
    return tchr;
}
// Slot Typedef
struct Slot {
    Teacher _tchr;
    Subject _subj;

    Slot() {}

    // Wrapper for setting vars by hand.
    Slot(Teacher tchr, Subject subj) {
        _tchr = tchr;
        _subj = subj;
    }

    bool operator==(Slot &slot) {
        if (_tchr == slot._tchr && _subj == slot._subj) return true;
        return false;
    }

    // For future subject prioritization
    bool operator<(const Slot &_slot) const {
        return (_subj._ID < _slot._subj._ID);
    }

    // For debugging porpuses ONLY.
    string get() { return string("[" + _tchr._name + ":" + _subj._name + "]"); }
};
// Table Typedef
struct Table {
    TableInfo _info;
    vector<Slot> _slots;
    // Generates random table with teacher and subject array.
    void GenerateRandTable(vector<Teacher> *tchr, vector<Subject> *subj) {
        vector<Subject> subjects = *subj;
        while (!subjects.empty()) {
            int rand = random(0, subjects.size() - 1);
            auto subject = subjects[rand];
            auto teacher = GetTeacherOfSubject(tchr, &subjects, subject);
            Slot slot(teacher, subject);
            _slots.push_back(slot);
            subjects.erase(subjects.begin() + rand);
        }
    }
};
// Report Type
struct Report {
    int _ID;
    string _name;
    bool _isGenerated = false;
    vector<Teacher> _teachers;
    vector<Level> _levels;
    vector<Table> _tables;
};
#endif