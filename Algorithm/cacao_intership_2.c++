#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1,q2;
    ll q1_sum = 0, q2_sum = 0;
    for(int a : queue1) {
        q1.push(a);
        q1_sum += a;
    }
    for(int a : queue2) {
        q2.push(a);
        q2_sum += a;
    }

    int ans = 0; 

    if ((q1_sum + q2_sum) % 2 == 1) return -1;
    
    while(q1_sum != q2_sum) { 
        if(q1.empty() || q2.empty()) return -1;

        ans++;

        if(q1_sum > q2_sum) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
            q1_sum -= x;
            q2_sum += x;
        }
        else {
            int x = q2.front();
            q2.pop();
            q1.push(x);
            q2_sum -= x;
            q1_sum += x;
        }
    }
    return ans;
}