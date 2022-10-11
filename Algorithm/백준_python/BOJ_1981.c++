#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100

int board[MAX][MAX];
int N, minN=987654321, maxN=0;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true; 
}

bool bfs(int diff) {
    for(int s=minN;s+diff<=maxN;s++) {
        bool visited[MAX][MAX] = {0,};
        int e = s+diff;
        if (board[0][0] < s || board[0][0] > e) continue;
        queue<pair<int,int>> q;
        visited[0][0] = true;
        q.push({0,0});

        while(!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            if (cr==N-1 && cc==N-1) return true;

            for(int i=0;i<4;i++) {
                int nr = cr+dr[i];
                int nc = cc+dc[i];

                if (!in_range(nr,nc) || visited[nr][nc]
                || board[nr][nc] < s || board[nr][nc] > e) continue;
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    return false;
}

void binary_search() {
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        minN = min(minN, board[r][c]);
        maxN = max(maxN, board[r][c]);
    }
    int lo = 0, hi = maxN-minN;

    while(lo < hi) { 
        int mid = (lo+hi)/2;
        cout << mid << endl;
        if (!bfs(mid)) lo=mid+1;
        else hi = mid;
    }
    cout << lo;
}

int main() {
    cin >> N;
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) cin >> board[r][c];
    binary_search();
}