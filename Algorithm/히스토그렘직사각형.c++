# include <iostream>
using namespace std;

# define ll long long 
# define MAX 100000
int arr[MAX] = {0,};
int N;

ll func(int idx, int s, int e) {
    int h = arr[idx];
    ll w = 1;
    int left = idx;
    int right = idx;
    ll ret = h*w;
    while (left != s || right != e) {
        if (left == s) {
            right++;
            h = min(h, arr[right]);
        }
        else if (right == e) {
            left--;
            h = min(h, arr[left]);
        }
        else {
            if (arr[left-1] > arr[right+1]) {
                left--;
                h = min(h, arr[left]);
            }
            else {
                right++;
                h = min(h, arr[right]);
            }
        }
        w++;
        ret = max(ret, h*w);
    }
    return ret; 
}

ll find_dp(int s, int e) {
    if (s == e) return arr[s];
    int mid = (s+e)/2;
    ll mid_included = func(mid,s,e);
    
    return max(find_dp(s,mid), max(find_dp(mid+1,e), mid_included));
}

int main() {
    cin >> N;
    while (N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        cout << find_dp(0,N-1) << "\n";
        cin >> N;
    }
}