#ifndef _H_FILE_UTIL_H_
#define _H_FILE_UTIL_H_
#pragma once
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "../misc/string_util.h"

// returns if the file with the name of the value of the string "file" exists
static bool fileExists(std::string file) {
    std::ifstream ffs(file);
    return ffs.is_open();
}

// return if the directory with the name of the value of the string "dirName_in"
// exists
static bool dirExists(const std::string& dirName_in) {
    struct stat info;
    if (stat(dirName_in.c_str(), &info) != 0)  // might be a file
        return false;
    else if (info.st_mode & S_IFDIR)  // it is a dir
        return true;
    else
        return false;  // it is neither
}

// creates a file with the name of the value of string "str"
// returns true if it exists
static bool createFile(std::string str) {
    FILE* fp = fopen(str.c_str(), "w");
    return fileExists(str);
}

// creates directory with the name of the value of string "str"
static bool createDir(std::string str) {
#ifdef _WINDOWS_
    mkdir(str);
#else
    mkdir(str.c_str(), 0755);
#endif
}

// deletes the file with the name of the value of the string "str"
// returns true if it is deleted
static bool deleteFile(std::string str) { return remove(str.c_str()); }

#endif  // !_H_FILE_UTIL_H_
