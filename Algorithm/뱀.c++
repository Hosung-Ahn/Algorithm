#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
#define INF INT32_MAX
#define ll long long

struct P {
    ll x,y;
    P(ll x, ll y) : x(x), y(y) {}
};

struct LINE {
    P s,e;
    LINE(P s, P e) : s(s), e(e) { }
};

vector<LINE> lines;
vector<int> times;
int L,N;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void left(int &d) {
    d -= 1;
    if (d < 0) d += 4;
}

void right(int &d) {
    d += 1;
    d %= 4;
}

int is_crossed(const LINE &l1, const LINE &l2) {
    // cout << l1.s.y << " " <<  l1.e.y << " " <<  l2.s.y << " " << l2.e.y << endl; 
    if (l1.s.x == l1.e.x && l1.s.x == l2.s.x && l1.s.x == l2.e.x) {
        ll a = max(l1.s.y, l1.e.y);
        ll b = min(l1.s.y, l1.e.y);
        if (l2.s.y >= b && l2.s.y <= a || 
            l2.e.y >= b && l2.e.y <= a) {
                return min(abs(l1.s.y - l2.s.y),abs(l1.s.y - l2.e.y)); 
            }
        return false;
    } 
    else if (l1.s.y == l1.e.y && l1.s.y == l2.s.y && l1.s.y == l2.e.y) {
        // cout << "asdasd" << endl;
        ll a = max(l1.s.x, l1.e.x);
        ll b = min(l1.s.x, l1.e.x);
        if (l2.s.x >= b && l2.s.x <= a || 
            l2.e.x >= b && l2.e.x <= a) {
                return min(abs(l1.s.x - l2.s.x),abs(l1.s.x - l2.e.x)); 
            }
        return false;
    }
    else if (l1.s.x == l1.e.x && l2.s.y == l2.e.y) {
        ll a = max(l1.s.y, l1.e.y);
        ll b = min(l1.s.y, l1.e.y);
        ll c = max(l2.s.x, l2.e.x);
        ll d = min(l2.s.x, l2.e.x);

        if (l2.s.y >= b && l2.s.y <= a && l1.s.x >= d && l1.s.x <= c) {
            return abs(l1.s.y - l2.s.y);
        }
        return false;
    }
    else if (l1.s.y == l1.e.y && l2.s.x == l2.e.x) {
        ll a = max(l1.s.x, l1.e.x);
        ll b = min(l1.s.x, l1.e.x);
        ll c = max(l2.s.y, l2.e.y);
        ll d = min(l2.s.y, l2.e.y);

        if (l2.s.x >= b && l2.s.x <= a && l1.s.y >= d && l1.s.y <= c) {
            return abs(l1.s.x - l2.s.x);
        }
        return false;
    }
    return false;
}


void solution() {
    ll time = 0;
    for (int i = 0; i <= N; i++) { 
        int min_dist = INF;
        bool crossed = false;
        for (int j = 0; j < i; j++) {
            int d = is_crossed(lines[i], lines[j]);
            if (d == 0) continue;
            min_dist = min(min_dist, d);
            crossed = true;
        }

        if (crossed) {
            cout << time + min_dist;
            return;
        }
        if (lines[i].e.x > L) {
            cout << time + L - lines[i].s.x + 1;
            return;
        }
        if (lines[i].e.x < -L) {
            cout << time + lines[i].s.x + L + 1;
            return;
        }
        if (lines[i].e.y > L) {
            cout << time + L - lines[i].s.y + 1;
            return;
        }
        if (lines[i].e.y < -L) {
            cout << time + lines[i].s.y + L + 1;
            return;
        }
        time += times[i];
    }
}

int main() {
    cin >> L >> N;
    int d = 0;
    ll cx = 0, cy = 0, nx, ny;
    for (int i = 0; i < N; i++) {
        int n; char op;
        cin >> n >> op;
        times.push_back(n);
        nx = cx + dx[d]*n;
        ny = cy + dy[d]*n;
        lines.push_back(LINE(P(cx,cy), P(nx,ny)));
        if (op == 'L') left(d);
        else right(d);
        cx = nx;
        cy = ny;
    }
    nx = cx + dx[d]*INF;
    ny = cy + dy[d]*INF;
    lines.push_back(LINE(P(cx,cy), P(nx,ny)));

    // for (LINE line : lines) {
    //     cout << line.s.x << " " << line.s.y << ", " << line.e.x << " " << line.e.y << endl;
    // }

    solution();
}