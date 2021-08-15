#pragma once

#include <vector>
#include <map>
#include <chrono>
#include <string>


using namespace std;
using namespace std::chrono;

typedef unsigned long long int uint64;

typedef long long int int64;

void read_array(vector<int>& ar, int n);
void read_array(vector<int64>& ar, int n);
void read_array(vector<long>& ar, int n);


class timethis {
public:
    timethis(string s);
    ~timethis();
    static void print_stats();

    string _s;
    steady_clock::time_point _start;

    static map<string, std::chrono::microseconds> _durs;
    static map<string, long long int> _counts;
};

