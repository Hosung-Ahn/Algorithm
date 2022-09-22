#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> game(6, vector<int>(3, 0));

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] > b[2];
}

bool cmp2(const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1];
}

void solve() {
    for(int i=0;i<6;i++) for(int j=0;j<3;j++) {
        cin >> game[i][j];
    }

    sort(game.begin(), game.end(), cmp2);

    for(int i=0;i<6;i++) {
        int &k = game[i][1];
        if (k == 0) continue;
        for(int j=0;j<6 && k>0;j++) {
            if (i==j) continue;
            if (game[j][1] > 0) {
                game[j][1]--;
                k--;
            }
        }
        if (k > 0) {
            cout << "0 ";
            return;
        } 
    }

    sort(game.begin(), game.end(), cmp);

    for(int i=0;i<6;i++) {
        int &k = game[i][0];
        if (k == 0) continue;
        for(int j=0;j<6 && k>0;j++) {
            if(i==j) continue;
            if (game[j][2] > 0) {
                game[j][2]--;
                k--;
            }
        }
        if (k > 0) {
            cout << "0 ";
            return;
        }
    }

    for(int i=0;i<6;i++) if(game[i][2] > 0) {
        cout << "0 ";
        return;
    }

    cout << "1 ";
}

int main() {
    for(int i=0;i<4;i++) {
        solve();
    }
}