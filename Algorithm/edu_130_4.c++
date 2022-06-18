#include <iostream>
#include <string>
using namespace std;
string result;
int cnt = 0;

void solution(int left, int right) {
    printf("? 2 %d %d\n", left, right);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == 0) return;

    if (ans == right-left+1) {
        if (left == right && cnt < 26) {
            printf("? 1 %d\n", left);
            fflush(stdout);
            char tans;
            scanf("%c", &tans);
            result[left-1] = tans;
            cnt++;
            return;
        }
        for (int i = left-1; i < right; i++) {
            if (result[i] == 'z') {
                result[i] = 'a';
                continue;
            }
            result[i] += 1;
        }
        return solution(left, right);
    }

    if (ans != 0) {
        int mid = (left+right)/2;
        solution(left, mid);
        solution(mid+1, right);
    }
}
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        result.push_back('a');
    }
    // cout << result; 

    solution(1,N);

    printf("! %s\n", result.c_str());
    fflush(stdout);
}