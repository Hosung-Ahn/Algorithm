# include <iostream>
# include <string>
using namespace std;

# define MAX 500000
# define INF 987654321

bool is_palin(int s, int e, string &str) {
    if (e-s < 1) return false;
    for (int i = 0; i <= (e-s)/2; i++) {
        if (str[s+i] != str[e-i]) return false;
    }
    // cout << "falin\n";
    return true;
}

bool cal(int s, int e, string &str) {
    int cnt = 0;
    for (int i = s; i <= e; i++) {
        if (str[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    if (cnt == 0) {
        // cout << "cal\n";
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string str; cin >> str;
        int s = 0, e = 0;
        
        int cnt = 0;
        while (e < n) {
            // cout << s << " " << e << endl;
            if (is_palin(s,e,str) || cal(s,e,str)) {
                s = e+1;
                e = s;
                cnt++;
            }
            else e++;
        }

        cout << cnt << " " << e-s << "\n";
    }
}