// Stack_Queue_1 기능개발

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;          // 현재의 진척도를 닮기 위한 큐
    for (int i = 0; i < progresses.size(); i++) {                   // 큐에 진척도를 추가
        if ((100 - progresses[i]) % speeds[i] == 0) {                   
            q.push((100 - progresses[i]) / speeds[i]);
        }
        else {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }
    while (!q.empty()) {                 // 큐가 비지 않았다면
        int cnt = 1;
        int current = q.front();           // 현재 값에 0번 인덱스 값을 넣어줌
        q.pop();                             // 큐에서 0번 인덱스를 을 pop
        while (!q.empty() && q.front() <= current) {          // 큐가 비지 않고, 0번 인덱스가 현재 값보다 작을때 
            cnt++;                           // 카운트 증가
            q.pop();                       // front값 pop
        }
        answer.push_back(cnt);       // cnt 값을 answer에 넣어줌
    }
    return answer;
}