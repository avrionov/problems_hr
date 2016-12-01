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

void insert_one1(vector <int>& ar, int i) {
    int j = i;
    int val = ar[i];

    while (j > 0 && ar[j - 1] > val) {
        int tmp = ar[j];
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

void insert_one(vector <int>& ar, int i) {
    int j = i;
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
        while (j>=0 && value<arr[j])
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


int partition1(vector<int>& ar, int left, int right)
{
  vector <int> left_ar;
  vector <int> right_ar;

  int pivot = ar[left];
  
  for (int i = left+1; i <= right; ++i) {
    if (ar[i] < pivot) {
      left_ar.push_back(ar[i]);
    }
    else {
      if (ar[i] > pivot)
        right_ar.push_back(ar[i]);
    }
  }

  int pos = left_ar.size() + left;

  for (size_t i = 0; i < left_ar.size(); i++)
    ar[i + left] = left_ar[i];

  ar[pos] = pivot;

  for (size_t i = 0; i < right_ar.size(); i++)
    ar[i+pos+1] = right_ar[i];

  return pos;
}


void quick_sort(vector<int>& ar, int left, int right) {

  if (left >= right)
    return;

  int pos = partition1(ar, left, right);
  

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

  quick_sort(ar, 0, n-1);
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
  for (int k = 0; k < 100; k++ ) {
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
  vector <string> strs (100, "");

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
    } else {
      if (dif == smallest)
        closest.push_back(make_pair(ar[i - 1], ar[i]));
    }
  }
  
  for (auto i : closest) {
    cout << i.first << " " << i.second << " ";
  }
}

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
    int tmp = ar[j];
    ar[j] = ar[j - 1];
    count++;
    j--;
  }

  ar[j] = val;
}

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
  } else {
    std::nth_element(v.begin(), v.begin() + n - 1, v.end());
    return (vn + v[n - 1]) / 2.0;
  }
}

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



//-----------------------------------------------------------------------------
void reduced_string() {

  string st;

  cin >> st;

  bool cont_flag = true;

  while (cont_flag) {

    if (st.empty())
      break;

    if (st.length() == 1)
      break;

    cont_flag = false;

    for (size_t i = 1; i < st.length(); i++) {
      if (st[i - 1] == st[i]) {
        st.erase(i - 1, 2);
        cont_flag = true;
        break;
      }        
    }  
  }

  if (st.empty())
    cout << "Empty String";
  else
    cout << st;
}

//-----------------------------------------------------------------------------
void camel_case() {

  string st;

  cin >> st;

  int len = 1;
  if (st.length() > 1) {
    for (size_t i = 1; i < st.length(); i++) {
      if ((st[i] >= 'A') && (st[i] <= 'Z'))
        len++;
    }
  }
    
  cout << len;
}


//-----------------------------------------------------------------------------
bool check_word(string& st) {

  if (st.length() <= 1)
    return false;

  bool b = true;
  char t1 = st[0];
  char t2 = st[1];
  for (size_t i = 2; i < st.length(); i++) {
    if (t1 == t2)
      return false;

    t1 = t2;
    t2 = st[i];
  }

  if (t1 == t2)
    return false;

  return true;
}


//-----------------------------------------------------------------------------
void two_characters() {
  string st;

  int len;

  cin >> len;

  cin >> st;

  set<char> chars;

  for (char& ch : st)
    chars.insert(ch);

  int max = 0;

  for (auto c : chars) {
    for (auto d : chars) {
      if (c != d) {
        string st1;

        for (char& ch : st)
          if (ch == c || ch == d)
            st1.push_back(ch);


        if (check_word(st1)) {
          int len = st1.length();
          if (len > max) {
            cout << len << " " << st1 << endl;
            max = len;
          }
        }

      }
    }
  }

  cout << max;
}

//-----------------------------------------------------------------------------
char tolower_(char in) {
  if (in <= 'Z' && in >= 'A')
    return in - ('Z' - 'z');
  return in;
}

void pangrams() {

  string st;

  getline(cin, st);

  set<char> chars;

  for (char& ch : st) {
    if (ch == ' ')
      continue;

    chars.insert(tolower_(ch));
  }

  if (chars.size() == 26)
    cout << "pangram";
  else
    cout << "not pangram";
}


//-----------------------------------------------------------------------------
void caesar_cipher() {
  int n, k;
  string st;

  cin >> n;
  cin >> st;
  cin >> k;

  string nst;

  for (char& ch : st) {

    char ch1 = ch;

    if (ch >= 'a' && ch <= 'z') {
      int pos = ch - 'a';
      pos += k;
      pos = pos % 26;
      ch1 = pos + 'a';
    }

    if (ch >= 'A' && ch <= 'Z') {
      int pos = ch - 'A';
      pos += k;
      pos = pos % 26;
      ch1 = pos + 'A';
    }

    nst.push_back(ch1);
  }

  cout << nst;
}

//-----------------------------------------------------------------------------
void mars_exploration() {

  string st;

  getline(cin, st);

  string pattern = "SOS";

  int count = 0;

  for (size_t i = 0; i < st.length(); i++) {
    if (st[i] != pattern[i % 3])
      count++;
  }

  cout << count;
}

//-----------------------------------------------------------------------------
void funny_string() {
  int t;

  cin >> t;

  for (int k = 0; k < t;) {
    string st;
    getline(cin, st);


    // check if we read something
    if (st.length() > 0) {

      int len = st.length();

      bool funny = true;
      for (int i = 1; i < len; i++) {
        int rev_i = len - i - 1;

        if (abs(st[i] - st[i - 1]) != abs(st[rev_i] - st[rev_i + 1])) {
          funny = false;
          break;
        }
      }

      if (funny)
        cout << "Funny" << endl;
      else
        cout << "Not Funny" << endl;
      k++;

    }    
  }
}

//-----------------------------------------------------------------------------
void gem_stones() {
  
  int n;

  cin >> n;

  int gem_count[26] = { 0 };

  for (int k = 0; k < n;) {
    string st;
    getline(cin, st);

    // check if we read something
    if (st.length() > 0) {
      set<char> gem_set;
      for (auto ch : st)
        gem_set.insert(ch);

      for (auto ch : gem_set)
        if (ch >= 'a' && ch <= 'z')
          gem_count[ch - 'a']++;

      k++;
    }    
  }

  int count = 0;
  for (int i = 0; i < 26; i++)
    if (gem_count[i] == n)
      count++;

  cout << count;
}

//-----------------------------------------------------------------------------
void alternating_characters() {

  int n;

  cin >> n;

  int gem_count[26] = { 0 };

  for (int k = 0; k < n;) {
    string st;
    getline(cin, st);

    // check if we read something
    if (st.length() > 0) {
      int count = 0;
      size_t j = 1;      
      for (size_t i = 0; i < st.length() - 1; i++) {
        if (st[i] ==  st[j] && j < st.length()) {
          count++;
        }
        j++;
      }
      cout << count << endl;
      k++;
    }
  }  
}

//-----------------------------------------------------------------------------
void beautiful_binary_string() {
  int n;
  string st;

  cin >> n;
  cin >> st;
  
  int count = 0;

  string pattern = "010";

  int pos = st.find(pattern);

  while (pos != string::npos) {
    count++;
    pos = st.find(pattern, pos +  3);
  }

  cout << count;
}

//-----------------------------------------------------------------------------
void the_love_letter_mystery() {
  
  int n;

  cin >> n;
    
  for (int k = 0; k < n;) {
    string st;
    getline(cin, st);

    // check if we read something
    if (st.length() > 0) {
     
      int count = 0;
      int len = st.length();
      for (int i = 0; i < len / 2; i++)
        count += abs(st[i] - st[len - i - 1]);

      cout << count << endl;
      k++;
    }
  }
}

//-----------------------------------------------------------------------------
void palindrome_index() {
  int n;

  cin >> n;

  for (int k = 0; k < n;) {
    string st;
    getline(cin, st);

    // check if we read something
    if (st.length() > 0) {

      int count = 0;
      int len = st.length();
      int start = 0;
      int end = len - 1;
      for (int i = 0; i < len / 2; i++) {

          if (st[i] != st[len - 1 - i]) {

              if ((st[i + 1] == st[len - 1 - i]) && (st[i + 2] == st[len - 1 - i - 1]))
                  cout << i << endl;
              else if ((st[i] == st[len - 1 - i - 1]) && (st[i + 1] == st[len - 1 - i - 2]))
                  cout << len - 1 - i << endl;

              goto skip;
          }           
      }
      cout << "-1" << endl;
      skip:;
      k++;
    }
  }
}

void anagram() {
    int n;

    cin >> n;

    for (int k = 0; k < n;) {
        string st;
        cin >> st;
        if (st.length() % 2 == 1) {
            cout << -1 << endl;
            
        } else {
            int len = st.length();

            multiset<char> char_set;
            for (int i = 0; i < len / 2; i++)
                char_set.insert(st[i]);

            for (int i = len / 2; i < len; i++) {
                multiset<char>::iterator it;
                it = char_set.find(st[i]);
                if (it != char_set.end())
                    char_set.erase(it);
            }
            cout << char_set.size() << endl;
        }        
        k++;
    }
}

void making_anagrams() {
  string s1, s2;

  cin >> s1 >> s2;

  int ar[26] = { 0 };
  
  for (auto ch : s1)
    ar[ch - 'a']++;

  for (auto ch : s2)
    ar[ch - 'a']--;

  int count = 0;
  for (int i = 0; i<26; i++) 
    count += abs(ar[i]);
  
  cout << count;
}


//-----------------------------------------------------------------------------
void sherlock_and_valid_string() {
  string st;
  getline(cin, st);

  int char_count[26] = { 0 };

  for (auto ch : st)
    if (ch >= 'a' && ch <= 'z')
      char_count[ch - 'a']++;

  map<int, int> buckets;
  for (int i = 0; i < 26; i++) {
      if (char_count[i]) {
          map<int, int>::iterator it = buckets.find(char_count[i]);
          if (it == buckets.end())
              buckets[char_count[i]] = 1;
          else
              buckets[char_count[i]] ++;
    }    
  }

  if (buckets.size() == 1) {
      cout << "YES";
  } else {
    if (buckets.size() == 2) {
       map<int, int>::iterator it = buckets.begin();
       map<int, int>::iterator it2 = it++;

       
       map<int, int>::iterator big;
       map<int, int>::iterator small;

       if (it->second > it2->second) {
               big = it;
               small = it2;
           } else  {
               big = it2;
               small = it;
           }

       if (small->second == 1) {
           if ( ( (small->first - 1) == big->first) || (small->first == 1))
               cout << "YES";
           else
               cout << "NO";
       } else {
           cout << "NO";
       }

    } else {    
      cout << "NO";
   }
  }
}

void game_of_thrones() {
  
  string st;

  cin >> st;

  int char_count[26] = { 0 };

  for (auto ch : st)
    if (ch >= 'a' && ch <= 'z')
      char_count[ch - 'a']++;

  if (st.length() % 2 == 1) {  // odd number of characters
    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
      if (char_count[i] % 2 == 1) {// odd number
        odd_count++;
        if (odd_count > 1) {
          cout << "NO";
          return;
        }
      }
    }
    cout << "YES";
  } else {  // even number of charters
 // all counts should be even
    for (int i = 0; i < 26; i++) {
      if (char_count[i])
        if (char_count[i] % 2 == 1) {// odd number
          cout << "NO";
          return;
        }
    }
    cout << "YES";
  }
}

//-----------------------------------------------------------------------------
void two_strings() {
  int q;
  cin >> q;

  while (q > 0) {
    string s1;
    string s2;

    string pattern = "abcdefghijklmnopqrstuvwxyz";

    cin >> s1;
    cin >> s2;
    bool bFlag = false;
    for (auto ch : pattern) {
      if (s1.find(ch) != string::npos && s2.find(ch) != string::npos) {
        bFlag = true;
        break;
      }        
    }
    if (bFlag)
      cout << "YES";
    else
      cout << "NO";

    cout << endl;
    q--;
  }
}

//-----------------------------------------------------------------------------
void string_construction() {
  int q;
  cin >> q;

  while (q > 0) {
    string st;
    
    cin >> st;

    int char_count[26] = { 0 };

    for (auto ch : st)
      if (ch >= 'a' && ch <= 'z')
        char_count[ch - 'a']++;

    int count = 0;

    for (int i = 0; i < 26; i++) {
      if (char_count[i])
        count++;
    }

    cout << count << endl;
    q--;
  }
}

int main() {

  string_construction();

  getchar();
}



