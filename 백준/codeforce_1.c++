# include <iostream>
# include <string>
using namespace std;

bool is_palin(string str) {
    int last = (str.size()-1) / 2;

    for (int i = 0; i <= last; i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n,k; cin >> n >> k;
        string str; cin >> str;

        if (k == 0) cout << "1\n";
        else {
            if (is_palin(str)) cout << "1\n";
            else cout << "2\n";
        }
    }
}