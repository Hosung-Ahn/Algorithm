# include <iostream>
# include <queue>
# include <string.h>
using namespace std;
# define MAX 1000001

int arr[MAX] = {0,};
int cnt[MAX] = {0,};
int result[MAX];
    memset(result, -1, sizeof(int)*MAX);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    priority_queue<pair<int,int>> pq;

    int arr_cnt[MAX] = {0,};

    for (int i = 0; i < N; i++) {
        arr_cnt[arr[i]]++;
    }
    for (int i = 0; i < N; i++) {
        cnt[i] = arr_cnt[arr[i]];
    }

    for (int i = 0; i < N; i++) {
        while(!pq.empty() && -pq.top().first < cnt[i]) {
            result[pq.top().second] = arr[i];
            pq.pop();
        }
        pq.push({-cnt[i], i});
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

}