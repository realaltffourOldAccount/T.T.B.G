#include "_GA.h"

void _GA::Init(vector<Teacher> tchr, vector<Subject> subj, vector<Level> level,
               size_t pop_size, size_t table_count) {
    mPopulation = new Population();
    mPopulation->Init(tchr, subj, level, pop_size, table_count);
}

void _GA::Start(float min, bool threaded) {
    if (threaded)
        mPopulation->StartThreaded(min);
    else
        mPopulation->Start(min);
}
