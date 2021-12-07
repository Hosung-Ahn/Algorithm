# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
# define MAX 26
# define INF 1000

using namespace std;
int d[MAX];
bool visited[MAX];
vector<int> dist[MAX];
vector<int> total_time(MAX, 0);

void bfs(int start) {
    d[start] = -2;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next : dist[current] ) {
            if (!visited[next]) {
                d[next] = d[current] + 3;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    d[start] = 0;
}
void clear() {
    for (int i = 0; i < MAX; i++) {
        d[i] = INF; 
        visited[i] = false;
    }
}
void find_min_time(char start) { 
    clear();
    bfs(start-'a');
    for (int i = 0; i < MAX; i++) {
        total_time[i] = max(total_time[i], d[i]);
    }
}
int main() {
    int n; cin >> n;
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
    if (result_time >= INF) cout << "@\n-1";
    else cout << result_alpha << '\n' << result_time;
}