# include <iostream>
# include <vector>
using namespace std;

# define ll long long

ll k; 
vector<ll> fivo = {0,1};
vector<ll> fivo_sum = {0,1};

void find_ks(ll k) {
    int i = 1;
    while (fivo_sum.back() < k) {
        fivo.push_back(fivo[i] + fivo[i-1]);
        fivo_sum.push_back(fivo_sum.back() + fivo.back());
        i++;
    }

    vector<int> ret = {1};
    
    for (int n = 2; n <= i; n++) {
        if (ret.back() == 1 ) {
            k-=1;
            ret.push_back(0);
        }

        else {
            if (k - fivo_sum[i-n+2] + 1 <= fivo[i-n+2]) {
                ret.push_back(0);
                k-= fivo_sum[i-n] + 1;
            }
            else {
                ret.push_back(1);
                k-= fivo_sum[i-n+2];
            }
            
        }
    }

    for (auto x : ret) cout << x;
    cout <<endl;
}

int main() {
    cin >> k;
    find_ks(k);
}