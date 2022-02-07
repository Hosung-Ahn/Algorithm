# include <iostream>
using namespace std;

# define ll long long
# define MAX 1000001

ll start_num, end_num;
bool arr[MAX] = {0,};

void erase_num(ll idx, ll pp) {
    for (ll i = idx; i <= end_num - start_num; i += pp) {
        arr[i] = true;
    }
}

int main() {
    cin >> start_num >> end_num;

    ll i = 2;
    while (i*i <= end_num) {
        ll idx;
        if (start_num % (i*i) == 0) {
            idx = 0;
        }
        else {
            idx = ( start_num / (i*i) ) * (i*i) + (i*i) - start_num;
        }
        erase_num(idx, i*i);
        i++;
    }

    int cnt = 0;

    for (int i = 0; i <= end_num - start_num; i++) {
        if (!arr[i]) cnt++;
    }

    cout << cnt;
}