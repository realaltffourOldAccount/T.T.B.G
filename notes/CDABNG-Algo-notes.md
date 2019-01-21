
This is the specification for the 'CDABNG' Algoirthm.

First of data representation:

    Code Representation:
    struct TimeLine {
        vector<vector<Slot>> *__slots = nullptr;
        vector<Teacher> _teachers;
        vector<Subject> _subjects;
        vector<Level> _levels;
        int _period_cnt = 0;
        int _class_cnt = 0;

        bool Check();
    };

    - The data will be represented internally as a struct.
    - A vector of vectors, called __slots, will be used to represent the timeline.
    - __slots will be row-major, __slots[0][1] will be the 1nd class, 2nd period.
    - A counter would be used for the periods, since not all classes will have all subjects.
    - A counter would be used for the classes, since not all classes will have all subjects.

    The vectors will be the type of 'Slot', a slot is a struct that have a value called teacher and subject.

    Conditions of a Slot:
        - A teacher may be the DEFAULT_TCHR which indicates a slot/period where the teacher may be not defined or arbitary, that is if and ONLY if subject isnt DEFUALT_SUBJ.
        - A subject may be the DEFUALT_SUBJ which indicates a slot/period needs a teacher and not a subject to teach, that is if and ONLY if teacher isnt DEFAULT_TCHR.
        - If both, teacher and subject, are defaults this means that the slot couldnt be made by CDABNG or not specified. This condition will be named EMPTY_SLOT. (Such as the 8th period of level 4A, refere to dummy 
        data/CLASSES_MASTER_TIMETABLE.xlsx)

    All vectors of the __slots must have the size of _period_cnt, or the TimeLine will be marked as incomplete or not correct.

    The _teachers vector will contain all of the teachers.
    The _subjects vector will contain all of the subjects.
    The _levels vector will contain all of the levels.

    Between c++ classes the TimeLine will be passed as a pointer(for optimizations), 
    instead of passing a individual vectors.

    Check():
        Returns if the timeline is valid.
        
        A timeline is valid if:
        - Its _levels.size() == _class_cnt.
        - Its _class_cnt == _slots.size();
        - Its _period_cnt == countof(_slots[i].size());
        - If a condition is false all of it is false.

    __slots is a pointer.

Then the "CDABNG" algorithm:
    - The parameters:
        - A TimeLine struct. (Will check of it & pass by value)
        - A value which is the 'Vision' of the generator, range: 0.0-1.0, perecentage.
        - A value which is the 'give up rate' of the generator, number of tries before giving up, should be more than the number of teachers by 15%.

    - The algorithm will have three parts:
        - The PREFIX.
        - The Generator, also split to two parts.
        - The POSTFIX.

    - The PREFIX stage will:
        - Pick the subjects and track each one to a class (Filtering).
        - Pick the the teachers that can teach what class/Level.

    - The Generator stage:
        - Two stages:
            - Generation proccess.
            - Checking process.

        - Generation Process:
            - The generation procces will generate the slots incrementaly.
            - Uses the data given by prefix stage.
            - Takes in mind, in every column, the above columns by a percentage of the vision rate / 2, also the below columns.
            - Gives up checking for teachers when it reaches the give up try.
        
        - Checking Process:
            - Makes sure that the empty slots are not makeable
            - Makes sure that the non-empty slots are valid teacher subject level combination.
            - Makes sure that every class gets one of its appropiate subject.
        
    - The PostFix stage:
        - 