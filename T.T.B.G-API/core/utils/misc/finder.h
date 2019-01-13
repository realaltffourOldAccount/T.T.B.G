#pragma once

// find item in vec, of type T
template <class T>
static int findInVec(vector<T> vec, T item) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == item) return i;
    }
    return -1;
}

// determine if all vector elements are unique
#include <algorithm>
template <class Fwd>
bool is_all_unique(vector<Fwd> vec) {
    return std::adjacent_find(vec.begin(), vec.end()) == vec.end();
}

// determine if a value of Type T is not in the vector vec
template <class T>
static bool isNotInVec(vector<T> vec, T item) {
    return (findInVec(vec, item) == -1);
}

// get all unique vales of Type T in the vector vec
template <class T>
static vector<T> GetAllUnique(vector<T> vec) {
    vector<T> result;
    for (T t : vec)
        if (isUnique(result, t)) result.push_back(t);
    return result;
}