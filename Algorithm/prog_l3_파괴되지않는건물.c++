#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int R = board.size();
    int C = board[0].size();

    int total[1002][1002] = {0,}; 

    for(int i=0;i<skill.size();i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int d = skill[i][5];

        if(type==1) d *= -1;

        total[r1+1][c1+1] += d;
        total[r1+1][c2+2] -= d;
        total[r2+2][c1+1] -= d;
        total[r2+2][c2+2] += d;
    }

    for(int r=1;r<=R;r++) for(int c=1;c<=C;c++) {
        total[r][c] += total[r-1][c] + total[r][c-1] - total[r-1][c-1];
    }

    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        board[r][c] += total[r+1][c+1];
    }

    int ans = 0;
    for (int r=0;r<R;r++) for(int c=0;c<C;c++) if (board[r][c] > 0) ans++;
    return ans;
}