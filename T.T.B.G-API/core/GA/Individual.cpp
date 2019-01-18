#include "Individual.h"

void Individual::Init(vector<Teacher> *teachers, vector<Subject> *subject,
                      vector<Level> *level, int n) {
    assert(teachers);

    mTeachers = teachers;
    mSubjects = subject;
    mLevels = level;
    mTables = new vector<Table>(n);

    *mTables;

    GenerateTables();
}

void Individual::CalcFitness() {
    int fit = 0;
    for (int i = 0; i < mSubjects->size(); i++) {  // iterate over columns
        vector<Slot> Column;

        // get ith column
        for (int j = 0; j < mTables->size(); j++)
            Column.push_back((*mTables)[j]._slots[i]);

        // determine freq of teachers
        map<Teacher, int> tchr_freq;
        for (int j = 0; j < mTeachers->size(); j++)
            tchr_freq[(*mTeachers)[j]] = 0;

        for (int j = 0; j < Column.size(); j++) tchr_freq[Column[j]._tchr]++;

        // calculate fitness
        for (std::map<Teacher, int>::iterator it = tchr_freq.begin();
             it != tchr_freq.end(); it++)
            if (it->second == 1) fit++;
    }

    // convert var "fit" to a value between 0.0 and 1.0
    int max_fit = (*mTables)[0]._slots.size() * mTables->size();
    // fit -> max_fit
    // ?   -> 1
    // (cross multiply)
    // ->(1*fit)/max_fit
    mFitness = fit / max_fit;  // gives a value between 0 and 1
}

Individual Individual::mate(const Individual &indiv) {
    Individual offspring;  // the child
    offspring.Init(mTeachers, mSubjects, mLevels, mTables->size());

    vector<Table> *chromosome_p2 = indiv.GetChromosome();
    vector<Table> child_chromosome;

    int ta2_counter = 0;  // counter for the p2 table
    for (auto p1_crnt_ta :
         (*mTables)) {  // iterate over all tables of the parents
        Table p2_crnt_ta = (*chromosome_p2)[ta2_counter];
        ta2_counter++;
        float chance = (float)random(0, 100) / 100;
        if (chance < 0.30)  // gene from first parent
            child_chromosome.push_back(p1_crnt_ta);
        else if (chance < 0.65)  // gene from second parent
            child_chromosome.push_back(p2_crnt_ta);
        else {  // mutated gene
            Table mutated_ta;
            mutated_ta.GenerateRandTable(mTeachers, mSubjects,
                                         (*mLevels)[ta2_counter]);
            child_chromosome.push_back(mutated_ta);
        }
    }
}

void Individual::GenerateTables() {
    for (int i = 0; i < mTables->size(); i++)
        (*mTables)[i].GenerateRandTable(mTeachers, mSubjects,
                                        (*mLevels)[i]);  // make more faster
}