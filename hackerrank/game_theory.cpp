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

#include "Utils.h"

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

inline int frexp_fast(long long int n) {
	
	if (n == 0)
		return 0;

	int msb = 0;
	while (n != 0) {
		n = n / 2;
		msb++;
	}

	return  msb;	
}


long long int stones_game_helper(long long int n) {
	
	if (n % 2) 
		return 1;
	
	int i;
		
	i = frexp_fast(n);
	
	long long int x = 1 ^ i;
			
	int i1;

	i1 = frexp_fast(x);

	long long int y = 1 << (i1 - 1);
		
	long long int  ret = 0;

	if (((x ^ y) + 1) == y)
		ret = 1 << (y - 2);
	else
		ret = (1 << y - 1) - (1 << (x ^ y)) + 1;

	return ret;
}

int stones_game_helper_int(long long int n) {

	if (n % 2)
		return 1;

	int i;

	i = frexp_fast(n);

	int x = 1 ^ i;

	int i1;

	i1 = frexp_fast(x);

	int y = 1 << (i1 - 1);

	int  ret = 0;

	if (((x ^ y) + 1) == y)
		ret = 1 << (y - 2);
	else
		ret = (1 << y - 1) - (1 << (x ^ y)) + 1;

	return ret;
}



void stones_game() {
	int t;

	cin >> t;

	ios_base::sync_with_stdio(false);

	vector<int> ret(t);
	int i = 0;
	while (i < t) {
		long long int n;
		cin >> n;
		ret[i] = stones_game_helper_int(n);		
		i++;		
	}

	for (auto a : ret)		
		printf("%d\n", a);
}

//-----------------------------------------------------------------------------
void vertical_rooks() {
	int t;

	cin >> t;

	while (t) {
		int n;
		cin >> n;

		vector<int> r1, r2;

		read_array(r1, n);
		read_array(r2, n);

		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum ^= abs(r1[i] - r2[i]) - 1;
		}
			 
		cout << (sum ? "player-2" : "player-1") << endl;
		
		t--;
	}
}

//-----------------------------------------------------------------------------
void chocolate_in_box() {
	int n;
	cin >> n;

	vector<long long int> ar;

	read_array(ar, n);

	long long int sum = 0;

	for (auto a : ar)
		sum ^= a;

	int count = 0;
	for (auto a : ar)
		if ((sum ^ a) < a)
			count++;

	cout << count;
}