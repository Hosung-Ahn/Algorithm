#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 501

bool visited[MAX][MAX] = {0,};
bool check = false;

void dfs(vector<int> arr) {
    sort(arr.begin(), arr.end());
    if (visited[arr[0]][arr[1]]) return;
    visited[arr[0]][arr[1]] = true;

    if (arr[0] == arr[1] && arr[1] == arr[2]) check = true;

    for(int i=0;i<3;i++) for(int j=i+1;j<3;j++) {
        if (arr[i] < arr[j]) {
            int ai = arr[i];
            int aj = arr[j];
            arr[i] += ai;
            arr[j] -= ai;
            dfs(arr);
            arr[i] = ai; 
            arr[j] = aj;
        }
    }
}

int main() {
    vector<int> arr;
    for (int i=0;i<3;i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    dfs(arr);
    cout << check;
}