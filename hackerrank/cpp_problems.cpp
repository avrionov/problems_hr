
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
#include <sstream>

#include <fstream>



using namespace std;

typedef unsigned long long int uint64;


//-----------------------------------------------------------------------------
void input_output() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b + c;
}

//-----------------------------------------------------------------------------
void basic_data_types() {
	int int_v;
	long long int long_v;
	char char_v;
	float float_v;
	double double_v;

	cin >> int_v >> long_v >> char_v >> float_v >> double_v;

	cout << int_v << endl;
	cout << long_v << endl;
	cout << char_v << endl;
	cout << std::setprecision(3) << std::fixed << float_v << endl;
	cout << std::setprecision(9) << std::fixed << double_v << endl;
}

//-----------------------------------------------------------------------------
void conditional_statements() {
	int n;

	cin >> n;

	if (n > 9)
		cout << "Greater than 9";
	else {
		if (n > 0) {
			std::vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
			cout << nums[n-1];
		}
	}
}

//-----------------------------------------------------------------------------
void for_loop() {

	std::vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (i > 0) {
			if (i > 9) {
				if (i % 2 == 0)
					cout << "even" << endl; 
				else 
					cout << "odd" << endl;
			} else {
				cout << nums[i - 1] << endl;
			}
		}
	}
}

int max_of_four(int a, int b, int c, int d) {
	int tmp = max(a, b);

	tmp = max(c, tmp);
	tmp = max(d, tmp);

	return tmp;
}

//-----------------------------------------------------------------------------
void functions() {
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	cout << max_of_four(a, b, c, d);
}

//-----------------------------------------------------------------------------
// pointers challange
void update(int *a, int *b) {
	
	int val1 = *a + *b;
	int val2 = abs(*a - *b);

	*a = val1;
	*b = val2;
}

//-----------------------------------------------------------------------------
void array_introduction() {

	int n;
	vector<int> ar;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ar.push_back(tmp);
	}

	for (int i = n - 1; i >= 0; i--)
		cout << ar[i] << " ";
}

//-----------------------------------------------------------------------------
void variable_size_arrays() {
	int n, q;

	cin >> n >> q;

	std::vector<std::vector<int>> ar;
	
	string line;
	
	for (int i = 0; i < n; i++) {
	
	
		vector<int> tmp_ar;

		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			tmp_ar.push_back(tmp);
		}

		ar.push_back(tmp_ar);
	}

	for (int l = 0; l < q; l++) {
		int i, j;

		cin >> i >> j;

		if (i >= 0 && i < ar.size()) {
			vector<int>& tmp_ar = ar[i];
			if (j >= 0 && j < tmp_ar.size()) {
				cout << tmp_ar[j] << endl;
			}
		}
	}
}

//-----------------------------------------------------------------------------
// string stream
vector<int> parseInts(string str) {
	vector<int> integers;

	std::stringstream ss(str);
	int i;
	char ch;
	do
	{
		ss >> i;
		integers.push_back(i);
	} while (ss >> ch);

	//while (ss >> i) //Extract integers from line
	//	integers.push_back(i);
	return integers;
}

//-----------------------------------------------------------------------------
void strings() {
	string a, b;

	cin >> a;
	cin >> b;

	cout << a.size() << " " << b.size() << endl;
	cout << a + b << endl;

	if (a.size() > 0 && b.size() > 0) {
		char tmp = a[0];
		a[0] = b[0];
		b[0] = tmp;
	}
	
	cout << a << " " << b << endl;
}

