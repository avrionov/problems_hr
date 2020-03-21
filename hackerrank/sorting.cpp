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
void big_sorting() {
  int n;
  cin >> n;

  vector<string> ar;

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    ar.push_back(tmp);
  }

  sort(begin(ar), end(ar), [](string& a, string& b) {
    int x = a.size();
    int y = b.size();
    if (x == y)
      return a < b;

    return x < y;
  });

    for (auto a : ar) {
      std::cout << a << endl;
    }
}

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
void insert_one_counting(vector <int>& ar, int i, long long int& count) {
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
void insertionsort_counting_slow() {

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

    long long int count = 0;
    for (size_t i = 1; i < ar.size(); i++) {
      insert_one_counting(ar, i, count);
    }

    cout << count;
    cout << endl;
  }
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

        long long int count = 0;

        map<int, vector<int>> idx;

        for (int i = 0; i < n; i++) {
            auto it = idx.find(ar[i]);
            if (it == idx.end()) {
                vector<int> tmp;
                tmp.push_back(i);
                idx[ar[i]] = tmp;
            }
            else {
                it->second.push_back(i);
            }
        }

        for (auto it : idx) {
            sort(it.second.begin(), it.second.end());
        }

        int pos = 0;

        for (auto it = idx.begin(); it != idx.end(); it++) {

            for (int i = 0; i < it->second.size(); i++) {
                if (pos != it->second[i]) {
                    count += (it->second[i] - pos);

                    
                    // adjust the indexes
                    for (auto it2 = next(it); it2 != idx.end(); it2++) {
                        for (int j = 0; j < it2->second.size(); j++) {
                            if (it2->second[j] < it->second[i])
                                it2->second[j]++;
                            else
                                break;
                        }

                    }
                    
                }

                pos++;
            }

        }

        cout << count;
        cout << endl;
    }
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()+1) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
        
    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

void insertionsort_counting_multi_set() {

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

        long long int count = 0;

        multiset<int> ms;

        ms.insert(ar[0]);

        for (int i = 1; i < n; i++) {
            ms.insert(ar[i]);

            auto it = ms.upper_bound(ar[i]);

            int dist = distance(it, ms.end());
            
            count += dist;

        }

        cout << count;
        cout << endl;
    }
}

long long int merge_sort (int  low, int  high, vector<int>&ar, vector<int>& tmp) {

    if (low >= high) 
        return 0;

    int mid = (low + high) / 2;

    long long int ax = merge_sort (low, mid, ar, tmp);
    long long int by = merge_sort (mid + 1, high, ar, tmp);

    long long int ret = 0;
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (ar [i] <= ar[j])  {
            tmp[k++] = ar[i++];
        } else {
            tmp[k++] = ar[j++];
            ret += abs(mid + 1 - i);
        }
    }

    while (i <= mid)  
        tmp[k++] = ar[i++];


    while (j <= high)  
        tmp[k++] = ar[j++];


    for (int i = low; i <= high; i++) 
        ar[i] = tmp[i];

    return ret + ax + by;
}


void insertionsort_counting_merge() {

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

        vector <int> tmp;
        tmp.resize(n, 0);

        long long int count = merge_sort(0, n - 1, ar, tmp);
               
        cout << count;
        cout << endl;
    }
}

//-----------------------------------------------------------------------------
void insertionsort_counting_f() {

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

        long long int count = 0;

        FenwickTree tree (ar);
        
        for (int i = 0; i < n; i++) {
            int pos = tree.point_query(i);
            cout << pos << " ";
        }


        cout << count;
        cout << endl;
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

  int alerts = 0;
  
  vector<int>::iterator it = ar.begin();
  std::vector<int> sub(it, it + d);
  sort(begin(sub), end(sub));

  multiset<int> min_set, max_set;
  
  for (int i = 0; i < d / 2; i++)
      min_set.insert(sub[i]);
  
  for (int i = d /2 ; i < d ; i++) {
      max_set.insert(sub[i]);
  }

  for (size_t i = d; i < ar.size(); i++) {
      
      double median;
      if (d % 2 == 1)
          median = *max_set.begin();
      else 
          median = (*max_set.begin() +  *min_set.rbegin()) / 2.0;

      if (ar[i] >= 2 * median)
          alerts++;

      int remove_item = ar[i - d];

      if (remove_item <= *min_set.rbegin()) {
          auto it = min_set.find(remove_item);
          min_set.erase(it);

          if (ar[i] <= *max_set.begin()) {
              min_set.insert(ar[i]);
          } else {
              max_set.insert(ar[i]);
              min_set.insert(*max_set.begin());
              max_set.erase (max_set.begin());
          } 
      }  else {
          auto it = max_set.find(remove_item);
          max_set.erase(it);

          if (ar[i] <= *max_set.begin()) {
              min_set.insert(ar[i]);
              max_set.insert(*min_set.rbegin());

              auto it = min_set.find(*min_set.rbegin());

              min_set.erase(it);
          } else {
              max_set.insert(ar[i]);
          }          
      }       
   }

  cout << alerts;
}

//-----------------------------------------------------------------------------
int count_swaps( const vector<int> arr, const vector<int> sorted) {

    vector<int> copy_ar(arr);
    int n = arr.size();

    int count = 0;

    map<int, int> idx;

    // save the indexes

    for (int i = 0; i < n; i++) {
        idx[arr[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {

        if (copy_ar[i] == sorted[i])
            continue;

        count++;

        int index = idx[sorted[i]];

        swap(copy_ar[i], copy_ar[index]);
        idx[copy_ar[i]] = i;

        idx[copy_ar[index]] = index;
    }

    return count;
}

int lilysHomework(vector<int> arr) {

    int n = arr.size();

    vector<int> sorted(arr);
    
    sort(begin(sorted), end(sorted));

    int count = count_swaps (arr, sorted);

    vector<int> rsorted(arr);

    sort(begin(rsorted), end(rsorted), greater<int>());

    int rcount = count_swaps(arr, rsorted);;
    
    return min (count, rcount);
    
}