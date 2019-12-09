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

using namespace std;

//-----------------------------------------------------------------------------
string gridChallenge(vector<string> grid) {

	int n = grid.size();

	for (int i = 0; i < n ; i++)
		sort(begin(grid[i]), end(grid[i]));

	for (int i = 0; i < n ; i++)
		for (int j = 0; j < n-1; j++)
			if (grid[j][i] > grid[j + 1][i])
				return "NO";

	return "YES";
}


void grid_challange() {
	int t;

	cin >> t;
	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;

		vector <string> grid;

		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;			
			grid.push_back(tmp);
		}
	}
}


//-----------------------------------------------------------------------------
int luckBalance(int k, vector<vector<int>> contests) {

	int sum = 0;

	vector <int> important;

	for (auto i : contests) {
		if (i[1] == 0)
			sum += i[0];
		else
			important.push_back(i[0]);
	}

	sort(begin(important), end(important), greater<int>());
	for (int i = 0; i < min(static_cast<int>(important.size()),k); i++)
		sum += important[i];

	for (int i = k; i < important.size(); i++)
		sum -= important[i];

	return sum;
}

void luck_balance() {
	int n, k;

	cin >> n >> k;

	vector<vector<int>> contests(n);
	for (int i = 0; i < n; i++) {
		contests[i].resize(2);

		for (int j = 0; j < 2; j++) {
			cin >> contests[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = luckBalance(k, contests);
}


void maximum_perimeter_triangle() {

	int n;
	cin >> n;
	vector<int> sticks(n);
	for (int i = 0; i < n; ++i) 
		cin >> sticks[i];

	sort(begin(sticks), end(sticks), greater<int>());

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				if ((sticks[i] < sticks[j] + sticks[k]) &&
					(sticks[j] < sticks[i] + sticks[k]) &&
					(sticks[k] < sticks[j] + sticks[i])) {
					cout << sticks[k] << " " << sticks[j] << " " << sticks[i];
					return;
				}

	cout << -1 << endl;
}

//-----------------------------------------------------------------------------
bool sort_function(vector<long>& i, vector<long>& j) {
	
	if (i[0] == j[0])
		return (i[1] < j[1]);

	return (i[0] < j[0]); 
}

vector<int> jimOrders(vector<vector<int>> orders) {

	auto n = orders.size();

	vector<vector<long>> srt(n);

	for (int i = 0; i < n; i++ ) {
		srt[i].resize(2);
		srt[i][0] = orders[i][0] + orders[i][1];
		srt[i][1] = i + 1;
		
    }

	sort(begin(srt), end(srt), sort_function);

	vector<int> res;

	for (auto i : srt) {
		res.push_back(i[1]);
	}

	return res;
}

void jim_orders() {

	int n;
	cin >> n;
	

	vector<vector<int>> orders(n);
	for (int i = 0; i < n; i++) {
		orders[i].resize(2);

		for (int j = 0; j < 2; j++) {
			cin >> orders[i][j];
		}	
	}

	vector<int> result = jimOrders(orders);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << " ";
		}
	}

	cout << endl;
}

//-----------------------------------------------------------------------------
void decentNumber(int n) {

	int num_5 = 0;
	int num_3 = 0;

	for (int i = n; i >= 0; i--) {
		if ((i % 3 == 0) && ((n - i) % 5 == 0)) {
			num_5 = i;
			num_3 = n-i;
			break;
		}			
	}

	if (num_5 == 0 && num_3 == 0) {
		cout << "-1" << endl;
		return;
	}

	for (int i = 0; i < num_5; i++)
		cout << "5";

	for (int i = 0; i < num_3; i++)
		cout << "3";
		
	cout << endl;
}

//-----------------------------------------------------------------------------
int toys(vector<int> w) {
	
	sort(begin(w), end(w));

	int count = 1;

	int start_w = w[0];
	int end_W = start_w + 4;

	for (auto i : w) {
		if (! (i >= start_w && i <= end_W)) {
			count++;
			start_w = i;
			end_W = start_w + 4;
		}

	}

	return count;
}


//-----------------------------------------------------------------------------
int maximumToys(vector<int> prices, int k) {

	sort(begin(prices), end(prices));

	int count = 0;
	int sum = 0;
	for (auto i : prices) {
		if (i + sum <= k) {
			sum += i;
			count++;
		} else  {
			break;
		}
	}

	return count;
}