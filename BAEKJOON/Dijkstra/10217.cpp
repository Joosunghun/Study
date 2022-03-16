// 문제 10217번 KCM Travel
// 최대 M원까지 비용만을 여행경비로 부담
// 인천에서 LA까지 M원 이하로 사용하면서 도착할 수 있는 가장 빠른경로를 택한다.
// 각 공항들간 티켓가격과 이동시간이 주어질 때, 인천에서 LA로 갈 수 있는 가장 빠른 길을 찾는 프로그램

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

			if (nextCost > MAX_COST)            // 최대 비용을 초과하는 가격이 나오면 패스
				continue;
			if (timeDelay[there][nextCost] > nextTime) {          // 이 비용 위로 이 시간이 최소시간이 되는지 확인하고, 미리 설정
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