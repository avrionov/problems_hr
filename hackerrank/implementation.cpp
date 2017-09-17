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