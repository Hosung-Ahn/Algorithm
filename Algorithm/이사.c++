# include <iostream>
# include <cmath>
# include <vector>
using namespace std;
# define INF 1987654321


int cal_dist(const pair<int,int> &a, const pair<int,int> &b) {
    return pow(abs(a.first - b.first),2) + pow(abs(a.second - b.second), 2);
}

vector<pair<int,int>> points;
int N; 

void solve() {
    int x = points[0].first, y = points[0].second;
    int dist = INF;
    for (int i = 0; i < N; i++) {
        int tmp = -1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int tmp_d = cal_dist(points[i], points[j]);
            if (tmp_d > tmp) {
                tmp = tmp_d;
            }
        }

        if (tmp < dist) {
            x = points[i].first;
            y = points[i].second;
            dist = tmp;
        }
    }
    cout << x << " " << y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        points.push_back({x,y});
    }

    solve();
}