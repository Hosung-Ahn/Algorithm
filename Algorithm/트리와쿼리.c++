# include <iostream>
# include <vector>
using namespace std;

# define MAX 100001
vector<int> edges[MAX];

bool visited[MAX] = {0,};
int arr[MAX] = {0,};

int find_arr(int cur) {
    visited[cur] = true;

    int result = 1;
    for (int next : edges[cur]) {
        if (visited[next]) continue;
        result += find_arr(next);
    }

    visited[cur] = false;
    arr[cur] = result;
    return result;
}

int main() {
    int N, R, Q; cin >> N >> R >> Q;
    for(int i = 0; i < N-1; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    find_arr(R);

    for (int i = 0; i < Q; i++) {
        int x; scanf("%d", &x);
        cout << arr[x] << "\n";
    }


}