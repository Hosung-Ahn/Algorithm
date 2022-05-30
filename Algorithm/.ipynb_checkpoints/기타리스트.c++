# include <iostream>
using namespace std;

bool visited[51][1001] = {0, };
int arr[51];
int N,S,M;

int result = -1;

void find_dp(int n, int cur) {
    if (n == N) {
        result = max(result, cur);
        return;
    }

    int up = cur + arr[n+1];
    if (up <= M && !visited[n+1][up]) {
        visited[n+1][up] = true;
        find_dp(n+1, up);
    }
        
    
    int down = cur - arr[n+1];
    if (down >= 0 && !visited[n+1][down]){
        visited[n+1][down] = true;
        find_dp(n+1, down);
    }
}

int main() {
    cin >> N >> S >> M;

    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    find_dp(0,S);

    cout << result << endl;
}