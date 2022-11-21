#include <iostream>
#include <math.h>
using namespace std;
float area;

struct Point {
    float x,y;
    Point(float x=0, float y=0) : x(x), y(y) {}
};

float ccw(const Point &A, const Point &B, const Point &C) {
    return (A.x*B.y + B.x*C.y + C.x*A.y - (B.x*A.y + C.x*B.y + A.x*C.y))/2;
}

bool check(const Point &A, const Point &B, const Point &C, const Point &P) {
    if (area >= 0) {
        if (ccw(A,B,P) == 0) {
            if (max(A.x, B.x) < P.x || min(A.x, B.x) > P.x) return false;
            return true;
        }
        else if (ccw(A,B,P) < 0) return false;

        if (ccw(B,C,P) == 0) {
            if (max(B.x, C.x) < P.x || min(B.x, C.x) > P.x) return false;
            return true;
        }
        else if (ccw(B,C,P) < 0) return false;

        if (ccw(C,A,P) == 0) {
            if (max(C.x,A.x) < P.x || min(C.x, A.x) > P.x) return false;
            return true;
        }
        else if (ccw(C,A,P) < 0) return false;

        return true;
    }

    if (area < 0) {
        if (ccw(A,B,P) == 0) {
            if (max(A.x, B.x) < P.x || min(A.x, B.x) > P.x) return false;
            return true;
        }
        else if (ccw(A,B,P) > 0) return false;

        if (ccw(B,C,P) == 0) {
            if (max(B.x, C.x) < P.x || min(B.x, C.x) > P.x) return false;
            return true;
        }
        else if (ccw(B,C,P) > 0) return false;

        if (ccw(C,A,P) == 0) {
            if (max(C.x,A.x) < P.x || min(C.x, A.x) > P.x) return false;
            return true;
        }
        else if (ccw(C,A,P) > 0) return false;

        return true;
    }
}

int main() {
    Point A[3];
    for(int i=0;i<3;i++) {
        int x,y; cin >> x >> y;
        A[i] = Point(x,y);
    }

    area = ccw(A[0],A[1],A[2]);
    cout << fixed;
    cout.precision(1);
    cout << abs(area) << endl;
    int ans = 0;
    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int x,y; cin >> x >> y;
        if (check(A[0], A[1], A[2], Point(x,y))) ans++;
    }
    cout << ans;
}