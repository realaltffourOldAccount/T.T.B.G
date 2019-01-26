#ifndef COURSECLASS_H
#define COURSECLASS_H

#include "../utils/include_bundles/utils_bundle.h"
#include "Course.h"
#include "Grade.h"
#include "Teacher.h"

struct CourseClass {  // slot
    Course *_course = nullptr;
    Grade *_grade = nullptr;
    Teacher *_teacher = nullptr;
};

#endif