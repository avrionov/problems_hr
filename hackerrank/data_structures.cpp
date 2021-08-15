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

vector<int> reverseArray(vector<int> a) {
	
	std::reverse(a.begin(), a.end());

	return a;
}

//-----------------------------------------------------------------------------

void dynamic_array() {

	int n, q;

	cin >> n >> q;

	long long int last_answer = 0;

	vector<vector<long long int>> seqs(n);

	while (q--) {

		long long int cmd, x, y;

		cin >> cmd >> x >> y;
		
		int index = (x ^ last_answer) % n;

		if (cmd == 1) {
			seqs[index].push_back(y);
		}

		if (cmd == 2) {
			int pos = y % seqs[index].size();
			last_answer = seqs[index][pos];
			cout << last_answer << endl;
		}
	}
}