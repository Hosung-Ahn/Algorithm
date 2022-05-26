#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define MAX 200000
int N; 
int result[MAX] = {0,};

struct Node {
    int s,c,i;
    Node(int s, int c, int i) : s(s), c(c), i(i) {}
};

vector<Node> arr;
bool cmpS(const Node &a, const Node &b) {
    return a.s < b.s;
}

bool cmpC(const Node &a, const Node &b) {
    if (a.c == b.c) {
        return a.s < b.s;
    }
    return a.c < b.c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int c, s; cin >> c >> s;
        arr.push_back(Node(s,c,i));
    }

    sort(arr.begin(), arr.end(), cmpS);

    int sum = 0;
    int last_sum = 0;
    int last_s = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (last_s == arr[i].s) {
            result[arr[i].i] += last_sum;    
        }
        else {
            result[arr[i].i] += sum;
            last_sum = sum;
        }
        sum += arr[i].s;
        last_s = arr[i].s;
    }

    sort(arr.begin(), arr.end(), cmpC);


    sum = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].c == arr[i-1].c) {
            sum += arr[i-1].s;
            if (arr[i].s == arr[i-1].s) continue;
            result[arr[i].i] -= sum;
        }
        else {
            sum = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }
    
}