# include <iostream>
using namespace std;

# define INF 987654321
int s,e;
int result = INF;

void find_cnt(int cur, int cnt) {
    if (cur < s) return;
    if (cur == s) {
        result = min(result, cnt);
    }

    if (cur % 10 == 1) find_cnt(cur / 10, cnt+1);
    if (cur % 2 == 0) find_cnt(cur / 2, cnt+1);
}

int main() {
    scanf("%d %d", &s, &e);

    find_cnt(e, 1);

    if (result == INF) cout << -1;
    else cout << result;
}