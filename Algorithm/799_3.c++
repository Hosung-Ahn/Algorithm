#include <iostream>
#include <cstring>
using namespace std;
#define MAX 8
bool board[MAX][MAX] = {0,};

void solve() {
    for (int i = 1; i < MAX-1; i++) {
        for (int j = 1; j < MAX-1; j++) {
            if (!board[i][j]) continue;

            if (!board[i-1][j-1] || !board[i-1][j+1] || !board[i+1][j-1] || !board[i+1][j+1]) 
                continue;
            
            cout << i+1 << " " << j+1 << "\n";
            return;
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        for (int i = 0; i < MAX; i++) {
            memset(board[i], 0, sizeof(bool)*MAX);
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                char x; cin >> x;
                if (x == '.') continue;
                board[i][j] = true;
            }
        }

        solve();
    }
}