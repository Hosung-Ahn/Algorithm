#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i=0;i<n;i++) {
        if (i%2==0) answer.push_back('수');
        else answer.push_back('박');
    }
    return answer;
}

int main() {
    int n; cin >> n;
    cout << solution(n);
}