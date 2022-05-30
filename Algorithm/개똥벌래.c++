#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define MAX 200000
vector<int> bot,top;
int N,H;

int main() {
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;

        if (i%2==0) bot.push_back(x);
        else top.push_back(x);
    }

    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());

    int block = N+1;
    int cnt = 0;

    for (int h = 1; h <= H; h++) {
        int tmp = 0;
        int idx = lower_bound(bot.begin(), bot.end(), h) - bot.begin();
        tmp += N/2-idx;
        int uh = H-h+1;
        idx = lower_bound(top.begin(), top.end(), uh) - top.begin();
        tmp += N/2-idx;

        if (tmp == block) cnt++;
        if (tmp < block) {
            block = tmp;
            cnt = 1;
        }
    }

    cout << block << " " << cnt;
}