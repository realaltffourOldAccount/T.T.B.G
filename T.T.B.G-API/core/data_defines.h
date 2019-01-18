#ifndef DATA_DEFS_H
#define DATA_DEFS_H
#include "utils/include_bundles/utils_bundle.h"

#include <map>
#include <string>
#include <vector>

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
    bool operator<=(const Level &level) const {
        return LevelNumber() <= level.LevelNumber();
    }
    bool operator>=(const Level &level) const {
        return LevelNumber() >= level.LevelNumber();
    }
    // Returns the level number
    int LevelNumber() const { return atoi(_value.c_str()); }
    // Returns the level string, or letter in other words.
    string LevelStr() const {
        int num = this->LevelNumber();
        string numstr = to_string(num);
        return ExtractFromStr(numstr, this->_value);
    }
};
// Subject Type
struct Subject {
    int _ID;
    string _name;
    Level _min_level;
    Level _max_level;
    bool _teacher_req = true;
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
// Teacher Type, without altering it is default.
struct Teacher {
    int _ID = -1;
    string _name = "<DEFAULT>";
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
// Default teacher:
static Teacher DEFAULT_TCHR;

// TableInfo Type
struct TableInfo {
    int _ID;
    string _name;
};
// Returns a random teacher of the subject
// TODO: MORE OPTIMIZATION
static Teacher GetTeacherOfSubject(vector<Teacher> *mTeachers,
                                   vector<Subject> *mSubjects, Subject subj,
                                   Level lvl) {
    Teacher tchr;
    vector<Teacher> _checked_teachers;
    while (true) {
        auto teacher = (*mTeachers)[random(0, mTeachers->size() - 1)];
        if (findInVec(teacher._subjects, subj) != -1)
            if (findInVec(teacher._levels, lvl) != -1) {
                tchr = teacher;
                return tchr;
            }
        _checked_teachers.push_back(teacher);
        if (make_vec_unique(_checked_teachers).size() >= mTeachers->size())
            break;
    }
    return tchr;
}
// Slot Typedef
struct Slot {
    Teacher _tchr;
    Subject _subj;
    bool _teacher_req = true;

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
    Level _level;
    TableInfo _info;
    vector<Slot> _slots;
    // Generates random table with teacher and subject array.
    void GenerateRandTable(vector<Teacher> *tchr, vector<Subject> *subj,
                           Level lvl) {
        vector<Subject> subjects = *subj;
        while (!subjects.empty()) {
            Slot slot;
            int rand = random(0, subjects.size() - 1);
            auto subject = subjects[rand];
            slot._subj = subject;
            if (!(subject._min_level <= lvl)) continue;
            if (!(subject._max_level >= lvl)) continue;
            if (subject._teacher_req != false) {
                auto teacher =
                    GetTeacherOfSubject(tchr, &subjects, subject, lvl);
                if (teacher == DEFAULT_TCHR) continue;
                slot._tchr = teacher;
            }
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
    vector<Subject> _subjects;
    vector<Level> _levels;
    vector<Table> _tables;
    vector<vector<string> > _raw_data;
};
#endif