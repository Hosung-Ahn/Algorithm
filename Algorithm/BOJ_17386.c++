#include <iostream>
using namespace std;
#define ll long long

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll res = x1*y2 + x2*y3 + x3*y1 - (x2*y1 + x3*y2 + x1*y3);
    if (res > 0) return 1;
    else return -1;
}

int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int a = ccw(x1,y1,x2,y2,x3,y3) * ccw(x1,y1,x2,y2,x4,y4);
    int b = ccw(x3,y3,x4,y4,x1,y1) * ccw(x3,y3,x4,y4,x2,y2);

    if (a==-1 && b==-1) cout << 1;
    else cout << 0;
}