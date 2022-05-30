# include <iostream>
# include <map>
using namespace std;

# define MAX 40

map<int,int> arr_sum;
int arr[MAX];
int total_sum;
long long cnt = 0;

void left_sum(int s, int mid, int sum) {
    if (s == mid) {
        arr_sum[sum]++;
        return;
    }
    left_sum(s+1,mid, sum + arr[s]);
    left_sum(s+1,mid, sum);
}

void right_sum(int mid, int e, int sum) {
    if (mid == e) {
        cnt += arr_sum[total_sum - sum];
        return;
    }

    right_sum(mid+1, e, sum+arr[mid]);
    right_sum(mid+1, e, sum);
}

int main() {
    int N; cin >> N >> total_sum;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    left_sum(0,N/2,0);
    right_sum(N/2,N,0);

    if (total_sum == 0) cout << cnt-1;
    else cout << cnt;
}