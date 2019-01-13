/*
    An individual contains his "submission" of the
    random set of generated tables.
    An individual is rated bases on his "submission",
    named here as mFitness.

    For convenience, the value of mFitness at is max
    is 1.0f and at is lowest is 0.0f.

    For optimization, pointers have been used almost
    everywhere.
*/

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#pragma once
#include <algorithm>
#include "../data_defines.h"
#include "../utils/include_bundles/utils_bundle.h"

class Individual {
   public:
    // Initializes the class, pass by pointer the teacher vec,
    // No need for the table info(long term optimization),
    // so number of tables are enough.
    // (Look at Table definition)
    void Init(vector<Teacher> *, vector<Subject> *, int numOfTables);
    // Calculates fitness and sits it to mFitness var.
    void CalcFitness();
    // Straightforward
    float GetFitness() const { return mFitness; };

    Individual mate(const Individual &);

    // for easy Individual comparisions
    bool operator<(const Individual &indiv) const {
        return indiv.GetFitness() < mFitness;
    }

    vector<Table> *GetChromosome() const { return mTables; }
    void SetChromosome(vector<Table> *tables) { mTables = tables; }

   private:
    // Wrapper for mTables[i].GenerateRandTable()
    void GenerateTables();

    vector<Teacher> *mTeachers;
    vector<Subject> *mSubjects;
    vector<Table> *mTables;  // also, in ga, Chromosome
    float mFitness = 0;
};

#endif