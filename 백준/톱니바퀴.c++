# include <iostream>
# include <vector>
# include <string.h>
using namespace std;

vector<string> arrs;
int tops[4] = {0,};
bool moved[4] = {0,};


int cal(int idx, int a) {
    idx += a;
    idx %= 8;
    if (idx < 0) idx += 8;
    return idx;
}

void move(int cur, int d) {
    if (moved[cur]) return;

    moved[cur] = true;

    int right = cur+1, left = cur -1;
    if (right <= 3 && 
    arrs[cur][cal(tops[cur], 2)] != arrs[right][cal(tops[right],-2)]) {
        move(right, -d);
    }
    if (left >= 0 &&
    arrs[cur][cal(tops[cur],-2)] != arrs[left][cal(tops[left],2)]) {
        move(left, -d);
    }
    tops[cur] = cal(tops[cur], d);
}


int main() {
    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        arrs.push_back(s);
    }
    int N; cin >> N;
    while (N--) {
        int idx, d; scanf("%d %d", &idx,&d);
        memset(moved, 0, sizeof(bool)*4);
        move(idx-1,-d);
    }

    int score = 1;
    int result = 0;

    for (int i = 0; i < 4; i++) {
        if (arrs[i][tops[i]] == '1') result += score;
        score *= 2;
    }

    cout << result;
}