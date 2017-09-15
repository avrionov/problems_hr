#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <list>
#include <set>
#include <map>

using namespace std;

//-----------------------------------------------------------------------------
void mini_max_sum() {
    vector <int> ar;

    int n = 5;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        ar.push_back(b);
    }


    unsigned long long sum = 0;
    for (const int& i : ar)
        sum += i;

    unsigned long long min = 1844674407370955165;
    unsigned long long max = 0;

    for (const int& i : ar) {
        unsigned long long tmp = sum - i;

        if (tmp < min)
            min = tmp;

        if (tmp > max)
            max = tmp;
    }

    cout << min << " " << max;
}
