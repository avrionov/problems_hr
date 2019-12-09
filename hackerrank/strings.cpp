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
#include <bitset>

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
	
	for (int i = 4; i < powers.size(); i++) {
		
		string& test_pattern = powers[i];
		
		if (test_pattern.length() > len)
			break;

		//int count2 = search_boyer_moore_horspool(tmp, test_pattern, badchars[i]);
		int count2 = search_boyer_moore_horspool(text, len, test_pattern, badchars[i]);

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
		for (int i = 0; i < tmp.size(); i++)
			switch (tmp[i]) {
				case '1':
				case '2':
				case '4':
				case '8': res++;
			}

		/*	if (tmp[i] == '1' || tmp[i] == '2' || tmp[i] == '4' || tmp[i] == '8')
				res++;*/

		//int res = find_all_power2_parallel(tmp, powers, badchars);
		
		cout << res << endl;
	}
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

#define MAXS 100000
#define MAXC 10
#define MAXW 802

class AhoCorasick {

private:
	vector<string>& arr;
	string text;
	int g[MAXS][MAXC];
	int f[MAXS];
	bitset<MAXW> out[MAXS];

public:
	void initialize() {		
		memset(g, -1, sizeof g);
		memset(f, 0, sizeof f);
	}

	void buildMachine() {
		int state = 0, currState = 0, index = 0;
		string str;
		///Building a trie, each new node gets the next number as node-name.
		for (int i = 0; i < arr.size(); i++) {
			str = arr[i];
			currState = 0;

			for (int j = 0; j < str.size(); j++)
			{
				index = str[j] - '0';
				if (g[currState][index] == -1)
				{
					g[currState][index] = ++state;
				}
				currState = g[currState][index];
			}
			out[currState].set(i);			
		}

		///Failure function
		queue<int>q;
		int s, fail;
		for (int i = 0; i < MAXC; i++) {
			if (g[0][i] != -1)
			{
				f[g[0][i]] = 0; ///here, depth is 1
				q.push(g[0][i]);
			} else {
				g[0][i] = 0; ///Necessary in failure alg below, non-existing char back to state 0. To stop infinite loop at line 68.
			}
		}

		while (!q.empty()) {
			s = q.front();
			q.pop();
			for (int i = 0; i < MAXC; i++) {
				if (g[s][i] != -1) {
					q.push(g[s][i]);
					fail = f[s]; ///here is the perfect place to calculate failure of g[s][i],cuz here 'state:s' is (depth-1) state of 'state:g[s][i]'.
					while (g[fail][i] == -1) {
						fail = f[fail];
					}

					fail = g[fail][i];
					f[g[s][i]] = fail;
					out[g[s][i]] |= out[fail]; ///merging output of the node & it's failure node.
					///Read the paper of aho-corasick,published in 1975.
				}
			}
		}
	}


	int nextState(int s, char ch) {
		int index = ch - '0';
		while (g[s][index] == -1) {
			s = f[s];
		}

		return g[s][index];
	}


	AhoCorasick(vector<string>& ar) :arr(ar) {
	}

	int search(string& text) {
		
		int state = 0;
		int count = 0;
		for (int i = 0; i < text.size(); i++) {
			state = nextState(state, text[i]); 
			count += out[state].count();			
		}

		return count;
	}

};

void twotwo() {

	vector<string> powers;
		
	powers.push_back("1"); 

	power_2_string(800, powers);

	int states = 0;
	for (auto i : powers) {
		states += i.size();
	}

	int t;

	cin >> t;
		
	AhoCorasick* alg = new AhoCorasick(powers);

	alg->initialize();
	alg->buildMachine();

	for (int i = 0; i < t; i++) {
		string tmp;
		cin >> tmp;
		
		int count = alg->search( tmp);		
				
		cout << count << endl;
	}
}



//-----------------------------------------------------------------------------
// circular_palindromes
int manchester_algoritm(const char* text, int len, int* LPS, int len2) {

	int N = len;

	N = 2 * N + 1;

	LPS[0] = 0;
	LPS[1] = 1;
	int center_position = 1;
	int center_right_position = 2;
	int current_left_pos;
	int max_length = 0;

	for (int current_right_pos = 2; current_right_pos < N; current_right_pos++) {

		current_left_pos = 2 * center_position - current_right_pos;

		int& cpr = LPS[current_right_pos];

		cpr = 0;
		int diff = center_right_position - current_right_pos;

		if (diff > 0)
			cpr = min(LPS[current_left_pos], diff);

		while (
			((current_right_pos + cpr) < N && (current_right_pos - cpr) > 0) &&
			(
			((current_right_pos + cpr + 1) % 2 == 0) ||
				(text[(current_right_pos + cpr + 1) >> 1] == text[(current_right_pos - cpr - 1) >> 1])
				)
			) {
			cpr++;
		}

		if ((cpr > max_length) && (cpr <= len)) {
			max_length = cpr;
		}

		if (current_right_pos + cpr > center_right_position) {
			center_position = current_right_pos;
			center_right_position = current_right_pos + cpr;
		}
	}

	//cout << max_length << endl;  
	//printf("%d\n", max_length);
	return max_length;
}

void circular_palindromes() {

	int k;
	cin >> k;

	string s;
	cin >> s;

	auto len = s.length();
	int* LPS = new int[len * 2 + 1];

	string s2 = s + s;
	char* s_start = const_cast <char*>(s2.c_str());
	auto len2 = len;

	int* res = new int[k];
	for (int i = 0; i < k; i++) {
		char tmp = s_start[len];
		s_start[len] = 0;
		res[i] = manchester_algoritm(s_start, len, LPS, len);
		s_start[len] = tmp;

		s_start++;
	}

	for (int i = 0; i < k; i++) {
		printf("%d\n", res[i]);
	}

	delete[] LPS;
}