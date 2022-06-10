#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long

vector<int> arr, leftIdx, rightIdx;
stack<int> arr_stack;
int N;


void swipping() {
    arr_stack.push(0);
    for (int i = 1; i <= N+1; i++) {
        while (arr[arr_stack.top()] > arr[i]) {
            rightIdx[arr_stack.top()] = i;
            arr_stack.pop();
        }
        leftIdx[i] = arr_stack.top();
        arr_stack.push(i);
    }
}

void solution() {
    ll result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, (ll)arr[i]*(rightIdx[i] - leftIdx[i]-1));
    }
    cout << result;
}

int main() {
    cin >> N;
    arr.resize(N+2);
    leftIdx.resize(N+2);
    rightIdx.resize(N+2);

    arr.push_back(0);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    arr.push_back(0);

    swipping();
    solution();    
}