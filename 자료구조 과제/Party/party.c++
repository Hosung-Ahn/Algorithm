# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstdio>
using namespace std;
# define MAX 26
# define INF 987654321

int n;
int d[MAX];
vector<int> dist[MAX];
vector<int> total_time(MAX, 0);

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(2,start));

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first; 
        pq.pop();

        if (d[current] < distance) continue;

        for (int i = 0; i < dist[current].size(); i++) {
            int next = dist[current][i];
            int next_dist = distance + 3;

            if (next_dist < d[next]) {
                d[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

void d_clear() {
    for (int i = 0; i < MAX; i++) d[i] = INF; 
}

void find_min_time(char start) {
    d_clear();
    dijkstra(start - 'a');
    for (int i = 0; i < MAX; i++) {
        total_time[i] = max(total_time[i], d[i]);
    }
}

int main() {
    cin >> n;
    char s1,s2,s3; cin >> s1 >> s2 >> s3;
    for (int i = 0; i < n; i++) {
        char start, end;
        cin >> start >> end;
        while (end != '$') {
            dist[start-'a'].push_back(end-'a');
            cin >> end;
        }
    }
    find_min_time(s1);
    find_min_time(s2);
    find_min_time(s3);

    vector<int>::iterator iter = min_element(total_time.begin(), total_time.end());
    int result_time = *iter;
    char result_alpha = iter-total_time.begin()+'a';
    if (result_time >= INF) cout << "@" << endl << -1;
    else cout << result_alpha << '\n' << result_time;
}