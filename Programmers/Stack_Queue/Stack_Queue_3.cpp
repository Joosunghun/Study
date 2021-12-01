// Stack_Queue_3 �ٸ��� ������ Ʈ��

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int num = 0;               // Ʈ�� ��ȣ
    int sum = 0;               // �ٸ��� �ö�� �ִ� Ʈ�� ������ ��
    queue<int> q;           // ���� �ٸ��� �ǳʴ� Ʈ�� üũ�� ť

    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }

    while (!q.empty()) {
        answer++;
        sum -= q.front();
        q.pop();

        if (num < truck_weights.size()) {           // ��� Ʈ���� �ִ� ���
            if (sum + truck_weights[num] <= weight) {
                sum += truck_weights[num];          // Ʈ���� ���Ը� ���ϰ�
                q.push(truck_weights[num]);        // ť�� �־���
                num++;                                       // ���� Ʈ������ �̵�
            }
            else
                q.push(0);
        }

    }
    return answer;
}