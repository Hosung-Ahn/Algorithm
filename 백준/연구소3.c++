# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <string.h>
using namespace std;

# define MAX 50
# define INF 2500

int N,K;
int board[MAX][MAX];
int cnt[MAX][MAX];
queue<pair<int,int>> starts;
vector<int> combinations;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void bfs() {
    queue<pair<int,int>> starts_copy = starts;

    while (!starts_copy.empty()) {
        int r = starts_copy.front().first;
        int c = starts_copy.front().second;
        cnt[r][c] = 0;
        starts_copy.pop();
    }

    while (!starts.empty()) {
        int cr = starts.front().first;
        int cc = starts.front().second;
        starts.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == 1 || cnt[nr][nc] != -1) 
                continue;
            cnt[nr][nc] = cnt[cr][cc] + 1;
            starts.push({nr,nc});
        }
        
        
    }
}

void clear(){
    for (int i = 0; i < MAX; i++) 
        memset(cnt[i], -1, sizeof(int)*MAX);
}

int find_cnt() {
    int result = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == 0) {
                if (cnt[r][c] == -1) return INF;
                result = max(result, cnt[r][c]);
            }
        }
    }
    return result;
}

int main() {
    
    
    vector<pair<int,int>> viruses;

    cin >> N >> K;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            scanf("%d", &board[r][c]);
            if (board[r][c] == 2) {
                viruses.push_back({r,c});
            }
        }
    }
    for (int i = 0; i < viruses.size() - K; i++)
        combinations.push_back(0);
    for (int i = 0; i < K; i++)
        combinations.push_back(1);

    
    int result = 2500;

    do {
        for (int i = 0; i < combinations.size(); i++) {
            if(combinations[i] == 1) starts.push(viruses[i]);
            
        }
        clear();
        bfs();
        result = min(result, find_cnt());
        
    } while(next_permutation(combinations.begin(), combinations.end()));
    
    if (result == INF) cout << -1;
    else cout << result;
}