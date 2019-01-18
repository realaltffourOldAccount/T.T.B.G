#include "core/utils/include_bundles/all_bundle.h"
#include "driver/API_driver.h"

//#define IDEAL_DATA 1  // correct data
#define SLIGHTLY_UNIDEAL_DATA 1  // TODO: MAKE IT UNIDEAL
//#define REAL_LIFE_DATA 1

//#define API_TEST 1
#define API_TEST_AUTOMATED 1

//#define API_FILESYSTEM_DRIVER_TEST 1
//#define API_REPORT_GENERATING_DRIVER_TEST 1

#pragma region IDEAL_DATA
#ifdef IDEAL_DATA
vector<Teacher> teacher;
vector<Subject> subject;
vector<Level> level;

Level lvl1, lvl2, lvl3;
Subject subj1, subj2, subj3, subj4;
Teacher t1, t2, t3;

static void init_data() {
    lvl1._ID = 1;
    lvl1._value = "1A";
    lvl2._ID = 2;
    lvl2._value = "2A";
    lvl3._ID = 3;
    lvl3._value = "3A";

    level.push_back(lvl1);
    level.push_back(lvl2);
    level.push_back(lvl3);

    subj1._ID = 1;
    subj1._name = "S1";
    subj1._min_level = lvl1;
    subj1._max_level = lvl3;
    subj2._ID = 2;
    subj2._name = "S2";
    subj2._min_level = lvl1;
    subj2._max_level = lvl3;
    subj3._ID = 3;
    subj3._name = "S3";
    subj3._min_level = lvl1;
    subj3._max_level = lvl3;
    subj4._ID = 4;
    subj4._name = "S4";
    subj4._min_level = lvl1;
    subj4._max_level = lvl3;
    subject.push_back(subj1);
    subject.push_back(subj2);
    subject.push_back(subj3);
    // subject.push_back(subj4);

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
}
#endif
#pragma endregion

#pragma region SLIGHTLY_UNIDEAL_DATA
#ifdef SLIGHTLY_UNIDEAL_DATA
vector<Teacher> teacher;
vector<Subject> subject;
vector<Level> level;

Level lvl1, lvl2, lvl3;
Subject subj1, subj2, subj3, subj4;
Teacher t1, t2, t3;

static void init_data() {
    lvl1._ID = 1;
    lvl1._value = "L1";
    lvl2._ID = 2;
    lvl2._value = "L2";
    lvl3._ID = 3;
    lvl3._value = "L3";

    level.push_back(lvl1);
    level.push_back(lvl2);
    level.push_back(lvl3);

    subj1._ID = 1;
    subj1._name = "S1";
    subj1._min_level = lvl1;
    subj1._max_level = lvl3;
    subj2._ID = 2;
    subj2._name = "S2";
    subj2._min_level = lvl1;
    subj2._max_level = lvl3;
    subj3._ID = 3;
    subj3._name = "S3";
    subj3._min_level = lvl1;
    subj3._max_level = lvl3;
    subj4._ID = 4;
    subj4._name = "S4";
    subj4._min_level = lvl1;
    subj4._max_level = lvl3;
    subject.push_back(subj1);
    subject.push_back(subj2);
    subject.push_back(subj3);
    // subject.push_back(subj4);

    t1._ID = 1;
    t1._levels.push_back(lvl1);
    t1._levels.push_back(lvl2);
    t1._levels.push_back(lvl3);
    t1._name = "T1";
    t1._subjects.push_back(subj1);

    t2._ID = 2;
    t2._levels.push_back(lvl1);
    t2._levels.push_back(lvl2);
    t2._levels.push_back(lvl3);
    t2._name = "T2";
    t2._subjects.push_back(subj2);

    t3._ID = 3;
    t3._levels.push_back(lvl1);
    t3._levels.push_back(lvl2);
    t3._levels.push_back(lvl3);
    t3._name = "T3";
    t3._subjects.push_back(subj3);

    teacher.push_back(t1);
    teacher.push_back(t2);
    teacher.push_back(t3);
}
#endif
#pragma endregion

#pragma region REAL_LIFE_DATA
#ifdef REAL_LIFE_DATA
vector<Teacher> teacher;
vector<Subject> subject;
vector<Level> level;

Level _4A, _4B, _4C, _5A, _5B, _5C, _6A, _6B, _6C, _7A, _7B, _8A, _8B, _9A;
// 16
Teacher _t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10, _t11, _t12, _t13,
    _t14, _t15, _t16;
Subject _maths, _computer, _english, _science, _chem, _phy, _bio, _business,
    _social, _islamic, _deen, _arabic;
static void init_data() {
    _4A._ID = 0;
    _4A._value = "4A";
    _4B._ID = 1;
    _4B._value = "4B";
    _4C._ID = 2;
    _4C._value = "4C";
    _5A._ID = 3;
    _5A._value = "5A";
    _5B._ID = 4;
    _5B._value = "5B";
    _5C._ID = 5;
    _5C._value = "5C";
    _6A._ID = 6;
    _6A._value = "6A";
    _6B._ID = 7;
    _6B._value = "6B";
    _6C._ID = 8;
    _6C._value = "6C";
    _7A._ID = 9;
    _7A._value = "7A";
    _7B._ID = 10;
    _7B._value = "7B";
    _8A._ID = 12;
    _8A._value = "8A";
    _8B._ID = 13;
    _8B._value = "8B";
    _9A._ID = 14;
    _9A._value = "9A";

    level.push_back(_4A);
    level.push_back(_4B);
    level.push_back(_4C);
    level.push_back(_5A);
    level.push_back(_5B);
    level.push_back(_5C);
    level.push_back(_6A);
    level.push_back(_6B);
    level.push_back(_6C);
    level.push_back(_7A);
    level.push_back(_7B);
    level.push_back(_8A);
    level.push_back(_8B);
    level.push_back(_9A);

    _maths._ID = 0;
    _maths._name = "Maths";
    _maths._min_level = _4A;
    _maths._max_level = _9A;

    _islamic._ID = 1;
    _islamic._name = "Islamic";

    _computer._ID = 2;
    _computer._name = "Computer";

    _english._ID = 3;
    _english._name = "English";

    _science._ID = 4;
    _science._name = "Science";

    _chem._ID = 5;
    _chem._name = "Chemistry";

    _phy._ID = 6;
    _phy._name = "Physics";

    _bio._ID = 7;
    _bio._name = "Biology";

    _business._ID = 8;
    _business._name = "Business";

    _social._ID = 9;
    _social._name = "Social";

    subject.push_back(_maths);
    subject.push_back(_islamic);
    subject.push_back(_computer);
    subject.push_back(_english);
    subject.push_back(_science);
    subject.push_back(_chem);
    subject.push_back(_phy);
    subject.push_back(_bio);
    subject.push_back(_business);
    subject.push_back(_social);

    _t1._ID = 0;
    _t1._name = "Mrs. Rumaiza";
    _t1._subjects.push_back(_maths);
    _t1._subjects.push_back(_islamic);
    _t1._levels.push_back(_4A);
    _t1._levels.push_back(_4B);
    _t1._levels.push_back(_4C);
    _t1._levels.push_back(_5C);

    _t2._ID = 1;
    _t2._name = "Mr. Imtiaz";
    _t2._subjects.push_back(_computer);
    _t2._levels.push_back(_4A);
    _t2._levels.push_back(_4B);
    _t2._levels.push_back(_4C);
    _t2._levels.push_back(_5C);

    _t3._ID = 2;
    _t3._name = "Mrs. Qudsia";
    _t3._subjects.push_back(_english);
    _t3._levels.push_back(_4A);
    _t3._levels.push_back(_4B);
    _t3._levels.push_back(_4C);
    _t3._levels.push_back(_5A);

    _t4._ID = 3;
    _t4._name = "Mrs. Anju";
    _t4._subjects.push_back(_science);
    _t4._levels.push_back(_4A);
    _t4._levels.push_back(_4B);
    _t4._levels.push_back(_4C);
    _t4._levels.push_back(_5A);
    _t4._levels.push_back(_5B);

    _t5._ID = 4;
    _t5._name = "Mr. Hany";
    _t5._subjects.push_back(_maths);
    _t5._levels.push_back(_5A);
    _t5._levels.push_back(_5B);
    _t5._levels.push_back(_6A);
    _t5._levels.push_back(_6B);
    _t5._levels.push_back(_6C);

    _t6._ID = 5;
    _t6._name = "Mr. Gamal";
    _t6._subjects.push_back(_english);
    _t6._levels.push_back(_5B);
    _t6._levels.push_back(_5C);
    _t6._levels.push_back(_6A);
    _t6._levels.push_back(_6B);
    _t6._levels.push_back(_6C);

    _t7._ID = 6;
    _t7._name = "Mr. Nizzami";
    _t7._subjects.push_back(_science);
    _t7._levels.push_back(_5C);
    _t7._levels.push_back(_6A);
    _t7._levels.push_back(_6B);
    _t7._levels.push_back(_6C);

    _t8._ID = 7;
    _t8._name = "Mr. Quazi";
    _t8._subjects.push_back(_computer);
    _t8._levels.push_back(_5A);
    _t8._levels.push_back(_5B);
    _t8._levels.push_back(_6A);
    _t8._levels.push_back(_6B);
    _t8._levels.push_back(_6C);

    _t9._ID = 8;
    _t9._name = "Mr. Shahnawaz";
    _t9._subjects.push_back(_maths);
    _t9._levels.push_back(_7B);
    _t9._levels.push_back(_8A);
    _t9._levels.push_back(_8B);
    _t9._levels.push_back(_9A);

    _t10._ID = 9;
    _t10._name = "Mr. Zaman";
    _t10._subjects.push_back(_english);
    _t10._levels.push_back(_7A);
    _t10._levels.push_back(_7B);
    _t10._levels.push_back(_8A);
    _t10._levels.push_back(_8B);
    _t10._levels.push_back(_9A);

    _t11._ID = 10;
    _t11._name = "Mr. Faisal";
    _t11._subjects.push_back(_maths);
    _t11._subjects.push_back(_chem);
    _t11._levels.push_back(_7A);
    _t11._levels.push_back(_8A);
    _t11._levels.push_back(_8B);
    _t11._levels.push_back(_9A);

    _t12._ID = 11;
    _t12._name = "Mrs. Minu";
    _t12._subjects.push_back(_phy);
    _t12._levels.push_back(_8A);
    _t12._levels.push_back(_8B);

    _t13._ID = 12;
    _t13._name = "Mrs. Hazeem";
    _t13._subjects.push_back(_phy);
    _t13._levels.push_back(_9A);

    _t14._ID = 13;
    _t14._name = "Mrs. Lakshmi";
    _t14._subjects.push_back(_computer);
    _t14._levels.push_back(_7A);
    _t14._levels.push_back(_7B);
    _t14._levels.push_back(_8A);
    _t14._levels.push_back(_8B);
    _t14._levels.push_back(_9A);

    _t15._ID = 14;
    _t15._name = "Mrs. Batool";
    _t15._subjects.push_back(_science);
    _t15._subjects.push_back(_bio);
    _t15._levels.push_back(_7B);
    _t15._levels.push_back(_8A);
    _t15._levels.push_back(_8B);
    _t15._levels.push_back(_9A);

    _t16._ID = 15;
    _t16._name = "Mr. Adnan";
    _t16._subjects.push_back(_social);
    _t16._subjects.push_back(_business);
    _t16._levels.push_back(_7A);
    _t16._levels.push_back(_7B);
    _t16._levels.push_back(_6A);
    _t16._levels.push_back(_6B);
    _t16._levels.push_back(_6C);
    _t16._levels.push_back(_9A);

    teacher.push_back(_t1);
    teacher.push_back(_t2);
    teacher.push_back(_t3);
    teacher.push_back(_t4);
    teacher.push_back(_t5);
    teacher.push_back(_t6);
    teacher.push_back(_t7);
    teacher.push_back(_t8);
    teacher.push_back(_t9);
    teacher.push_back(_t10);
    teacher.push_back(_t11);
    teacher.push_back(_t12);
    teacher.push_back(_t13);
    teacher.push_back(_t14);
    teacher.push_back(_t15);
    teacher.push_back(_t16);
}
#endif
#pragma endregion

#pragma region API_TEST
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
#pragma endregion

#pragma region API_TEST_AUTOMATED
#ifdef API_TEST_AUTOMATED
#include <iostream>
int main() {
    init_data();
    _GA ga;
    ga.Init(teacher, subject, level, 1000, level.size());
    ga.Start(1.0, false);

    cout << std::fixed << std::setprecision(2);
    while (!ga.GetIsWorkerStopped()) {
        cout << "Fitness: " << (*ga.GetPopulation())[0].GetFitness()
             << " Crnt Gen: " << ga.GetCurrentGenMadeCnt() << endl;
        system("clear");
    }

    int ta_cnt = 1;
    for (auto indiv : *ga.GetPopulation()) {
        for (int i = 0; i < indiv.GetChromosome()->size(); i++) {
            cout << "Table " << ta_cnt++ << ": ";
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
#pragma endregion

#pragma region API_FILE_SYSTEM_DRIVER_TEST
#ifdef API_FILESYSTEM_DRIVER_TEST
#include <iostream>
int main() {
    init_data();
    API_driver driver;
    driver.Init();
    DB db;
    db._db_teachers = teacher;
    db._db_levels = level;
    db._db_subjects = subject;

    cout << "DB Name: ";
    cin >> db._db_name;

    string path;
    cout << "DB File Path To Create: ";
    cin >> path;

    driver.CreateEmptyDB(path, db, false);
    return 0;
}
#endif
#pragma endregion

#pragma region API_REPORT_GENERATING_DRIVER_TEST
#ifdef API_REPORT_GENERATING_DRIVER_TEST
#include <iostream>
int main() {
    API_driver driver;

    return 0;
}
#endif
#pragma endregion
