# include <iostream>
# include <string.h>
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 100000

int main() {
    int T; cin >> T;
        for (int t = 0; t < T; t++) {

        int N; cin >> N;

        vector<pair<int,int>> recruits;
        for (int i = 0; i < N; i++) {
            int a,b; scanf("%d %d", &a, &b);
            recruits.push_back({a,b});
        }

        sort(recruits.begin(), recruits.end());

        int cnt = 1;
        int tmp = recruits[0].second;

        for (int i = 1; i < N; i++) {
            if (recruits[i].second < tmp) {
                cnt++;
                tmp = recruits[i].second;
            }
        }

        cout << cnt << "\n";
        recruits.clear();
    }
}