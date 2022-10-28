#include <iostream>
using namespace std;

bool Red[6][4] = {0,}, Blue[6][4] = {0,};
int ans = 0;

int is_score(bool board[6][4]) {
    for(int r=5;r>=2;r--) {
        bool ck = true;
        for(int c=0;c<4;c++) {
            if (!board[r][c]) ck = false;
        }
        if (ck) return r;
    }
    return 0;
}

void fall_score(int r, bool board[6][4]) {
    for(int cr=r;cr>=1;cr--) {
        for(int c=0;c<4;c++) {
            board[cr][c] = board[cr-1][c];
        }
    }
    for(int c=0;c<4;c++) board[0][c] = 0;
}

int is_special(bool board[6][4]) {
    int ret = 0;
    for (int r=0;r<2;r++) {
        for (int c=0;c<4;c++) {
            if (board[r][c]) {
                ret++;
                break;
            }
        }
    }
    return ret;
}

void fall_special(int s, bool board[6][4]) {
    for(int r=5;r>=s;r--) {
        for(int c=0;c<4;c++) {
            board[r][c] = board[r-s][c];
        }
    }
    for(int r=0;r<s;r++) for(int c=0;c<4;c++) board[r][c]=0;
}

void fall_block(int c, int type, bool board[6][4]) {
    int r = 0;
    if (type==0) {
        while(r<5 && !board[r+1][c]) r++;
        board[r][c] = true;
    }
    else if (type==1) {
        while(r<5 && (!board[r+1][c] && !board[r+1][c+1])) r++;
        board[r][c] = true;
        board[r][c+1] = true;
    }
    else {
        while(r<4 && (!board[r+2][c])) r++;
        board[r][c] = true;
        board[r+1][c] = true;
    }
}

void one_time(int type, int c, bool board[6][4]) {
    fall_block(c, type, board);
    int scored = is_score(board);
    while(scored) {
        ans++;
        fall_score(scored, board);
        scored = is_score(board);
    }
    int s = is_special(board);
    if (s) fall_special(s, board);
}

void solve(){
    int M; cin >> M;

    for(int i=0;i<M;i++) {
        int a,b,c; cin >> a >> b >> c;
        a--;
        one_time(a,c,Red);
        if (a==1) a=2;
        else if (a==2) a=1;
        one_time(a,b,Blue);
    }

    int ans2 = 0;
    for(int r=2;r<6;r++) for(int c=0;c<4;c++) {
        if (Red[r][c]) ans2++;
        if (Blue[r][c]) ans2++;
    }

    cout << ans << endl;
    cout << ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
}