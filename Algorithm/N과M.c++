# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> v;
vector<int> result;
bool visited[8] = {0, };
int n,m;

void permutation(int cnt) {
    if (cnt == m) {
        for (int x : result) printf("%d ", x);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result.push_back(v[i]);

            permutation(cnt+1);

            visited[i] = false;
            result.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <=n; i++) {
        int x; scanf("%d",&x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    permutation(0);
}