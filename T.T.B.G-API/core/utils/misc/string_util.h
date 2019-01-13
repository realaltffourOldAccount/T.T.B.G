#ifndef STRING_UTIL_H_
#define STRING_UTIL_H_

#pragma once
#include <string>
#include <vector>
using namespace std;

// converts string s to a wstring value
static std::wstring s2ws(const std::string &s) {
    std::wstring wsTmp(s.begin(), s.end());

    return wsTmp;
}

// converts wstring ws to a string value
static std::string ws2s(const std::wstring &ws) {
    std::string sTmp(ws.begin(), ws.end());
    return sTmp;
}

// splits str with delim as the delimeter, returns a vector of the splitted
// items
static vector<string> split(const string &str, const string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

// removes toErase strings from mainStr
static string ExtractFromStr(std::string mainStr, const std::string toErase) {
    size_t pos = std::string::npos;

    // Search for the substring in string in a loop untill nothing is found
    while ((pos = mainStr.find(toErase)) != std::string::npos) {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
    return mainStr;
}
#endif  // !STRING_UTIL_H_
