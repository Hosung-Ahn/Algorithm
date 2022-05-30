# include <iostream>
# include <vector>
# include <cstdio>

using namespace std;

# define MAX 10001
int work_time[MAX] = {0,};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int result = 0;
    int n; cin >> n;
    for (int cur_work = 1; cur_work <= n; cur_work++) {
        int cur_time, cnt; cin >> cur_time >> cnt;
        int total_time = 0;
        for (int j = 0; j < cnt; j++) {
            int pre_work; cin >> pre_work;
            total_time = max(total_time, work_time[pre_work]);
        }
        work_time[cur_work] = cur_time + total_time;

        if (work_time[cur_work] > result) result = work_time[cur_work];
    }

    cout << result;
}