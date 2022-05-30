# include <iostream>
# include <queue> 
using namespace std;
# define ll long long

ll arr[10] = {0,};

class Node {
public:
    int a,b,p,q;
    Node(int a, int b, int p, int q) : a(a), b(b), p(p), q(q) {}
};

ll gcd(ll a, ll b) {
    ll c = a%b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() {
    queue<Node> que;
    int n; cin >> n; 
    for (int i = 0; i < n-1; i++) {
        int a,b,p,q; scanf("%d %d %d %d", &a,&b,&p,&q);
        int d = gcd(p,q);
        p/=d;
        q/=d;
        que.push(Node(a,b,p,q));
    }

    Node first = que.front();
    que.pop();
    arr[first.a] = first.p;
    arr[first.b] = first.q;

    while (!que.empty()){
        // for (int i = 0; i < n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        Node cur = que.front();
        que.pop();

        if (arr[cur.a] == 0 && arr[cur.b] == 0) {
            que.push(cur);
            continue;
        }

        int a = cur.a, b = cur.b, p = cur.p, q = cur.q;
        
        if (arr[b] == 0) {
            a = cur.b;
            b = cur.a;
            p = cur.q;
            q = cur.p;
        }

        int d = gcd(arr[b], q);
        ll x = q/d;
        for (int i = 0; i < n; i++) {
            arr[i] *= x;
        }
        arr[a] = arr[b] * p/q;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}