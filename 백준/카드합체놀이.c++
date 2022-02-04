# include <iostream>
# include <queue>
using namespace std;

# define ll long long

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        pq.push(x);
    }

    for (int i = 0; i < M; i++) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        pq.push(a+b);
        pq.push(a+b);
    }

    ll result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result;
}   