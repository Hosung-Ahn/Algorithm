#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> Green(6, vector<int>(4,0)), Blue(6, vector<int>(4,0));
int score = 0;
int bloc_idx = 1;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

void stack(vector<vector<int>> &board, int r, int c, int t, int idx) {
    switch (t) {
        case 1 : {
            while(r < 5 && board[r+1][c] == 0) {
                r++;
            }
            board[r][c] = idx;
            break;
        }

        case 2 : {
            while(r < 5 && board[r+1][c] == 0 && board[r+1][c+1] == 0) {
                r++;
            }
            board[r][c] = idx;
            board[r][c+1] = idx;
            break;
        }

        case 3 : {
            while(r < 4 && board[r+2][c] == 0) {
                r++;
            }
            board[r][c] = idx;
            board[r+1][c] = idx;
            break;
        }
        
    }
} 

void stack_two(vector<vector<int>> &Green, vector<vector<int>> &Blue, int r, int c, int t, int idx) {
    switch(t) {
        case 1 : {
            stack(Green,0,c,1,idx);
            stack(Blue,0,r,1,idx);
            break;
        }
        default : {
            stack(Green,0,c,t,idx);
            stack(Blue,0,r,5-t,idx);
            break;
        }
    }
}

bool is_score(vector<vector<int>> &board) {
    for (int r = 2; r < 6; r++) {
        int cnt = 0;
        for (int c = 0; c < 4; c++) {
            cnt += board[r][c] > 0;
        }
        if (cnt == 4) {
            for (int k = 0; k < 4; k++) {
                board[r][k] = 0;
            }
            score++;
            return true;
        }
    }
    return false;
}


void move_after_score(vector<vector<int>> &board) {
    for (int r = 4; r >= 0; r--) {
        for (int c = 0; c < 4; c++) {
            if (board[r][c] == 0) continue;

            if (board[r][c] == board[r+1][c]) {
                int idx = board[r][c];
                board[r][c] = 0;
                board[r+1][c] = 0;
                stack(board,r,c,3,idx);
            }
            else if (c < 3 && board[r][c] == board[r][c+1]) {
                int idx = board[r][c];
                board[r][c] = 0;
                board[r][c+1] = 0;
                stack(board,r,c,2,idx);
            }

            else {
                if (c > 0 && board[r][c] == board[r][c-1]) continue;
                if (r > 0 && board[r][c] == board[r-1][c]) continue;
                int idx = board[r][c];
                board[r][c] = 0;
                stack(board,r,c,1,idx);
            }
        }
    }
}

void is_special(vector<vector<int>> &board) {
    int cnt = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 4; c++) {
            if (board[r][c] > 0) {
                cnt++;
                break;
            }
        }
    }
    for (int r = 5; r > 5-cnt; r--) {
        for (int c = 0; c < 4; c++) {
            board[r][c] = 0;
        }
    }

    if (cnt > 0) {
        for (int r = 5; r >= 2; r--) {
            for (int c = 0; c < 4; c++) {
                board[r][c] = board[r-cnt][c];
                board[r-cnt][c] = 0;
            }
        }
    }
}

void solution() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int t,r,c; cin >> t >> r >> c;
        stack_two(Green, Blue, r,c,t,bloc_idx++);
        while(is_score(Green)) {
            move_after_score(Green);
        }
        while(is_score(Blue)) {
            move_after_score(Blue);
        }
        is_special(Green);
        is_special(Blue);
    }

    int cnt = 0;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 4; c++) {
            cnt += Green[r][c] > 0;
            cnt += Blue[r][c] > 0;
        }
    }

    cout << score << "\n" << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solution();
    
}

