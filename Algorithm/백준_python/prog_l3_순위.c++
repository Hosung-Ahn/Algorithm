#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX 101
vector<int> edges[MAX];
int in_degree[MAX] = {0,};

int solution(int n, vector<vector<int>> results) {
    for(int i=0;i<results.size();i++) {
        int a = results[i][0];
        int b = results[i][1];

        edges[b].push_back(a);
        in_degree[a]++;
    }

    queue<int> q;
}