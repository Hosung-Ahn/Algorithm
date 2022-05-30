#include <iostream>
#include <vector>
#include <stack>
using namespace std;
# define MAX 20001
int h[MAX] = {0,};

int main() {
    int T; cin >> T;
    
    while(T--) {
        int N; cin >> N;
        int result = 0;
        stack<int> remain;

        for (int i = 1; i <= N; i++) {
            cin >> h[i];
        }
        h[N+1] = 0;

        for (int i = 0; i <= N+1; i++) {
            
            while(!remain.empty() && h[remain.top()] >= h[i]) {
                int ci = remain.top();
                remain.pop();

                int width;

                if(remain.empty()) width = N;
                else width = i - remain.top() -1;

                result = max(result, h[ci] * width);
            }
        remain.push(i);
        }

        cout << result << "\n";
    }
    
}