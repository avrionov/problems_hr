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
#include <chrono> 

#include "Utils.h"

using namespace std::chrono;

//-----------------------------------------------------------------------------
int superDigit(unsigned long long int n) {

	if (n < 10)
		return n;

	unsigned long long int sum = 0;

	while (n) {
		int mod = n % 10;
		sum += mod;

		n /= 10;
	}

	return superDigit(sum);
}


int superDigit(string n, int k) {

	if (n.size() == 1 && k == 1)
		return n[0] - '0';

	int carry = 0;

	string str;
	unsigned long long int sum = 0;

	//for (int i = 0; i < k; i++) {

		for (auto ch : n) {
			sum += ch - '0';
		}
	//}

	return superDigit(sum*k);
}

//-----------------------------------------------------------------------------
int powerSum_helper(int X, int N, int inc) {

	int power_inc= pow(inc, N);

	if (power_inc > X)
		return 0;

	if (power_inc == X)
		return 1;

	return powerSum_helper(X, N, inc + 1) + powerSum_helper(X - power_inc, N, inc + 1);
}

int powerSum(int X, int N) {

	return powerSum_helper(X, N, 1);
}


//-----------------------------------------------------------------------------
typedef vector<string> crossword_type;

bool check_word_horizontal(crossword_type crossword, int x, int y, string& word) {

	for (int i = 0; i < word.length(); i++) {
		if (x + i >= 10)
			return false;

		if (crossword[y][x + i] == '-')
			continue;

		if (crossword[y][x + i] != word[i])
			return false;
	}

	return true;
}


bool check_word_vertical(crossword_type crossword, int x, int y, string& word) {
	for (int i = 0; i < word.length(); i++) {
		if (y + i >= 10)
			return false;

		if (crossword[y+i][x] == '-')
			continue;

		if (crossword[y + i][x] != word[i])
			return false;
	}

	return true;
}

crossword_type apply_word_horizontal(crossword_type& crossword, int x, int y, string& word) {
	vector<string> crossword_copy;

	for (int i = 0; i < 10; i++)
		crossword_copy.push_back(crossword[i]);

	for (int i = 0; i < word.length(); i++)
		crossword_copy[y][x + i] = word[i];			

	return crossword_copy;
}

crossword_type apply_word_vertical(crossword_type& crossword, int x, int y, string& word) {
	vector<string> crossword_copy;

	for (int i = 0; i < 10; i++)
		crossword_copy.push_back(crossword[i]);

	for (int i = 0; i < word.length(); i++)
		crossword_copy[y+i][x] = word[i];

	return crossword_copy;
}


bool crossword_puzzle_rec(crossword_type crossword, vector<string>& words, int pos, crossword_type& ret_crossword) {

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (check_word_horizontal(crossword, i, j, words[pos])) {
				crossword_type crossword_copy = apply_word_horizontal(crossword, i, j, words[pos]);

				if (pos == words.size() - 1) {
					ret_crossword = crossword_copy;
					return true;
				}
					
				bool bFound = crossword_puzzle_rec(crossword_copy, words, pos + 1, ret_crossword);
				if (bFound)
					return true;
			}

			if (check_word_vertical(crossword, i, j, words[pos])) {
				crossword_type crossword_copy =  apply_word_vertical(crossword, i, j, words[pos]);

				if (pos == words.size() - 1) {
						ret_crossword = crossword_copy;
						return true;
				}

				bool bFound = crossword_puzzle_rec(crossword_copy, words, pos + 1, ret_crossword);
				if (bFound)
					return true;
			}

		}
	return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {

	vector<string> words_ar;

	string::size_type prev_pos = 0, pos = 0;

	//words.append(";");

	while ((pos = words.find(';', pos)) != string::npos)
	{
		string substring(words.substr(prev_pos, pos - prev_pos));

		words_ar.push_back(substring);

		prev_pos = ++pos;
	}

	words_ar.push_back(words.substr(prev_pos, pos - prev_pos));

	crossword_type ret_crossword;
	crossword_puzzle_rec(crossword, words_ar, 0, ret_crossword);

	return ret_crossword;
}
	
void crossword_puzzle() {

	vector<string> crossword(10);

	for (int i = 0; i < 10; i++) {
		string crossword_item;
		cin >> crossword_item;

		crossword[i] = crossword_item;
	}

	string words;
	cin >> words;

	vector<string> result = crosswordPuzzle(crossword, words);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << endl;
		}
	}
}


//-----------------------------------------------------------------------------
bool password_cracker_rec(vector<string>& passwords, string& loginAttempt, int pos, string constructed, string& result, vector<int>& memo) {

	for (auto pass : passwords) {
		if (loginAttempt.find(pass, pos) == pos) {
			int len = pass.length();
			string next_level;

			if (pos == 0)
				next_level = pass;
			else
				next_level = constructed + string(" ") + pass;

			if (len + pos == loginAttempt.length()) {				
				result = next_level;
				return true;		
			}
			
			if (memo[pos+len] == -1) {
				bool bfound = password_cracker_rec(passwords, loginAttempt, pos + len, next_level, result, memo);

				if (bfound)
					memo[pos+len] = 1;
				else
					memo[pos+len] = 0;

				if (bfound)
					return true;
			}/* else {
					if (memo[pos+len] == 0) {						
						bool bfound = password_cracker_rec(passwords, loginAttempt, pos + len, next_level, result, memo);
						return true;
					}
			}*/
		}			
	}

	return false;
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
	string result;

	
	/*std::sort(passwords.begin(), passwords.end(), [](string& a, string& b) {
		return a.length() > b.length();
		});*/
	/*
	std::sort(passwords.begin(), passwords.end(), [](string& a, string& b) {
		return a < b;
		});
		*/

	set<char> pass_set;
	
	for (auto a : passwords) {
		for (auto ch : a)
			pass_set.insert(ch);
	}

	for (int i = 0; i < loginAttempt.length(); i++)	
		if (pass_set.find(loginAttempt[i]) == pass_set.end())
			return "WRONG PASSWORD";

	vector<int> memo(loginAttempt.size(), -1);

	if (password_cracker_rec(passwords, loginAttempt, 0, "", result, memo)) {
		return result;
	}
	else {
		return "WRONG PASSWORD";
	}

}


void password_cracker_test() {
	int t;

	cin >> t;

	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;

		vector<string> passwords;
		string loginAttempt;

		for (int i = 0; i < n; i++) {
			string password;
			cin >> password;

			passwords.push_back(password);
		}

		cin >> loginAttempt;

		string result = passwordCracker(passwords, loginAttempt);
		cout << result << endl;
	}
}

//-----------------------------------------------------------------------------
long long int calculate_max(long long int n, vector<long long int>& ar, map<long long int, long long int>& memo) {
	long long int max = 0;

	auto it = memo.find(n);

	if (it != memo.end())
		return it->second;

	for (auto a : ar) {
		if (n != a)
			if (n % a == 0) {
				long long int mult = n / a;
				long long int count = 1 + mult * calculate_max(a, ar, memo);
				if (count > max)
					max = count;
			}
	}

	memo[n] = max;
	return max;
}

void stone_devision() {
	int t;

	cin >> t;

	for (int k = 0; k < t; k++) {
		long long int n, m;

		cin >> n >> m;
		vector<long long int> ar;
		read_array(ar, m);
		map<long long int, long long int> memo;
		long long int max = calculate_max(n, ar, memo);
		cout << max << endl;

	}
}


//-----------------------------------------------------------------------------
void find_k_sums_utol(int n, int sum, vector<int>& out, int index, vector<long long int>& a, multiset<long long int>& sums)
{
	
	if (index > n || sum < 0)
		return;
		
	if (index == n) {
		
		if (sum == 0) {
			
			int last = out.size() - 1;

			if (out[last] != 0) {
				long long int target_sum = 0;
				bool b_new = false;
				for (int i = 0; i < out.size(); i++) {
					target_sum += out[i] * a[i];
				}

				auto itr = sums.find(target_sum);
				if (itr != sums.end()) {
					sums.erase(itr);
				}
			}
			//cout << endl;
		}
		return;
	}
		
	for (int i = 0; i <= sum; i++) {
		
		out[index] = i;
		
		find_k_sums_utol(n, sum - i, out, index + 1, a, sums);
	}
}


void find_k_sums(int n, int sum, vector<long long int>& a, multiset<long long int>& sums) {
	
	vector<int> out(n);
	
	for (int i = 0; i <= sum; i++) {
		out[0] = i;
		find_k_sums_utol(n, sum - i, out, 1, a, sums);
	}
}

void test_k_sums() {
	int n = 1, sum = 3;

	//findNDigitNums(n, sum);
}

void repetitive_k_sums() {
	
	int t;
	cin >> t;

	for (int l = 0; l < t; l++) {
		int n, k;

		cin >> n >> k;
		
		multiset<long long int> sums;

		{
			timethis t("parser");
			string s;
			getline(cin, s);
			getline(cin, s);

			string::size_type prev_pos = 0, pos = 0;

			while ((pos = s.find(' ', pos)) != string::npos)
			{
				string substring(s.substr(prev_pos, pos - prev_pos));

				sums.insert(std::stoll(substring));

				prev_pos = ++pos;
			}

			sums.insert(stoll(s.substr(prev_pos, pos - prev_pos)));
		}

		
			
		{
			timethis t("solver");

			if (n == sums.size()) {
				for (auto num : sums) {
					cout << num / k  << " ";
				}
				cout << endl;
			} else {
				vector <long long int> a;


				while (a.size() < n && sums.size() > 0) {


					long long int a0;

					if (a.size() == 0)
						a0 = *sums.begin() / k;
					else
						a0 = *sums.begin() - (k - 1) * a[0];

					a.push_back(a0);

					// remove all sums;
					find_k_sums(a.size(), k, a, sums);
				}

				for (auto num : a) {
					cout << num << " ";
				}
				cout << endl;
			}			
		}

		

		
	}
}