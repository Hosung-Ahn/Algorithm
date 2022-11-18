#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 102
#define INF 987654321
double dist[MAX];
int N;
vector<pair<double,double>> points;
vector<pair<double,int>> edges[102];

double cal_dist(const pair<double, double> &a, const pair<double, double> &b) {
    return sqrt(pow(a.first - b.first,2) + pow(a.second - b.second, 2));
}

void dijsktra() {
    for(int i=0;i<MAX;i++) dist[i]=INF;
    dist[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.push({0,0});
    while(!pq.empty()) {
        int cur_node = pq.top().second;
        double cur_dist = -pq.top().first;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].second;
            double next_dist = cur_dist + edges[cur_node][i].first;
            if (dist[next_node] <= next_dist) continue;
            dist[next_node] = next_dist;
            pq.push({-next_dist, next_node});
        }
    }

    cout << dist[1];
}


int main() {
    for(int i=0;i<2;i++) {
        double x,y; cin >> x >> y;
        points.push_back({x,y});
    }
    cin >> N;
    for(int i=0;i<N;i++) {
        double x,y; cin >> x >> y;
        points.push_back({x,y});
    }
    for(int s=0;s<N+2;s++) for(int e=0;e<N+2;e++) {
        if(s==0 || s==1) {
            double walk_cost = cal_dist(points[s], points[e])/5;
            edges[s].push_back({walk_cost,e});
        }
        else {
            double walk = cal_dist(points[s], points[e]);
            double walk_cost = walk/5;
            double boom_cost = abs(walk - 50)/5 + 2;
            edges[s].push_back({min(walk_cost, boom_cost),e});
        }
    }
    dijsktra();
}