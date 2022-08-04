#include <iostream>
#include <string>
using namespace std;

bool is_falin(const string &s, int lo, int hi) {
    int mid = (lo+hi)/2;
    for(int i = 0; i < mid; i++) {
        if (s[lo+i] != s[hi-i]) return false; 
    }
    return true;
}

int is_falin_all(const string &s) {
    int lo = 0;
    int hi = s.size()-1;
    int mid = (lo+hi)/2;
    for(int i = 0; i < mid; i++) {
        if (s[lo+i] != s[hi-i]) {
            if (is_falin(s, lo+i, hi-i-1) || is_falin(s,lo+i+1,hi-i)) return 1;
            return 2;
        }
    }
    return 0;

}

int main() {
    cout << "hello";
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        cout << is_falin_all(s);
    }
}