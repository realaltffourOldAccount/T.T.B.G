#include "core/utils/include_bundles/all_bundle.h"

//#define API_TEST 1
#define API_TEST_AUTOMATED 1

#ifdef API_TEST
#include <iostream>
int main() {
    vector<Teacher> teachers;
    vector<Subject> subjects;
    size_t pop_size;
    size_t table_cnt;

    cout << "Population Size: ";
    cin >> pop_size;
    cout << "Table Count: ";
    cin >> table_cnt;

    int tchr_cnt, subj_cnt;
    cout << "Teachers count: ";
    cin >> tchr_cnt;
    cout << "Subject Count: ";
    cin >> subj_cnt;

    for (int i = 0; i < tchr_cnt; i++) {
        Teacher tchr;
        tchr._ID = i + 1;

        cout << "Enter teacher " << i + 1 << " Name: ";
        cin >> tchr._name;

        int subj_n;
        cout << "Enter teacher " << i + 1 << " Subject count: ";
        cin >> subj_n;
        for (int j = 0; j < subj_n; j++) {
            Subject subj;
            cout << "Enter Subject " << j + 1 << " Name: ";
            cin >> subj._name;
            subj._ID = j + 1;
            tchr._subjects.push_back(subj);
        }

        int level_n;
        cout << "Enter teacher " << i + 1 << " Level Count: ";
        cin >> level_n;
        for (int j = 0; j < level_n; j++) {
            Level level;
            cout << "Enter Level " << j + 1 << " Value: ";
            cin >> level._value;
            level._ID = j + 1;
            tchr._levels.push_back(level);
        }

        teachers.push_back(tchr);
    }

    for (int i = 0; i < subj_cnt; i++) {
        Subject subj;
        subj._ID = i + 1;
        cout << "Enter subject " << i + 1 << " Value: ";
        cin >> subj._name;
        subjects.push_back(subj);
    }

    float min_correctness = 0.0f;
    cout << "ENter Minimum Correctness(0.0-1.0): ";
    cin >> min_correctness;

    Population ga;
    ga.Init(teachers, subjects, pop_size, table_cnt);
    ga.Start(min_correctness);

    for (auto indiv : *ga.GetPopulation()) {
        for (int i = 0; i < indiv.GetChromosome()->size(); i++)
            for (int j = 0; j < (*indiv.GetChromosome())[i]._slots.size(); j++)
                cout << (*indiv.GetChromosome())[i]._slots[j].get();
    }
    system("pause");
}
#endif

#ifdef API_TEST_AUTOMATED

#include <iostream>

int main() {
    vector<Teacher> teacher;
    vector<Subject> subject;
    vector<Level> level;

    Level lvl1, lvl2, lvl3;
    lvl1._ID = 1;
    lvl1._value = "8A";
    lvl2._ID = 2;
    lvl2._value = "8B";
    lvl3._ID = 3;
    lvl3._value = "7A";

    level.push_back(lvl1);
    level.push_back(lvl2);
    level.push_back(lvl3);

    Subject subj1, subj2, subj3, subj4;
    subj1._ID = 1;
    subj1._name = "S1";
    subj2._ID = 2;
    subj2._name = "S2";
    subj3._ID = 3;
    subj3._name = "S3";
    subj4._ID = 4;
    subj4._name = "S4";

    subject.push_back(subj1);
    subject.push_back(subj2);
    subject.push_back(subj3);
    // subject.push_back(subj4);

    Teacher t1, t2, t3;
    t1._ID = 1;
    t1._levels.push_back(lvl1);
    t1._levels.push_back(lvl2);
    t1._levels.push_back(lvl3);
    t1._name = "T1";
    t1._subjects.push_back(subj1);
    t1._subjects.push_back(subj2);
    t1._subjects.push_back(subj3);

    t2._ID = 2;
    t2._levels.push_back(lvl1);
    t2._levels.push_back(lvl2);
    t2._levels.push_back(lvl3);
    t2._name = "T2";
    t2._subjects.push_back(subj1);
    t2._subjects.push_back(subj2);
    t2._subjects.push_back(subj3);

    t3._ID = 3;
    t3._levels.push_back(lvl1);
    t3._levels.push_back(lvl2);
    t3._levels.push_back(lvl3);
    t3._name = "T3";
    t3._subjects.push_back(subj1);
    t3._subjects.push_back(subj2);
    t3._subjects.push_back(subj3);

    teacher.push_back(t1);
    teacher.push_back(t2);
    teacher.push_back(t3);

    _GA ga;
    ga.Init(teacher, subject, 1000, 3);
    ga.Start(1.0, true);

    cout << std::fixed << std::setprecision(2);
    while (!ga.GetIsWorkerStopped()) {
        cout << "Fitness: " << (*ga.GetPopulation())[0].GetFitness()
             << " Crnt Gen: " << ga.GetCurrentGenMadeCnt() << endl;
        system("clear");
    }

    for (auto indiv : *ga.GetPopulation()) {
        for (int i = 0; i < indiv.GetChromosome()->size(); i++) {
            for (int j = 0; j < (*indiv.GetChromosome())[i]._slots.size(); j++)
                cout << (*indiv.GetChromosome())[i]._slots[j].get();
            cout << endl;
        }
        break;
    }

    cout << "Fitness: " << (*ga.GetPopulation())[0].GetFitness() << endl;
    cout << "Generation: " << ga.GetGen() << endl;
    return 0;
}

#endif