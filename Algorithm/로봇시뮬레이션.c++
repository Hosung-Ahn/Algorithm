#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

struct Robot {
    int r,c,d; 
    Robot(int r, int c, int d) : r(r), c(c), d(d) { }

    void R(int x) {
        d -= x;
        d %= 4;
        if (d < 0) d+=4;
    }

    void L(int x) {
        d += x;
        d %= 4;
    }
};

struct OP {
    int n,t;
    char op;
    OP(int n, char op, int t) : n(n), op(op), t(t) { }
};

int A,B,N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int board[MAX][MAX] = {0,};
vector<Robot> robots;
vector<OP> ops;

bool in_range(int r, int c) {
    if (r < 1 || r > B || c < 1 || c > A) return false;
    return true;
}

int into_d(char d) {
    switch (d) {
        case 'S' :
            return 0;
        case 'E' :
            return 1;
        case 'N' :
            return 2;
        case 'W' :
            return 3;
    }
    return -1;
}

void solution() {
    for (OP O : ops) {
        int n,t;
        char op;
        n = O.n;
        t = O.t;
        op = O.op;

        // for (Robot X : robots) {
        //     cout << X.r << " " << X.c << " " << X.d << endl;
        // }
        // cout << endl;

        switch (op) {

            case 'L' :
                robots[n-1].L(t);
            break;

            case 'R' :
                robots[n-1].R(t);
            break;

            case 'F' :
                int cr = robots[n-1].r;
                int cc = robots[n-1].c;
                int d = robots[n-1].d;
                int nr,nc;
                for (int k = 1; k <= t; k++) {
                    nr = cr + dr[d] * k;
                    nc = cc + dc[d] * k;
                    // cout << nr << " " << nc << endl;
                    if (!in_range(nr,nc)) {
                        cout << "Robot " << n << " crashes into the wall";
                        return; 
                    }
                    else if (board[nr][nc]) {
                        cout << "Robot " << n << " crashes into robot " << board[nr][nc];
                        return; 
                    }
                }
                robots[n-1].r = nr;
                robots[n-1].c = nc;
                board[cr][cc] = 0;
                board[nr][nc] = n;
        }
    }
    cout << "OK";
}

int main() {
    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; i++) {
        int r,c;
        char d;
        cin >> c >> r >> d;
        robots.push_back(Robot(r,c,into_d(d)));
        board[r][c] = i;
    }

    for (int i = 0; i < M; i++) {
        int n,t;
        char op;
        cin >> n >> op >> t;
        ops.push_back(OP(n,op,t));
    }

    // for (Robot bot : robots) {
    //     cout << bot.r << " " <<  bot.c << " " << bot.d << endl;
    // }

    solution();

    
    
}