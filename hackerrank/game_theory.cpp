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

//-----------------------------------------------------------------------------
void alice_and_bob_game() {
	int t;

	cin >> t;

	int* prime_numbers = new int[100005]; // 10^5 + buffer

	prime_numbers[0] = 0;
	prime_numbers[1] = 0;

	for (int i = 2; i < 100001; i++)
		prime_numbers[i] = 1;


	for (int i = 2; i < 100001; i++) {
		for (int j = i * 2; j < 100001; j += i) {
			prime_numbers[j] = 0;
		}
	}


	while (t--) {
		int n;  // set size
		cin >> n;

		if (n == 1) {
			cout << "Bob" << endl;
			continue;
		}

		int count = 0;
		for (int i = 0; i <= n; i++) {
			if (prime_numbers[i]) count ++;
		}

		if (count % 2)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;		
	}
}

//-----------------------------------------------------------------------------
void kitty_and_katty() {

	int t;
	cin >> t;

	while (t--) {

		int n;

		cin >> n;

		if (n % 2 == 0 || n == 1)
			cout << "Kitty" << endl;
		else
			cout << "Katty" << endl;
	}	
}

//-----------------------------------------------------------------------------
bool increased_seq(const vector<int>& v, int mask) {
	int last = INT_MAX; 
	
	for (int i = v.size() - 1; i >= 0; i--) {
		if (mask & (1 << i)) {
			if (v[i] >= last) {
				return false;
			}
			last = v[i];
		}
	}
	return true;
}

bool first_wins(const vector<int>& perm, int mask, bool first_win, vector<short>& masks) {

	if (masks[mask] == -1)
		masks[mask] = increased_seq(perm, mask);
	else if (masks[mask] == 0)
		return first_win; 

	if (masks[mask] == 1)
		return !first_win;

	int copy = mask;

	while (copy) {
		int last_bit = copy & (~(copy - 1));
		copy ^= last_bit; 
		int newmask = mask ^ last_bit;
		if (first_win == first_wins(perm, newmask, !first_win, masks)) {
			masks[newmask] = true;
			return first_win; 
		}
	}

	masks[mask] = false;
	return !first_win;
}

void permutation_game() {
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> perm(n);
		for (int i = 0; i < n; i++)
			cin >> perm[i];

		int total = pow(2, n);
		vector<short> masks(total, -1);

		int mask = (1 << n) - 1;

		if (first_wins(perm, mask, true, masks))
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;

	}
}

//-----------------------------------------------------------------------------
void new_year_game() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int arr[2001];

		int mod_1 = 0;
		int mod_2 = 0;
		for (int i = 0; i < n; i++) {
			//scanf("%d", arr[i]); // scanf is faster
			cin >> arr[i];

			int mod = arr[i] % 3;

			if (mod == 1)
				mod_1++;

			if (mod == 2)
				mod_2 ++;
		}
			
		if ((mod_1 % 2) || (mod_2 % 2))
			cout << "Balsa" << endl;
		else
			cout << "Koca" << endl;		

	}
}