# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Points{
public : 
    int r1,c1,r2,c2;
    Points(int r1, int c1, int r2, int c2) : r1(r1), c1(c1), r2(r2), c2(c2) {}
    void print() {
        cout << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
    }
};

void solve() {
    vector<Points> result; 
    vector<string> board;
    int R, C; cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    
    if (board[0][0] == '1') {
        cout << "-1\n";
        return;
    } 

    int ans = 0;
    for (int r = R-1; r >= 0; r--) {
        for (int c = C-1; c >= 0; c--) {
            if (board[r][c] == '1') {
                ans++;
                if (c == 0) {
                    result.push_back({r,c+1,r+1,c+1});
                }
                else {
                    result.push_back({r+1,c,r+1,c+1});
                }
            }
        }
    }
    cout << ans << "\n";
    for (Points point : result) {
        point.print();
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}