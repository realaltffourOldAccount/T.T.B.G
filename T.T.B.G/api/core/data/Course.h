#ifndef COURSE_H
#define COURSE_H

#include "../utils/include_bundles/utils_bundle.h"
#include "Grade.h"

struct Course {
    int _ID;
    float _priority;               // 0.0-1.0
    Grade _min_taker;              // min grade taker of the course
    Grade _max_taker;              // max grade taker of the course
    bool _isTeacherNeeded = true;  // if false the teacher is not needed

    Course();
    Course(int id, float prior, Grade min, Grade max, bool teacher = true) {
        _ID = id;
        _priority = prior;
        _min_taker = min;
        _max_taker = max;
        _isTeacherNeeded = teacher;
    }

    bool operator<(const Course& course) const {
        return _priority < course._priority;
    }
    bool operator<=(const Course& course) const {
        return _priority <= course._priority;
    }
    bool operator>(const Course& course) const {
        return _priority < course._priority;
    }
    bool operator>=(const Course& course) const {
        return _priority >= course._priority;
    }
};

#endif