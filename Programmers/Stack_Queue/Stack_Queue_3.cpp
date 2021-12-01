// Stack_Queue_3 다리를 지나는 트럭

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int num = 0;               // 트럭 번호
    int sum = 0;               // 다리에 올라와 있는 트럭 무게의 합
    queue<int> q;           // 현재 다리를 건너는 트럭 체크용 큐

    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }

    while (!q.empty()) {
        answer++;
        sum -= q.front();
        q.pop();

        if (num < truck_weights.size()) {           // 대기 트럭이 있는 경우
            if (sum + truck_weights[num] <= weight) {
                sum += truck_weights[num];          // 트럭의 무게를 더하고
                q.push(truck_weights[num]);        // 큐에 넣어줌
                num++;                                       // 다음 트럭으로 이동
            }
            else
                q.push(0);
        }

    }
    return answer;
}