# include <iostream>
# include <vector>
# include <queue>
using namespace std;
# define MAX 10001
int n;
vector<pair<int,int> > cost[MAX]; // dist[start][index] = (end,dist)
int ans = 0; 
int end_point = 0;

void dfs(int point, int dist, int prev = -1) {
    if (dist > ans) {
            ans = dist;
            end_point = point;
        }
    for (int i = 0; i < cost[point].size(); i++) {
        int next = cost[point][i].first;
        int next_dist = dist + cost[point][i].second;

        if (next == prev) continue;
        
        dfs(next, next_dist, point);
    }
}


int main() { 
    cin >> n;
    int s, e, d;
    for (int i = 0; i < n-1; i++) {
        cin >> s >> e >> d;
        cost[s].push_back(make_pair(e,d));
        cost[e].push_back(make_pair(s,d));
    }

    dfs(1,0);
    ans = 0;
    dfs(end_point,0);
    cout << ans << endl;
}