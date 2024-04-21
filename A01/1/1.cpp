#include <bits/stdc++.h>
using namespace std;

static int U[4][3][3] = {
    {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
};

static int N[2][3][3] = {
    {
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    },
    {
        {1, 1, 1},
        {0, 1, 0},
        {1, 1, 1}
    }
};

static int L[4][3][3] = {
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
};


bool eq(const vector<vector<int> >& a, int i, int j, int letter[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (letter[x][y] != a[i - 1 + x][j - 1 + y]) return false;
        }
    }
    
    return true;
}


bool is_l(const vector<vector<int> >& a, int i, int j) {
    for (int k = 0; k < 4; k++) {
        if (eq(a, i, j, L[k])) return true;
    }
    return false;
}

bool is_n(const vector<vector<int> >& a, int i, int j) {
    for (int k = 0; k < 2; k++) {
        if (eq(a, i, j, N[k])) return true;
    }
    return false;
}

bool is_u(const vector<vector<int> >& a, int i, int j) {
    for (int k = 0; k < 4; k++) {
        if (eq(a, i, j, U[k])) return true;
    }
    return false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > a(n, vector<int>(m));
	
    for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	        int t;
	        cin >> t;
	        a[i][j] = t;
        }
    }
    
    int n_count = 0;
    int l_count = 0;
    int u_count = 0;

    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (is_n(a, i, j)) n_count++;
            if (is_u(a, i, j)) u_count++;
            if (is_l(a, i, j)) l_count++;
        }
    }
    
    cout << "L-count " << l_count << "\n";
    cout << "N-count " << n_count << "\n";
    cout << "U-count " << u_count;
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}
