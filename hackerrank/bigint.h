#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

class bigint {

public:
  bigint(int num = 0);

  bigint &operator+=(const bigint & num2);
  void swap(bigint &num);

  bigint &operator=(bigint num);
  
  string to_string() const;

  friend bigint operator*(const bigint & num1, const bigint & num2);
  friend bigint operator+(bigint num1, const bigint & num2);
  friend ostream & operator<<(ostream & outstream, const bigint & num);

  friend bigint power(const bigint& num, const int p);

private:
  void add(const bigint &num, int exp);

private:
  string _num;
};
