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


//-----------------------------------------------------------------------------
char ashtonString(string s, int k) {
    
    vector<string> substrings;
    int sum = 0;
    k--;
    
    for (char ch = 'a'; ch <='z'; ch++) {
        for (int i = 0; i < s.length(); i++) {
            if (ch == s[i]) {
                string sub = s.substr(i, s.length()-1);
                substrings.push_back(sub);
            }
                
               /* for (int j = 1; j < s.length() - i+1; j++) {
                    string sub = s.substr(i, j);
                    substrings.push_back(sub);
                }*/
        }
        
        sort (begin(substrings), end(substrings));
        substrings.erase( unique( substrings.begin(), substrings.end() ), substrings.end() );
        
        for (auto str: substrings) {
            auto len = str.length();
            if ((sum + len) > k ) {
                k -= sum;
                return str[k];
            }
            sum += len;
        }
        
        substrings.clear();
    }
    
    /*
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j < s.length() - i+1; j++) {
            string sub = s.substr(i, j);
            substrings.push_back(sub);
        }
    }

    sort (begin(substrings), end(substrings));
    substrings.erase( unique( substrings.begin(), substrings.end() ), substrings.end() );
    
    int sum = 0;
    k--;
    for (auto str: substrings) {
        auto len = str.length();
        if ((sum + len) > k ) {
            k -= sum;
            return str[k];
        }
        sum += len;
    }
    */
    
    
    return ' ';
}

struct build_suffix_naive {


	// Structure to store information of a suffix 
	struct suffix
	{
		int index;
		char* suff;
	};

	// A comparison function used by sort() to compare two suffixes 
	static int cmp(struct suffix& a, struct suffix& b)
	{
		return strcmp(a.suff, b.suff) < 0 ? 1 : 0;
	}

	// This is the main function that takes a string 'txt' of size n as an 
	// argument, builds and return the suffix array for the given string 
	static void buildSuffixArray(const char* txt, int n, vector<int>& suffix_ar)
	{
		// A structure to store suffixes and their indexes 
		//struct suffix suffixes[n];

		vector<struct suffix> suffixes(n);

		// Store suffixes and their indexes in an array of structures. 
		// The structure is needed to sort the suffixes alphabatically 
		// and maintain their old indexes while sorting 
		for (int i = 0; i < n; i++)
		{
			suffixes[i].index = i;
			suffixes[i].suff = const_cast<char*> (txt + i);
		}

		// Sort the suffixes using the comparison function 
		// defined above. 
		//sort(suffixes, suffixes + n, cmp);
		sort(begin(suffixes), end(suffixes), build_suffix_naive::cmp);

		// Store indexes of all sorted suffixes in the suffix array 
		
		suffix_ar.resize(n);
		for (int i = 0; i < n; i++)
			suffix_ar[i] = suffixes[i].index;		
	}
};

struct build_suffix_logn2 {

	struct suffix {
		int index;
		int rank[2];
	};

	static bool cmp(struct suffix a, struct suffix b) {
		return ((a.rank[0] < b.rank[0]) || (a.rank[0] == b.rank[0] && a.rank[1] < b.rank[1]));
	} 

	static int* buildSuffixArray(const char* txt, int n) {
		int i, k, rank, next_index, prev_rank;
		int* ind = new int[n];
		struct suffix* suffixes = new struct suffix[n];
		for (i = 0; i < n; i++) {
			suffixes[i].index = i;
			suffixes[i].rank[0] = txt[i] - 'a';
			suffixes[i].rank[1] = (i + 1 < n) ? txt[i + 1] - 'a' : -1;
		}
		sort(suffixes, suffixes + n, cmp);
		for (k = 4; k < 2 * n; k *= 2) {
			rank = 0;
			prev_rank = suffixes[0].rank[0];
			suffixes[0].rank[0] = rank;
			ind[suffixes[0].index] = rank;
			for (i = 1; i < n; i++) {
				prev_rank = suffixes[i].rank[0];
				if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
					suffixes[i].rank[0] = rank;
				}
				else {
					suffixes[i].rank[0] = rank + 1;
					++rank;
				}
				ind[suffixes[i].index] = rank;
			}
			for (i = 0; i < n; i++) {
				next_index = suffixes[i].index + k / 2;
				suffixes[i].rank[1] = (next_index < n) ? ind[next_index] : -1;
			}
			sort(suffixes, suffixes + n, cmp);
		}
		int* suffixArr = new int[n];
		for (i = 0; i < n; i++) {
			suffixArr[i] = suffixes[i].index;
		}
		free(ind);
		free(suffixes);
		return suffixArr;
	}
};

//-----------------------------------------------------------------------------
struct suffix {
	int index;
	int rank[2];
};


int cmp(struct suffix& a, struct suffix& b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
		(a.rank[0] < b.rank[0] ? 1 : 0);
}


void buildSuffixArray(const char* txt, size_t n, vector<int>& suffix_ar) {

	vector<struct suffix> suffixes(n);

	for (size_t i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
	}

	sort(begin(suffixes), end(suffixes), cmp);

	vector<int> ind(n);

	for (size_t k = 4; k < 2 * n; k = k * 2) {

		size_t rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for (size_t i = 1; i < n; i++) {
			if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		for (size_t i = 0; i < n; i++) {
			size_t nextindex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextindex < n) ?
				suffixes[ind[nextindex]].rank[0] : -1;
		}
		sort(begin(suffixes), end(suffixes), cmp);
	}

	suffix_ar.resize(n);
	for (size_t i = 0; i < n; i++) {
		suffix_ar[suffixes[i].index] = i;
	}
}


bool select_from_first(string& A, int indexA, string& B, int indexB, vector<int>& ranks, int len_a) {
	return (indexB == B.length()) ||
		((indexA < len_a) && ranks[indexA] < ranks[indexB + 1 + len_a]);
}

void morgan_and_a_string() {
	int n;

	cin >> n;

	while (n > 0) {
		string s1;
		string s2;

		cin >> s1 >> s2;

		auto len_s1 = s1.length();
		auto len_s2 = s2.length();

		const char DIV = 'Z' + 1;

		int i_s1 = 0;
		int i_s2 = 0;

		string combined_ar = s1 + DIV + s2 + DIV;

		vector<int> suf_ar;
		buildSuffixArray(combined_ar.c_str(), combined_ar.length(), suf_ar);

		string s;

		for (size_t i = 0; i < len_s1 + len_s2; i++) {
			if (select_from_first(s1, i_s1, s2, i_s2, suf_ar, len_s1)) {
				s.push_back(s1[i_s1]);
				i_s1++;
			}
			else {
				s.push_back(s2[i_s2]);
				i_s2++;
			}
		}

		cout << s << endl;
		n--;
	}
}


//-----------------------------------------------------------------------------
void ashton_and_string() {
	int t, k;
	string s;

	cin >> t;
	cin >> s;
	cin >> k;

	vector<int> suf_ar;
	buildSuffixArray(s.c_str(), s.length(), suf_ar);
}

/* To construct and return LCP */
vector<int> kasai(string txt, vector<int> suffixArr) {
	int n = suffixArr.size();

	// To store LCP array 
	vector<int> lcp(n, 0);

	// An auxiliary array to store inverse of suffix array 
	// elements. For example if suffixArr[0] is 5, the 
	// invSuff[5] would store 0.  This is used to get next 
	// suffix string from suffix array. 
	vector<int> invSuff(n, 0);

	// Fill values in invSuff[] 
	for (int i = 0; i < n; i++)
		invSuff[suffixArr[i]] = i;

	// Initialize length of previous LCP 
	int k = 0;

	// Process all suffixes one by one starting from 
	// first suffix in txt[] 
	for (int i = 0; i < n; i++)
	{
		/* If the current suffix is at n-1, then we don’t
		   have next substring to consider. So lcp is not
		   defined for this substring, we put zero. */
		if (invSuff[i] == n - 1)
		{
			k = 0;
			continue;
		}

		/* j contains index of the next substring to
		   be considered  to compare with the present
		   substring, i.e., next string in suffix array */
		int j = suffixArr[invSuff[i] + 1];

		// Directly start matching from k'th index as 
		// at-least k-1 characters will match 
		while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
			k++;

		lcp[invSuff[i]] = k; // lcp for the present suffix. 

		// Deleting the starting character from the string. 
		if (k > 0)
			k--;
	}

	// return the constructed lcp array 
	return lcp;
}


//-----------------------------------------------------------------------------
void find_string() {

	int n;
	cin >> n;

	vector<string> strs;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		strs.push_back(tmp);
	}

	set<string> uniques;

	// generate all strings

	for (auto str : strs) {
		for (int i = 0; i < str.size(); i++) {
			string tmp;

			tmp.reserve(2000);
			for (int j = i; j < str.size(); j++) {
				tmp = tmp + str[j];
				uniques.insert(tmp);
				//uniques.insert(str.substr(i, j));
			}
			
		}

		// test suffix array

		vector<int>suffixArr;
		buildSuffixArray(str.c_str(), str.length(), suffixArr);
		int n = suffixArr.size();

		vector<int>suffixArr2;
		build_suffix_naive::buildSuffixArray(str.c_str(), str.length(), suffixArr2);

		int* suffixArr3 = build_suffix_logn2::buildSuffixArray(str.c_str(), str.length());
		//cout << "Suffix Array : \n";
		//printArr(suffixArr, n);

		vector<int>lcp = kasai(str, suffixArr);
		vector<int>lcp2 = kasai(str, suffixArr2);
	}

	int q;

	cin >> q;

	for (int k = 0; k < q; k++) {
		int tmp;

		cin >> tmp;

		tmp--;

		if (tmp > uniques.size()) {
			cout << "INVALID" << endl;
		}
		else {
			auto it = next(uniques.begin(), tmp);
			cout << *it << endl;
		}
	}
}
