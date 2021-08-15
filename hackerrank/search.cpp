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
#include <bitset>
#include <queue>
#include <iterator>  

#include "Utils.h"


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

//-----------------------------------------------------------------------------
void hacker_radio_transmitters() {
	int n, k;
	cin >> n >> k;

	vector<int> a;

	//a.push_back(0);

	read_array(a, n);

	sort(a.begin(), a.end());

	int transmitters = 0;
	int start_pos = 0;
	
	int i = 0;

	while (i < n) {
		transmitters++;
		int right_end = a[i] + k;

		while ((i < n) && (a[i] <= right_end))
			i++;

		// position of the transmitter 
		i--;

		right_end = a[i] + k;

		while ((i < n) && (a[i] <= right_end))
			i++;
	}

	cout << transmitters;
}

//-----------------------------------------------------------------------------
typedef long long int int64;

void gridland_metro() {
	int64 n, m, k;

	cin >> n >> m >> k;
		
	map<int64, vector<pair<int64, int64>>> rows;

	for (int64 l = 0; l < k; l++) {
	
		int64 r, c1, c2;

		cin >> r >> c1 >> c2;
	
		auto& row = rows[r];

		vector<pair<int, int>> b;

		bool add_new_track = true;

		for (int i = 0; i < row.size(); i++) {
		  // the new track is entirely inside an existing track
			if (row[i].first <= c1 && row[i].second >= c2) {

				for (int j = i; j < row.size(); j++)
					b.push_back(row[j]);

				add_new_track = false;
				break;
			}
			
			// track i is entirely in the new track, remove track i;
			if (row[i].first >= c1 && row[i].second <= c2) {				
			} else {
				b.push_back(row[i]);

				if (row[i].first <= c1 && c1 <= row[i].second) 
					c1 = row[i].second+1;
				
				if (row[i].first <= c2 && c2 <= row[i].second)
					c2 = row[i].first-1;
				
			}
		}

		if (add_new_track)
			b.push_back({ c1, c2 });

		row.assign(b.begin(), b.end());
	}

	int64 count = 0;
	for (auto a : rows) {
		int64 row_count = m;
		for (auto j = 0; j < a.second.size(); j++)
			row_count -= a.second[j].second - a.second[j].first+1;

		count += row_count;
	}

	count += (n - rows.size()) * m;

	cout << count;
}


//-----------------------------------------------------------------------------
typedef long long int int64;

struct num_index {
	int64 num, index;
	bool operator < (const num_index& b) const {
		return num < b.num;
	}
};


void minimum_loss() {
	int64 n;

	cin >> n;

	vector<num_index> a;

	for (int i = 0; i < n; i++) {
		num_index tmp;
		cin >> tmp.num;
		tmp.index = i + 1;

		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
		
	int64 min_price = LLONG_MAX;
	for (int i = 1; i < n; i++)
		if (a[i].index < a[i-1].index)
			//if (a[i].num > a[i - 1].num)
				min_price = min(min_price, a[i].num - a[i-1].num);

	cout << min_price;
}

//-----------------------------------------------------------------------------
void pairs() {
	int64 n, k;

	cin >> n >> k;

	set<int64> a;

	for (int i = 0; i < n; i++) {
		int64 tmp;
		cin >> tmp;

		a.insert(tmp);
	}

	int count = 0;

	for (auto it: a) {
		auto fnd = a.find(it + k);
		if (fnd != a.end())
			count++;
	}

	cout << count;
}


//-----------------------------------------------------------------------------
void count_region(int i, int j, vector<vector<int>>& matrix, int n, int m, int& count) {
	
	if (i < 0)  return;
	if (i >= n) return;

	if (j < 0) return;
	if (j >= m) return;

	if (matrix[i][j] != 1) return;

	count++;

	matrix[i][j] = 2; // mark as visited;

	// top
	count_region(i-1, j-1, matrix, n, m, count);
	count_region(i-1, j, matrix, n, m, count);
	count_region(i-1, j+1, matrix, n, m, count);

	// bottom
	count_region(i+1, j-1, matrix, n, m, count);
	count_region(i+1, j, matrix, n, m, count);
	count_region(i+1, j+1, matrix, n, m, count);

	// left, right
	count_region(i, j - 1, matrix, n, m, count);
	count_region(i, j + 1, matrix, n, m, count);
}

void connected_cells() {

	int n;
	cin >> n;
	

	int m;
	cin >> m;
	
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; i++) {
		matrix[i].resize(m);

		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (matrix[i][j] == 1) {
				int tmp_count = 0;
				count_region(i, j, matrix, n, m, tmp_count);
				count = max(tmp_count, count);
			}

	cout << count;
}

//-----------------------------------------------------------------------------
void short_palindrome() {
	string s;
	uint64 div = 1000000007L;
	cin >> s;

	uint64 sums[26][26][4] = { 0 };

	for (auto a : s) {
		int i = a - 'a';
		for (int j = 0; j < 26; j++) {

			sums[i][j][3] += sums[i][j][2] % div;
			sums[j][i][2] += sums[j][i][1] % div;
			sums[j][i][1] += sums[j][i][0] % div;
			sums[i][j][0]++;
		}
	}

	uint64 sum = 0;

	for (int i = 0; i < 26; i++) 
		for (int j = 0; j < 26; j++)
			sum += sums[i][j][3];

	cout << sum / div;
}

//-----------------------------------------------------------------------------

const int BOARD_SIZE = 25;

int board[BOARD_SIZE][BOARD_SIZE];

void clear_board(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = -1;
}

void knightl(int x, int y, int a, int b, int n, int num) {

	if (x < 0) return;
	if (y < 0) return;

	if (x > (n - 1)) return;

	if (y > (n - 1)) return;

	if (board[x][y] != -1) {
		if (board[x][y] <= num)
			return;
	}

	board[x][y] = num;

	int xm[8] = { a, -a, -a,  a, b, -b, -b,  b };
	int ym[8] = { b,  b, -b, -b, a,  a, -a, -a };

	for (int i = 0; i < 8; i++)
		knightl(x + xm[i], y + ym[i], a, b, n, num+1);
}

void knightl_on_chessboard() {
	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			clear_board(n);
			knightl(n - 1, n - 1, i, j, n, 0);
			cout << board[0][0] << " ";
		}
		cout << endl;
	}
}

//-----------------------------------------------------------------------------
const int RED_BOARD_SIZE = 201;

struct path_struct {
	int distance;
	int x, y;
	string path_str;
};


void red_knight() {
	int n;

	cin >> n;

	int xs, ys, xe, ye;

	cin >> xs >> ys >> xe >> ye;
	queue <path_struct> qu;

	qu.push({ 0, xs, ys, "" });

	bool visited[RED_BOARD_SIZE][RED_BOARD_SIZE] = { false };

	visited[xs][ys] = true;
	int xm[6] = { -2, -2,  0, 2,  2,  0};
	int ym[6] = { -1,  1,  2, 1, -1, -2};
	string dirs[6] = { "UL", "UR", "R", "LR", "LL", "L" };

	while (!qu.empty()) {

		auto  p = qu.front(); 
		qu.pop();

		if (p.x == xe && p.y == ye) {
			cout << p.distance << endl;
			cout << p.path_str << endl;
			return;
		}

		for (int i = 0; i < 6; i++) {
			int xn = p.x + xm[i];
			int yn = p.y + ym[i];

			if ((xn >= 0) && (xn < n) && (yn >= 0) && (yn < n)) {
				if (visited[xn][yn] == false) {
					visited[xn][yn] = true;
					qu.push({ p.distance + 1, xn, yn, p.path_str + dirs[i] + " " });
				}
			}
		}
	}

	cout << "Impossible\n";
}

//-----------------------------------------------------------------------------
const int GRID_SIZE = 101;
typedef char grid_type[GRID_SIZE][GRID_SIZE];

struct grid_info {
	grid_type grid;
	int n, m;
	int xe, ye;
	int guess;
};

grid_info grid;
int xm[4] = { -1, 1,  0, 0 };
int ym[4] = { 0, 0, -1, 1 };

void count_moves(int xs, int ys, int changes) {
	int num_moves = 0;

	if (xs == grid.xe && ys == grid.ye)
		if (changes == grid.guess)
			cout << "Impressed" << endl;
		else
			cout << "Oops!" << endl;

	grid.grid[ys][xs] = 'X';

	for (int i = 0; i < 4; i++) {
		int xn = xs + xm[i];
		int yn = ys + ym[i];

		if ((xn >= 0) && (xn < grid.m) && (yn >= 0) && (yn < grid.n) && grid.grid[yn][xn] != 'X')
			num_moves++;
	}
			
	if (num_moves > 1)
		changes++;

	for (int i = 0; i < 4; i++) {
		int xn = xs + xm[i];
		int yn = ys + ym[i];

		if ((xn >= 0) && (xn < grid.m) && (yn >= 0) && (yn < grid.n) && grid.grid[yn][xn] != 'X')
			count_moves(xn, yn, changes);
	}
}

void count_luck() {
	
	int t;
	cin >> t;		

	for (int q = 0; q < t; q++) {
		
		cin >> grid.n >> grid.m;

		int xs, ys;// start position
		
		for (int i = 0; i < grid.n; i++) {
			for (int j = 0; j < grid.m; j++) {
				cin >> grid.grid[i][j];
				if (grid.grid[i][j] == 'M') {
					xs = j;
					ys = i;
				}

				if (grid.grid[i][j] == '*') {
					grid.xe = j;
					grid.ye = i;
				}
			}				
		}	
				
		cin >> grid.guess;

		int changes = 0;
		bool found = false;

		count_moves(xs, ys, changes);		

	}
}

//-----------------------------------------------------------------------------
void beautiful_quadruples() {
	int a[4];

	cin >> a[0] >> a[1] >> a[2] >> a[3];
	
	sort(a, a+4);

	long long int count = 0;

	int max_num = pow(2, ceil(log2(a[3] + 1)));
	long long all_count = 0;

	vector<long long int> inner(max_num);
	for (int ic = 1; ic <= a[2]; ic++)		
		for (int id = ic; id <= a[3]; id++) {
			inner[ic ^ id] +=1;
			all_count +=1;
		}

	for (int ib = 1; ib <= a[1]; ib++) {
		for (int ia = 1; ia <= min(a[0], ib); ia++) {
			count += all_count - inner[ia ^ ib];
		}

		for (int id = ib; id <= a[3]; id++) {
			inner[ib ^ id] -= 1;
			all_count -= 1;
		}		
	}
		
	cout << count;
}

//-----------------------------------------------------------------------------
void moves_from_here(int mask, vector<int>& moves, map<int, bool>& states) {
	int poles[4] = { -1, -1, -1, -1 };

	// unpack mask and put the largest disk per pole
	for (int i = 0; i < 10; i++) {
		int disk = mask >> (i << 1);

		if (poles[3 & disk] == -1)
			poles[3 & disk] = i;
	}

	for (int i = 0; i < 4; i++) {

		if (poles[i] == -1) continue;
		
		for (int j = 0; j < 4; j++) {
			if (poles[j] == -1 || poles[i] < poles[j]) {
				int tmp = mask;
				tmp = tmp & (~(3 << (poles[i] << 1)));
				tmp |= (j << (poles[i] << 1));
				if (!states[tmp]) {
					states[tmp] = true;
					moves.push_back(tmp);
				}
			}
		}		
	}
}

long long int search_solutions(int state, map<int, bool>& states) {
	long long int ret = 0;
	vector<int> moves;
	moves.push_back(state);
			
	while (true) {

		ret++;
		vector<int> next;
		for (auto x : moves)
			moves_from_here(x, next, states);

		if (states[0])
			return ret;

		moves = next;
	}
}

void gena_hanoi() {

	int n;
	cin >> n;

	int state = 0;

	for (int i = 0; i < n; i++) {
		int disk;
		cin >> disk;
		disk--;
		state |= disk << (i << 1);
	}

	map<int, bool> states;
	states[state] = true;
	long long int ret = search_solutions(state, states);
	cout << ret;
}

//-----------------------------------------------------------------------------
void maximum_subarray_sum() {
	int q;

	cin >> q;

	while (q--) {
		int n, m;

		cin >> n >> m;

		vector<int> ar;
		read_array(ar, n);

		int sum = 0;
		int max_sum = 0;

		for (int i = 0; i < n; i++) {
			sum = (ar[i] + sum) % m;
			ar[i] = sum;
			max_sum = max(sum, max_sum);
		}

		if (max_sum == m - 1) {
			cout << max_sum << endl;
			continue;
		} 

		set<int> sorted;
		int min_mod = m+1;

		for (int i = 0; i < n; i++) {
			auto it = sorted.insert(ar[i]);
			it.first++;

			if (it.first != sorted.end())
				min_mod = min(*it.first - ar[i], min_mod);
		}

		cout << max(max_sum, m - min_mod) << endl;
	}
}