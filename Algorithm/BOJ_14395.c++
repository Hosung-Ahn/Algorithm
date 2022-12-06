#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define ll long long
struct Node {
    ll n;
    string s;
    Node(ll n, string s) : n(n), s(s) {}
};
map<ll,int> visited;

void bfs(ll start, ll end) {
    queue<Node> q;
    visited[start] = 0;
    q.push(Node(start, ""));

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();
        if (cur.n == end) {
            cout << cur.s;
            return;
        }

        int cost = visited[cur.n];

        if (cur.n > end && visited.count(1) != 0) continue;
        
        ll next = cur.n * cur.n;
        if (visited.count(next) == 0) {
            visited[next] = cost+1;
            q.push(Node(next, cur.s+"*"));
        }
        next = cur.n * 2;
        if (visited.count(next) == 0) {
            visited[next] = cost+1;
            q.push(Node(next, cur.s+"+"));
        }
        if (visited.count(1) == 0) {
            visited[1] = cost+1;
            q.push(Node(1, cur.s+"/"));
        }
    }
    cout << -1;
}

int main() { 
    ll s,e; cin >> s >> e;
    if (s == e) cout << 0;
    else bfs(s,e);
}