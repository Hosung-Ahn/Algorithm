# include <iostream>
# include <queue>
# include <deque>
using namespace std;

void pq_clear(priority_queue<pair<int,int> >& peak_pq) {
    while (!peak_pq.empty()) {
        peak_pq.pop();
    }
}

int main() {
    priority_queue<int> start_pq;
    priority_queue<int> end_pq;
    priority_queue<pair<int,int> > peak_pq;

    int n, s, e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        start_pq.push(-s);
        end_pq.push(-e);
    }

    int peak_start = 1 , peak_end = 1, start, end, overlap, max_overlap = 0;
    bool peak = false;

    while(!start_pq.empty()) {
        start = -start_pq.top();
        end = -end_pq.top();

        if (start < end) {
            start_pq.pop();
            overlap = end_pq.size() - start_pq.size();
            if (overlap >= max_overlap) {
                if (overlap > max_overlap) pq_clear(peak_pq);
                // overlap 이 같은 peak 들끼리만 peak_pq 에 들어가게 해준다.
                max_overlap = overlap;
                peak_start = start;
                peak = true;
            }
        }
        else { // start == end 이면 end 를 팝하여 overlap을 낮춰준다.
                //  overlap을 낮춰주면 조건에 따라서 peak_pq에 push 된다.
            end_pq.pop();
            overlap = end_pq.size() - start_pq.size();
            if (peak && overlap < max_overlap) {
                peak_end = end;
                peak = false;
                
            }
        }
        peak_pq.push(make_pair(peak_end - peak_start, peak_end));
                cout << peak_start << " " << peak_end << " max_overlap = " << max_overlap << endl;
    }

    if (peak_start >= peak_end) { // peak_start > peak_end 이면 peak_start 가 갱신되어 있다는
                                 // 뜻이고 그렇다면 overlap >= max_overlap 이였단 뜻
        peak_end = -end_pq.top();
        peak_pq.push(make_pair(peak_end - peak_start, peak_end));
        cout << peak_start << " " << peak_end << " max_overlap = " << max_overlap << endl;
    }

    cout << "final result : " << endl;
    cout << peak_pq.top().second - peak_pq.top().first << " " 
         << peak_pq.top().second << endl;


    cout << "in peak_pq : " << endl;
    while (!peak_pq.empty()) {
        cout << peak_pq.top().second - peak_pq.top().first << " " 
         << peak_pq.top().second << endl;
        peak_pq.pop();
    }
}