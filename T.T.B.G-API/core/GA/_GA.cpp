#include "_GA.h"

void _GA::Init(vector<Teacher> tchr, vector<Subject> subj, size_t pop_size,
               size_t table_count) {
    mPopulation = new Population();
    mPopulation->Init(tchr, subj, pop_size, table_count);
}

void _GA::Start(float min, bool threaded) {
    if (threaded)
        mPopulation->StartThreaded(min);
    else
        mPopulation->Start(min);
}
