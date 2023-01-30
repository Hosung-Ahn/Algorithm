#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// 15-퍼즐 문제의 상태를 표현하는 클래스
struct State {
    // 인접한 상태들의 목록를 반환한다.
    vector<State> getAdjacent() const {};
    // map에 State를 넣기 위한 비교 연산자
    bool operator < (const State &rhs) const {};

    bool operator == (const State &rhs) const {};
};
// x의 부호를 반환한다.
int sgn(int x) { if(!x) return 0; return x > 0 ? 1 : -1; }
// x의 절대값을 1 증가시킨다.
int incr(int x) { if(x<0) return x-1 ; return x+1; }

// start 에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bidirectional(State start, State finish) {
    // 각 정점까지의 최단 경로의 길이를 저장한다.
    map<State, int> c;
    // 앞으로 방문할 정점들을 저장한다.
    queue<State> q;
    // 시작 상태와 목표 상태가 같은 경우는 예외로 처리해야한다.
    if(start == finish) return 0;
    q.push(start); c[start] = 1;
    q.push(finish); c[finish] = -1;

    //너비 우선 탐색
    while(!q.empty()) {
        State here = q.front();
        // 인접한 상태들을 검사한다.    
        vector<State> adjacent = here.getAdjacent();
        for(auto next : adjacent) {
            if (c.count(next) == 0) {
                c[next] = incr(c[here]);
                q.push(next);
            }
            // 가운데서 만난 경우
            else if(sgn(c[next]) != sgn(c[here])) {
                return abs(c[next]) + abs(c[here]) -1;
            }
        }
    }

    return -1;
}