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

#include <fstream>

using namespace std;

typedef unsigned long long int uint64;

//-----------------------------------------------------------------------------
void find_absent_students() {

	int n;

	int mask[101] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0 && tmp <= n)
			mask[tmp] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (mask[i] == 0)
			cout << i << " ";
}

//-----------------------------------------------------------------------------
void members_in__the_largest_group() {
	int n; // total number of students
	int m; // number of requests

	int a, b; // minimum and maximum number of students in a group, respectively.

	int f, s, t; // maximum number of first, second and third grade students in a group, respectively. 
}

//-----------------------------------------------------------------------------
bool get_parent_list_for(int start_node, int end_node, vector<int>& parents, vector<int>& output) {

	output.push_back(start_node);

	int parent = parents[start_node];

	while ((parent !=1) && (parent != end_node)) {
		output.push_back(parent);
		parent = parents[parent];
	}
	
	output.push_back(parent);

	if (parent == end_node)
		return true;

	return false;
}


void get_kth_black_node(int k, vector<int>& nodes, vector<int>& values) {
	
	int count = 0;

	if (k > nodes.size()) {
		cout << "-1" << endl;
		return;
	}

	for (int i = 0; i < nodes.size(); i++) {
		if (values[nodes[i]] == 1) {
			count++;
			if (count == k) {
				cout << nodes[i] << endl;
				return;
			}

		}
	}
	
	cout << "-1" << endl;
}

void dynamic_tree() {

	int n; // number of nodes
	int q; // number of queries

	cin >> n;

	cin >> q;

	vector<int> values;
	vector<int> parents;

	values.push_back(0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		values.push_back(tmp);
	}

	parents.push_back(0);
	parents.push_back(0);
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;

		parents.push_back(tmp);
	}

	// read and process the queries
	for (int i = 0; i < q; i++) {
		char command;

		cin >> command;

		switch(command) {
			case 'T': {
				int node;
				cin >> node;

				if ((node >= 1) && (node <= n)) {
					if (values[node] == 1)
						values[node] = 0;
					else {
						if (values[node] == 0)
							values[node] = 1;
					}
				}			
				
			} break;

			case 'C': {
				int u, v;  // set the new parent of u to be v;

				cin >> u >> v;
								
				if ((u <= n) && (u >= 1))
					parents[u] = v;
			} break;

			case 'K': {

				int u, v, k; // Output the k-th black node on the simple path from u to v in the tree

				cin >> u >> v >> k;

				if (!((u <= n) && (u >= 1)))
					break;

				if (!((v <= n) && (v >= 1)))
					break;
				
				vector<int> output_u;

				bool find_u_to_v = get_parent_list_for(u, v, parents, output_u);

				if (find_u_to_v) {
					get_kth_black_node(k, output_u, values);
					break;
				}

				vector<int> output_v;
				bool find_v_to_u = get_parent_list_for(v, u, parents, output_v);

				if (find_v_to_u) {
					reverse(std::begin(output_v), std::end(output_v));
					get_kth_black_node(k, output_v, values);
					break;
				}

				// merge the 2 arrays

				for (int i = output_v.size() - 2; i >= 0; i--)
					output_u.push_back(output_v[i]);

				get_kth_black_node(k, output_u, values);

			} break;
		}
	}
}