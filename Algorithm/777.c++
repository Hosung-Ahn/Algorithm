# include <iostream>
# include <string>
using namespace std;

void solve(int n) {
    int x = n % 3;
    string result;
    switch(x) {
        case 0 : 
        result = "";
        for (int i = 0; i < n/3; i++) {
            result += "21";
        }
        break;
        
        case 1 :
        result = "1";
        for (int i = 0; i < n/3; i++) {
            result += "21";
        }
        break;

        case 2 :
        result = "2";
        for (int i = 0; i < n/3; i++) {
            result += "12";
        }
        break;
    }
    cout << result << "\n";
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; scanf("%d", &n);
        solve(n);
    }
}