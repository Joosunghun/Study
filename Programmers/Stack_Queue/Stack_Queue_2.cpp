// Stack_Queue_2 ������

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;              // �켱���� ť
    queue<pair<int, int>> q;            // �Ϲ� ť
    int cnt = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i,priorities[i]));                // ť�� ���� ������ �߿䵵�� ����
        pq.push(priorities[i]);                                // �켱���� ť�� �߿䵵�� ����
    }
    
    while (!q.empty()) {                            // ť�� �������� �ݺ�
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (pq.top() == value) {        // �켱���� 1������ ���簪�� ���ٸ�
            pq.pop();                      // �켱���� ť pop
            cnt++;                           // �ϳ��� pop�Ǿ����Ƿ� count++
            if (index == location) {    // pop�� �Ͱ� ���ϴ� ���� ���ٸ�
                answer = cnt;            // ���� count ����
                break;
            }
        }
        else                                // �켱���� 1������ ���簪�� ���� �ʴٸ� ť �ڿ� push
            q.push(make_pair(index, value));
    }
    return answer;
}