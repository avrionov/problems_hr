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
void read_array(vector<int>& ar, int n);
void read_array(vector<long long int>& ar, int n);

//-----------------------------------------------------------------------------
int flippingMatrix(vector<vector<int>> matrix) {

  int m = matrix.size();
  int n = m / 2;

  int sum = 0;


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sum += max(matrix[i][j], 
                max(matrix[m - i - 1][j], 
                  max(matrix[i][m - j - 1], matrix[m - i - 1][m - j - 1])));


  return sum;
}

void flipping_the_matrix_test() {

  int q;
  cin >> q;

  for (int q_itr = 0; q_itr < q; q_itr++) {
    int n;
    cin >> n;

    vector<vector<int>> matrix(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      matrix[i].resize(2 * n);

      for (int j = 0; j < 2 * n; j++) {
        cin >> matrix[i][j];
      }
          
    }

    int result = flippingMatrix(matrix);

    cout << result << "\n";
  }

}


