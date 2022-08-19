#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seq = {1,2,3,4,5,6,7,8};
int play[50][9] = {0,};
int tmp_score=0;
int N, ans = 0;

void score(int k, bool room[4]) {
    room[0] = true;
    for(int i=3;i>=0;i--) {
        if(!room[i]) continue;
        room[i] = false;

        if(i+k > 3) {
            tmp_score++;
        }
        else {
            room[i+k] = true;
        }
    }
}

void inning(const vector<int> &arr, int &start, int nth) {
    int out = 0;
    bool room[4] = {0,};
    
    while(out<3) {
        int k = arr[start];
        if (play[nth][k] == 0) out++;
        else {
            score(play[nth][k], room);
        }

        start++;
        start%=9;
    }
}

void solve() {
    tmp_score = 0;
    int start = 0;
    vector<int> arr;
    for(int i=0;i<8;i++) {
        if (i==3) arr.push_back(0);
        arr.push_back(seq[i]);
    }
    for(int nth=0;nth<N;nth++){
        inning(arr, start, nth);
    }
    ans = max(ans, tmp_score);
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for (int j=0;j<9;j++) {
            cin >> play[i][j];
        }
    }

    do {
        solve();
    } while(next_permutation(seq.begin(), seq.end()));

    cout << ans;
}