# include <iostream>
# include <string.h>
# include <string>
# include <queue>
# include <vector>
# include <math.h>
using namespace std;

# define MAX 10000
bool primes[MAX];
int cnt[MAX];

int change_num(int num, int n, int nst) {
    string s = to_string(num);
    s[nst] = (char)(n+48);
    int result = stoi(s);
    return result;
}

bool in_range(int num) {
    if (num < 1000 || num >= MAX) return false;
    return true;
}

void bfs(int start, int end) {
    cnt[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) {
            cout << cnt[cur] << "\n";
            return;
        }

        for (int nst = 0; nst < 4; nst++) {
            for (int n = 0; n < 10; n++) {
                int next = change_num(cur, n, nst);
                if (!in_range(next) || !primes[next] || cnt[next] != -1) continue;
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    memset(primes, 1, sizeof(bool)*MAX);
    

    int check = sqrt(MAX);
    for (int i = 2; i <= check; i++) {
        if (primes[i]) {
            for (int j = i*2; j < MAX; j += i) {
                primes[j] = false;
            }
        }
    }
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        memset(cnt, -1, sizeof(int)*MAX);
        int start, end; cin >> start >> end;
        bfs(start, end);
    }


}