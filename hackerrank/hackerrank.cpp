
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
#include <sstream>

#include <fstream>

using namespace std;

typedef unsigned long long int uint64;

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

  size_t max = 0;

  for (auto c : chars) {
    for (auto d : chars) {
      if (c != d) {
        string st1;

        for (char& ch : st)
          if (ch == c || ch == d)
            st1.push_back(ch);


        if (check_word(st1)) {
          auto len = st1.length();
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

      auto len = st.length();

      bool funny = true;
      for (size_t  i = 1; i < len; i++) {
        auto rev_i = len - i - 1;

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

  auto pos = st.find(pattern);

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
      auto len = st.length();
      for (size_t i = 0; i < len / 2; i++)
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

      auto len = st.length();
     
      for (size_t i = 0; i < len / 2; i++) {

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
            auto len = st.length();

            multiset<char> char_set;
            for (size_t i = 0; i < len / 2; i++)
                char_set.insert(st[i]);

            for (auto i = len / 2; i < len; i++) {
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

//-----------------------------------------------------------------------------
void richie_rich() {
    int n, k;

    string st;

    cin >> n >> k;

    cin >> st;

    auto len = st.length();

    int diffs = 0;
    for (size_t i = 0; i < len / 2; i++)
        if (st[i] != st[len - i - 1])
            diffs++;

    if (diffs > k) {
        cout << -1;
        return;
    }

    int save_k = k;

    size_t i = 0;

    while (save_k > diffs && i < len / 2) {

        if ((save_k == diffs + 1) && (st[i] != 9) && (st[len - i - 1] != 9))
            break;

        if (st[i] != st[len - i - 1])
            diffs--;

        if (st[i] != '9') {
            st[i] = '9';            
            save_k--;
        }

         if (st[len - i - 1] != '9') {
            st[len - i - 1] = '9';
            save_k -= 1;        
        }            
        
        i++;
    }

    for (; i < len / 2; i++) {
        if (st[i] != st[len - i - 1]) {
            if (save_k >= (diffs+1)) {
                st[i] = '9';
                st[len - i - 1] = '9';
                save_k -= 2;
                diffs--;                
            } else {
                int max_num = max(st[i], st[len - i - 1]);
                st[i] = max_num;
                st[len - i - 1] = max_num;
                save_k--;
                diffs--;
            }

        }
    }
    
    i = 0; 
    while (save_k >= 2 && i < len / 2) {
        if (st[i] != '9') {
            st[i] = '9';
            st[len - i - 1] = '9';
            save_k -= 2;
        }        
        i++;
    }

    if (save_k > 0) {
        if (len % 2 == 1) {
            st[len / 2 ] = '9';
        }
    }

    cout << st;
}

//-----------------------------------------------------------------------------
bool check_anagram(string & s, int start1, int start2, size_t len)  {
    int let[26] = { 0 };
    bool result = true;
    for (size_t n = 0; n < len; n++) {
        let[s[start1 + n] - 'a']++;
        let[s[start2 + n] - 'a']--;
    }

    for (int n = 0; n < 26; n++) {
        if (let[n] != 0) {
            result = false;
            break;
        }
    }
    return result;
}

void sherlock_and_the_anagrams() {

    int q;
    cin >> q;

    while (q > 0) {
        string st;
        cin >> st;

        int count = 0;
        for (size_t len = 1; len < st.length(); len++) {
            for (size_t i = 0; i < st.length() - len; i++) {                
                for (size_t j = i + 1; j < st.length() - len + 1; j++) {                  
                    if (check_anagram(st, i, j, len) == true) {
                        count++;
                    }
                }
            }        
        }    
        cout << count << endl;
        q--;
    }    
}

//-----------------------------------------------------------------------------
int lcs(string& x, string& y) {

    const int arSize = 5000;
    auto m = x.length();
    auto n = y.length();

    //int *l = new int [m + 1][n + 1];
    auto l = new int[arSize + 1][arSize + 1];
    size_t i, j;
        
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {

            if (i == 0 || j == 0)
                l[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }    
    return l[m][n];    
}

void common_child() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    cout << lcs(s1, s2);
}

//-----------------------------------------------------------------------------
struct suffix {
  int index; 
  int rank[2]; 
};


int cmp(struct suffix& a, struct suffix& b) {
  return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
    (a.rank[0] < b.rank[0] ? 1 : 0);
}


void buildSuffixArray(const char *txt, size_t n, vector<int>& suffix_ar) {

  vector<struct suffix> suffixes(n);

  for (size_t i = 0; i < n; i++) {
    suffixes[i].index = i;
    suffixes[i].rank[0] = txt[i] - 'a';
    suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
  }

  sort(begin(suffixes), end(suffixes), cmp);
    
  vector<int> ind(n);

  for (size_t k = 4; k < 2 * n; k = k * 2) {

    size_t rank = 0;
    int prev_rank = suffixes[0].rank[0];
    suffixes[0].rank[0] = rank;
    ind[suffixes[0].index] = 0;
    
    for (size_t i = 1; i < n; i++) {
      if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
        prev_rank = suffixes[i].rank[0];
        suffixes[i].rank[0] = rank;
      } else {
        prev_rank = suffixes[i].rank[0];
        suffixes[i].rank[0] = ++rank;
      }
      ind[suffixes[i].index] = i;
    }
        
    for (size_t i = 0; i < n; i++) {
      size_t nextindex = suffixes[i].index + k / 2;
      suffixes[i].rank[1] = (nextindex < n) ?
        suffixes[ind[nextindex]].rank[0] : -1;
    }
    sort(begin(suffixes), end(suffixes), cmp);
  }

  suffix_ar.resize(n);
  for (size_t i = 0; i < n; i++) {
    suffix_ar[suffixes[i].index] = i;
  }
}


bool select_from_first(string& A, int indexA, string& B, int indexB, vector<int>& ranks, int len_a) {
  return (indexB == B.length()) || 
    ((indexA < len_a) && ranks[indexA] < ranks[indexB + 1 + len_a]);
}

void morgan_and_a_string() {
  int n;

  cin >> n;

  while (n > 0) {
    string s1;
    string s2;

    cin >> s1 >> s2;

    auto len_s1 = s1.length();
    auto len_s2 = s2.length();

    const char DIV = 'Z' + 1;
    
    int i_s1 = 0;
    int i_s2 = 0;
        
    string combined_ar = s1 + DIV +  s2 + DIV;

    vector<int> suf_ar;
    buildSuffixArray(combined_ar.c_str(), combined_ar.length(), suf_ar);

    string s;

    for (size_t i = 0; i <len_s1 + len_s2; i++) {
      if (select_from_first(s1, i_s1, s2, i_s2, suf_ar, len_s1)) {
        s.push_back(s1[i_s1]);
        i_s1++;
      } else {
        s.push_back(s2[i_s2]);
        i_s2++;
      }
    }

    cout << s << endl;  
    n--;
  }
}

//-----------------------------------------------------------------------------
bool is_valid(map<char, int>& dict, int limit) {
  if (dict['A'] <= limit && dict['C'] <= limit && dict['G'] <= limit && dict['T'] <= limit) {
    return true;
  }
  else {
    return false;
  }
}

void bear_and_steady_gene() {

  int n;
  cin >> n;

  string s1;
  cin >> s1;

  int max_index = 0, out = 999999;
  map<char, int> dict;

  int limit = n / 4;

  for (int i = n - 1; i >= 0; i--) {
    dict[s1[i]]++;
    if (!is_valid(dict, limit)) {
      max_index = i + 1;
      dict[s1[i]]--;
      break;
    }
  }

  for (int min_index = -1; (min_index < n - 1) && (max_index < n) && (min_index < max_index); min_index++) {
    while (!is_valid(dict, limit) && max_index < n) {
      dict[s1[max_index]]--;
      max_index++;
    }

    if (max_index > n || !is_valid(dict, limit)) {
      break;
    }

    int substringLength = max(0, max_index - min_index - 1);
    if (substringLength < out) {
      out = substringLength;
    }
    dict[s1[min_index + 1]]++;
  }
  cout << out << endl;
}

//-----------------------------------------------------------------------------
void ashton_and_string() {
  int t, k;
  string s;

  cin >> t;
  cin >> s;
  cin >> k;

  vector<int> suf_ar;
  buildSuffixArray(s.c_str(), s.length(), suf_ar);
}

//-----------------------------------------------------------------------------
void strange_code() {
  uint64  t;

  cin >> t;

  t += 2;
  uint64  k;
  k = floor(log2(t / 3));

  //t += 2;
  uint64 ret = 3 * ((uint64) 2 << k) - t;

  cout << ret;

}

//-----------------------------------------------------------------------------
void cavity_map() {
  
  int n;
  cin >> n;
  
  int a[100][100];

  for (int i = 0; i<n; i++)  
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i >= 1) && (i<n - 1) && (j >= 1) && (j < n - 1)) {
        if ((a[i][j] > a[i - 1][j]) && (a[i][j] > a[i][j + 1])
          && (a[i][j] > a[i + 1][j]) && (a[i][j] > a[i][j - 1]))
          cout << "X";
        else
          cout << a[i][j];
      } else {
        cout << a[i][j];
      }
    }
    cout << endl;
  }
}



//-----------------------------------------------------------------------------
void utopian_tree() {
  int t; // number of test cases

  cin >> t;
  for (int i = 0; i < t; i++) {
    int n; // number of students, cancelation threshold
    cin >> n;
    int ret = ~(~1 << (n >> 1)) << (n & 1);
    cout << ret << endl;
  }  
}


void birthday_cake_candles();
void matrix_layer_rotation();
void birthday_chocolate();
void almost_sorted();
void divisible_sum_pairs();
void migratory_birds();
void day_of_the_programmer();
void bon_appetit();
void sock_merchant();
void drawing_book();
void counting_valleys();
void electronics_shop();
void cats_and_mouse();
void magic_square();
void picking_numbers();
void climbing_the_leaderboard();
void number_race();
void days_at_the_movies();
void sequence_equation();
void jumping_on_clouds();
void extra_long_factorials();
void library_fine();
void cut_the_sticks();
void big_sorting();
void repeated_string();
void jumping_on_the_clouds();
void equalize_the_array();
void counter_game();
void xor_sequence();
void absolute_permutation();
void bomberman_game();
void non_divisible_subset();
void larrys_array();
void find_absent_students();
void dynamic_tree();
void acm_icpc_team();
void beautiful_triplets();
void service_lane();
void lisa_workbook();
void flatland_spacestations();
void manasa_and_stones();
void happy_ladybugs();

// strings
int minimumNumber(int n, string password);
void twotwo();
void circular_palindromes();

// search
void ice_cream_parlor();
void missing_numbers();
void sherlock_and_array();

//gready
void luck_balance();
void jim_orders();
void decentNumber(int n);
int toys(vector<int> w);

//debug
int main_lucky_dates();

// c++ problems

void input_output();
void basic_data_types();
void conditional_statements();
void for_loop();
void functions();
void variable_size_arrays();
void maps_stl();

void classes_and_objects();
void attribute_parser();
void message_order();
int virtual_function_main();
int attending_workshops_main();
int deque_main();
int polymorphism_main();
int wizard_main();
void bit_array_start();
void taumBday();
void kaprekarNumbers(int p, int q);


bool is_smart_number(int num) {
	int val = num;
	int count = 1;

	for (int i = 2; i <= val; i++)
		if (num % i == 0)
			count++;

	if (count % 2 == 1)
		return true;

	return false;
}


unsigned long flippingBits(unsigned long n) {

	int x = 31;

	unsigned long ret = n;
	// Inverting the bits one by one 
	for (int i = 0; i <= 31; i++) {
		unsigned long mask = (1 << i);
		ret = (ret ^ mask);
	}
		

	return ret;
}



int main() {

#ifdef __APPLE__
    ifstream arq;
    
    if (getenv("INPUTQ")) {
        string s = getenv("INPUTQ");
        arq.open (s);
        cin.rdbuf(arq.rdbuf());
    }
#endif
	
	//vector<int> w = { 16, 18, 10, 13, 2, 9, 17, 17, 0, 19 };
	//toys(w);

	circular_palindromes();

	getchar();
}



