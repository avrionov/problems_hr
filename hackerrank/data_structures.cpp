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

vector<int> reverseArray(vector<int> a) {
	
	std::reverse(a.begin(), a.end());

	return a;
}