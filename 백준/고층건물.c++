# include <iostream>
using namespace std;

# define MAX 50
double arr[MAX] = {0,};

double cal_gradient(int a, int b) {
    return (arr[b] - arr[a]) / (b-a);
}

bool can_see(int a, int b) {
    for (int mid = a + 1; mid < b; mid++) {
        double gradient_a = cal_gradient(a,mid);
        double gradient_b = cal_gradient(mid,b);
        if (gradient_a >= gradient_b) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%lf", &arr[i]);

    int result = 0;

    for (int a = 0; a < N; a++) {
        int cnt = 0;
        for (int b = 0; b < N; b++) {
            if (a == b) continue;

            if (a > b && can_see(b,a)) cnt++;
            if (a < b && can_see(a,b)) cnt++;
        }

        result = max(result, cnt);
    }

    cout << result;
}