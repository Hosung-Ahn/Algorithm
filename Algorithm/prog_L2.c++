#include <string>
#include <vector>

using namespace std;

void fill(vector<vector<int>> &arr, int s, int e, int n, int k) {
    if (e-s == 0) {
        arr[e][k] = n;
        return;
    }
    else if (e-s == 1) {
        arr[s][k] = n++;
        arr[e][k] = n++;
        arr[e][k+1] = n++;
        return;
    }
    else if (e-s == 2) {
        arr[s][k] = n++;
        arr[s+1][k] = n++;
        arr[s+2][k] = n++;
        arr[s+2][k+1] = n++;
        arr[s+2][k+2] = n++;
        arr[s+1][k+1] = n++;
        return;
    }

    for(int i=s;i<e;i++) {
        arr[i][k] = n++;
    }
    for(int i=0;i<e-s;i++) {
        arr[e][k+i] = n++;
    }
    for(int i=e;i>s;i--) {
        arr[i][i-k+1] = n++;
    }
    fill(arr, s+2,e-1,n,k+1);
}

vector<int> solution(int n) {
    vector<vector<int>> arr(1001, vector<int>());
    for(int i=1;i<=n;i++) {
        arr[i].resize(i+1);
    }
    fill(arr, 1, n, 1, 1);
    vector<int> answer;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}