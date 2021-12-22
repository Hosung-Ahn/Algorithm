# include <iostream>
# include <vector>
# include <queue>

using namespace std;

# define MAX 100000

int min_cost[MAX+1];

void find_min_cost(int start, int end) {
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    min_cost[start] = 0;

    while(!q.empty()) {
        pair<int,int> cur = q.top();
        q.pop();
        int point = cur.second;
        int cost = -cur.first;

        if (point == end) return;

        if (point-1 >= 0 && min_cost[point-1] == -1) {
            min_cost[point-1] = cost+1;
            q.push(make_pair(-(cost+1), point-1));
        }

        if (point+1 <= MAX && min_cost[point+1] == -1 ) {
            min_cost[point+1] = cost+1;
            q.push(make_pair(-(cost+1), point+1));
        }

        if (point*2 <= MAX && min_cost[point*2] == -1 ) {
            min_cost[point*2] = cost;
            q.push(make_pair(-cost, point*2));
        }
    }


}

int main() {
    memset(min_cost,-1,sizeof(min_cost));

    int s,e; cin >> s >> e;

    find_min_cost(s,e);

    cout << min_cost[e] << endl;
    
}