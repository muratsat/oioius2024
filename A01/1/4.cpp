#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x;
	double y;
	Point(double X, double Y) {
		x = X;
		y = Y;
	}

	bool operator<(const Point& other) const {
		if (x == other.x) return y < other.y;
		return x < other.x;
	}
};


struct Line {
	int k;
	int b;

	Line(int K, int B) {
		k = K;
		b = B;
	}

	pair<bool, Point> intersect(const Line& l) const {
		if (k == l.k) {
			return make_pair(false, Point(0, 0));
		}
		double k1 = k, b1 = b, k2 = l.k, b2 = l.b;
		double y = (b2 * k1 - b1 * k2) / (k1 - k2);
		double x;
		if (k1 == 0) x = (y - b2) / k2;
		else x = (y - b1) / k1;

		return make_pair(true, Point(x, y));
	}
};

set<Point> intersections(const vector<Line>& lines) {
	int n = lines.size();
	set<Point> isections;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pair<bool, Point> res = lines[i].intersect(lines[j]);
			bool exist = res.first;
			if (exist) isections.insert(res.second);
		}
	}

	return isections;
}

void solve() {
	int n;
	cin >> n;
	vector<Line> lines;

	for (int i = 0; i < n; i++) {
		int k, b;
		cin >> k >> b;
		lines.push_back(Line(k, b));
	}

	set<Point> points = intersections(lines);

	if (points.empty()) {
		cout << "0";
		return;
	}

	const Point& p = *points.begin();
	double max_x = p.x, min_x = p.x;
	double max_y = p.y, min_y = p.y;

	for (set<Point>::iterator it = points.begin(); it != points.end(); ++it) {
		Point p = *it;
		if (p.x < min_x) min_x = p.x;
		if (p.x > max_x) max_x = p.x;
		if (p.y < min_y) min_y = p.y;
		if (p.x > max_y) max_y = p.y;
	}

	double area = (max_x - min_x) * (max_y - min_y);

	printf("%.5f", area);
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}

/*

k1 * x - y = -b1
k2 * x - y = -b2

x = (y - b1) / k1
y = k2 * x + b2
y = k2 * (y - b1) / k1 + b2
k1*y = k2*y - b1*k2 + b2*k1
y * (k1 -k2) = b2*k1 - b1*k2
y = (b2 * k1 - b1 * k2) / (k1 - k2)
x = (y - b1) / k1
x = (y - b2) / k2

*/
