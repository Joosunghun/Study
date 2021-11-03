// 9_3 전보
// N개의 도시, 도시끼리 전보 주고받기 가능
// C에서 위급 상황이 발생해서 C에서 출발하여 각 도시 사이에 설치된 통로를 거쳐, 최대한 많이 퍼져나갈 것
// C에서 보낸 메시지를 받게 되는 도시의 개수는 총 몇개이며, 모두 메시지를 받는 데 걸리는 시간
// 도시의 개수 N, 통로의 개수 M, 보내고자 하는 도시 C
// 둘째 줄부터 M+1 번쨰 줄까지 통로에 대한 정보 X,Y,Z가 주어짐 이는 X부터 Y까지로 이어지는 통로가 있으며 메시지가 전달되는 시간이 Z

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, start;                                                        // 노드의 개수, 간선의 개수, 시작 노드 번호
vector<pair<int, int>> graph[30001];                         // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[30001];                                                         // 최단 거리 테이블 만들기

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;                                 // 큐 생성
	pq.push({ 0, start });                                         // 시작 노드로 가기 위한 최단 경로는 0, 큐에 삽입
	d[start] = 0;
	while (!pq.empty()) {                                         // 큐가 비어 있지 않다면 
		int dist = -pq.top().first;                                  // 현재 노드까지의 비용
		int now = pq.top().second;                             // 현재 노드
		pq.pop();
		if (d[now] < dist) continue;                            // 현재 노드가 이미 처리된 적 있는 노드라면 무시
		for (int i = 0; i < graph[now].size(); i++) {        // 현재 노드와 연결된 다른 인접한 노드들을 확인
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {              // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
 			}
		}
	}
}

int main(void) {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {                                    // 모든 간선 정보 입력받기 
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });                        // x에서 y로 가는 비용 
	}

	fill(d, d + 30001, INF);                                        // 최단 거리 테이블을 모두 무한으로 초기화

	dijkstra(start);                                                  // 다익스트라 수행

	int count = 0;                                                    // 도달 할 수있는 노드의 개수
	int maxDistance = 0;                                          // 가장 멀리 있는 노드와의 최단 거리
	for (int i = 1; i <= n; i++) { 
		if (d[i] != INF) {                                            // 도달 할  수 있는 노드의 경우
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	cout << count - 1 << ' ' << maxDistance << endl;      // 시작 노드는 제외 하므로 count -1 을 출력
}