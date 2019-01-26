#ifndef TEACHER_H
#define TEACHER_H

#include "../utils/include_bundles/utils_bundle.h"
#include "Course.h"
#include "Grade.h"

struct Teacher {
    int _ID;
    string _name;
    vector<Grade> _grades;
    vector<Course> _courses;
};

#endif