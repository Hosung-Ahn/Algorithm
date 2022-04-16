# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

string to_bin(int n) {
    string s = "";
    while (n != 0) {
        s.push_back(n%2+'0');
        n/=2;
    }
    if (s == "") return "0";
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n; cin >> n;
    string result = "";
    for (int i = 0; i <= n; i++) {
        result += to_bin(i);
    }
    cout << result;
}