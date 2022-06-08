#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 500
#define INF 987654321

int d[MAX];
vector<int> in_node[MAX];
vector<pair<int,int>> go[MAX];
bool erased[MAX][MAX] = {0,};

void d_clear() {
    for (int i = 0; i < MAX; i++) {
        d[i] = INF;
    }
}

void dijstra(int Start) {
    d_clear();
    priority_queue<pair<int,int>> pq;
    pq.push({0,Start});
    d[Start] = 0;
    while(!pq.empty()) {
        int cur_dist = -pq.top().first; 
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_dist > d[cur_node]) continue;

        for (int i = 0; i < go[cur_node].size(); i++) {
            int next_node = go[cur_node][i].first;
            int next_dist = cur_dist + go[cur_node][i].second;

            if (d[next_node] < next_dist) continue;

            else if (d[next_node] > next_dist) {
                d[next_node] = next_dist;
                in_node[next_node].clear();
                in_node[next_node].push_back(cur_node);
                pq.push({-next_dist, next_node});
            }

            else {
                in_node[next_node].push_back(cur_node);
            }
        }
    }
}

void erase_edges(int Start, int End) {
    if (End == Start) return;
    for (int next_End : in_node[End]) {
        if (erased[next_End][End]) return;
        erased[next_End][End] = true;
        erase_edges(Start, next_End);
    }
}

void dijstra_second(int Start) {
    d_clear();
    priority_queue<pair<int,int>> pq;
    pq.push({0,Start});
    d[Start] = 0;

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (d[cur_node] < cur_dist) continue;

        for (int i = 0; i < go[cur_node].size(); i++) {
            int next_node = go[cur_node][i].first;
            int next_dist = cur_dist + go[cur_node][i].second;

            if (next_dist >= d[next_node] || erased[cur_node][next_node]) continue;

            d[next_node] = next_dist;
            pq.push({-next_dist, next_node});
        }
    }
}

void clear() {
    for (int i = 0; i < MAX; i++) {
        in_node[i].clear();
        go[i].clear();
    }
    for (int i = 0; i < MAX; i++) {
        memset(erased[i], 0, sizeof(bool)*MAX);
    }
}



void solution(int Start, int End) {
    dijstra(Start);
    erase_edges(Start, End);
    dijstra_second(Start);

    if (d[End] == INF) cout << "-1\n";
    else cout << d[End] << "\n";
    clear();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1) { 
        int V,E,Start,End;
        cin >> V >> E;
        if (V == 0) break;
        cin >> Start >> End;
        for (int i = 0; i < E; i++) {
            int s,e,d; cin >> s >> e >> d;
            go[s].push_back({e,d});
        }
        solution(Start, End);
    }
}