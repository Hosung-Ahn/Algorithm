# include <iostream>
using namespace std;
# define INF 987654321

int N,M,H, ans = INF;
bool ladder[32][12] = {0,};

bool is_ok() {
    for (int n = 1; n <= N; n++){
        int cur = n;
        for (int h = 1; h <= H; h++) {
            if (ladder[h][cur]) cur++;
            else if (ladder[h][cur-1]) cur--;
        }
        if (cur != n) return false;
    }
    return true;
}

void find_ans(int idx, int cnt) {
    if (cnt > 3) return;

    if(is_ok()) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = idx; i < H*N; i++) {
        int ch = i/N + 1;
        int cn = i%N + 1;
        // cout << i << endl;

        if (cn == N) continue;

        if (ladder[ch][cn] || ladder[ch][cn-1] || ladder[ch][cn+1]) continue;
        // cout << ch << " " << cn << " " << ladder[ch][cn] << endl;



        ladder[ch][cn] = true;
        find_ans(i, cnt+1);
        ladder[ch][cn] = false;
    }
}


int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int h,n; scanf("%d %d", &h, &n);
        ladder[h][n] = true;
    }

    find_ans(0,0);

    if (ans == INF) cout << -1;
    else cout << ans;
    
}