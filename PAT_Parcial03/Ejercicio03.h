#pragma once

#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap
{
public:
    TimeMap();

    void set(string key, string value, int timestamp);

    string get(string key, int timestamp);

private:
    unordered_map<string, map<int, string>> data;
};

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
    data[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp)
{
    if (data.find(key) == data.end()) {
        return "";
    }

    auto it = data[key].upper_bound(timestamp);
    if (it == data[key].begin()) {
        return "";
    }

    --it;
    return it->second;
}


