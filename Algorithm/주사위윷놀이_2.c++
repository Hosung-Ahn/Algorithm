#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 33
#define END 32

bool visited[MAX][MAX][MAX][MAX][10] = {0,};
int go[10];
int points[MAX] = {0,
              0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,
              13,16,19,22,24,28,27,26,25,30,
              35,0};
vector<int> mal(4,0);
int arr5[] = {21,22,23,29,30,31,20};
int arr10[] = {24,25,29,30,31,20};
int arr15[] = {26,27,28,29,30,31,20};

int cal_idx(int idx, int k) {
    if (idx <= 20) {
        if (idx == 5) {
            idx = arr5[k-1];
        }
        else if (idx == 10) {
            idx = arr10[k-1];
        }
        else if (idx == 15) {
            idx = arr15[k-1];
        }
        else idx + k > 20 ? idx = END : idx += k;
    }

    else if (idx >= 21 && idx <= 23) {
        int idx5 = idx-21+k;
        idx5 >= 7 ? idx = END : idx = arr5[idx5];
    }

    else if (idx == 24 || idx == 25) {
        int idx10 = idx-24+k;
        idx10 >= 6 ? idx = END : idx = arr10[idx10];
    }

    else {
        int idx15 = idx-26+k;
        idx15 >= 7 ? idx = END : idx = arr15[idx15];
    }
    return idx;
}

int result = 0;

bool already_in(const vector<int> &mal, int idx) {
    for (int i = 0; i < 4; i++) {
        if (mal[i] == idx) return true;
    }
    return false;
}

void dfs(vector<int> mal, int k, int sum) {
    if (k == 10) {
        result = max(result, sum);
        return;
    }

    
    // sort(mal.begin(), mal.end());
    // if (visited[mal[0]][mal[1]][mal[2]][mal[3]][k]) return;
    // visited[mal[0]][mal[1]][mal[2]][mal[3]][k] = true;

    for (int i = 0; i < 4; i++) {
        if (mal[i] == END) continue;

        vector<int> next = mal;

        next[i] = cal_idx(mal[i], go[k]); 
        
        if (next[i] != END && already_in(mal, next[i])) continue;
        dfs(next, k+1, sum + points[next[i]]);
    }
}

int main() {
    for (int i = 0; i <= 20; i++) {
        points[i] = i*2;
    }
    for (int i = 0; i < 10; i++) {
        cin >> go[i];
    }
    dfs(mal, 0,0);
    cout << result;
}