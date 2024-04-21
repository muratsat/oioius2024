#include <bits/stdc++.h>
using namespace std;

static int a[3][3] = {
	{ 1, 2, 3 },
	{ 1, 2, 3 },
	{ 1, 2, 3 }
};

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int> > cars;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cars.push_back(make_pair(x, y));
	}

	sort(cars.begin(), cars.end());

	for (int i = 0; i < n; i++) {
		pair<int,int> car = cars[i];
		cout << car.first << ' ';
		cout << car.second << '\n';
	}
	
	vector<int> gaps;
	vector<int> to_move;
    int idx = 0;
    
	for (int i = 0; i < n; i++) {
	    
    }

}


int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}
