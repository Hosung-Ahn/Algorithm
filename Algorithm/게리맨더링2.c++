#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 21

int board[MAX][MAX] = {0,};
int N;

bool is_ok(int x, int y, int d1, int d2) {
    if (y-d1>=1 && y+d2<=N && x+d1+d2<=N) return true;
    return false;
}   

int tmp(int x, int y, int d1, int d2) {
    vector<int> n(5,0);
    int k1 = x+y;
    int k2 = x+d2 + N-(y+d2)+1;
    int k3 = N-(x+d1)+1 + y-d1;
    int k4 = N-(x+d1+d2)+1 + N-(y-d1+d2)+1;
    for (int r=1;r<=N;r++) for(int c=1;c<=N;c++) {
        int kr = N-r+1;
        int kc = N-c+1;
        if (r<x+d1 && c<=y) {
            if (r+c>=k1) n[4]+=board[r][c];
            else n[0]+=board[r][c];
        }
        else if (r<=x+d2 && c>y) {
            if (r+kc>=k2) n[4]+=board[r][c];
            else n[1]+=board[r][c];
        }
        else if (r>=x+d1 && c<y-d1+d2) {
            if (kr+c>=k3) n[4]+=board[r][c];
            else n[2]+=board[r][c];
        }
        else if (r>x+d2 && c>=y-d1+d2) {
            if (kr+kc>=k4) n[4]+=board[r][c];
            else n[3]+=board[r][c];
        }
        else n[4]+=board[r][c];
    }
    sort(n.begin(), n.end());
    return n.back() - n.front();
}
void solve() {
    int ans = 987654321;
    for (int r=1;r<=N;r++) for(int c=1;c<=N;c++) {
        for (int d1=1;d1<=N;d1++) for (int d2=1;d2<=N;d2++) {
            if (is_ok(r,c,d1,d2)) {
                ans = min(ans, tmp(r,c,d1,d2));
            }
        }
    }
    cout << ans;
}

int main() {
    cin >> N;
    for (int r=1;r<=N;r++) for (int c=1;c<=N;c++) {
        cin >> board[r][c];
    }
    solve();

}