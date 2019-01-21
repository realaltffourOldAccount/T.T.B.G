#ifndef TIMELINE_H
#define TIMELINE_H

#include <vector>
#include "../data_defines.h"

struct TimeLine {
    vector<vector<Slot>> *__slots = nullptr;
    vector<Teacher> _teachers;
    vector<Subject> _subjects;
    vector<Level> _levels;
    int _period_cnt = 0;
    int _class_cnt = 0;

    bool Check();
};

#endif