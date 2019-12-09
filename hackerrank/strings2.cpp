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
#include <stack>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <thread>
#include <mutex>

#include "bigint.h"


using namespace std;

//-----------------------------------------------------------------------------
int minimumNumber(int n, string password) {

	string numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";

	int len = password.length();

	int count = 0;

	if (password.find_first_of(numbers) == std::string::npos)
		count++;

	if (password.find_first_of(lower_case) == std::string::npos)
		count++;

	if (password.find_first_of(upper_case) == std::string::npos)
		count++;

	if (password.find_first_of(special_characters) == std::string::npos)
		count++;

	if ((count + len) < 6)
		count += 6 - count - len;

	return count;
}

//-----------------------------------------------------------------------------

#define NO_OF_CHARS 256  

void badCharHeuristic(string& str, int size, int badchar[NO_OF_CHARS]) {
	int i;
		
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
		
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

// returns number of occurences
int search_boyer_moore_horspool(string& txt, string& pat, int* badchar) {
	
	int m = pat.size();
	int n = txt.size();

	//int badchar[NO_OF_CHARS];
	//badCharHeuristic(pat, m, badchar);

	int count = 0;

	int s = 0; 
	while (s <= (n - m)) {
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;
				
		if (j < 0) 	{
			count++;					
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		} else {
			s += max(1, j - badchar[txt[s + j]]);
		}	
	}

	return count;
}


// returns number of occurences
int search_boyer_moore_horspool_copy(string txt, string pat, int* badchar) {

	int m = pat.size();
	int n = txt.size();

	//int badchar[NO_OF_CHARS];
	//badCharHeuristic(pat, m, badchar);

	int count = 0;

	int s = 0;
	while (s <= (n - m)) {
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0) {
			count++;
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else {
			s += max(1, j - badchar[txt[s + j]]);
		}
	}

	return count;
}

// returns number of occurences
int search_boyer_moore_horspool(const char* txt, int n, string& pat, int* badchar) {

	int m = pat.size();
	//int n = txt.size();

	//int badchar[NO_OF_CHARS];
	//badCharHeuristic(pat, m, badchar);

	int count = 0;

	int s = 0;
	while (s <= (n - m)) {
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0) {
			count++;
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else {
			s += max(1, j - badchar[txt[s + j]]);
		}
	}

	return count;
}


void power_2_string(int power, vector<string>& powers, int badchars[801][NO_OF_CHARS]) {

	const int max_digits = 250; // 2^800 has 241 digits. heristics to reduce the time

	int d[max_digits] = { 0 };
		
	d[0] = 1;

	int carry = 0;
	int temp = 0;
	for (int j = 0; j <= power; j++) {
		carry = 0;
		temp = 0;

		for (int i = 0; i < max_digits; i++) {
			temp = d[i] * 2 + carry;
			d[i] = temp % 10;
			carry = temp / 10;			
		}
				
		string x(max_digits+1, 0);
		
		int sz = max_digits - 1;

		while (d[sz] == 0 && sz > 0)
			sz--;

		for (int i = 0; i < max_digits; i++) {			
			x[i] = d[i] + '0';
		}
				
		x.erase(sz+1);
		
		reverse(x.begin(), x.end());

		powers.push_back(x);	
		badCharHeuristic(x, sz+1, badchars[j + 1]);
	}
}


int find_all_power2(string& tmp, vector<string>& powers, int badchars[801][NO_OF_CHARS]) {
	auto len = tmp.length();
	int count = 0;

	const char* text = tmp.c_str();
	
	for (int i = 0; i < powers.size(); i++) {
		
		string& test_pattern = powers[i];
		
		if (test_pattern.length() > len)
			break;

		int count2 = search_boyer_moore_horspool(tmp, test_pattern, badchars[i]);
		//int count2 = search_boyer_moore_horspool(text, len, test_pattern, badchars[i]);

		count += count2;
	}

	return count;
}


int find_all_power2_parallel(string& tmp, vector<string>& powers, int badchars[801][NO_OF_CHARS]) {
	auto len = tmp.length();
	int count = 0;

	const char* text = tmp.c_str();
	std::vector<std::thread> workers;


	std::mutex lock;
	for (int i = 0; i < powers.size(); i++) {

		string& test_pattern = powers[i];

		if (test_pattern.length() > len)
			break;

		workers.push_back(std::thread([=, &count, &lock]()
			{
				//std::cout << "thread function\n";
				int count2 = search_boyer_moore_horspool_copy(tmp, test_pattern, badchars[i]);
				lock.lock();
				count += count2;
				lock.unlock();
			}));
		
	}

	std::for_each(workers.begin(), workers.end(), [](std::thread& t)
		{
			t.join();
		});


	return count;
}


int badchars[820][NO_OF_CHARS];

void twotwo_old() {
	
	vector<string> powers;

	unsigned long long int p2= 2;

	powers.push_back("1"); 

	badCharHeuristic(powers[0], 1, badchars[0]);

	power_2_string(800, powers, badchars);
	
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string tmp;
		cin >> tmp;

		int res = find_all_power2(tmp, powers, badchars);
		//int res = find_all_power2_parallel(tmp, powers, badchars);
		
		cout << res << endl;
	}
}



const int MaxStates = 100 * 10000 + 10;
const int MaxChars = 26;

long long int Out[MaxStates];
long long int FF[MaxStates];
long long int GF[MaxStates][MaxChars];

int build_matching_machine(const vector<string>& words, char lowestChar = 'a', char highestChar = 'z') {

	memset(Out, 0, sizeof Out);
	memset(FF, -1, sizeof FF);
	memset(GF, -1, sizeof GF);

	long long int states = 1;

	for (int i = 0; i < words.size(); ++i) {
		const string& keyword = words[i];
		long long int currentState = 0;

		for (int j = 0; j < keyword.size(); ++j) {
			int c = keyword[j] - lowestChar;

			if (GF[currentState][c] == -1) {
				GF[currentState][c] = states++;
			}

			currentState = GF[currentState][c];
		}

		Out[currentState] |= (1 << i);
	}

	for (int c = 0; c < MaxChars; ++c) {
		if (GF[0][c] == -1) {
			GF[0][c] = 0;
		}
	}

	queue<long long int> q;
	for (int c = 0; c <= highestChar - lowestChar; ++c) {
		if (GF[0][c] != -1 && GF[0][c] != 0) {
			FF[GF[0][c]] = 0;
			q.push(GF[0][c]);
		}
	}

	while (q.size()) {
		int state = q.front();
		q.pop();

		for (int c = 0; c <= highestChar - lowestChar; ++c) {
			if (GF[state][c] != -1) {
				long long int failure = FF[state];

				while (GF[failure][c] == -1) {
					failure = FF[failure];
				}

				failure = GF[failure][c];
				FF[GF[state][c]] = failure;
				Out[GF[state][c]] |= Out[failure];
				q.push(GF[state][c]);
			}
		}
	}

	return states;
}

int find_next_state(int currentState, char nextInput, char lowestChar = 'a') {
	int answer = currentState;
	int c = nextInput - lowestChar;

	while (GF[answer][c] == -1) {
		answer = FF[answer];
	}

	return GF[answer][c];
}


int  find_all_states_count(string text, vector<string>& keywords, char lowestChar = 'a') {

	int currentState = 0;
	
	int count = 0;

	int counts[802] = { 0 };

	for (int i = 0; i < text.size(); ++i) {
		currentState = find_next_state(currentState, text[i], lowestChar);

		if (Out[currentState] == 0)
			continue;

		
			for (int j = 0; j < keywords.size(); ++j) {
				//if (text.size() >= keywords[j].size())
				if (keywords[j].size() + i <= text.size())
					if (Out[currentState] & (1 << j)) {
						count++;
						counts[j]++;
					}
			}
	}

	return count;
}

void power_2_string(int power, vector<string>& powers) {

	const int max_digits = 250; // 2^800 has 241 digits. heristics to reduce the time

	int d[max_digits] = { 0 };

	d[0] = 1;

	int carry = 0;
	int temp = 0;
	for (int j = 0; j <= power; j++) {
		carry = 0;
		temp = 0;

		for (int i = 0; i < max_digits; i++) {
			temp = d[i] * 2 + carry;
			d[i] = temp % 10;
			carry = temp / 10;
		}

		string x(max_digits + 1, 0);

		int sz = max_digits - 1;

		while (d[sz] == 0 && sz > 0)
			sz--;

		for (int i = 0; i < max_digits; i++) {
			x[i] = d[i] + '0';
		}

		x.erase(sz + 1);

		reverse(x.begin(), x.end());

		powers.push_back(x);		
	}
}


void twotwo() {

	vector<string> powers;
		
	powers.push_back("1"); 

	power_2_string(31, powers);

	int t;

	cin >> t;

	build_matching_machine(powers, '0', '9');

	for (int i = 0; i < t; i++) {
		string tmp;
		cin >> tmp;
			
		int count = find_all_states_count(tmp, powers, '0');
				
		cout << count << endl;
	}
}
