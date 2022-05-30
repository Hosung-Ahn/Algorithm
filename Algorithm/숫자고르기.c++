#include <iostream>
#include <vector>
using namespace std;
# define MAX 101
int arr[MAX];

bool is_cycle(int start) {
    bool visited[MAX] = {0,};
    visited[start] = true;

    int cur = start;
    while(1) {
        int next = arr[cur];
        if (visited[next]) return start == next;
        visited[next] = true;
        cur = next;
    }
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (is_cycle(i)) result.push_back(i);
    }
    cout << result.size() << "\n";
    for (int x : result) {
        cout << x << "\n";
    }
}
