#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool dfs(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 == s2;
    }
    if (s2.back() == 'A') {
        s2.pop_back();
        return dfs(s1,s2);
    }
    else {
        s2.pop_back();
        reverse(s2.begin(), s2.end());
        return dfs(s1, s2);
    }
}

int main() {
    string s1,s2; cin >> s1 >> s2;
    cout << dfs(s1,s2);
}