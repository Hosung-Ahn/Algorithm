#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stck;
    for(char c : s) {
        if (stck.empty() || stck.top() != c) {
            stck.push(c);
        }
        else stck.pop();
    }
    return stck.empty();
}

int main() {
    cout << solution("bcbc");
}