// 문제 9370번 미확인 도착지
// 두 명의 사람이 목적지 후보들 중 하나의 목적지로 최단거리로 이동한다.
// 이 두 명의 사람이 가는 목적지를 구하는 프로그램

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 2100000000

using namespace std;


int T;
int n, m, t, s, g, h, a, b, d, x;
int scent, crossroad1, crossroad2;
int result_1[50001], result_2[50001];
vector<int> ans;
vector<pair<int, int>> road[50001];

void dijkstra(int start, int* result) {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		result[i] = INF;

	result[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		int dist = result[node];
		q.pop();

		for (int i = 0; i < road[node].size(); i++) {
			int next_node = road[node][i].first;
			int next_dist = road[node][i].second;

			if (result[next_node] > dist + next_dist) {
				result[next_node] = dist + next_dist;
				q.push(next_node);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		ans.clear();        // 정답, 다익스트라 결과값, 교차로 거리정보 초기화
		memset(result_1, 0, sizeof(result_1));
		memset(result_2, 0, sizeof(result_2));

		for (int i = 0; i < 50001; i++)
			road[i].clear();

		cin >> n >> m >> t;      // 교차로, 도로, 목적지 수
		cin >> s >> g >> h;     // 출발지, 후각1, 후각2

		for (int i = 0; i < m; i++) {        // 교차로 사이 거리 입력
			cin >> a >> b >> d;

			road[a].push_back({ b,d });
			road[b].push_back({ a,d });

			if ((a == g && b == h) || (a == h && b == g))
				scent = d;
		}

		dijkstra(s, result_1);        // 출발점에서 다익스트라

		if (result_1[g] > result_1[h]) {       // 후각으로 탐지한 도로에서의 다익스트라
			crossroad1 = h;
			crossroad2 = g;
		}
		else {
			crossroad1 = g;
			crossroad2 = h;
		}

		dijkstra(crossroad2, result_2);

		for (int i = 0; i < t; i++) {       // 목적지 후보 검사
			cin >> x;
			if (result_1[x] == result_1[crossroad1] + scent + result_2[x])        // 최단거리
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';

	}
}