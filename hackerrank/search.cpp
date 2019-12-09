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

//-----------------------------------------------------------------------------
void find_indexes(int n, int m, vector <int>& ar) {

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (ar[i] + ar[j] == m) {
				cout << i + 1 << " " << j + 1 << endl;
				return;
			}
}

void ice_cream_parlor() {

	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		int m, n;

		cin >> m;
		cin >> n;

		vector <int> ar;	
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			ar.push_back(tmp);		
		}

		find_indexes(n, m, ar);					
	}
}

//-----------------------------------------------------------------------------
void read_multi_set(int n, multiset<int>& ms) {
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ms.insert(tmp);
	}
}


void missing_numbers() {

	int n;
	cin >> n;

	int min_number = 10001;
	int max_number = 0;

	vector<int> missing;
	

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		missing.push_back(tmp);
		min_number = min(min_number, tmp);
		max_number = max(max_number, tmp);
	}
	
	int m;
	cin >> m;
	const int cMagic = 10001;

	vector<int> original;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		original.push_back(tmp);
		min_number = min(min_number, tmp);
		max_number = max(max_number, tmp);
	}

	int count[100];
	for (int i = 0; i < 100; i++)
		count[i] = cMagic;

	for (auto i : missing)
		if (count[i - min_number] == cMagic)
			count[i - min_number] = -1;
		else 
			count[i - min_number] --;
	
	for (auto i : original)
		count[i - min_number] ++;

	for (int i = 0; i < 100; i++)
		if (count[i] != 0 && count[i] != cMagic)
			if (i + min_number <= max_number)
				cout << i + min_number  << " ";
}

//-----------------------------------------------------------------------------
string balancedSums(vector<int> arr) {

	int sum = 0;
	for (auto i : arr)
		sum += i;

	int sum_left = 0;
	int sum_right = sum;
	for (int i = 0; i < arr.size(); i++) {

		sum_right -= arr[i];

		if (sum_left == sum_right)
			return "YES";
		
		sum_left += arr[i];
		
	}
	
	return "NO";
}

void sherlock_and_array() {
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;

		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}

		string result = balancedSums(arr);

		cout << result << endl;

	}
}


int minimumAbsoluteDifference(vector<int> arr) {
	sort(begin(arr), end(arr));
	
	int minv = pow(10, 9) + 1;

	for (int i = 0; i < arr.size() - 1; i++) {
		int abs_v = abs(arr[i] - arr[i + 1]);
		minv = min(minv, abs_v);
	}

	return minv;
}