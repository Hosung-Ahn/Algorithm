# include <iostream>
using namespace std;

# define ll long long
# define MAX 300000
# define INF 987654321
ll c[MAX], d[MAX], h[MAX], D[MAX];
ll H[MAX];

int cal(ll d, ll h, ll D, ll H) {
    int ret = 1;
    while (h*d <= D*H) {
        ret++;
        d += d;
    }
    return ret;
}

int main() {
    int n,m,C; cin >> n >> C;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &c[i], &d[i], &h[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &D[i], &H[i]);
    }


    for (int i = 0; i < m; i++) {
        int ret = INF;
        for (int j = 0; j < n; j++) {
            int tmp = cal(d[j],h[j],D[i],H[i]);
            if (c[j] * tmp > C) continue;
            ret = min(ret, c[j] * tmp);
        }

        if (ret == INF) cout << -1 << " ";
        else cout << ret << " ";
    }
    
}