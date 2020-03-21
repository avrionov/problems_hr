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

//-----------------------------------------------------------------------------
string nimGame(vector<int> pile) {
	
	if (pile.size() == 1) {
		return "First";
	}


	int sum = pile[0] ^ pile[1];

	for (int i = 2; i < pile.size(); i++) {
		sum = sum ^ pile[i];
	}

	if (sum != 0)
		return "First";

	return "Second";
}

//-----------------------------------------------------------------------------
string misereNim(vector<int> pile) {
	
	int sum = pile[0] ^ pile[1];

	int count_n = 0;

	for (auto a : pile) {
		if (a == 1)
			count_n++;
	}

	for (int i = 2; i < pile.size(); i++) {
		sum = sum ^ pile[i];
	}

	// all ones
	if (count_n == pile.size())
		if (count_n % 2 == 0)
			return "First";
		else
			return "Second";

	if (sum != 0)
		return "First";

	return "Second";
}

void test_misereNim() {
	int t;

	cin >> t;

	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;
				
		vector<int> ar;

		read_array(ar, n);

		string result = misereNim(ar);
		cout << result;
		cout << endl;
	}
}

//-----------------------------------------------------------------------------
string nimbleGame(vector<int> s) {

	int sum = 0;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] %2 == 1)
			sum = sum ^ i;
	}

	if (sum != 0)
		return "First";

	return "Second";	
}

//-----------------------------------------------------------------------------
string pokerNim(int k, vector<int> c) {

	if (c.size() == 1) {
		return "First";
	}
	
	int sum = c[0] ^ c[1];

	for (int i = 2; i < c.size(); i++) {
		sum = sum ^ c[i];
	}

	if (sum != 0)
		return "First";

	return "Second";

}