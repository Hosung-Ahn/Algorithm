# include <iostream>
# include <vector>
using namespace std;
int N,K;

vector<int> plugs;
vector<int> schedule;

bool is_include_empty() {
    if (plugs.size() < N) return true;
    return false;
}

bool is_plug_in(int n) {
    for (int plug : plugs) {
        if (n == plug) return true;
    }
    return false;
}

int find_using_idx(int plug, int cur_idx) {
    for (int i = cur_idx+1; i < K; i++) {
        if (schedule[i] == plug)
            return i;
    }
    return 100;
}

int find_max_idx(int cur_idx) {
    int max_idx = 0;
    int tmp = 0;
    for (int i = 0; i < plugs.size(); i++) {
        int plug = plugs[i];
        int cur = find_using_idx(plug, cur_idx);
        if (cur > tmp) {
            tmp = cur;
            max_idx = i;
        }
    }
    return max_idx;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x; scanf("%d", &x);
        schedule.push_back(x);
    }

    int result = 0;

    for (int i = 0; i < K; i++) {
        int cur = schedule[i];

        if (is_plug_in(cur))
            continue;
            
        if (is_include_empty()) {
            plugs.push_back(cur);
            continue;
        }
        
        

        int removed_idx = find_max_idx(i);
        plugs[removed_idx] = cur;
        result++;
    }

    cout << result;
}