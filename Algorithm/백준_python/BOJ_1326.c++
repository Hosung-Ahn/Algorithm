#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10000
#define INF 987654321
int arr[MAX] = {0,};
int visited[MAX] = {0,};
int N,S,E;

void bfs(int S, int E) {
    queue<int> q;
    visited[S] = 1;
    q.push(S);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == E) {
            cout << visited[cur]-1;
            return;
        }
        for(int next=cur;next<N;next+=arr[cur]) {
            if(visited[next]) continue;
            visited[next] = visited[cur]+1;
            q.push(next);
        }
        for(int next=cur;next>=0;next-=arr[cur]) {
            if(visited[next]) continue;
            visited[next] = visited[cur]+1;
            q.push(next);
        }
    }
    cout << -1;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    cin >> S >> E;
    bfs(S-1, E-1);
}