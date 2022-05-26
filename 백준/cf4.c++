#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
# define ll long long

map<ll,int> visited;
ll N,X;

int len(ll n) {
    int ret = 0;
    while(n) {
        ret++;
        n/=10;
    }
    return ret;
}

void find(ll n, int num[]) {
    while(n) {
        num[n%10] = true;
        n /= 10;
    }
}

void bfs(ll start) {
    visited[start] = true;
    queue<pair<ll,int>> q;
    q.push({start,0});

    while(!q.empty()) {
        ll cur = q.front().first;
        ll cnt = q.front().second;
        q.pop();


        int l = len(cur);

        if (l == N) {
            cout << cnt;
            return;
        }
        if (l > N) continue;

        int num[10] = {0,};
        find(cur, num);

        for (int c = 2; c < 10; c++) {
            if (!num[c]) continue;
            ll next = c * cur;
            if (visited[next]) continue;
            visited[next] = true;
            q.push({next, cnt+1});
        }
    }

    cout << -1;
}

int main() {
    cin >> N >> X;

    bfs(X);
}