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
#include <numeric>

#include "Utils.h"

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


void permuting_two_arrays() {

	int t;

	cin >> t;

	for (int t1 = 0; t1 < t; t1++) {

		int n, k;

		cin >> n >> k;
		
		vector<int> a;
		vector<int> b;
		read_array(a, n);
		read_array(b, n);

		//int ac[1000] = { 0 };
		//int bc[1000] = { 0 };

		map<int, int> ac, bc;

		for (int i = 0; i < n; i++) {
			ac[a[i]]++;
			bc[b[i]]++;
		}

		bool bPossible = true;

		for (auto i: ac) {
			int greater = k - i.first;

			auto bc_start = bc.lower_bound(greater);

			if (bc_start == bc.end()) {
				bPossible = false;
				break;
			}

			int count = 0;

			while (count < i.second && bc_start != bc.end()) {
				count += bc_start->second;
				bc_start++;
			}

			if (count < i.second) {
				bPossible = false;
				break;
			}			
		}

		if (bPossible)
			for (auto i : bc) {
				int greater = k - i.first;

				auto ac_start = ac.lower_bound(greater);

				if (ac_start == ac.end()) {
					bPossible = false;
					break;
				}

				int count = 0;

				while (count < i.second && ac_start != ac.end()) {
					count += ac_start->second;
					ac_start++;
				}

				if (count < i.second) {
					bPossible = false;
					break;
				}
			}

		if (bPossible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

void largest_permutation () {

	int n, k;

    cin >> n >> k;

    vector<int> a;
    read_array(a, n);

	vector<int> ac;
	ac.resize(n+1);

    for (int i = 0; i < n; i++) {
        ac[a[i]] = i; // store the position
    }

	int i = 0;
	int current_number = n;
	while (k > 0 && i < n) {
		if (a[i] == current_number) {// don't swap the element is in place
			i++;
			current_number--;
		} else {
			// find the number in the array and swap it
			int pos = ac[current_number];

			
		//		cout << pos << ", " << current_number << endl;
			

			swap(a[i], a[pos]);

		
			// adjust the indexes
			ac[a[i]] = i;
			ac[a[pos]] = pos;
			current_number--;
			i++;
			k--;
		}
	}


	for (auto i : a) {
		cout << i << " ";
	}
}

void beatufil_pairs() {

	int n;

	cin >> n;

	vector<int> a, b;
	read_array(a, n);

	read_array(b, n);

	map<int, int> map_a, map_b;

	// ordered count of numbers
	for (int i = 0; i < n; i++) {
		map_a[a[i]]++;
		map_b[b[i]]++;
	}

	int pairs = 0;
	bool different_counts = false;
	for (auto i : map_a) {

		auto b_it = map_b.find(i.first);

		if (b_it != map_b.end()) {
			pairs += min(i.second, b_it->second);

			if (i.second != b_it->second)
				different_counts = true;
		} else {
			different_counts = true;
		}
		
	}

	if (different_counts)
		cout << pairs + 1;
	else
		cout << pairs - 1;
}



void goodland_electricity() {
	int n, k;
	cin >> n >> k;

	vector<int> a;

	read_array(a, n);
	int plants = 0;

	int start_pos = 0;
	int new_pos = 0;
	while (start_pos < n) {
		
		new_pos = min(start_pos + k-1, n - 1);

		while ( (start_pos - k + 1) <= new_pos && a[new_pos] == 0) {
			new_pos--;
		}

		if (new_pos < start_pos - k + 1) {
			cout << -1;
			return;
		}

		plants++;
		start_pos = new_pos + k;		
	}

	cout << plants;
}

void goodland_electricity3() {
	int k, n, x;
	cin >> n >> k;
	int start_pos, new_pos, ans = 0;

	vector<int> a;

	read_array(a, n);

	start_pos = 0;
	while (start_pos < n) {
		ans++;
		new_pos = min(n - 1, start_pos + k - 1);

		while (start_pos - k + 1 <= new_pos && a[new_pos] == 0) new_pos--;

		if (new_pos < start_pos - k + 1) {
			cout << -1;
			return ;
		}
		else start_pos = new_pos + k;
	}
	cout << ans;
}

void goodland_electricity1() {
	int n, k;
	cin >> n >> k;

	vector<int> a;

	a.push_back(0);

	read_array(a, n);

	int plants = 0;
	int start_pos = -1;
	bool b_first = true;
	while (true) {
		int new_pos;

		if (b_first == true)
			new_pos = start_pos + k  ;
		else
			new_pos = start_pos + 2* k - 1;
		
		if (new_pos >= n)
			new_pos = n - 1;

		int neg_count = 0;
		while (a[new_pos] == 0 && neg_count <= k) {
			new_pos--;
			neg_count++;
		}

		if (neg_count > k) {
			cout << -1;
			return;
		}

		plants++;
		start_pos = new_pos;
		cout << start_pos << " " << a[start_pos] << endl;
		if (start_pos + k >= n)
			break;

		b_first = false;
	}

	cout << plants;
}

//-----------------------------------------------------------------------------
void greedy_florist() {

	int num_friends, num_flowers;

	cin >>  num_flowers >> num_friends;

	vector<int> flowers (num_flowers);

	for (int i = 0; i < num_flowers; i++) {
		cin >> flowers[i];
	}

	sort(flowers.begin(), flowers.end(), greater<int>());

	long long int sum = 0;

	for (int i = 0; i < num_flowers; i++) {
		sum += (1 + i / num_friends) * flowers[i];
	}

	cout << sum;
}

//-----------------------------------------------------------------------------
void candies() {
	int n;

	cin >> n;

	vector<int> scores(n);

	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	vector<long long int> candies(n);

	long long int candy = 1;
	candies[0] = candy;

	for (int i = 1; i < n; i++) {
		if (scores[i - 1] < scores[i])
			candy++;
		else
			candy = 1;
		candies[i] = candy;	
	}
	candy = 1;
	long long int sum = candies[n - 1];

	for (int i = n-2; i >= 0; i--) {
		if (scores[i] > scores[i + 1]) 
			candy++;
		else 
			if (scores[i] <= scores[i + 1]) candy = 1;

		candies[i] = max(candy, candies[i]);
		sum += candies[i];
	}

	cout << sum;
}

//-----------------------------------------------------------------------------
void max_min() {

	int n, k;
	
	cin >> n >> k;

	vector<int> ar(n);

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort(ar.begin(), ar.end());

	int fair_sum = INT_MAX;

	for (int i = 0; i < n-k; i++) {
		fair_sum = min(fair_sum, ar[i + k -1 ] - ar[i]);
	}

	cout << fair_sum;
}

//-----------------------------------------------------------------------------
const int maxn = 1e5 + 5;

const int no_cloud = -5;
const int two_or_more_clouds = -4;

typedef long cloudtype;

struct town {
	cloudtype loc, population, covered, cloud;

	bool operator < (const town& t) {
		return loc < t.loc;
	}

};

town towns[maxn];

bool operator < (town const& ms, cloudtype const i)
{
	return ms.loc < i;
}

struct cloud {
	cloudtype left, right;
	bool operator < (const cloud& t) {
		return left < t.left;
	}

	bool remove;
};


void cloudy_day() {

	int n;
	cin >> n;

	vector<town> towns (n);

	for (int i = 0; i < n; i++) {
		cloudtype tmp;
		cin >> tmp;	
		towns[i].population = tmp;
		towns[i].covered = 0;		
		towns[i].cloud = no_cloud;
	}

	for (int i = 0; i < n; i++) {
		cloudtype tmp;
		cin >> tmp;
		towns[i].loc = tmp;		
	}

	sort(towns.begin(), towns.end());

	int dup_count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (towns[i].loc == towns[i + 1].loc)
			dup_count++;
	}

	int m;
	cin >> m;
		
	vector<cloud> clouds(m);

	for (int i = 0; i < m; i++) {
		cloudtype tmp;
		cin >> tmp;		
		clouds[i].left = tmp;
		clouds[i].right =tmp;		
	}

	int big_clouds = 0;	
	for (int i = 0; i < m; i++) {
		cloudtype tmp;
		cin >> tmp;
		clouds[i].left = min(1L, clouds[i].left - tmp);
		clouds[i].right += tmp;		
	}

	//sort(clouds.begin(), clouds.end());
	//sort(clouds, clouds+m);

	int covered_by_two = 0;
	for (int i = 0; i < m; i++) {

		cloudtype& rb = clouds[i].left, re = clouds[i].right;

		vector<town>::iterator it;

		if (rb <= towns[0].loc)
			it = towns.begin();
		else {
				it = lower_bound(towns.begin(), towns.end(), rb);
				if (it == towns.end())
					continue;
		}
			
		while (it != towns.end() && it->loc >= rb && it->loc <= re) {
			//it->covered++ ;
			if (it->cloud == no_cloud)
				it->cloud = i;
			else
				if (it->cloud >= 0) {
					it->cloud = two_or_more_clouds;
					covered_by_two++;
					if (covered_by_two == n) {
						cout << 0 << endl;
						return;
					}
				}
			it++;
		}
	}

	vector<town> towns2;

	long long int pop_sun = 0;
	for (int i = 0; i < n; i++) {
	/*	if (towns[i].covered == 0)
			pop_sun += towns[i].population;
		if (towns[i].covered == 1)
			towns2.push_back(towns[i]);*/
		if (towns[i].cloud == no_cloud)
			pop_sun += towns[i].population;
		else 
			if (towns[i].cloud  >= 0)
				towns2.push_back(towns[i]); 
	}
					
	long long int max_pop_sun = pop_sun;

	if (towns2.size())
		for (int i = 0; i < m; i++) {

			long long rb = clouds[i].left, re = clouds[i].right;

			long long int cloud_count = 0;
			
			auto it = lower_bound(towns2.begin(), towns2.end(), rb);
			if (it == towns2.end()) continue;
				
			while (it != towns2.end() && it->loc >= rb && it->loc <= re) {
				if (towns[i].cloud >= 0)
					cloud_count += it->population;
			
				it++;
			}

			max_pop_sun = max(max_pop_sun, pop_sun + cloud_count);
		}

	cout << max_pop_sun << endl;
}