#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "bigint.h"

using namespace std;


namespace
{
  char toChar(char d) {
    return d | 0x30;
  }
}

constexpr unsigned Base = 100;

bigint::bigint(int num) {

  for (; num; num /= Base) {
    _num.push_back(num % Base);
  }

  if (_num.empty()) {
    _num.push_back(0);
  }
}


bigint operator*(const bigint & num1, const bigint & num2) {

  bigint precomp[Base];
  for (int i = 1; i < Base; ++i) {
    precomp[i] = precomp[i - 1] + num1;
  }

  bigint result;
  int exp = 0;
  for_each(num2._num.begin(), num2._num.end(), [&result, &precomp, &exp](char c) {
    result.add(precomp[c], exp++);
  });
  return result;
}

void bigint::add(const bigint & num, int exp) {

  if (exp > _num.size()) {
    _num.append(exp - _num.size(), 0).append(num._num.begin(), num._num.end());
  }
  else {
    auto b1 = _num.begin() + exp, e1 = _num.end();
    auto b2 = num._num.begin(), e2 = num._num.end();

    int r = 0;
    for (; b1 != e1 && b2 != e2; ++b1, ++b2, r /= Base) {
      r += *b1 + *b2;
      *b1 = r % Base;
    }

    for (; r && b1 != e1; ++b1, r /= Base) {
      r += *b1;
      *b1 = r % Base;
    }

    for (; r && b2 != e2; ++b2, r /= Base) {
      r += *b2;
      _num.push_back(r % Base);
    }

    if (b2 != e2) {
      _num.append(b2, e2);
    }

    if (r) {
      _num.push_back(r);
    }
  }
}

bigint &bigint::operator+=(const bigint & num2) {
  add(num2, 0);
  return *this;
}

bigint operator+(bigint num1, const bigint & num2) {
  num1.add(num2, 0);
  return num1;
}

ostream & operator<<(ostream & outstream, const bigint & num) {
	  
  return outstream << num.to_string();
}

bigint & bigint::operator=(bigint num) {
  _num = std::move(num._num);
  return *this;
}

void bigint::swap(bigint & num)
{
  _num.swap(num._num);
}


bigint power(const bigint& num, const int p) {

	if (p == 0)
		return 1;

	if (p == 1)
		return num;

	bigint half_power = power(num, p / 2);
	half_power = half_power * half_power;

	if ((p % 2) == 0)
		return half_power;
	else
		return num * half_power;
}

string bigint::to_string() const {

	string x(_num.size() * 2, 0);
	for (size_t i = 0; i < _num.size(); ++i) {
		auto d = _num[i];
		x[2 * i] = toChar(d % 10);
		x[2 * i + 1] = toChar(d / 10);
	}

	if (x.back() == '0') {
		x.erase(x.size() - 1);
	}

	reverse(x.begin(), x.end());

	return x;
}


