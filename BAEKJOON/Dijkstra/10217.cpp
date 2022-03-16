// ���� 10217�� KCM Travel
// �ִ� M������ ��븸�� ������� �δ�
// ��õ���� LA���� M�� ���Ϸ� ����ϸ鼭 ������ �� �ִ� ���� ������θ� ���Ѵ�.
// �� ���׵鰣 Ƽ�ϰ��ݰ� �̵��ð��� �־��� ��, ��õ���� LA�� �� �� �ִ� ���� ���� ���� ã�� ���α׷�

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> idx[101];
const int INF = 1000000007;
int timeDelay[101][10001];

void dijkstra(const int& N, const int& MAX_COST) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= MAX_COST; j++)
			timeDelay[i][j] = INF;
	}

	timeDelay[1][0] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,1} });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int time = pq.top().second.first;
		int here = pq.top().second.second;

		pq.pop();
		if (timeDelay[here][cost] < time)
			continue;
		for (int i = 0; i < idx[here].size(); i++) {
			int nextCost = cost + idx[here][i].second.first;
			int there = idx[here][i].first;
			int nextTime = time + idx[here][i].second.second;

			if (nextCost > MAX_COST)            // �ִ� ����� �ʰ��ϴ� ������ ������ �н�
				continue;
			if (timeDelay[there][nextCost] > nextTime) {          // �� ��� ���� �� �ð��� �ּҽð��� �Ǵ��� Ȯ���ϰ�, �̸� ����
				for (int i = nextCost; i <= MAX_COST; i++) {
					if (timeDelay[there][i] > nextTime)
						timeDelay[there][i] = nextTime;
				}
				pq.push({ -nextCost, { nextTime,there } });
			}
		}
	}
	int ret = INF;
	for (int i = 1; i <= MAX_COST; i++)
		ret = min(ret, timeDelay[N][i]);
	if (ret == INF)
		cout << "Poor KCM" << '\n';
	else 
		cout << ret << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, k;
	int u, v, c, d;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			while (!idx[i].empty())
				idx[i].pop_back();
		}
		for (int i = 0; i < k; i++) {
			cin >> u >> v >> c >> d;
			idx[u].push_back({ v,{c,d} });
		}
		dijkstra(n, m);
	}

	return 0;
}