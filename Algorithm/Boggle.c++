#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 40

vector<string> words;
vector<string> boards[MAX];
int point[9] = {0,0,0,1,1,2,3,5,11};
bool visited[4][4] = {0,};
int N,M;
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

bool in_range(int r, int c) {
    if (r < 0 || r >= 4 || c < 0 || c >= 4) return false;
    return true;
}

bool dfs(int r, int c, int k, const string &s, int idx) {
    if (idx == s.size()) return true;
    if (!in_range(r,c) || visited[r][c] || boards[k][r][c] != s[idx]) return false;
    visited[r][c] = true;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (dfs(nr,nc,k,s,idx+1)) {
            visited[r][c] = false;
            return true;
        }
    }
    visited[r][c] = false;
    return false;
}

bool is_find(int k, string &s) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (dfs(r,c,k,s,0)) return true;
        }
    }
    return false;
}

bool cmp(const string &a, const string &b) {
    if (a.size() == b.size()) return a > b;
    return a.size() < b.size();
}

void solution() {
    for (int k = 0; k < M; k++) {
        int score = 0, cnt = 0;
        string ans;
        for (int i = 0; i < N; i++) {
            if (is_find(k, words[i])) {
                score += point[words[i].size()];
                cnt++;
                ans = words[i];
            }
        }
        cout << score << " " << ans << " " << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; 
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        words.push_back(s);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            string s; cin >> s;
            boards[i].push_back(s);
        }
    }
    sort(words.begin(), words.end(), cmp);

    solution();
}