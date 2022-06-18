#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX 3000

struct P {
    int x,y;
    P(int x, int y) : x(x), y(y) {}
};

int SET[MAX];
int cnt[MAX];

int get_parent(int a) {
    if (a == SET[a]) return a;
    return SET[a] = get_parent(SET[a]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a < b) {
        SET[b] = a;
        cnt[a] += cnt[b];
    }
    else {
        SET[a] = b;
        cnt[b] += cnt[a];
    }
}

int ccw(const P &p1,const P &p2,const P &p3) {
    int x = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y); 
    if (x == 0) return 0;
    else if (x > 0) return 1;
    else return -1;
}

bool is_in_line(const P &p1, const P &p2, const P &p3) {
    return p3.x >= min(p1.x,p2.x) && p3.x <= max(p1.x,p2.x)
          && p3.y >= min(p1.y,p2.y) && p3.y <= max(p1.y,p2.y);
}

bool find(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a == b;
}

bool is_cross(const pair<P,P> &A, const pair<P,P> &B) {
    P p1 = A.first;
    P p2 = A.second;
    P p3 = B.first;
    P p4 = B.second;
    int a = ccw(p1,p2,p3);
    int b = ccw(p1,p2,p4);
    int c = ccw(p3,p4,p2);
    int d = ccw(p3,p4,p1);
    if (a*b > 0 || c*d > 0) return false;
    else if (a == 0 && b == 0 && c == 0 && d == 0) {
        if (is_in_line(p1,p2,p3) || is_in_line(p1,p2,p4)
            || is_in_line(p3,p4,p1) || is_in_line(p3,p4,p2)) return true;
        return false;
    }
    else if (a == 0) {
        if (is_in_line(p1,p2,p3)) return true;
        return false;
    }
    else if (b == 0) {
        if (is_in_line(p1,p2,p4)) return true;
        return false;
    }
    else if (c == 0) {
        if (is_in_line(p3,p4,p2)) return true;
        return false;
    }
    else if (d == 0) {
        if (is_in_line(p3,p4,p1)) return true;
        return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        SET[i] = i;
        cnt[i] = 1;
    }
    int N; cin >> N;
    vector<pair<P,P>> points;
    for (int i = 0; i < N; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back({P(x1,y1), P(x2,y2)});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (is_cross(points[i], points[j])) {
                if (find(i,j)) continue;
                union_node(i,j);
            }
        }
    }
    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(get_parent(i));
    }
    cout << s.size() << endl;

    int max_cnt = 0;
    for (int i = 0; i < N; i++) {
        max_cnt = max(max_cnt, cnt[i]);
    }
    cout << max_cnt;
}