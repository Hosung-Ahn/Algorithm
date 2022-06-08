#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preOrder,inOrder,postOrder;

vector<int> slice(const vector<int> &v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int> &preOrder, const vector<int> &inOrder) {
    int N = preOrder.size();
    if (N == 0) return;

    int root = preOrder[0];

    int L = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
    int R = N-L-1;

    printPostOrder(slice(preOrder,1,L+1), slice(inOrder,0,L));
    printPostOrder(slice(preOrder,L+1,N), slice(inOrder, L+1,N));

    cout << root << " ";
}


int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        preOrder.clear();
        preOrder.resize(N);
        inOrder.clear();
        inOrder.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> preOrder[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> inOrder[i];
        }

        printPostOrder(preOrder, inOrder);
        cout << "\n";
    }
}