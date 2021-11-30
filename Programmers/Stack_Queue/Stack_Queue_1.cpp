// Stack_Queue_1 ��ɰ���

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;          // ������ ��ô���� ��� ���� ť
    for (int i = 0; i < progresses.size(); i++) {                   // ť�� ��ô���� �߰�
        if ((100 - progresses[i]) % speeds[i] == 0) {                   
            q.push((100 - progresses[i]) / speeds[i]);
        }
        else {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }
    while (!q.empty()) {                 // ť�� ���� �ʾҴٸ�
        int cnt = 1;
        int current = q.front();           // ���� ���� 0�� �ε��� ���� �־���
        q.pop();                             // ť���� 0�� �ε����� �� pop
        while (!q.empty() && q.front() <= current) {          // ť�� ���� �ʰ�, 0�� �ε����� ���� ������ ������ 
            cnt++;                           // ī��Ʈ ����
            q.pop();                       // front�� pop
        }
        answer.push_back(cnt);       // cnt ���� answer�� �־���
    }
    return answer;
}