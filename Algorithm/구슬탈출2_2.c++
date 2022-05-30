# include <iostream>
# include <vector>
# include <string>
# include <queue>
using namespace std; 

# define MAX 10

class Point {
public :
    int r,c;    
    Point(int r = 0, int c = 0) : r(r), c(c) {}

    bool operator==(Point cmp) {
        if (this->r != cmp.r || this->c != cmp.c) return false;
        return true;
    }
};

class TmpPoints {
public:
    Point red,blue;
    int cnt;

    TmpPoints(Point red, Point blue) : red(red), blue(blue) {
        cnt = 0;
    }

    bool operator==(TmpPoints cmp) {
        if (this->red.r != cmp.red.r || this->red.c != cmp.red.c
            || this->blue.r != cmp.blue.r || this->blue.c != cmp.blue.c)
            return false;
        return true;
    }
};
int N,M;
vector<string> board;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

Point move_point(Point point, int dir) {
    for (int i = 1; i <= 10; i++) {
        int nr = point.r + dr[dir] * i;
        int nc = point.c + dc[dir] * i;

        if (board[nr][nc] == 'O') {
            return Point(nr,nc);
        }
        else if(board[nr][nc] == '#') {
            return Point(point.r + dr[dir] * (i-1), point.c + dc[dir] * (i-1));
        }
    }
    return point;
}

TmpPoints move_left(TmpPoints tmp) {
    Point next_red = move_point(tmp.red, 1);
    Point next_blue = move_point(tmp.blue, 1);

    if (next_red == next_blue) {
        if (board[next_red.r][next_red.c] == 'O')
            return TmpPoints(next_red, next_blue);

        if (tmp.red.c < tmp.blue.c) next_blue.c++;
        else next_red.c++;
    }

    return TmpPoints(next_red, next_blue);
}

TmpPoints move_right(TmpPoints tmp) {
    Point next_red = move_point(tmp.red, 3);
    Point next_blue = move_point(tmp.blue, 3);

    if (next_red == next_blue) {
        if (board[next_red.r][next_red.c] == 'O')
            return TmpPoints(next_red, next_blue);

        if (tmp.red.c < tmp.blue.c) next_red.c--;
        else next_blue.c--;
    }

    return TmpPoints(next_red, next_blue);
}

TmpPoints move_up(TmpPoints tmp) {
    Point next_red = move_point(tmp.red, 0);
    Point next_blue = move_point(tmp.blue, 0);

    if (next_red == next_blue) {
        if (board[next_red.r][next_red.c] == 'O')
            return TmpPoints(next_red, next_blue);

        if (tmp.red.r < tmp.blue.r) next_blue.r++;
        else next_red.r++;
    }

    return TmpPoints(next_red, next_blue);
}

TmpPoints move_down(TmpPoints tmp) {
    Point next_red = move_point(tmp.red, 2);
    Point next_blue = move_point(tmp.blue, 2);

    if (next_red == next_blue) {
        if (board[next_red.r][next_red.c] == 'O')
            return TmpPoints(next_red, next_blue);

        if (tmp.red.r < tmp.blue.r) next_red.r--;
        else next_blue.r--;
    }

    return TmpPoints(next_red, next_blue);
}

TmpPoints (*move_next[])(TmpPoints) = {move_up, move_left, move_down, move_right};

void bfs(Point red, Point blue) {
    TmpPoints start(red, blue);
    queue<TmpPoints> q;
    q.push(start);

    while (!q.empty()) {
        TmpPoints cur = q.front();
        q.pop();

        // cout << endl;
        // cout << cur.red.r << " " << cur.red.c << endl;
        // cout << cur.blue.r << " " << cur.blue.c << endl;
        // cout << cur.cnt << endl;


        if (cur.cnt > 10) {
            cout << -1;
            return;
        }

        if (board[cur.red.r][cur.red.c] == 'O') {
            cout << cur.cnt;
            return;
        }

        for (int i = 0; i < 4; i++) {
            TmpPoints next = move_next[i](cur);
            // 구슬들이 움직이지 않은 경우
            if (cur == next) continue;
            // 같이 구멍에 빠지는 경우
            if (next.red == next.blue) continue;
            // 파란색 공이 빠지는 경우
            if (board[next.blue.r][next.blue.c] == 'O') continue;

            next.cnt = cur.cnt + 1;
            q.push(next);
        }
    }

    cout << -1;
}


int main() {
    cin >> N >> M; 

    Point red;
    Point blue;

    for (int r = 0; r < N; r++){
        string s; cin >> s;
        board.push_back(s);
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            switch (board[r][c]) {
                case 'R' :
                red.r = r;
                red.c = c;
                board[r][c] = '.';
                break;

                case 'B' :
                blue.r = r;
                blue.c = c;
                board[r][c] = '.';
                break;
            }
        }
    }

    bfs(red, blue);


}