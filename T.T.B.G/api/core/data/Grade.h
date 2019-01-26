#ifndef GRADE_H
#define GRADE_H

#include "../utils/include_bundles/utils_bundle.h"

struct Grade {
    int _ID;
    string _value;
    Grade();
    Grade(int id, string val) {
        _ID = id;
        _value = val;
    }
    // clears the level var
    void clear() {
        _ID = 0;
        _value = "";
    }
    bool operator==(const Grade &level) const {
        if (_ID == level._ID && _value == level._value) return true;
        return false;
    }
    bool operator<=(const Grade &level) const {
        return LevelNumber() <= level.LevelNumber();
    }
    bool operator>=(const Grade &level) const {
        return LevelNumber() >= level.LevelNumber();
    }
    // Returns the Grade number
    int LevelNumber() const { return atoi(_value.c_str()); }
    // Returns the level string, or letter in other words.
    string LevelStr() const {
        int num = this->LevelNumber();
        string numstr = to_string(num);
        return ExtractFromStr(numstr, this->_value);
    }
};

#endif