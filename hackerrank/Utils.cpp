#include "Utils.h"
#include <cstdio>
#include <iostream>
#include <algorithm>


map<string, std::chrono::microseconds> timethis::_durs;
map<string, long long int> timethis::_counts;

timethis::timethis(string s) {
    _s = s;
    _start = high_resolution_clock::now();

}

timethis::~timethis() {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - _start);

    _counts[_s]++;
    _durs[_s] += duration;

    cout << "Time taken by " << _s << ": " << duration.count() << " microseconds" << endl;
}

void timethis::print_stats() {

    for (auto a : _durs) {
        long long int count = _counts[a.first];

        cout << a.first << ": " << a.second.count() << ", " << (double)a.second.count() / count << endl;
    }
}


//-----------------------------------------------------------------------------
void read_array(vector<int>& ar, int n) {
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }
}

void read_array(vector<long long int>& ar, int n) {
    for (int i = 0; i < n; i++) {
        long long int tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }
}


void read_array(vector<long >& ar, int n) {
    for (int i = 0; i < n; i++) {
        long tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }
}


