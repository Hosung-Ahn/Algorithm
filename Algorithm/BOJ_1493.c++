#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 201
int V,E;
vector<pair<int,int>> edges[MAX];
int ans[MAX][MAX] = {0,};



int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }
}