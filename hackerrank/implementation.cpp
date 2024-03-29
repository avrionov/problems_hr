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
#include <iterator>

#include "bigint.h"

#include "Utils.h"

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
void electronics_shop() {

  int s, n, m; // s- money, n - keyboards, m - usb devices
  cin >> s >> n >> m;

  vector<int> keyboards;
  vector<int> usb;
  read_array(keyboards, n);
  read_array(usb, m);

  sort(begin(keyboards), end(keyboards), greater<int>());
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
void repeated_string() {
  string s;
  cin >> s;

  long long int n;
  cin >> n;

  int len = s.length();

  long long a_count = 0;
  for (auto c : s) {
    if (c == 'a')
      a_count++;
  }

  long long full_strings = n / len;
  long long total_a = full_strings * a_count;

  for (long long i = 0; i < n % len; i++)
    if (s[i] == 'a')
      total_a++;

  cout << total_a;
}

//-----------------------------------------------------------------------------
void jumping_on_the_clouds() {
  int n;
  cin >> n;

  vector<int> clouds;
  read_array(clouds, n);

  int count = 0;
  int i;
  for (i = 0; i < n - 2; i++ ) {
    if (clouds[i + 2] == 0) {
      i++;
      count++;
    } else {
      count++;
    }
  }

  if (i < n - 1)
    count++;

  cout << count;
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
void equalize_the_array() {

  int n;
  cin >> n;

  map<int, int> numbers;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    auto it = numbers.find(tmp);
    if (it == numbers.end())
      numbers[tmp] = 1;
    else
      numbers[tmp] ++;
  }

  int max = 0;
  
  for (auto it : numbers) {
    if (it.second > max)
      max = it.second;    
  }

  cout << (n - max);
}

void queens_attack_2() {
  int n; // n - the side lenght of the board
  int k; // number of obstacles

  int r, c; // queens possition;
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

//-----------------------------------------------------------------------------
void absolute_permutation() {
  int t; // number of tests

  cin >> t;

  for (int tests = 0; tests < t; tests++) {
    int n, k;

    cin >> n >> k;
    int temp = k;

    if (k == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
      continue;
    }
    
   if ((n % (2 * k)) != 0) {
        cout << -1 << endl;
        continue;
   }

    for (int i = 1; i <= n; i++) {
        cout << i + temp << " ";
        if (i % k == 0) {
          temp = temp * -1;
      }
    }
    cout << endl;
  } 
}

//-----------------------------------------------------------------------------
const int grid_max = 200;
typedef char grid_type[grid_max+2][grid_max+2];

const char empty_cell = '.';
const char bomb3_cell = 'O';
const char bomb0_cell = bomb3_cell - 3;

void print_grid(grid_type& grid, int r, int c) {

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      if (grid[i][j] == empty_cell)
        cout << empty_cell;
      else
        cout << bomb3_cell;
      
    cout << endl;
  }
}

void decrease_bomb_counters(grid_type& grid, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      if (grid[i][j] != empty_cell)
        grid[i][j] --;
  }
}
void copy_grid(grid_type& source, grid_type& dest, int r, int c) {

  for (int i = 0; i < r; i++) 
    for (int j = 0; j < c; j++)
      dest[i][j] = source[i][j];
}

void plant_bombs(grid_type& grid, int r, int c) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (grid[i][j] == empty_cell)
        grid[i][j] = bomb3_cell;
}

void detonate_bombs(grid_type& grid, int r, int c) {
  
  grid_type tmp;
  // copy
  copy_grid(grid, tmp, r, c);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      if (grid[i][j] == bomb0_cell) {
        tmp[i][j] = empty_cell;

        if (i != 0) {
          tmp[i - 1][j] = empty_cell;
        }

        tmp[i + 1][j] = empty_cell;

        if (j != 0) {
          tmp[i][j - 1] = empty_cell;
        }

        tmp[i][j + 1] = empty_cell;
      }
  }

  copy_grid(tmp, grid, r, c);
}

void bomberman_game() {

  grid_type grid;

  int r, c, n;

  cin >> r >> c >> n;


  for (int i = 0; i < r; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < c; j++)
      grid[i][j] = row[j];
  }

  //cout << "1. inital state" << endl;
  //print_grid(grid, r, c);
  grid_type n0;
  copy_grid(grid, n0, r, c);
  
  //cout << "2 . second 1" << endl;
    
  decrease_bomb_counters(grid, r, c);
  //print_grid(grid, r, c);
  grid_type n1;
  copy_grid(grid, n1, r, c);

  //cout << "3 . second 2" << endl;
  decrease_bomb_counters(grid, r, c);
  plant_bombs(grid, r, c);
  //print_grid(grid, r, c);
  grid_type n2;
  copy_grid(grid, n2, r, c);
   

   //cout << "4 . second 3" << endl;
   decrease_bomb_counters(grid, r, c);
   detonate_bombs(grid, r, c);    
   //print_grid(grid, r, c);

   grid_type n3;
   copy_grid(grid, n3, r, c);


   //cout << "5 . second 4" << endl;
   decrease_bomb_counters(grid, r, c);
   plant_bombs(grid, r, c);
   //print_grid(grid, r, c);
   grid_type n4;
   copy_grid(grid, n4, r, c);

   //cout << "6 . second 5" << endl;
   decrease_bomb_counters(grid, r, c);
   detonate_bombs(grid, r, c);
   //print_grid(grid, r, c);

   grid_type n5;
   copy_grid(grid, n5, r, c);


   if (!(n % 2)) {
     print_grid(n2, r, c);
     return;
   }

   if (n == 1) {
     print_grid(n0, r, c);
     return;
   }

   if (n %4  == 3)
     print_grid(n3, r, c);
   else 
     print_grid(n5, r, c);
}

//-----------------------------------------------------------------------------
void non_divisible_subset() {

	int n, k;
		
	cin >> n >> k;

	vector<int> s;
	read_array(s, n);

	vector<int> divs;
	
	divs.resize(k, 0);

	for (auto i : s) {
		divs[i % k] ++;
	}

	int total = min(divs[0], 1);

	int k2 = k / 2;
	if (k2 * 2 == k) k2 -= 1; 

	for (int i = 1; i <= k2; ++i) 
		total += max(divs[i], divs[k - i]);

	if (k % 2 == 0) 
		total += divs[k / 2] > 0;
	cout << total << endl;

}

//-----------------------------------------------------------------------------
void queens_attack_ii() {

	int n, k;

	cin >> n >> k;


}

//-----------------------------------------------------------------------------
void larrys_array() {

	int t; // number of tests

	cin >> t;

	for (int t1 = 0; t1 < t; t1++) {

		int n;

		cin >> n;

		vector<int> arr;
		read_array(arr, n);

		int inversions = 0;

		// count number of inversions
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++)
				if (arr[i] > arr[j])
					inversions++;
		}

		if (inversions % 2 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}//-----------------------------------------------------------------------------
int calc_topics(string& s1, string& s2, int m) {
	int count = 0;

	for (int i = 0; i < m; i++) {

		if (s1[i] == '1' || s2[i] == '1')
			count++;
		
	}

	return count;
}
void acm_icpc_team() {
	int n, m;

	cin >> n >> m;

	vector <string> skills;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		skills.push_back(t);
		
	}
	int max_topics = 0;
	int teams = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int topics = calc_topics(skills[i], skills[j], m);
			if (topics > max_topics) {
				max_topics = topics;
				teams = 1;
			}
			else {
				if (topics == max_topics) {
					teams++;
				}
			}
		}

	cout << max_topics << endl;
	cout << teams << endl;
}

//-----------------------------------------------------------------------------
void taumBday() {
	int t;
	long long b, w;
	long long bc, wc, z;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> b >> w;
		cin >> bc >> wc >> z;

		
		if (bc > wc + z) {
			long long cost;
			cost = wc * (b + w);
			cost += b * z;
			cout << cost << endl;
			continue;
		}

		if (wc > bc + z) {
			long long cost;
			cost = bc * (b + w);
			cost += w * z;
			cout << cost << endl;
			continue;
		}
				
		cout << b * bc + w * wc << endl;
	}	
}

//-----------------------------------------------------------------------------
void kaprekarNumbers(int p, int q) {

	bool bFound = false;
	for (long long i = p; i <= q; i++) {
		long long sq = i * i;
		int digits = log10(i)+1;

		
		string str = to_string(sq);
		int len = str.length();
		string right_str = str.substr(len / 2, digits);
		string left_str = str.substr(0, len / 2);
				
		long long left = left_str.empty() ? 0:  stol(left_str);
		long long right = right_str.empty() ? 0 : stol(right_str);

		if ((left + right) == i) {
			cout << i << " ";
			bFound = true;
		}
	}

	if (!bFound) {
		cout << "INVALID RANGE";
	}

}

void karpekar_number_main() {
	int p;
	cin >> p;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	kaprekarNumbers(p, q);
}

//-----------------------------------------------------------------------------
void beautiful_triplets() {
	int n, d;

	cin >> n >> d;

	vector <int> ar;
	multiset <int> st;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ar.push_back(tmp);
		st.insert(tmp);
	}

	int count = 0;

	for (auto i = st.begin(); i != st.end(); i++) {
		if (st.find(*i + d) != st.end())
			if (st.find(*i + 2 * d) != st.end())
				count++;
	}

	int count1 = 0;;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if ((ar[j] - ar[i] == d) && (ar[k] - ar[j] == d))
					count1++;

	cout << count1 << endl;
	cout << count;
}

//-----------------------------------------------------------------------------
void minimumDistances() {
	int n;

	cin >> n;

	vector <int> ar;	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ar.push_back(tmp);
	}

	int min_distance = n + 1;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (ar[i] == ar[j]) {
				int dist = j - i;

				if (dist < min_distance)
					min_distance = dist;
			}

	if (min_distance == n + 1)
		cout << -1;
	else
		cout << min_distance;
}

//-----------------------------------------------------------------------------

int howManyGames(int p, int d, int m, int s) {
	// Return the number of games you can buy
	int count = 0;

	int current_game_price = p;
	int sum = s;

	while (true) {

		if (current_game_price > sum)
			break;

		// bought one game
		sum -= current_game_price;
		count++;

		// calculate the new game price

		current_game_price -= d;
		if (current_game_price < m)
			current_game_price = m;
	}

	return count;
}

//-----------------------------------------------------------------------------
void chocolate_feast() {

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int n; // an integer representing Bobby's initial amount of money 
		int c; // an integer representing the cost of a chocolate bar 
		int m; // an integer representing the number of wrappers he can turn in for a free bar 

		cin >> n >> c >> m;

		int money_left = n;
		int wrappers = 0;
		int count = 0;

		count = money_left / c;
		wrappers = count;

		while (wrappers >= m) {
			int add = wrappers / m;
			count += add;
			
			wrappers %= m;
			wrappers += add;
		}

		cout << count << endl;
	}
}

//-----------------------------------------------------------------------------
void service_lane() {

	int n, t;

	cin >> n >> t;

	vector <int> widths;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		widths.push_back(tmp);
	}

	for (int l = 0; l < t; l++) {
		int i, j;
		cin >> i >> j;

		int max_w = widths[i];

		for (int k = i+1; k < j; k++) {
			max_w = min(max_w, widths[k]);
		}

		cout << max_w << endl;
	}

}

//-----------------------------------------------------------------------------
void lisa_workbook() {

	int n, k;

	cin >> n >> k;

	vector <int> ar;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ar.push_back(tmp);
	}

	int current_page = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		//int first_page = current_page + 1;
		/*int last_page = first_page + ar[i] / k;
		last_page += (ar[i] % k) != 0 ? 1 : 0;*/

		int page = 0;
		for (int j = 1; j <= ar[i]; j++) {
			page = j / k;
			page += (j % k) != 0 ? 1 : 0; 

			if ((page + current_page) == j)
				count++;
		}
		
		current_page += page;
	}

	cout << count;
}

//-----------------------------------------------------------------------------
void flatland_spacestations() {

	int n, m;

	cin >> n >> m;

	set <int> stations;
	vector <int> ar;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		stations.insert(tmp);
		ar.push_back(tmp);
	}

	int min_dist = 0;

	for (int i = 0; i < n; i++) {
		std::set<int>::iterator itlow, itup;
		
		int dist = n + 1;
		for (auto j : ar) {
			dist = min(dist, abs(j - i));
		}
		
		min_dist = max(min_dist, dist);
	}

	cout << min_dist;
}

//-----------------------------------------------------------------------------
void fair_rations() {

	int n;

	cin >> n ;
		
	vector <int> ar;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;		
		ar.push_back(tmp);
		sum += tmp;
	}

	if (sum % 2 == 1) {
		cout << "NO";
		return;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] % 2 == 1) {
			ar[i] ++;
			ar[i + 1]++;
			count += 2;
		}
			
	}

	cout << count;
}

//-----------------------------------------------------------------------------
void manasa_and_stones() {
	int t;

	cin >> t;
	
	for (int i = 0; i < t; i++) {
		set<int> last_stone;
		int n, a, b;
		cin >> n >> a >> b;

		int sum = 0;
		int first = 0;

		first = (n - 1) * min(a, b);
		cout << first << " ";
		while (sum + first < (n - 1) * max(a, b)) {
			sum += abs(b - a);
			cout << first + sum << " ";
		}
		
		cout << endl;
	}	
}

//-----------------------------------------------------------------------------
void happy_ladybugs() {

	int g;

	cin >> g;

	for (int i = 0; i < g; i++) {
		int n;
		string str;
		cin >> n;
		cin >> str;

		bool bSpace = 0;
		int count[26] = { 0 };
		int unhappy = 0;

		for (int i = 0; i < n; i++) {
			if (str[i] == '_')
				bSpace = true;
			else
				count[str[i] - 'A'] ++;

			bool bUnhappy = true;
			if (i > 0)
				if (str[i] == str[i - 1])
					bUnhappy = false;

			if (i < (n - 1))
				if (str[i] == str[i + 1])
					bUnhappy = false;

			if (bUnhappy)
				unhappy++;
		}

		if (unhappy == 0) {
			cout << "YES" << endl;
			continue;
		}

		if (!bSpace) {
			cout << "NO" << endl;
			continue;
		}

		// we have a space and some unhappy ladybugs
		bool bOne = false;
		for (int i = 0; i < 26; i++)
			if (count[i] != 0)
				if (count[i]  == 1) {
					bOne = true;
					break;
				}

		if (bOne) 
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}
}

//-----------------------------------------------------------------------------
string encryption(string s) {
    string trimmed;
    for (auto ch: s) {
        if (ch != ' ')
            trimmed += ch;
    }
    
    auto len_trimmed = trimmed.length();
    int rows = floor(sqrt(len_trimmed));
    int columns = ceil(sqrt(len_trimmed));
    
    if ( (rows * columns) < len_trimmed)
        rows++;
      
    string ret;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            auto pos = j * columns + i;
            if (pos < len_trimmed)
                ret += trimmed[pos];
        }
        
        ret += " ";
    }
    
	return ret;
}


//-----------------------------------------------------------------------------|
long marcsCakewalk(vector<int> calorie) {
	
	sort(begin(calorie), end(calorie), greater<int>());
	
	long factor = 1;
	long  sum = 0;
	for (auto i : calorie) {
		sum += i * factor;
		factor *= 2;
	}

	return sum;
}

//-----------------------------------------------------------------------------
string biggerIsGreater(string w) {
    
    auto last = w.length() - 1;
    auto i = last;
    
    while (i > 0 && w[i - 1] >= w[i])
        i--;
    
    if (i == 0)
        return "no answer";
    
    auto j = last;
 
    while (w[j] <= w[i-1])
        j--;
    
    swap (w[i-1], w[j]);
    
    std::reverse(w.begin() +i, w.end());
    
    return w;
}

//-----------------------------------------------------------------------------
void container_of_balls() {

    int q;

    cin >> q;

    for (int l = 0; l < q; l++) {

        int n;

        cin >> n;

        vector <vector < int>> a;

        for (int i = 0; i < n; i++) {
            vector <int> tmp;
            read_array(tmp, n);
            a.push_back(tmp);
        }

         vector <long long int> slots_ar, missing_ar;
        
        for (int i = 0; i < n; i++) {
            long long int slots = 0;
            long long int missing = 0;
            for (int j = 0; j < n; j++) {
                // if (i != j)
                {
                    slots += (long long int) a[i][j];
                    missing += (long long int) a[j][i];
                }
            }

            slots_ar.push_back(slots);
            missing_ar.push_back(missing);
        }

        sort(begin(slots_ar), end(slots_ar));
        sort(begin(missing_ar), end(missing_ar));

        bool possible = true;
        for (int i = 0; i  < n; i++)
            if (slots_ar[i] != missing_ar[i]) {
                possible = false;
                break;
            }

        if (possible)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
}

//-----------------------------------------------------------------------------
string timeInWords(int h, int m) {
    string numbers[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"
    };

     if (m == 0) {
         return  numbers[h - 1] + " o' clock";
     }

     if (m >= 1 && m <= 30) {
         if (m == 15)
            return numbers[m - 1] + string(" past ") + numbers[h - 1];

         if (m == 30)
             return numbers[m - 1] + string(" past ") + numbers[h - 1];
         
         if (m == 1)
            return numbers[m - 1] + string(" minute past ") + numbers[h - 1];

         return numbers[m - 1] + string(" minutes past ") + numbers[h - 1];
     }
     
     int remaining_minutes = 60 - m;

     if (remaining_minutes == 15)
         return numbers[remaining_minutes - 1] + string(" to ") + numbers[h];
     
     if (remaining_minutes == 1)
        return numbers[remaining_minutes - 1] + string(" minute to ") + numbers[h];

     return numbers[remaining_minutes - 1] + string(" minutes to ") + numbers[h ];
}

void test_time_in_words() {
    string result;

    result = timeInWords(5, 47);
    cout << result << endl;

    result = timeInWords(3, 0);
    cout << result << endl;

    result = timeInWords(7, 15);
    cout << result << endl;

    result = timeInWords(7, 10);
    cout << result << endl;


    result = timeInWords(7, 29);
    cout << result << endl;

    result = timeInWords(5, 45);
    cout << result << endl;

    result = timeInWords(1, 1);
    cout << result << endl;
}

//-----------------------------------------------------------------------------
string gridSearch(vector<string> G, vector<string> P) {
    
    int pattern_len = P.size();

    for (int i = 0; i <= G.size() - pattern_len; i++) {
        size_t pos = G[i].find(P[0]);

        if (pos == std::string::npos) // the pattern is not found, moved to the next line
            continue;

        while (pos != std::string::npos) {
            bool found = true;
            for (int j = 1; j < pattern_len; j++) {
                size_t pos2 = G[i + j].find(P[j], pos);
                if (pos != pos2) {
                    found = false;
                    break;
                }
            }

            if (found)
                return "YES";

            pos = G[i].find(P[0], pos + 1);
        }
     }
     
    return "NO";
}

void grid_search() {

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int R, C;
        cin >> R >> C;

        vector<string> G;

        for (int i = 0; i < R; i++) {
            string tmp;
            cin >> tmp;
            G.push_back(tmp);
        }

        int r, c;
        cin >> r >> c;
        vector<string> P;

        for (int i = 0; i < r; i++) {
            string tmp;
            cin >> tmp;
            P.push_back(tmp);
        }

        string result = gridSearch(G, P);

        cout << result << endl;
    }
}


//-----------------------------------------------------------------------------
int surfaceArea(vector<vector<int>> A) {

    int H = A.size();
    int W = A[0].size();

    int sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int cub_sum = 0;
            int top = 1;
            int bottom = 1;
            
            // west, north, east, south walls;

            int west = 0;
            if (j == 0)
                west = A[i][j];
            else
                if (A[i][j] > A[i][j - 1])
                    west = A[i][j] - A[i][j - 1];

            int east = 0;
            if (j == W - 1)
                east = A[i][j];
            else
                if (A[i][j] > A[i][j + 1])
                    east = A[i][j] - A[i][j + 1];

            int north = 0;
            if (i == 0)
                north = A[i][j];
            else
                if (A[i][j] > A[i - 1][j])
                    north = A[i][j] - A[i - 1][j];

            int south = 0;

            if (i == H - 1)
                south = A[i][j];
            else
                if (A[i][j] > A[i + 1][j])
                    south = A[i][j] - A[i + 1][j];

            cub_sum = top + bottom + west + east + north + south;

            sum += cub_sum;
        }
    }

    return sum;
}

//-----------------------------------------------------------------------------
int twoPluses(vector<string> grid) {

    int n = grid.size();
    int m = grid[0].size();
    int max_area = 0;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B')
                continue;

           // int max_grid_size = min (j, m - j - 1)
        }

    return max_area;
}

//-----------------------------------------------------------------------------
typedef unsigned long long int uint64;


uint64 make_uint(int r, int c) {
    const uint64 mult = 1000000L;

    return r* mult + c;
}

uint64 check_direction(int rq, int cq, int dr, int dc, int n, set<uint64> onbstacles) {

    int r = rq + dr;
    int c = cq + dc;

    uint64 count = 0;

    while (true) {

        if (r <= 0)
            break;

        if (c <= 0)
            break;

        if (r > n)
            break;

        if (c > n)
            break;

        uint64 pos = make_uint(r, c);

        if (onbstacles.find(pos) != onbstacles.end())
            break;

        count++;

        r += dr;
        c += dc;
    }

    return count;
}

void queens_attackii () {
    int n, k;

    cin >> n >> k;

    int rq, cq;

    cin >> rq >> cq;

    set<uint64> onbstacles;


    for (int i = 0; i < k; i++) {
        int r, c;

        cin >> r >> c;

        onbstacles.insert(make_uint(r, c));
    }

    uint64 count = 0;
        
    // check left
    count += check_direction(rq, cq, 0, -1, n, onbstacles);

    // check right
    count += check_direction(rq, cq, 0, 1, n, onbstacles);

    // check  up
    count += check_direction(rq, cq, 1, 0, n, onbstacles);

    // check  down
    count += check_direction(rq, cq, -1, 0, n, onbstacles);

    // check  up-left
    count += check_direction(rq, cq, 1, -1, n, onbstacles);

    // check up-right
    count += check_direction(rq, cq, 1, 1, n, onbstacles);

    // check down-left
    count += check_direction(rq, cq, -1, -1, n, onbstacles);

    // check down-right
    count += check_direction(rq, cq, -1, 1, n, onbstacles);

    cout << count;
}


struct plus_struct{
    int  x, y, size, area;
    set<tuple<int, int>> coords;

    bool overlap(plus_struct& s1) {
        std::vector<tuple<int, int>> intersect;

        auto ov = set_intersection(coords.begin(), coords.end(),
            s1.coords.begin(), s1.coords.end(),
            back_inserter(intersect));

        if (intersect.size() != 0)
            return true;

        return false;
    }

    bool overlap1(plus_struct& s1) {

        if (size > s1.size)
            return s1.overlap1(*this);

        int x1 = x - size;
        int x2 = x + size;
        
        int y1 = y - size;
        int y2 = y + size;

        int sx1 = s1.x - s1.size;
        int sx2 = s1.x + s1.size;

        int sy1 = s1.y - s1.size;
        int sy2 = s1.y + s1.size;

        // top left corner of r1 inside r2
        if (x1 >= sx1 && x1 <= sx2 &&
            y1 >= sy1 && y1 <= sy2)
            return true;

        // bottom right corner of r1 inside r2
        if (x2 >= sx1 && x2 <= sx2 &&
            y2 >= sy1 && y2 <= sy2)
            return true;

        // top right corner of r1 inside r2
        if (x2 >= sx1 && x2 <= sx2 &&
            y1 >= sy1 && y1 <= sy2)
            return true;

        // bottom left corner of r1 inside r2
        if (x1 >= sx1 && x1 <= sx2 &&
            y2 >= sy1 && y2 <= sy2)
            return true;

        return false;
    }    
};

void ema_supercomputer() {

    int n, m;

    cin >> n >> m;

    vector<string> grid;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        grid.push_back(tmp);
    }

    vector <plus_struct> pluses;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 'B') continue;
            

            //int prev_size = 0;
            int size = 0;
            
            set<tuple<int,int>> coords;

            while (true) {

                if (i - size < 0)
                    break;

                if (grid[i - size][j] == 'B')
                    break;

                coords.insert(make_tuple(j, i - size));
                
                if (i + size >= n)
                    break;


                if (grid[i + size][j] == 'B')
                    break;

                coords.insert(make_tuple(j, i + size));

                if (j - size < 0)
                    break;

                if (grid[i][j - size] == 'B')
                    break;

                coords.insert(make_tuple(j-size, i));

                if (j + size >= m)
                    break;

                if (grid[i][j + size] == 'B')
                    break;

                coords.insert(make_tuple(j + size, i));

                //cout << i << " " << j << " " << size << endl;
                //if (prev_size == 0)
                //    continue;

                plus_struct plus;
                plus.y = i;
                plus.x = j;
                plus.size = size;
                plus.area = size * 4 + 1;
                plus.coords = coords;

                if (size)
                    cout << plus.x << " " << plus.y << " " << plus.area << endl;
                pluses.push_back(plus);

                size++;
            }

            
            
        }    

    int max_area = 0;

    for (int i = 0; i < pluses.size(); i++)
        for (int j = i + 1; j < pluses.size(); j++)
            if (!pluses[i].overlap(pluses[j])) {
                int area = pluses[i].area * pluses[j].area;
                max_area = max(area, max_area);
            }

    cout << max_area;
}
