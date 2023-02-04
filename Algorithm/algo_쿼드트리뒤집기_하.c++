#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find_sub(vector<string> &sub_str, const string &str) {
    int cnt = 0, idx = 0;
    for(char c : str) {
        if (c == 'x') cnt += 4;
        sub_str[idx].push_back(c);
        if (cnt == 0) idx++;
        else cnt--;
    }
}

string dc(const string &str) {
    if (str.size() == 1) return str;
    string ret = "";
    
    vector<string> sub_str(4, "");

    if (str[0] == 'x') {
        ret.push_back('x');
        find_sub(sub_str, str.substr(1));
    }
    else find_sub(sub_str, str);
    
    ret += dc(sub_str[2]);
    ret += dc(sub_str[3]);
    ret += dc(sub_str[0]);
    ret += dc(sub_str[1]);
    return ret;
}

void solve() {
    string str; cin >> str;
    cout << dc(str) << "\n";
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}