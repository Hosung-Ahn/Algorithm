# include <iostream>
# include <queue>
# include <vector>
using namespace std;
# define MAX 100000
# define INF -1

int min_cost[MAX+1];

void find_min_cost(int start, int end) {
    priority_queue<pair<int, int>> q;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));
    min_cost[start] = 0;
    int point, cost;


    while(!q.empty()) {
        pair<int,int> cur = q.top();
        q.pop();
        point = cur.second;
        cost = -cur.first;
        // cost = cur.first;

        if (point == end) return;

        if (point*2 <= MAX && min_cost[point*2] == INF) {
            q.push(make_pair(-cost, point*2));
            // q.push(make_pair(cost, point*2));
            min_cost[point*2] = cost;
        }
        if (point > 0 && min_cost[point-1] == INF) { 
            min_cost[point-1] = cost+1;
            q.push(make_pair( -(cost+1), point-1));
            // q.push(make_pair( cost+1, point-1));
        }
        if (point < MAX && min_cost[point+1] == INF) {
            min_cost[point+1] = cost+1;
            q.push(make_pair( -(cost+1), point+1));
            // q.push(make_pair( cost+1, point+1));
        }
    }
}

int main() {
    for (int i = 0; i <= MAX; i++) min_cost[i] = INF;

    int s,e; cin >> s >> e;
    find_min_cost(s,e);

    cout << min_cost[e] << endl;

}