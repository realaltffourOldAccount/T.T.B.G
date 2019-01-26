#ifndef SCHOOL_H
#define SCHOOL_H
#include "../utils/include_bundles/utils_bundle.h"

#include "Course.h"
#include "Grade.h"
#include "Room.h"
#include "Teacher.h"

using namespace std;

struct School {
    vector<Room> _rooms;
    vector<Course> _courses;
    vector<Teacher> _teachers;
    vector<Grade> _grades;
};

#endif