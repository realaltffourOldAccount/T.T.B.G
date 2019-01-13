#include "Population.h"
#include <thread>

void Population::Init(vector<Teacher> teachers, vector<Subject> subjects,
                      size_t pop_size, size_t table_count) {
    assert(teachers.size());
    assert(subjects.size());

    mTeachers = teachers;
    mSubjects = subjects;
    mIndividuals = new vector<Individual>(pop_size);
    mPopulationSize = pop_size;
    mTablesCount = table_count;
}

void Population::Start(float min) { __start(min); }

void Population::StartThreaded(float min_correctness) {
    new thread(&Population::__start, this, min_correctness);
}

void Population::__start(float min_correctness) {
    mThreadStopped = false;
    bool correctnessReached = false;

    //  initialize the indivs
    mCrntGenMadeCnt = 0;
    for (int i = 0; i < mIndividuals->size(); i++) {
        (*mIndividuals)[i].Init(&mTeachers, &mSubjects, mTablesCount);
        (*mIndividuals)[i].CalcFitness();
        mCrntGenMadeCnt++;
    }

    // main run loop
    while (!correctnessReached) {
        stable_sort(mIndividuals->begin(), mIndividuals->end());
        if ((*mIndividuals)[0].GetFitness() >= min_correctness) {
            correctnessReached = true;
            break;
        }

        vector<Individual> new_generation;

        // only 10% of the fittest will survive, might decrease
        int r = (10 * mPopulationSize) / 100;
        for (int i = 0; i < r; i++)
            new_generation.push_back((*mIndividuals)[i]);

        // only 70% will mate
        r = (70 * mPopulationSize) / 100;
        for (int i = 0; i < r; i++)
            new_generation.push_back((*mIndividuals)[i]);

        // only 25% will mutate
        r = (20 * mPopulationSize) / 100;
        for (int i = 0; i < r; i++) {
            Individual indiv;
            indiv.Init(&mTeachers, &mSubjects, mTablesCount);
            indiv.CalcFitness();
            new_generation.push_back(indiv);
        }
        *mIndividuals = new_generation;
        mGenerationCnt++;
    }

    mThreadStopped = true;
}