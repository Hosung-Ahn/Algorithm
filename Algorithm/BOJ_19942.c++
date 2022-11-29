#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
int table[16][5];
int ans = INF;
vector<int> ans_arr;
int N;

void brute(int idx, vector<int> ms, vector<int> arr, int cost) {
    if (idx == N) {
        for(int m : ms) if(m > 0) return;
        if (ans == cost && arr < ans_arr) {
            ans = cost;
            ans_arr = arr;
        }
        if (ans > cost) {
            ans = cost;
            ans_arr = arr;
        }
        return;
    }
    brute(idx+1, ms, arr, cost);
    for(int i=0;i<4;i++) ms[i]-=table[idx][i];
    arr.push_back(idx+1);
    brute(idx+1, ms, arr, cost+table[idx][4]);
}

int main() {
    vector<int> ms(4);
    cin >> N;
    for(int i=0;i<4;i++) cin >> ms[i];
    for(int i=0;i<N;i++)for(int j=0;j<5;j++) cin >> table[i][j];
    brute(0,ms,vector<int>(),0);
    if (ans == INF) cout << -1;
    else {
        cout << ans << "\n";
        for(int a : ans_arr) cout << a << " ";
    }
}   