# include <iostream>
# include <stack>
# include <string>
using namespace std;

int main() {
    string s;   cin >> s;
    stack<char> stck; 

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];

        switch (s[i]) {
        case '(' :
            stck.push(s[i]);
            break;
        case '-' : 
        case '+' : 
            while (!stck.empty() && stck.top() != '(') {
                cout << stck.top();
                stck.pop();
            }  
            stck.push(s[i]);
            break;
        case '*' :
        case '/' :
            while (!stck.empty() && (stck.top() == '*' || stck.top() == '/')) {
                cout <<stck.top();
                stck.pop();
            }
            stck.push(s[i]);
            break;
        case ')' :
            while (!stck.empty() && stck.top() != '(') {
                cout << stck.top();
                stck.pop();
            }
            stck.pop();
            break;
        default:
            break;
        }
    }
    while (!stck.empty()) {
        cout << stck.top();
        stck.pop();
    }
}