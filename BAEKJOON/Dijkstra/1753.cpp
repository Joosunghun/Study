// 문제 1753번 최단경로
// 방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램
// 단 모든 간선의 가중치는 10 이하의 자연수

#include <iostream>
#include <queue>
#include <vector>

#define INF 1000000
#define MAX_VERTEX 20001
#define MAX_EDGE 300001

using namespace std;


int d[MAX_VERTEX];         // 최소 비용 배열

vector<pair<int, int>> edge[MAX_EDGE];

void dijkstra(int v) {
	d[v] = 0;          // 시작에서 시작으로 가는 비용 0

	priority_queue<pair<int, int>> pq;      // 비용, 도착 노드 형식의 우선순위 큐
	pq.push({ 0,v });

	while (!pq.empty()) {
		int current = pq.top().second;        // 도착 노드를 현재 노드로 설정
		int distance = -pq.top().first;          // 시작 노드에서 현재 노드까지의 비용 설정

		pq.pop();            // 현재 경로는 확인 되었으므로, 우선 순위 큐에서 제거

		if (d[current] < distance)
			continue;

		for (int i = 0;i < edge[current].size(); i++) {
			int next = edge[current][i].second;            // 현재 노드와 i번째로 인접한 노드. 즉, 다음 노드

			int next_distance = distance + edge[current][i].first;          // 시작 노드부터 다음 노드까지의 비용

			if(d[next] > next_distance){                          // 기존에 계산한 최소비용 보다 새롭게 계산 비용이 작으면 업데이트
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

	for (int i = 0; i < v + 1; i++) {          // 최소 비용 배열 초기화
		d[i] = INF;
	}

	for (int i = 0; i < e; i++) {          // 간선 저장
		int start, end, cost;
		cin >> start >> end >> cost;

		edge[start].push_back(make_pair(cost, end));           // 시작 노드에 따른 <비용, 도착 노드> 설정
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