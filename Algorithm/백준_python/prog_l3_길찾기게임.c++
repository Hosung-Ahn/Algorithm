#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,int>> tree[1001];
int total_deep=0;

struct Node {
    int x,y,idx;
    Node(int x, int y, int idx) : x(x), y(y), idx(idx) {}
};

bool cmp(const Node &a, const Node &b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

int binary_search(int x, int deep) {
    int lo = 0;
    int hi = tree[deep].size()-1;

    while(lo < hi) {
        int mid = (lo+hi)/2;
        if (tree[deep][mid].first < x) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

void preorder(int left, int right, int deep, vector<int> &arr) {
    if (total_deep < deep) return;
    int cur_idx = binary_search(left, deep);
    int cur = tree[deep][cur_idx].first;
    int cur_num = tree[deep][cur_idx].second;
    if (cur < left || cur > right) return;
    arr.push_back(cur_num);
    preorder(left, cur, deep+1, arr);
    preorder(cur, right, deep+1, arr);
}

void postorder(int left, int right, int deep, vector<int> &arr) {
    if (total_deep < deep) return;
    int cur_idx = binary_search(left, deep);
    int cur = tree[deep][cur_idx].first;
    int cur_num = tree[deep][cur_idx].second;
    if (cur < left || cur > right) return;
    postorder(left, cur, deep+1, arr);
    postorder(cur, right, deep+1, arr);
    arr.push_back(cur_num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> arr;
    for(int i=0;i<nodeinfo.size();i++) {
        arr.push_back(Node(nodeinfo[i][0],nodeinfo[i][1],i+1));
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i=1;i<arr.size();i++) {
        tree[total_deep].push_back({arr[i-1].x, arr[i-1].idx});
        if (arr[i].y != arr[i-1].y) total_deep++;
    }
    tree[total_deep].push_back({arr.back().x, arr.back().idx});

    vector<int> pre, post;
    preorder(0, 100000, 0, pre);
    postorder(0,100000, 0, post);

    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}