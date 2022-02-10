// 문제 1504번 특정한 최단 경로
// 방향성이 없는 그래프가 주어진다. 1번에서 N번까지 최단 거리로 이동할 때 임의로 주어진 두 정점은 반드시 통과하며 이동하는 프로그램
// 한번 이동했던 정점은 물론, 이동했던 간선도 이동가능

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, e, v1, v2, res = INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
vector<pair<int, int>> v[801];         // v[a] = (b,c) : a에서 b까지의 c의 거리로 이동 가능
int dist[801];

void dijkstra(int start) {
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;        // 오름차순 우선순위 큐
	q.push({ 0,start });         // 현재까지의 거리, 현재 위치
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

	dijkstra(1);              // 시작점에서 v1, v2까지의 거리
	sToV1 = dist[v1];
	sToV2 = dist[v2];

	dijkstra(v1);           // v1에서 v2, n까지의 거리
	V1ToV2 = dist[v2];
	V1ToN = dist[n];

	dijkstra(v2);           // v2에서 n까지의 거리
	V2ToN = dist[n];

	res = min(res, sToV1 + V1ToV2 + V2ToN);             // start + v1 + v2 + n 과 start + v2 + v1 + n 까지의 거리중 더 짧은 값을 찾기
	res = min(res, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || res == INF)
		cout << -1;
	else
		cout << res << '\n';
}