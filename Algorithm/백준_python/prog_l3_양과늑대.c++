#include <string>
#include <vector>

using namespace std;
vector<int> edges[17];
int ans = 0;

void dfs(const vector<int> &info, vector<int> next_node, int cur, int sheep, int wolf) {
    info[cur] == 0 ? sheep++ : wolf++;
    for (int next : edges[cur]) next_node.push_back(next);

    ans = max(ans, sheep);
    if (sheep <= wolf) return;

    for (int i=0;i<next_node.size();i++) {
        int next = next_node[i];
        vector<int> next_node_copy = next_node;
        next_node_copy.erase(next_node_copy.begin()+i);
        dfs(info, next_node_copy, next, sheep, wolf);
    }
}

int solution(vector<int> info, vector<vector<int>> arr) {
    for(int i=0;i<arr.size();i++) {
        int s = arr[i][0];
        int e = arr[i][1];
        edges[s].push_back(e);
    }
    dfs(info, vector<int>(), 0,0,0);
    return ans;
}