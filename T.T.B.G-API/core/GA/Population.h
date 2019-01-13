/*
    This class is meant to be used indirectly from the _GA class.
    It contains the individuals, can be got from GetPopulation().
    It controls the 'evolution' of the individiauls.
    Can be used on seperate thread.
*/

#ifndef POPULATION_H
#define POPULATION_H

#pragma once
#include "../data_defines.h"
#include "../utils/include_bundles/utils_bundle.h"

#include "Individual.h"

#include <algorithm>

class Population {
   public:
    // Initialize population.
    // Teacher array,
    // Subject array,
    // Population size, and table count.
    void Init(vector<Teacher>, vector<Subject>, size_t pop_size,
              size_t table_count);
    // Starts the genetic algorithm on the calling thread.
    void Start(float min_correctness);
    // Starts the genetic algorithm on a seperate thread from the main.
    void StartThreaded(float min_correctness);

    // Returns the whole population.
    vector<Individual>* GetPopulation() const { return mIndividuals; }
    // Returns the current generation.
    int GetGen() const { return mGenerationCnt; }

    // Returns if the worker thread stopped.
    bool GetIsWorkerStopped() { return mThreadStopped; }

    // Returns the initialization of the current gen.
    int GetCurrentGenMadeCnt() { return mCrntGenMadeCnt; }

   private:
    // Genetic Algorithm
    void __start(float min_correctness);

    vector<Teacher> mTeachers;
    vector<Subject> mSubjects;
    vector<Individual>* mIndividuals = nullptr;
    size_t mPopulationSize = 0;
    size_t mTablesCount = 0;
    size_t mGenerationCnt = 0;

    bool mThreadStopped = false;
    int mCrntGenMadeCnt = 0;
};

#endif