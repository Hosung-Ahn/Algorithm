#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool in_range(int r, int c, int N) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}

bool is_match(const vector<vector<int>> &key, const vector<vector<int>> &lock, int whole) {
    int M = key.size();
    int N = lock.size();

    for(int i=0-(M-1);i<N+M-1;i++) {
        for(int j=0-(M-1);j<N+M-1;j++) {
            int cnt = 0;
            for(int r=0;r<M;r++) for(int c=0;c<M;c++) {
                if (!in_range(i+r,j+c,N) || key[r][c] != 1) continue;
                if (lock[i+r][j+c] == 1) cnt = -987654321;
                cnt+= 1;
            }
            if (cnt == whole) return true;
        }
    }
    return false;
}

vector<vector<int>> rotate(const vector<vector<int>> &board) {
    int M = board.size();
    vector<vector<int>> ret(M, vector<int>(M, 0));
    for(int r=0;r<M;r++) for(int c=0;c<M;c++) {
        ret[r][c] = board[M-1-c][r];
    }
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int whole = 0;
    int N = lock.size();
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if (lock[i][j]==0) whole++;
    
    if (is_match(key, lock, whole)) return true;
    for (int i=0;i<3;i++) {
        key = rotate(key);
        if (is_match(key, lock, whole)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> key = {{0,1,0}, {1,0,0}, {1,0,0}};
    vector<vector<int>> lock = {{1,1,1}, {1,1,0}, {1,0,1}};
    cout << is_match(key, lock, 2);
}