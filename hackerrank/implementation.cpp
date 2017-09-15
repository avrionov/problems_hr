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
    
    int array[n][m];
    int out_array[n][m];
    
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
