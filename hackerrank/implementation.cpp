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
#include <stack>
#include <functional>
#include <cstdlib>
#include <cmath>

#include "bigint.h"


using namespace std;

//-----------------------------------------------------------------------------
void grading_students() {

  int n, temp;

  const int failing_grade = 38;

  cin >> temp;


  while (cin >> n) {

    if (n < failing_grade) {
      cout << n;
    }
    else {
      int mod = n % 5;

      if (mod >= 3)
        cout << n + (5 - mod);
      else
        cout << n;
    }

    cout << endl;
  }
}

//-----------------------------------------------------------------------------
int count_fruits(int count, int s, int t, int tree_pos) {
  int fruits = 0;
  for (int i = 0; i < count; i++) {
    int d;
    cin >> d;
    int pos = tree_pos + d;

    if (pos >= s && pos <= t)
      fruits++;
  }

  return fruits;
}

//-----------------------------------------------------------------------------
void apple_and_orange() {

  int s, t; // house coordinates

  cin >> s >> t;

  int a, b; // a - apple tree position, b - orange tree position
  cin >> a >> b;

  int m, n; // m - apples count, n - oranges count
  cin >> m >> n;

  int apples = count_fruits(m, s, t, a);
  int oranges = count_fruits(n, s, t, b);;

  cout << apples << endl;
  cout << oranges << endl;
}

//-----------------------------------------------------------------------------
void kangaroo() {
  int x1, v1, x2, v2;

  cin >> x1 >> v1 >> x2 >> v2;

  if (v1 > v2 && ((x2 - x1) % (v1 - v2) == 0))
    cout << "YES";
  else
    cout << "NO";
}

//-----------------------------------------------------------------------------
void between_two_sets() {
  int n, m;

  cin >> n;
  cin >> m;

  vector<int> a;
  vector<int> b;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    b.push_back(tmp);
  }

  sort(begin(a), end(a));
  sort(begin(b), end(b));

  int lower = a[n - 1];
  int upper = b[0];

  int count = 0;
  for (int i = lower; i <= upper; i++) {
    bool found = true;
    for (int j = 0; j < n; j++)
      if (i % a[j] != 0) {
        found = false;
        break;
      }

    if (found) {
      for (int j = 0; j < m; j++)
        if (b[j] % i != 0) {
          found = false;
          break;
        }
    }

    if (found) count++;
  }

  cout << count << endl;
}

//-----------------------------------------------------------------------------
void breaking_the_records() {

  int n;

  cin >> n;

  int count = 0;

  int break_high = 0;
  int break_low = 0;

  int tmp;

  cin >> tmp;
  count++;

  int low = tmp;
  int high = tmp;

  while (count < n) {
    cin >> tmp;

    if (tmp > high) {
      break_high++;
      high = tmp;
    }

    if (tmp < low) {
      break_low++;
      low = tmp;
    }
    count++;
  }

  cout << break_high << " " << break_low << endl;
}


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

//-----------------------------------------------------------------------------
void matrix_layer_rotation () {
    
    int n, m; // dimension of the matrix
    cin >> n;
    cin >> m;
    
    int rot; // rotations
    cin >> rot;
    
    const int arsize = 300; // fix for Visual Studio 2015

    //int array[n][m];
    //int out_array[n][m];
    
    int array[arsize][arsize];
    int out_array[arsize][arsize];

    // read the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
    
    n--;
    m--;
    
    for (int r = 0; r <= n; r++) {
        for (int c = 0; c <= m; c++) {
            int x = r < n - r ? r : n - r;
            int y = c < m - c ? c : m - c;
            int min = x < y ? x : y;
            int max_row = n - min;
            int max_col = m - min;
            int flag = (max_row + max_col) * 2 - min * 4;
            
            int row = r;
            int col = c;
            for (int a = 0; a < rot % flag; a++) {
                if (col == min && row < max_row) {
                    row++;
                }
                else if (row == max_row && col < max_col) {
                    col++;
                }
                else if (row > min && col == max_col) {
                    row--;
                }
                else if (row == min && col > min) {
                    col--;
                }
            }
            
            out_array[row][col] = array[r][c];
        }
    }
    
    
    // print the matrix
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << out_array[i][j] << " ";

        cout << endl;
    }
    
}

//-----------------------------------------------------------------------------
void birthday_chocolate() {
  
  int n;

  int squares[100];

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> squares[i];

  int m, d;

  cin >> d;
  cin >> m;
  
  int sum[200]; // big number for padding
  int count = 0;
  sum[0] = 0;

  for (int i = 0; i < n; i++) 
    sum[i + 1] = sum[i] + squares[i];

  for (int i = 0; i <= (n - m); i++) {
    if ( (sum[i + m] - sum[i]) == d) {
      count++;
    }
  }

  cout << count;

}

//-----------------------------------------------------------------------------
void divisible_sum_pairs() {
  int n, k;

  cin >> n;
  cin >> k;

  vector<int> a;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  int pairs = 0;

  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if ((a[i] + a[j]) % k == 0)
        pairs++;

  cout << pairs;
}

//-----------------------------------------------------------------------------
void migratory_birds() {
  int n;

  cin >> n;
  
  vector<int> a;

  long int max = 0;

  long int counts[6] = { 0 };

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
     
    counts[tmp]++;

    if (counts[tmp] > max)
      max = counts[tmp];      
  }

  for (int i = 1; i <= 5; i++)
    if (counts[i] == max) {
      cout << i;
      return;
    }      
}

//-----------------------------------------------------------------------------
void day_of_the_programmer() {
  int year;

  cin >> year;

  if (year == 1918) {
    cout << "26.09.1918";
  } else {
    bool leap = false;
    if (year <= 1917)
      leap = (year % 4) == 0;
    else
      leap = ((year % 400) == 0) || ( ((year % 4) == 0) && ((year % 100) != 0));
      
    if (leap)
      cout << "12";
    else
      cout << "13";

    cout << ".09." << year;
  }
}

//-----------------------------------------------------------------------------
void bon_appetit() {

  int n, k;

  cin >> n;
  cin >> k;

  vector<int> a;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    sum += tmp;
  }

  int b;
  cin >> b;

  int shared_sum = sum - a[k];

  int half = shared_sum / 2;

  if (half  == b) {
    cout << "Bon Appetit";
  } else {
    cout << b - half;
  }

}

//-----------------------------------------------------------------------------
void sock_merchant() {

  int n;
  cin >> n;

  map<int, int> socks;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    map<int, int>::iterator it = socks.find(tmp);
    if (it == socks.end())
      socks[tmp] = 1;
    else
      socks[tmp] ++;
  }
  
  int count = 0;
  map<int, int>::iterator it = socks.begin();
  while (it != socks.end()) {
    count += it->second / 2;
    it++;
  }

  cout << count;
}

//-----------------------------------------------------------------------------
void drawing_book() {

  int n, p;
  cin >> n;
  cin >> p;

  int front_page = p / 2;
  int last_page = n / 2 - p / 2;
  
  int pages = min(front_page, last_page);

  cout << pages;
}

//-----------------------------------------------------------------------------
void counting_valleys() {
 
  int n;
  cin >> n;

  string record;
  cin >> record;

  int level = 0;
  int prev = 0;

  int valleys = 0;

  for (int i = 0; i < n; i++) {

    if (record[i] == 'U')
      level++;

    if (record[i] == 'D')
      level--;

    if (level < 0) {// find a valley {
      if (prev == 0)
        valleys++;
    }

    prev = level;
  }
  
  cout << valleys;

}
//-----------------------------------------------------------------------------

void read_array(vector<int>& ar, int n) {
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ar.push_back(tmp);    
  }
}

//-----------------------------------------------------------------------------
void electronics_shop() {

  int s, n, m; // s- money, n - keyboards, m - usb devices
  cin >> s >> n >> m;

  vector<int> keyboards;
  vector<int> usb;
  read_array(keyboards, n);
  read_array(usb, m);

  sort(begin(keyboards), end(keyboards), greater<>());
  sort(begin(usb), end(usb));
  
  int max = -1;

  int i = 0, j = 0;

  while (i < n) {
    while (j < m) {
      int sum = keyboards[i] + usb[j];
      if (sum > s)
        break;

      if (sum > max)
        max = sum;
      j++;
    }
    i++;
  }

  cout << max;
}

//-----------------------------------------------------------------------------
void cats_and_mouse() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int cat_a;
    int cat_b;
    int mouse;

    cin >> cat_a >> cat_b >> mouse;

    int d1 = abs(cat_a - mouse);
    int d2 = abs(cat_b - mouse);

    if (d1 < d2) {
      cout << "Cat A" << endl;
    } else {
      if (d1 > d2)
        cout << "Cat B" << endl;
      else
        cout << "Mouse C" << endl;
    }
  }
}

//-----------------------------------------------------------------------------
void magic_square() {

  int all_magic[8][3][3] = {
    { { 8, 1, 6 },{ 3, 5, 7 },{ 4, 9, 2 } },
    { { 6, 1, 8 },{ 7, 5, 3 },{ 2, 9, 4 } },
    { { 4, 9, 2 },{ 3, 5, 7 },{ 8, 1, 6 } },
    { { 2, 9, 4 },{ 7, 5, 3 },{ 6, 1, 8 } },
    { { 8, 3, 4 },{ 1, 5, 9 },{ 6, 7, 2 } },
    { { 4, 3, 8 },{ 9, 5, 1 },{ 2, 7, 6 } },
    { { 6, 7, 2 },{ 1, 5, 9 },{ 8, 3, 4 } },
    { { 2, 7, 6 },{ 9, 5, 1 },{ 4, 3, 8 } },
  };

  int mat[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      cin >>  mat[i][j];
  }

  int min_cost = 81;
  for (int k = 0; k < 8; k++) {
    int cost = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
        cost += abs(mat[i][j] - all_magic[k][i][j]);
    }
    if (cost < min_cost)
      min_cost = cost;
  }

  cout << min_cost;
}

//-----------------------------------------------------------------------------
void picking_numbers() {

  int n; 
  cin >> n ;

  int counts[101] = { 0 };
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    counts[tmp]++;
  }

  int max = 0;
  for (int i = 0; i < 99; i++) {
    int count = counts[i] + counts[i + 1];
    if (count > max)
      max = count;
  }

  cout << max;
   
}

//-----------------------------------------------------------------------------
void climbing_the_leaderboard() {
  int n;
  cin >> n;
  
  stack<int> leaderboard;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (i == 0) {
      leaderboard.push(tmp);
    } else {
      if (leaderboard.top() != tmp)
        leaderboard.push(tmp);
    }
  }

  int m;
  cin >> m;

  vector<int> alice;
  read_array(alice, m);

  for (int i = 0; i < m; i++) {
    while (!leaderboard.empty() && (alice[i] >= leaderboard.top()))
      leaderboard.pop();
    cout << leaderboard.size() + 1 << endl;
  }
}

//-----------------------------------------------------------------------------
void number_race() {
  int n, k;
  cin >> n >> k;

  int count = 0;
  int current_jump = k;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;

    if (current_jump < tmp) {
      int diff = tmp - current_jump;
      count += diff;
      current_jump = tmp;
    }
  }

  cout << count;
}

//-----------------------------------------------------------------------------
void days_at_the_movies() {
  int i, j, k;

  cin >> i >> j >> k;

  int count = 0;
  for (int x = i; x <= j; x++) {

    int tmp = x;
    int y = 0;
    while (tmp > 0) {
      int digit = tmp % 10;
      y = y * 10 + digit;
      tmp /= 10;
    }

    int diff = abs(x - y);

    if ((diff % k) == 0)
      count++;
  }

  cout << count;
}

//-----------------------------------------------------------------------------
void viral_advestising() {
  int n;
  cin >> n;

  int total_viewers = 0;
  int shared = 5;
  int viewers = 0;
  for (int i = 0; i < n; i++) {
    viewers = shared / 2;
    total_viewers += viewers;
    shared = viewers * 3;
  }

  cout << total_viewers;
}

//-----------------------------------------------------------------------------
void save_the_prisoner() {
  int t; // number of test cases
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m, s;
    cin >> n >> m >> s;
    if ( (m + s - 1) % n == 0)
      cout << n << endl;
    else
      cout << (m + s - 1) % n << endl;
  }
}

//-----------------------------------------------------------------------------
void sequence_equation() {
  int n;
  cin >> n;

  vector<int> ar;
  read_array(ar, n);

  vector<int> p;
  p.resize(n, 0);

  for (int i = 0; i < n; i++)
    p[ar[i] - 1] = i + 1;

  for (int i = 0; i < n; i++)
    cout << p[p[i] - 1] << endl;

}

//-----------------------------------------------------------------------------
void jumping_on_clouds() {
  int n, k;
  cin >> n >> k;

  vector<int> ar;
  read_array(ar, n);

  int pos = 0;
  int energy = 100;
  do {
    pos = (pos + k) % n;
    energy--;
    if (ar[pos] == 1)
      energy -= 2;
  } while (pos != 0);

   cout << energy;
}

//-----------------------------------------------------------------------------
void append_and_delete() {

  string s, t; 
  int k;
  cin >> s >> t >> k;


  int diff, i = 0;
  
  while (s[i] == t[i]) 
    i++;

  diff = s.size() + t.size() - i * 2;

  cout << ((diff <= k && diff % 2 == k % 2) || s.size() + t.size() < k ? "Yes" : "No");
}

//-----------------------------------------------------------------------------
void extra_long_factorials() {

  int n;
  cin >> n;

  bigint factorial(1);

  for (int i = 2; i <= n; i++) {
      bigint t(i);
      bigint t2 = t * factorial;
      factorial.swap(t2);
  }

  cout << factorial;
}

//-----------------------------------------------------------------------------
void sherlock_and_squares() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    cout << floor(sqrt(b) - ceil(sqrt(a)) + 1) << endl;
  }
}

//-----------------------------------------------------------------------------
void library_fine() {

  int d1, m1, y1;  // actual return date
  cin >> d1 >> m1 >> y1;

  int d2, m2, y2;  // expected return date
  cin >> d2 >> m2 >> y2;

  if (y1 != y2) {
    cout << ((y1 - y2)  < 0 ? 0 : (y1 - y2) * 10000);
    return;
  }
  
  if (m2 != m1) {
    cout << ((m1 - m2) < 0 ? 0 :(m1 - m2) * 500);
    return;
  }

  cout << ((d1 - d2) < 0 ?  0: (d1 - d2) * 15);
}

//-----------------------------------------------------------------------------
void cut_the_sticks() {
  int n;
  cin >> n;

  vector<int> ar;
  
  int min = 1001;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;

    if (tmp < min)
      min = tmp;

    ar.push_back(tmp);
  }

  while (ar.size()) {
    cout << ar.size() << endl;

    vector<int> tmp_ar;
    int new_min = 1001;

    for(auto i:ar) {
      int tmp = i - min;

      if (tmp > 0) {
        tmp_ar.push_back(tmp);

        if (tmp < new_min)
          new_min = tmp;
      }        
     }

    min = new_min;
    ar.assign(begin(tmp_ar), end(tmp_ar));
  }
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

//-----------------------------------------------------------------------------
void find_digits() {
  int t; // number of test cases

  cin >> t;
  for (int i = 0; i < t; i++) {
    int n; // number of students, cancelation threshold
    cin >> n;
    int tmp = n;
    int count = 0;

    while (tmp) {
      int digit = tmp % 10;

      if (digit)
        if (n % digit == 0)
          count++;

      tmp = tmp / 10;
    }

    cout << count << endl;
  }
}

//-----------------------------------------------------------------------------
void angry_professor() {
  int t; // number of test cases

  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k; // number of students, cancelation threshold
    cin >> n >> k;

    int on_time = 0;

    for (int j = 0; j < n; j++) {
      int st_time;
      cin >> st_time;
      if (st_time <= 0)
        on_time++;
    }

    if (on_time >= k)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}

//-----------------------------------------------------------------------------
void designer_pdf_viewer() {
  int heights[26] = { 0 };

  for (int i = 0; i < 26; i++)
    cin >> heights[i];

  string word;
  cin >> word;

  int max_height = 0;

  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';
    int height = heights[index];
    if (height > max_height)
      max_height = height;
  }

  cout << max_height * word.length();
}

//-----------------------------------------------------------------------------
void almost_sorted() {
  int n;

  vector<int> d;

  cin >> n;

  bool not_ordered = 0;
  bool index = -1;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;        
    d.push_back(tmp);
  }

  vector<int> sorted(begin(d), end(d));
  sort(begin(sorted), end(sorted));
  
  int diffs = 0;
  int start = -1;
  int end = -1;
  for (int i = 0; i < n; i++) {
    if (d[i] != sorted[i]) {
      diffs++;

      if (start == -1)
        start = i;
      else
        end = i;
    }      
  } 
  
  if (diffs == 0) {
    cout << "yes";
    return;
  }

  if (diffs == 2) {
    cout << "yes" << endl;
    cout << "swap " << start + 1 << " " << end + 1;
  }

  if (diffs > 2) {
    // check if it is reversed
    for (int i = start, j = end; i <= end; i++, j--) {
      if (d[i] != sorted[j]) {
        cout << "no";
        return;
      }
    }
          
    cout << "yes" << endl;
    cout << "reverse " << start + 1 << " " << end + 1;      
  }  
}