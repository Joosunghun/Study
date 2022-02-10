// ���� 1504�� Ư���� �ִ� ���
// ���⼺�� ���� �׷����� �־�����. 1������ N������ �ִ� �Ÿ��� �̵��� �� ���Ƿ� �־��� �� ������ �ݵ�� ����ϸ� �̵��ϴ� ���α׷�
// �ѹ� �̵��ߴ� ������ ����, �̵��ߴ� ������ �̵�����

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, e, v1, v2, res = INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
vector<pair<int, int>> v[801];         // v[a] = (b,c) : a���� b������ c�� �Ÿ��� �̵� ����
int dist[801];

void dijkstra(int start) {
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;        // �������� �켱���� ť
	q.push({ 0,start });         // ��������� �Ÿ�, ���� ��ġ
	while (!q.empty()) {
		int current = q.top().second;
		int current_distance = q.top().first;
		q.pop();
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			int next_distance = v[current][i].second;
			if (dist[next] > current_distance + next_distance) {
				dist[next] = current_distance + next_distance;
				q.push({ dist[next],next });
			}
		}
	}
}

int main(void) {
	cin >> n >> e;
	while(e--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	dijkstra(1);              // ���������� v1, v2������ �Ÿ�
	sToV1 = dist[v1];
	sToV2 = dist[v2];

	dijkstra(v1);           // v1���� v2, n������ �Ÿ�
	V1ToV2 = dist[v2];
	V1ToN = dist[n];

	dijkstra(v2);           // v2���� n������ �Ÿ�
	V2ToN = dist[n];

	res = min(res, sToV1 + V1ToV2 + V2ToN);             // start + v1 + v2 + n �� start + v2 + v1 + n ������ �Ÿ��� �� ª�� ���� ã��
	res = min(res, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || res == INF)
		cout << -1;
	else
		cout << res << '\n';
}