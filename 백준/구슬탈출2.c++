# include <iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;

# define MAX 10

vector<string> board;
int N,M;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

class Point {
public:
    int r,c;
    Point(int r = 0, int c = 0) : r(r), c(c) { }

    bool operator ==(Point other) {
        if (this->r == other.r && this->c == other.c) return true;
        return false;
    }
};

class TmpPoint {
public:
    Point red, blue;
    int cnt = 0;
    TmpPoint(Point red, Point blue) : red(red), blue(blue) { }
};

Point move_point(Point point, int dir) {
    int idx = 1;

    while(1) {
        int nr = point.r + dr[dir] * idx;
        int nc = point.c + dc[dir] * idx;
        if (board[nr][nc] == '#') {
            point.r += dr[idx] * (idx-1);
            point.c += dc[idx] * (idx-1);
            return Point(point.r, point.c);
        }
        else if(board[nr][nc] == 'O') {
            return Point(point.r, point.c);
        }
        idx++;
    }
}

TmpPoint move_left(Point red, Point blue) {
    if (red.r == blue.r) {
        if (red.c < blue.c) {
            move_point(red,0);
            move_point(blue,0);
            if (red.c == blue.c) {
                blue.c++;
            }
        }
        else {
            move_point(red,0);
            move_point(blue,0);
            if (red.c == blue.c)
                red.c++;
        }
    }
    else {
        move_point(red,0);
        move_point(blue,0);
    }
    return TmpPoint(red,blue);
}

TmpPoint move_right(Point red, Point blue) {
    if (red.r == blue.r) {
        if (red.c < blue.c) {
            move_point(red,2);
            move_point(blue,2);
            if (red.c == blue.c) {
                red.c--;
            }
        }
        else {
            move_point(red,2);
            move_point(blue,2);
            if (red.c == blue.c)
                blue.c--;
        }
    }
    else {
        move_point(red,2);
        move_point(blue,2);
    }
    return TmpPoint(red,blue);
}

TmpPoint move_up(Point red, Point blue) {
    if (red.c == blue.c) {
        if (red.r < blue.r) {
            move_point(red,1);
            move_point(blue,1);
            if (red.r == blue.r) {
                blue.r++;
            }
        }
        else {
            move_point(red,1);
            move_point(blue,1);
            if (red.r == blue.r)
                red.r++;
        }
    }
    else {
        move_point(red,1);
        move_point(blue,1);
    }
    return TmpPoint(red,blue);
}

TmpPoint move_down(Point red, Point blue) {
    if (red.c == blue.c) {
        if (red.r < blue.r) {
            move_point(red,3);
            move_point(blue,3);
            if (red.c == blue.c) {
                red.c--;
            }
        }
        else {
            move_point(red,3);
            move_point(blue,3);
            if (red.c == blue.c)
                blue.c--;
        }
    }
    else {
        move_point(red,3);
        move_point(blue,3);
    }
    return TmpPoint(red,blue);
}

TmpPoint (*move_next[])(Point, Point) = {move_left, move_up, move_right, move_down};

void bfs(Point red, Point blue) {
    TmpPoint tmp(red, blue);
    queue<TmpPoint> q;
    q.push(tmp);

    while (!q.empty()) {
        Point cur_red = q.front().red;
        Point cur_blue = q.front().blue;
        int cur_cnt = q.front().cnt;
        q.pop();

        if (cur_cnt > 10) {
            cout << -1;
            return;
        }
        if (board[cur_red.r][cur_red.c] == 'O') {
            if (board[cur_blue.r][cur_blue.c] == 'O')
                continue;
            else {
                cout << cur_cnt;
            }
        }

        for (int i = 0; i < 4; i++) {
            TmpPoint next = move_next[i](cur_red, cur_blue);

            if (next.red == cur_red && next.blue == cur_blue) continue;

            next.cnt = cur_cnt + 1;
            q.push(next);
        }

    }
}



int main() {
    cin >> N >> M;
    Point red;
    Point blue;
    for (int r = 0; r < N; r++) {
        string s; cin >> s;
        board.push_back(s);
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == 'R') {
                red.r = r;
                red.c = c;
                board[r][c] = '.';
            }
            if (board[r][c] == 'B') {
                blue.r = r;
                blue.c = c;
                board[r][c] = '.';
            }
        }
    }
    bfs(red,blue);




}