# include <iostream>
# include <queue>
# include <algorithm>
# include <map>
using namespace std;

# define ll long long
# define MAX 100

vector<ll> arr;
map<ll,int> visited;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int K,N; cin >> K >> N;

    ll max_num = 0;
    for (int i = 0; i < K; i++) {
        ll x; cin >> x;
        arr.push_back(x);
        pq.push(x);
        visited[x] = 1;
        max_num = max(max_num, x);
    }

    int cnt = 0;
    ll cur;
    while (cnt != N) {
        cur = pq.top();
        pq.pop();
        cnt++;
        
        for (int i = 0; i < K; i++) {
            ll next = cur * arr[i];
            if (visited.count(next)) continue;
            if (pq.size() > N && next >= max_num) continue;
            pq.push(next);
            visited[next] = 1;
            max_num = max(max_num, next);
        }
    }
    cout << cur;
    
}
