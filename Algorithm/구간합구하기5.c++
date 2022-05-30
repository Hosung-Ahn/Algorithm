# include <iostream>
# include <cstdio>

using namespace std;
# define MAX 1025

int nums[MAX][MAX] = {0, };


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            int x; cin >> x;
            nums[r][c] = nums[r][c-1] + x;
        }
    }
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            nums[r][c] += nums[r-1][c];
        }
    }

    for (int i = 0; i < m; i++) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        cout << nums[er][ec] - nums[sr-1][ec] - nums[er][sc-1] + nums[sr-1][sc-1] << "\n";
    }
}