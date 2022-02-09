// ���� 1753�� �ִܰ��
// ����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷�
// �� ��� ������ ����ġ�� 10 ������ �ڿ���

#include <iostream>
#include <queue>
#include <vector>

#define INF 1000000
#define MAX_VERTEX 20001
#define MAX_EDGE 300001

using namespace std;


int d[MAX_VERTEX];         // �ּ� ��� �迭

vector<pair<int, int>> edge[MAX_EDGE];

void dijkstra(int v) {
	d[v] = 0;          // ���ۿ��� �������� ���� ��� 0

	priority_queue<pair<int, int>> pq;      // ���, ���� ��� ������ �켱���� ť
	pq.push({ 0,v });

	while (!pq.empty()) {
		int current = pq.top().second;        // ���� ��带 ���� ���� ����
		int distance = -pq.top().first;          // ���� ��忡�� ���� �������� ��� ����

		pq.pop();            // ���� ��δ� Ȯ�� �Ǿ����Ƿ�, �켱 ���� ť���� ����

		if (d[current] < distance)
			continue;

		for (int i = 0;i < edge[current].size(); i++) {
			int next = edge[current][i].second;            // ���� ���� i��°�� ������ ���. ��, ���� ���

			int next_distance = distance + edge[current][i].first;          // ���� ������ ���� �������� ���

			if(d[next] > next_distance){                          // ������ ����� �ּҺ�� ���� ���Ӱ� ��� ����� ������ ������Ʈ
				d[next] = next_distance;

				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}

int main(void) {
	int v, e;
	cin >> v >> e;

	int start_node;
	cin >> start_node;

	for (int i = 0; i < v + 1; i++) {          // �ּ� ��� �迭 �ʱ�ȭ
		d[i] = INF;
	}

	for (int i = 0; i < e; i++) {          // ���� ����
		int start, end, cost;
		cin >> start >> end >> cost;

		edge[start].push_back(make_pair(cost, end));           // ���� ��忡 ���� <���, ���� ���> ����
	}

	dijkstra(start_node);

	for (int i = 1; i < v + 1; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else
			cout << d[i] << '\n';
	}

	return 0;
}