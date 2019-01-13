/*
    A Population class wrapper.
*/

#include <vector>
#include "../data_defines.h"
#include "../utils/include_bundles/utils_bundle.h"
#include "Population.h"

class _GA {
   public:
    // Initializes the class, and the Population class.
    // The teachers and subjects are directly passed to the Population
    // class.
    void Init(vector<Teacher>, vector<Subject>, size_t pop_size,
              size_t table_count);
    // Min is the minimum correctness of the result. (ranges: 0.0-1.0)
    // threaded, if true start threaded else normal start.
    void Start(float min, bool threaded = true);

    // Returns the whole population.
    vector<Individual>* GetPopulation() const {
        return mPopulation->GetPopulation();
    }
    // Returns the current generation.
    int GetGen() const { return mPopulation->GetGen(); }

    // Returns if the worker thread stopped.
    bool GetIsWorkerStopped() { return mPopulation->GetIsWorkerStopped(); }

    // Returns the initialization of the current gen.
    int GetCurrentGenMadeCnt() { return mPopulation->GetCurrentGenMadeCnt(); }

   private:
    // The soul of the wrapper.
    Population* mPopulation = nullptr;
};