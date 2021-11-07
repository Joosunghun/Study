// 10_4 Ŀ��ŧ��
// N���� ����, 1������ N������ ��ȣ�� ����, ���ÿ� ���� ���� ���� ����
// ���� ���ǰ� ���� ���� ���� ���Ǹ� ���� ��� ���Ǹ� ������
// N���� ���� ������ �־� ���� �� N���� ���ǿ� ���Ͽ� �����ϱ� ���� �ɸ��� �ּҽð��� ���� ���

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;                                                    // ������ ����
int indegree[501];                                  // ��� ��忡 ���� �������� 0���� �ʱ�ȭ
vector<int> graph[501];                          // �� ��忡 ����� ���� ������ ������� ���� ����Ʈ �ʱ�ȭ
int times[501];                                       // �� ���� �ð��� 0���� �ʱ�ȭ

void topologysort() {                               // ���� ���� �Լ�
	vector<int> result(501);                        // �˰��� ���� ����� ���� ����Ʈ
	for (int i = 1; i <= n; i++) {
		result[i] = times[i];
	}

	queue<int> q;                                     // ť ���

	for (int i = 1; i <= n; i++) {                     // ó�� ������ �� ���� ������ 0�� ��带 ť�� ����
		if (indegree[i] == 0) {
			q.push(1);
		}
	}

	while (!q.empty()) {                             // ť�� �� ������ �ݺ�
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {                 // �ش� ���ҿ� ����� ������ ������������ 1 ����
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0) {                     // ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
				q.push(graph[now][i]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << result[i] << endl;
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {                   // ���� �׷����� ��� ���� ���� �Է� �ޱ�
		int x;                                           // ù ��° ���� �ð� ����
		cin >> x;
		times[i] = x;
		while (true) {                               // �ش� ���Ǹ� ��� ���� ���� ���� �ϴ� ���ǵ��� ��ȣ �Է�
			cin >> x;
			if (x == -1) break;
			indegree[i] += 1;
			graph[x].push_back(i);
		}
	}
	topologysort();
}

