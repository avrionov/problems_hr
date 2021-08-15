#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Utils.h"

#include "bigint.h"

using namespace std;




//-----------------------------------------------------------------------------
void fibonachi_modified() {

  int n, t1, t2;

  cin >> t1 >> t2 >> n;

  bigint lt1(t1);
  bigint lt2(t2);

  for (int j = 2; j < n; j++) {
    lt1 += lt2* lt2;
    lt1.swap(lt2);
  }

  cout << lt2;
}

//-----------------------------------------------------------------------------
void travel_around_the_world() {
    int n;
    long long int capacity;

    cin >> n >> capacity;

    vector<long long int> a, b, difference(n), min_diff(n);

    read_array(a, n);
    read_array(b, n);
    int test_start = 0;
    int start_city = 0;

    for (int i = 0; i < n; i++) {
        difference[i] = a[i] - b[i];
        if (difference[i] < 0)
            test_start = i;
    }

    for (int i = n * 2 + test_start; i >= test_start + 1; i--) {
        
        int pos = i % n;
        min_diff[pos] = min(difference[pos], min_diff[(i + 1) % n] + difference[pos]);

        if (a[pos] > capacity) 
            min_diff[pos] -= (a[pos] - capacity);
        
        int temp = a[pos] - min_diff[pos];
        if (temp > capacity) {
            cout << 0;
            return;
        }        
    }

    for (int i = 0; i < n; i++) {
        if (min_diff[i] >= 0) 
            start_city++;        
    }

    cout << start_city;
}

//-----------------------------------------------------------------------------
int dynamic_coin_change(int n, vector<int>& coins, vector<int>& memo) {

    if (memo[n] != -1)
        return memo[n];

    int count = 0;
    for (int i = 0; i < coins.size(); i++) {
         if (coins[i] > n) {
            count += dynamic_coin_change(n - coins[i], coins, memo);
        } else {
            //if coins[i] ==)
        }
    }

    memo[n] = count + 1;

    return memo[n];
}

void coin_change_prroblem() {

    // n is the number of units
    // m is the number of coin types

    int n, m; 
    cin >> n >> m;

    vector<int> coins;

    read_array(coins, m);
    vector<int> memo(n+1);

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    memo[0] = 1;

    int ret = dynamic_coin_change(n, coins, memo);

    cout << ret;
}