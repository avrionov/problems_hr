#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

//-----------------------------------------------------------------------------
void simple_array_sum() {
  int count;

  cin >> count;

  int sum = 0;


  while (std::cin && (count > 0)) {
    int b;
    std::cin >> b;
    sum += b;
    count--;
  }

  cout << sum;
}

//-----------------------------------------------------------------------------
void compare_the_triplets() {

  int a[3];
  int b[3];

  cin >> a[0] >> a[1] >> a[2];
  cin >> b[0] >> b[1] >> b[2];

  int alice_pt = 0;
  int bob_pt = 0;

  for (int i = 0; i < 3; i++) {

    if (a[i] > b[i])
      alice_pt++;

    if (b[i] > a[i])
      bob_pt++;
  }

  cout << alice_pt << " " << bob_pt;
}

//-----------------------------------------------------------------------------
void very_big_sum() {
  int count;

  cin >> count;

  long long int sum = 0;


  while (std::cin && (count > 0)) {
    long long int b;
    std::cin >> b;
    sum += b;
    count--;
  }

  cout << sum;
}

//-----------------------------------------------------------------------------
void diagonal_difference() {
  int count;

  cin >> count;

  int left_diag = 0;
  int right_diag = 0;

  for (int j = 0; j < count; j++) {
    for (int k = 0; k < count; k++) {
      int b;
      cin >> b;
      if (j == k) {
        left_diag += b;
      }
      if (j + k == (count - 1)) {
        right_diag += b;
      }
    }
  }

  int diff = abs(left_diag - right_diag);

  cout << diff;
}

//-----------------------------------------------------------------------------
void plus_minus() {

  int count;
  cin >> count;

  int positives = 0;
  int negatives = 0;
  int zeroes = 0;

  int total_count = count;

  while (std::cin && (count > 0)) {

    int b;
    std::cin >> b;

    if (b > 0)
      positives++;

    if (b < 0)
      negatives++;

    if (b == 0)
      zeroes++;

    count--;
  }

  std::cout << std::fixed;
  cout.precision(5);

  cout << (double)positives / (double)total_count << endl;
  cout << (double)negatives / (double)total_count << endl;
  cout << (double)zeroes / (double)total_count << endl;
}

//-----------------------------------------------------------------------------
void staircase() {

  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      if (j < (count - i - 1))
        cout << " ";
      else
        cout << "#";

    }
    cout << endl;
  }
}

//-----------------------------------------------------------------------------
void time_conversion() {
  string it;

  cin >> it;

  if (it.length() < 10)
    return;

  int hour = (it[0] - '0') * 10 + (it[1] - '0');
  int min = (it[3] - '0') * 10 + (it[4] - '0');
  int sec = (it[6] - '0') * 10 + (it[7] - '0');

  string ampm = it.substr(it.size() - 2);
  if (ampm == "PM" && hour != 12) {
    hour = (hour + 12) % 24;
  } else {
    if (ampm == "AM" && hour == 12) {
      hour = 0;
    }
  }

  cout << setfill('0') << setw(2) << hour;
  cout << ":";
  cout << setfill('0') << setw(2) << min;
  cout << ":";
  cout << setfill('0') << setw(2) << sec;
}

//-----------------------------------------------------------------------------
void circular_array_rotation() {

  int n, k, q;

  cin >> n >> k >> q;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  // rotations
  for (int i = 0; i < k; i++)
    rotate(ar.begin(), ar.end() - 1, ar.end());

  i = 0;

  while (std::cin && (i < q)) {
    size_t b;
    cin >> b;

    if (b < ar.size()) {
      cout << ar[b] << endl;
    }

    i++;
  }
}