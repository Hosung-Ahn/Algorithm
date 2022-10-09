#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define MAX 100000
vector<pair<int,int>> node;

void up(int &k, int x) {
    for (int i=0;i<x;i++) {
        k = node[k].first;
    }
}

void down(int &k, int x) {
    for (int i=0;i<x;i++) {
        k = node[k].second;
    }
}

void delete_node(int &k, int n) {
    int left = node[k].first;
    int right = node[k].second;
    node[left].second = node[k].second;
    node[right].first = node[k].first;
    if (right == n) k = node[k].first;
    else k = node[k].second;
}   

void restore_node(int n) {
    int left = node[n].first;
    int right = node[n].second;
    node[left].second = n;
    node[right].first = n;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for (int i=0;i<n;i++) {
        answer.push_back('O');
    }
    vector<int> deleted;

    for(int i=0;i<n;i++) {
        node.push_back({i-1,i+1});
    }

    for(string cm : cmd) {
        if (cm[0] == 'U') {
            int x = stoi(cm.substr(2));
            up(k, x);
        }
        else if (cm[0] == 'D') {
            int x = stoi(cm.substr(2));
            down(k, x);
        }
        else if (cm[0] == 'C') {
            deleted.push_back(k);
            delete_node(k, n);
        }
        else {
            int n = deleted.back();
            deleted.pop_back();
            restore_node(n);
        }
    }
    for(int d : deleted) {
        answer[d] = 'X';
    }
    return answer;
}

int main() {
    vector<string> arr = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"}; 
    cout << solution(8,2, arr);
}