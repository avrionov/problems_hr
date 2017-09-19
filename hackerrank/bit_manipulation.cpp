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

#include <fstream>

using namespace std;

typedef unsigned long long int uint64;

//-----------------------------------------------------------------------------
void lonely_integer() {
  int n;

  cin >> n;

  int accum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    accum ^= a;
  }

  cout << accum;
}

//-----------------------------------------------------------------------------
void maximum_xor() {
  int l, r;

  cin >> l >> r;

  int max = 0;
  int cnt = 0;
  for (int xorRes = l^r; xorRes; xorRes >>= 1) {
    max |= (1 << cnt++);
  }

  cout << max << endl;
}

//-----------------------------------------------------------------------------
bool is_power_of_2(uint64 n) {
  return !(n == 0) && !(n & (n - 1));
}

int number_of_bits (uint64 n) {
  int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}


void counter_game() {

  int t;
  uint64 n;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    
    if (number_of_bits(n - 1) & 1)
      cout << "Louise" << endl;
    else
      cout << "Richard" << endl;
  }
}

//-----------------------------------------------------------------------------
long long get_nt_xor(long long x) {
  if (x == 0)
    return 0;

  if (x % 4 == 3)
    return 0;

  return get_nt_xor(x - 1) ^ x;
}

long long G(long long x) {
  long long a = x % 8;
  if (a == 0 || a == 1) return x;
  if (a == 2 || a == 3) return 2;
  if (a == 4 || a == 5) return x + 2;
  if (a == 6 || a == 7) return 0;
  return 0;
}

void xor_sequence() {
  int a = 0;
  for (int i = 1; i < 100; i++) {
    cout << (i-1) << " : " << a << " "<< get_nt_xor(i-1) << " " << G(i-1) << endl;
    a = a ^ i;
  }
 

  int t;  // number of test cases
  cin >> t;

  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;

    
    long long l_x = get_nt_xor(l - 1);
    long long r_x = get_nt_xor(r);
    long long sum = r_x ^ l_x;

    long long l_g = G(l - 1);
    long long r_g = G(r);
    long long sum_g = r_g ^ l_g;

    //int current_value = get_nt_xor(l);
    /*for (int j = l + 1; j <= r; j++) {
      int next_value = current_value ^ j;
      sum = sum ^ next_value;
      current_value = next_value;
    }*/

    cout << sum <<" "<< sum_g << endl;
  }
}