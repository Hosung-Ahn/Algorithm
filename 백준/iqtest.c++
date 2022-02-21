# include <iostream>
using namespace std;

# define MAX 50

int N; 
int arr[MAX] = {0,};

void solve() {
    int a = arr[2]-arr[1];
    int b = arr[1]-arr[0];
    int d = 0;
    if (b != 0) d = a / b;
    int c = arr[1] - arr[0]*d;

    for (int i = 2; i < N; i++) {
        if (arr[i] != arr[i-1]*d + c) {
            cout << 'B';
            return;
        }
    }
    cout << arr[N-1]*d+c;

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) 
        scanf("%d", &arr[i]);

    if (N==1) {
        cout << 'A';
    }
    else if (N==2) {  
        if (arr[0] == arr[1]) cout << arr[0];
        else cout << 'A';
    }
    else {
        solve();
    }
}