#include <iostream>
#include <queue>
using namespace std;
#define MOD 10000

struct RNG {
    unsigned seed;
    RNG() : seed(1983) { }
    unsigned next() {
        unsigned ret = seed % MOD + 1; 
        seed = (seed * 214013u) + 2531011u;
        return ret;
    }
};

int main() {
    int T; cin >> T;
    while(T--) {
        RNG rng;
        int K,N; cin >> K >> N;
        queue<int> q;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int e = rng.next();
            q.push(e);
            sum += e;
            
            while(sum > K) {
                sum -= q.front();
                q.pop();
            }

            if (sum == K) cnt++;
        }
        cout << cnt << "\n";
    }
}