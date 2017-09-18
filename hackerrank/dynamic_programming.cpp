#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

#include "bigint.h"

using namespace std;




//-----------------------------------------------------------------------------
void fibonachi_modified() {

  int n, t1, t2;

  cin >> t1 >> t2 >> n;

  bigint lt1(t1);
  bigint lt2(t2);

  for (int j = 2; j < n; j++) {
    lt1 += lt2* lt2;
    lt1.swap(lt2);
  }

  cout << lt2;
}