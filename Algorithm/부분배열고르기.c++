#include <iostream>
using namespace std;
#define ll long long
#define MAX 100100
#define INF 987654321
int N;
int arr[MAX];
ll sum_arr[MAX];
int Tree[MAX*4];

int init(int node, int left, int right) {
    if (left == right) return Tree[node] = arr[left];
    int mid = (left+right)/2;
    int left_val = init(node*2, left, mid);
    int right_val = init(node*2+1, mid+1, right);
    return Tree[node] = min(left_val, right_val);
}

int find(int node, int left, int right, int start, int end) {
    if (end < left || right < start) return INF;
    if (left >= start && right <= end) return Tree[node];
    int mid = (left+right)/2;
    int left_val = find(node*2, left, mid, start, end);
    int right_val = find(node*2+1, mid+1, right, start, end);
    return min(left_val, right_val);
}

void two_pointer() {
    int left = 1, right = N;
    ll result = 0;
    while (left <= right) {
        ll cur = (sum_arr[right]-sum_arr[left-1]) * find(1,1,N, left, right);
        result = max(result, cur);
        if (arr[left] < arr[right]) left++;
        else right--;
    }
    cout << result;
}

int main() {
    cin >> N;
    sum_arr[0] = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) sum_arr[i] = sum_arr[i-1] + arr[i];
    init(1,1,N);
    two_pointer();
}