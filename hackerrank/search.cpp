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

//-----------------------------------------------------------------------------

typedef long long int int64;
struct Node {
	vector<int> children;
	int value;
	int64 sum;
	int64 children_sum;

	bool isLeaf() {
		return children.size() == 0;
	}
};

int64  calculate_sum(int current_node, int parent, vector<Node>& nodes) {
	
	if (parent != 0)
		if (nodes[current_node].children.size() == 1)
			{
				nodes[current_node].sum = nodes[current_node].value;
				return nodes[current_node].sum;
			}

	int64 sum = 0;
	for (auto ch : nodes[current_node].children) {
		if (parent != ch) {
			int64 tmp = calculate_sum(ch, current_node, nodes);
			sum += tmp;
		}		
	}

	nodes[current_node].children_sum = sum;
	nodes[current_node].sum = nodes[current_node].value + sum;

	return nodes[current_node].sum;
}



void  calculate_cut(int current_node, int parent, vector<Node>& nodes, int64 &min_cut, int64 parent_sum) {

	if (parent != 0)
		if (nodes[current_node].children.size() == 1)		
			return;
	
	for (auto ch : nodes[current_node].children) {
		if (parent != ch) {
			int64 tree1 = nodes[ch].sum;
			int64 tree2 = nodes[current_node].sum - nodes[ch].sum + parent_sum;
			int64 new_min = abs(tree1 - tree2);

			if (new_min < min_cut)
				min_cut = new_min;

			int64 new_sum = parent_sum + nodes[current_node].value;
			new_sum -= nodes[ch].sum;
			new_sum += nodes[current_node].children_sum;
			calculate_cut(ch, current_node, nodes, min_cut, new_sum);
		}
	}	
}

void cut_the_tree() {
	
	int n;
	cin >> n;

	vector<Node> nodes(n + 1);

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nodes[i + 1].value = tmp;
		nodes[i + 1].sum = 0;
		nodes[i + 1].children_sum = 0;
	}

	// read the vetices
	for (int i = 0; i < n - 1; i++) {
		int n1, n2;

		cin >> n1 >> n2;

		nodes[n1].children.push_back(n2);
		nodes[n2].children.push_back(n1);
	}

	calculate_sum(1, 0, nodes);

	int64 min_cut = LLONG_MAX;
	calculate_cut(1, 0, nodes, min_cut, 0);
	cout << min_cut;
}