#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 40

struct Node {
    int lx,ly,rx,ry;
    Node(int lx, int ly, int rx, int ry) : lx(lx), ly(ly), rx(rx), ry(ry) { }
    bool operator<(const Node& a) const {
        if (lx == a.lx) {
            if (ly == a.ly) {
                if (rx == a.rx) {
                    return ry < a.ry;
                }
                return rx < a.rx;
            }
            return ly < a.ly;
        }
        return lx < a.lx;
    }
};

struct Tree {
    int idx,x,y,d;
    Tree(int idx, int x, int y, int d) : idx(idx), x(x), y(y), d(d) {}
};
vector<Tree> xSort,ySort,dSort,arr;

bool cmpX(const Tree &a, const Tree &b) { return a.x < b.x; }
bool cmpY(const Tree &a, const Tree &b) { return a.y < b.y; }
bool cmpD(const Tree &a, const Tree &b) { return a.d > b.d; }
bool cuted[MAX] = {0,};
map<Node,int> dp;
int N;

Tree minX() {
    for (int i = 0; i < N; i++) {
        if (cuted[xSort[i].idx]) continue;
        return xSort[i];
    }
}
Tree maxX() {
    for (int i = N-1; i >= 0; i--) {
        if (cuted[xSort[i].idx]) continue;
        return xSort[i];
    }
}
Tree minY() {
    for (int i = 0; i < N; i++) {
        if (cuted[ySort[i].idx]) continue;
        return ySort[i];
    }
}
Tree maxY() {
    for (int i = N-1; i >= 0; i--) {
        if (cuted[ySort[i].idx]) continue;
        return ySort[i];
    }
}

bool is_all_cut() {
    for (int i = 0; i < N; i++) {
        if (!cuted[i]) return false;
    }
    return true;
}

int cal_cur(int length) {
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (cuted[dSort[i].idx]) continue;
        sum += dSort[i].d;
        ret++;
        if (sum >= length) return ret;
    }
    return 100;
}

int find_dp(int cuted_len) {
    if (is_all_cut()) return 100;
    Tree lx = minX();
    Tree ly = minY();
    Tree rx = maxX();
    Tree ry = maxY();
    int &ret = dp[Node(lx.x,ly.y,rx.x,ry.y)];

    if (ret != 0) return ret;

    int length = (rx.x-lx.x)*2 + (ry.y-ly.y)*2 - cuted_len;
    if (length <= 0) return 0;
    int cur = cal_cur(length);

    // cout << length << " " << cur << endl;
    
    cuted[lx.idx] = true;
    int leftx = 1 + find_dp(cuted_len + lx.d);
    cuted[lx.idx] = false;

    cuted[ly.idx] = true;
    int lefty = 1 + find_dp(cuted_len + ly.d);
    cuted[ly.idx] = false;

    cuted[rx.idx] = true;
    int rightx = 1 + find_dp(cuted_len + rx.d);
    cuted[rx.idx] = false;

    cuted[ry.idx] = true;
    int righty = 1 + find_dp(cuted_len + ry.d);
    cuted[ry.idx] = false;
    
    ret = min(cur, min(leftx, min(lefty, min(rightx, righty))));
    return ret;
}



int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y,d; cin >> x >> y >> d;
        arr.push_back(Tree(i,x,y,d));
    }
    sort(arr.begin(), arr.end(), cmpX);
    xSort = arr;
    sort(arr.begin(), arr.end(), cmpY);
    ySort = arr;
    sort(arr.begin(), arr.end(), cmpD);
    dSort = arr;

    cout << find_dp(0);
}