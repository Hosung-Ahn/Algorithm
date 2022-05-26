#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> arrN, arrM;
bool visited[10000] = {0,};


bool oneTime() {
    int cnt = 0;
    int idxN = 0;
    for (int i = 0; i < arrM.size(); i++) {
        if (visited[i]) continue;
        if (arrM[i] <= arrN[idxN]) {
            visited[i] = true;
            idxN++;
            cnt++;
            if (idxN == arrN.size()) return true;
        }
    }
    return cnt > 0;
}

void solution() {
    int result = 0;
    while (oneTime()) {
        result++;
    }
    for (int i = 0; i < arrM.size(); i++) {
        if (!visited[i]) {
            cout << -1;
            return;
        }
    } 

    cout << result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arrN.push_back(x);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        arrM.push_back(x);
    }

    sort(arrN.begin(), arrN.end(), greater<int>());
    sort(arrM.begin(), arrM.end(), greater<int>());

    solution();
}