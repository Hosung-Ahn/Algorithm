# include <iostream>
using namespace std;

# define MAX 1000
int N;
int arr[MAX];
int dp_left[MAX] = {0,};
int dp_right[MAX] = {0,};

int find_left(int idx, int value) {
    int max_dp = 0;
    for (int i = 0; i < idx; i++) {
        if (dp_left[i] > max_dp && arr[i] < value) 
            max_dp = dp_left[i];
        
    }
    return max_dp;
}

int find_right(int idx, int value) {
    int max_dp = 0;
    for (int i = N-1; i > idx; i--) {
        if (dp_right[i] > max_dp && arr[i] < value) 
            max_dp = dp_right[i];
    }
    return max_dp;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        dp_left[i] = find_left(i,arr[i]) + 1;
    }
    
    for (int i = N-1; i >= 0; i--) {
        dp_right[i] = find_right(i,arr[i]) + 1;
    }

    int result = 0;


    for (int i = 0; i < N; i++) {
        result = max(result, dp_left[i] + dp_right[i] - 1);
    }
    
    cout << result;
}