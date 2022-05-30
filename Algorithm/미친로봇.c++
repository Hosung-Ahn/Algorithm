# include <iostream>
# include <queue>
using namespace std;

# define MAX 29

bool visited[MAX][MAX] = {0,};
double p[4] = {0,};
int N;
double result = 1;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};


void dfs(int r,int c, int n, double pob) {
    if (n == N) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) continue;
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (visited[nr][nc]) {
            result -= pob * p[i];
        }
        else {
            visited[nr][nc] = true;
            dfs(nr,nc,n+1, pob * p[i]);
            visited[nr][nc] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> p[i];
        p[i] /= 100;
    }

    visited[14][14] = true;
    dfs(14,14,0,1);

    printf("%.10f", result);

}


