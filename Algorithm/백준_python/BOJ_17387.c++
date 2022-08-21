#include <iostream>
using namespace std;
#define ll long long

struct P {
    ll x,y;
    P(ll x=0, ll y=0) : x(x), y(y) {}
};

int ccw(const P &p1,const P &p2,const P &p3) {
    ll x = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y); 
    if (x == 0) return 0;
    else if (x > 0) return 1;
    else return -1;
}

bool is_in_line(const P &p1, const P &p2, const P &p3) {
    return p3.x >= min(p1.x,p2.x) && p3.x <= max(p1.x,p2.x)
          && p3.y >= min(p1.y,p2.y) && p3.y <= max(p1.y,p2.y);
}

bool is_cross(const P &p1, const P &p2, const P &p3, const P &p4) {
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
    P p[4];
    for (int i=0;i<2;i++) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[2*i] = P(x1,y1);
        p[2*i+1] = P(x2,y2);
    }

    cout << is_cross(p[0],p[1],p[2],p[3]);
}