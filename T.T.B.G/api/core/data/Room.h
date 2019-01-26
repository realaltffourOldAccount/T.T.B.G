#ifndef ROOM_H
#define ROOM_H

#include "../utils/include_bundles/utils_bundle.h"

enum RoomTypes {
    NORMAL = 0,
    LAB,
    CLAB,
};

struct Room {
    int _ID;
    int _type = -1;
    bool _free = true;
    string _name;
};

#endif