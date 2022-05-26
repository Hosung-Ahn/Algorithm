#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
# define MAX 100

int board[MAX][MAX] = {0,};

bool is_R() {
    int R = 0, C = 0;
    for (int c = 0; c < MAX; c++) {
        for (int r = 0; r < MAX; r++) {
            if (board[r][c] != 0) C = c; 
        }
    }
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            if (board[r][c] != 0) R = r;
        }
    }

    return R >= C;
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void row_sort() {
    for (int r = 0; r < MAX; r++) {
        int cnt[MAX+1] = {0,};
        for (int c = 0; c < MAX; c++) {
            cnt[board[r][c]]++;
        }

        vector<pair<int,int>> arr;

        for (int n = 1; n <= MAX; n++) {
            if (cnt[n] == 0) continue;
            arr.push_back({n,cnt[n]});
        }

        sort(arr.begin(), arr.end(), cmp);
        memset(board[r], 0, sizeof(int)*MAX);

        for (int i = 0; i < arr.size() && i < 50; i++) {
            board[r][i*2] = arr[i].first;
            board[r][i*2+1] = arr[i].second;
        }
    }
}

void column_sort() {
    for (int c = 0; c < MAX; c++) {
        int cnt[MAX+1] = {0,};
        for (int r = 0; r < MAX; r++) {
            cnt[board[r][c]]++;
        }

        vector<pair<int,int>> arr;

        for (int n = 1; n <= MAX; n++) {
            if (cnt[n] == 0) continue;
            arr.push_back({n,cnt[n]});
        }

        sort(arr.begin(), arr.end(), cmp);
        for (int r = 0; r < MAX; r++) {
            board[r][c] = 0;
        }

        for (int i = 0; i < arr.size() && i < 50; i++) {
            board[i*2][c] = arr[i].first;
            board[i*2+1][c] = arr[i].second;
        }

    }
}

void solution(int r, int c, int k) {
    int T = 0;
    while (T <= 100) {
        if (board[r-1][c-1] == k) {
            cout << T;
            return;
        }

        if(is_R()) row_sort();
        else column_sort();
        T++;
    }
    cout << -1;
}


int main() {
    int r,c,k; cin >> r >> c >> k;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cin >> board[r][c];
        }
    }

    solution(r,c,k);

}