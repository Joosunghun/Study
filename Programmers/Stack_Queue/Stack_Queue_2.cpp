// Stack_Queue_2 프린터

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;              // 우선순위 큐
    queue<pair<int, int>> q;            // 일반 큐
    int cnt = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i,priorities[i]));                // 큐에 들어온 순서와 중요도를 넣음
        pq.push(priorities[i]);                                // 우선순위 큐에 중요도를 넣음
    }
    
    while (!q.empty()) {                            // 큐가 빌때까지 반복
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (pq.top() == value) {        // 우선순위 1순위와 현재값이 같다면
            pq.pop();                      // 우선순위 큐 pop
            cnt++;                           // 하나가 pop되었으므로 count++
            if (index == location) {    // pop된 것과 원하는 것이 같다면
                answer = cnt;            // 현재 count 리턴
                break;
            }
        }
        else                                // 우선순위 1순위와 현재값이 같지 않다면 큐 뒤에 push
            q.push(make_pair(index, value));
    }
    return answer;
}