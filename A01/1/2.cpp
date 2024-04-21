#include <bits/stdc++.h>
using namespace std;

struct Key {
    string converted;
    string value;
    Key(char val, string conv){
        value += val;
        converted = conv;
    }
    
    Key(string val, string conv){
        value = val;
        converted = conv;
    }
};

bool is_there(const string& s, int i, string t) {
    if (i + t.size() >= s.size()) return false;
    for (int j = 0; j < t.size(); j++) {
        if (s[i + j] != t[j]) return false;
    }
    return true;
}

string get_key(const string& s, int i) {
    if (is_there("Tab")) return "Tab";
    if (is_there("BackSp")) return "BackSp";
    if (is_there("Control")) return "Control";
    if (is_there("Alt")) return "Alt";
    if (is_there("Enter")) return "Enter";
}



void get_keys() {
    
}

void solve() {
    
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
}
