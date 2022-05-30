# include <iostream>
using namespace std;

# define MAX 1000000

int buy[MAX];
int sale[MAX];

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {

        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%d", &buy[i]);
        }

        int max_price = 0;
        for (int i = N-1; i >= 0; i--) {
            if (buy[i] > max_price)
                max_price = buy[i];

            sale[i] = max_price;
        }

        long long result = 0;
        for (int i = 0; i < N; i++) {
            result += sale[i] - buy[i];
        }
        cout << result << "\n"; 
    }

}