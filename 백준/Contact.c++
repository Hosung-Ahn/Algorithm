# include <iostream>
# include <string>
# include <regex>
# include <cstring>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string str; cin >> str;

        if (regex_match(str, regex("(100+1+|01)+"))) cout <<"YES\n";
        else cout << "NO\n";
    }
}