#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define VMAX 50001
#define INF 987654321
vector<pair<int,int>> edges[VMAX];

void bfs(int s, const vector<int> &summits, int &num, int &inten) {
    int visited[VMAX];
    for(int i=0;i<VMAX;i++) visited[i] = INF;
    visited[s] = 0;
    queue<pair<int,int>> q;
    q.push({s,0});

    while(!q.empty()) {
        int cur = q.front().first;
        int path = q.front().second;
        q.pop();
        for (int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            int next_path = max(path, edges[cur][i].second);

            if(visited[next] <= next_path) continue;
            visited[next] = next_path;
            q.push({next, next_path});
        }
    }
    for (int summit : summits) {
        if (visited[summit] <= inten) {
            inten = visited[summit];
            num = min(num, summit);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(int i=0;i<paths.size();i++) {
        int a = paths[i][0], b = paths[i][1], d = paths[i][2];
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }
    int num = 0, inten = INF;
    for(int s : gates) {
        bfs(s, summits, num, inten);
    }
    vector<int> answer;
    answer.push_back(num);
    answer.push_back(inten);
    return answer;
}