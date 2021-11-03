// 9_3 ����
// N���� ����, ���ó��� ���� �ְ�ޱ� ����
// C���� ���� ��Ȳ�� �߻��ؼ� C���� ����Ͽ� �� ���� ���̿� ��ġ�� ��θ� ����, �ִ��� ���� �������� ��
// C���� ���� �޽����� �ް� �Ǵ� ������ ������ �� ��̸�, ��� �޽����� �޴� �� �ɸ��� �ð�
// ������ ���� N, ����� ���� M, �������� �ϴ� ���� C
// ��° �ٺ��� M+1 ���� �ٱ��� ��ο� ���� ���� X,Y,Z�� �־��� �̴� X���� Y������ �̾����� ��ΰ� ������ �޽����� ���޵Ǵ� �ð��� Z

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, start;                                                        // ����� ����, ������ ����, ���� ��� ��ȣ
vector<pair<int, int>> graph[30001];                         // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
int d[30001];                                                         // �ִ� �Ÿ� ���̺� �����

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;                                 // ť ����
	pq.push({ 0, start });                                         // ���� ���� ���� ���� �ִ� ��δ� 0, ť�� ����
	d[start] = 0;
	while (!pq.empty()) {                                         // ť�� ��� ���� �ʴٸ� 
		int dist = -pq.top().first;                                  // ���� �������� ���
		int now = pq.top().second;                             // ���� ���
		pq.pop();
		if (d[now] < dist) continue;                            // ���� ��尡 �̹� ó���� �� �ִ� ����� ����
		for (int i = 0; i < graph[now].size(); i++) {        // ���� ���� ����� �ٸ� ������ ������ Ȯ��
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {              // ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
 			}
		}
	}
}

int main(void) {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {                                    // ��� ���� ���� �Է¹ޱ� 
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });                        // x���� y�� ���� ��� 
	}

	fill(d, d + 30001, INF);                                        // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ

	dijkstra(start);                                                  // ���ͽ�Ʈ�� ����

	int count = 0;                                                    // ���� �� ���ִ� ����� ����
	int maxDistance = 0;                                          // ���� �ָ� �ִ� ������ �ִ� �Ÿ�
	for (int i = 1; i <= n; i++) { 
		if (d[i] != INF) {                                            // ���� ��  �� �ִ� ����� ���
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	cout << count - 1 << ' ' << maxDistance << endl;      // ���� ���� ���� �ϹǷ� count -1 �� ���
}