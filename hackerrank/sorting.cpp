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
void sorting_tutorial_intro() {

  int n, v;

  cin >> v >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  vector <int>::iterator it = find(begin(ar), end(ar), v);

  if (it != end(ar))
    cout << it - begin(ar);

}

//-----------------------------------------------------------------------------
void insert_one1(vector <int>& ar, size_t i) {
  auto j = i;
  int val = ar[i];

  while (j > 0 && ar[j - 1] > val) {
   
    ar[j] = ar[j - 1];
    //ar[j - 1] = tmp;
    j--;

    // print the array
    for (auto elem : ar)
      cout << elem << " ";
    cout << endl;
  }

  ar[j] = val;
  // print the array
  for (auto elem : ar)
    cout << elem << " ";
  cout << endl;
}


void insertionsort1() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  insert_one1(ar, ar.size() - 1);
}

//-----------------------------------------------------------------------------

void insert_one(vector <int>& ar, size_t i) {
  auto j = i;
  while (j > 0 && ar[j - 1] > ar[j]) {
    int tmp = ar[j];
    ar[j] = ar[j - 1];
    ar[j - 1] = tmp;
    j--;
  }
}

void insertionsort2() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  for (size_t i = 1; i < ar.size(); i++) {

    insert_one(ar, i);

    // print the array
    for (auto elem : ar)
      cout << elem << " ";
    cout << endl;
  }

}

//-----------------------------------------------------------------------------
void insertionSort(int N, int arr[]) {
  int i, j;
  int value;
  for (i = 1; i<N; i++)
  {
    value = arr[i];
    j = i - 1;
    while (j >= 0 && value<arr[j])
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = value;
  }
  for (j = 0; j<N; j++)
  {
    printf("%d", arr[j]);
    printf(" ");
  }
}


//-----------------------------------------------------------------------------

int partition(vector<int>& ar, int left, int right)
{
  int pivot = ar[left];
  while (left != right)
  {
    if (ar[left] > ar[right])
    {
      swap(ar[left], ar[right]);
    }

    if (pivot == ar[left])
      right--;
    else // Pivot == arr[right]
      left++;
  }
  return left;
}


void partition_test() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  partition(ar, 0, n - 1);

  // print the array
  for (auto elem : ar)
    cout << elem << " ";
  cout << endl;
}


size_t partition1(vector<int>& ar, size_t left, size_t right)
{
  vector <int> left_ar;
  vector <int> right_ar;

  int pivot = ar[left];

  for (auto i = left + 1; i <= right; ++i) {
    if (ar[i] < pivot) {
      left_ar.push_back(ar[i]);
    }
    else {
      if (ar[i] > pivot)
        right_ar.push_back(ar[i]);
    }
  }

  auto pos = left_ar.size() + left;

  for (size_t i = 0; i < left_ar.size(); i++)
    ar[i + left] = left_ar[i];

  ar[pos] = pivot;

  for (size_t i = 0; i < right_ar.size(); i++)
    ar[i + pos + 1] = right_ar[i];

  return pos;
}


void quick_sort(vector<int>& ar, int left, int right) {

  if (left >= right)
    return;

  auto pos = partition1(ar, left, right);


  quick_sort(ar, left, pos - 1);
  quick_sort(ar, pos + 1, right);

  // print the array
  for (int i = left; i <= right; i++)
    cout << ar[i] << " ";
  cout << endl;
}


void quick_sort_test() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  quick_sort(ar, 0, n - 1);
}


//-----------------------------------------------------------------------------

int partition3(vector<int>& ar, int left, int right) {
  int pivot = ar[right];

  int i = left;

  for (int j = left; j <= (right - 1); j++) {
    if (ar[j] <= pivot) {
      swap(ar[i], ar[j]);
      i++;
    }
  }

  swap(ar[i], ar[right]);

  return i;
}

void quick_sort3(vector<int>& ar, int left, int right) {

  if (left >= right)
    return;

  int pos = partition3(ar, left, right);
  // print the array
  for (auto elem : ar)
    cout << elem << " ";
  cout << endl;

  quick_sort3(ar, left, pos - 1);
  quick_sort3(ar, pos + 1, right);

}

void quick_sort_test3() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  quick_sort3(ar, 0, n - 1);
}
//-----------------------------------------------------------------------------

void counting_sort1() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  vector<int> field(100, 0);

  for (auto i : ar) {
    if (i >= 0 && i < 100)
      field[i]++;
  }

  // print the array
  for (auto elem : field)
    cout << elem << " ";
}


void counting_sort2() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;
    ar.push_back(b);
    i++;
  }

  vector<int> field(100, 0);

  for (auto i : ar) {
    if (i >= 0 && i < 100)
      field[i]++;
  }

  // print the array
  for (int k = 0; k < 100; k++) {
    for (int i = 0; i < field[k]; i++)
      cout << k << " ";
  }
}


void counting_sort3() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;

    // string
    string tmp;
    cin >> tmp;

    ar.push_back(b);
    i++;
  }

  vector<int> field(100, 0);

  for (auto i : ar) {
    if (i >= 0 && i < 100)
      field[i]++;
  }

  int sum = 0;
  for (auto elem : field) {
    sum += elem;
    cout << sum << " ";
  }

}

void counting_sort4() {

  int n;

  cin >> n;

  vector <int> ar;
  vector <string> strs(100, "");

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;


    // string
    string tmp;
    cin >> tmp;

    if (i < n / 2)
      tmp = "-";

    if (strs[b].empty())
      strs[b] = tmp;
    else {
      strs[b].append(" ");
      strs[b].append(tmp);
    }
    i++;
  }

  for (auto elem : strs) {
    if (!elem.empty())
      cout << elem << " ";
  }
}

//-----------------------------------------------------------------------------
void closest_numbers() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;

    ar.push_back(b);
    i++;
  }

  sort(begin(ar), end(ar));

  list < pair <int, int>> closest;

  int smallest = 2147483647;

  for (int i = 1; i < n; i++) {
    int dif = ar[i] - ar[i - 1];

    if (dif < smallest) {
      closest.clear();
      closest.push_back(make_pair(ar[i - 1], ar[i]));
      smallest = dif;
    }
    else {
      if (dif == smallest)
        closest.push_back(make_pair(ar[i - 1], ar[i]));
    }
  }

  for (auto i : closest) {
    cout << i.first << " " << i.second << " ";
  }
}

//-----------------------------------------------------------------------------
void find_median() {

  int n;

  cin >> n;

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;

    ar.push_back(b);
    i++;
  }

  std::nth_element(ar.begin(), ar.begin() + ar.size() / 2, ar.end());

  cout << ar[ar.size() / 2];

}

//-----------------------------------------------------------------------------
void insert_one_counting(vector <int>& ar, int i, int& count) {
  int j = i;
  int val = ar[i];

  while (j > 0 && ar[j - 1] > val) {
   
    ar[j] = ar[j - 1];
    count++;
    j--;
  }

  ar[j] = val;
}

//-----------------------------------------------------------------------------
void insertionsort_counting() {

  int q;

  cin >> q;

  vector <int> ar;

  ar.resize(10000001);

  for (int k = 0; k < q; k++) {

    ar.clear();
    int n;

    cin >> n;

    int i = 0;

    while (std::cin && (i < n)) {
      int b;
      cin >> b;
      ar.push_back(b);
      i++;
    }

    int count = 0;
    for (size_t i = 1; i < ar.size(); i++) {
      insert_one_counting(ar, i, count);
    }

    cout << count;
    cout << endl;
  }
}

//-----------------------------------------------------------------------------
double proper_median(std::vector<int> &v) {
  size_t n = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + n, v.end());
  int vn = v[n];
  if (v.size() % 2 == 1) {
    return vn;
  }
  else {
    std::nth_element(v.begin(), v.begin() + n - 1, v.end());
    return (vn + v[n - 1]) / 2.0;
  }
}

//-----------------------------------------------------------------------------
void fraudulent_activity() {

  int n, d;

  cin >> n >> d; // prior days to calculate activity

  vector <int> ar;

  int i = 0;

  while (std::cin && (i < n)) {
    int b;
    cin >> b;

    ar.push_back(b);
    i++;
  }

  //std::nth_element(ar.begin(), ar.begin() + ar.size() / 2, ar.end());

  vector<int>::iterator it = ar.begin();

  int alerts = 0;
  for (size_t i = d; i < ar.size(); i++) {
    std::vector<int> sub(it, it + d);
    double median = proper_median(sub);

    if (ar[i] >= 2 * median)
      alerts++;

    it++;
  }

  cout << alerts;
}
