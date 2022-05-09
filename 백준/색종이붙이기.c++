# include <iostream>
using namespace std;

# define INF 987654321

int board[10][10] = {0,};
int cnt[] = {5,5,5,5,5};

bool in_range(int r, int c) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10) return false;
    return true;
}

bool can_set(int r, int c, int n) {
    if (!in_range(r+n, c+n)) return false;
    for (int nr = r; nr <= r+n; nr++) {
        for (int nc = c; nc <= c+n; nc++) {
            if (!board[nr][nc]) return false;
        }
    }
    return true;
} 

void set(int r, int c, int n, bool deset = false) {
    int k = -1;
    if (deset) k = 1;

    for (int nr = r; nr <= r+n; nr++) {
        for (int nc = c; nc <= c+n; nc++) {
            board[nr][nc] += k;
        }
    }
}

int result = INF;

void find_result(int idx) {    
    // cout << idx << endl;
    
    for (int next_idx = idx; next_idx < 100; next_idx++) {
        int r = next_idx / 10;
        int c = next_idx % 10;

        if (!board[r][c]) continue;

        for (int n = 4; n >= 0; n--) {
            if (can_set(r,c,n) && cnt[n] > 0) {
                // cout << r << " " << c << endl;
                set(r,c,n,false);
                cnt[n]--;
                find_result(next_idx);
                set(r,c,n,true);
                cnt[n]++;
            }
        }
        return;
    }

    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        tmp += 5 - cnt[i];
    }
    result = min(result, tmp);
    return;
    
}

int main() {
    for (int i = 0; i < 10; i++) 
        for (int j = 0; j < 10; j++)
            cin >> board[i][j];

    find_result(0);

    if (result == INF) cout << -1;
    else cout << result;
    
}