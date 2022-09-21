#include <iostream>
#include <vector>
using namespace std;
#define VMAX 1001
vector<pair<int,int>> edges[VMAX];
int N,M;

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }
}