// 9_2 미래도시
// 첫째 줄에 회사 개수 N, 경로 개수 M
// 둘째 줄 부터 M+1 번째 줄까지 연결된 두 회사의 번호
// M+2 번째 줄에는 X와 K가 주어짐
// A가 1 에서 출발해서 K번 회사를 거쳐 X번 회사로 가는 최소 이동시간
// X번 회사에 도달할 수 없으면 -1 출력

#include <iostream>
#include <algorithm>
#define INF 1e9                                       // 무한을 의미하는 값 설정

using namespace std;

int main(void) {
	int n, m;                                             // 노드의 개수와 간선의 개수
	int graph[101][101];                            // 2차원 배열 만들기

	cin >> n >> m;
	for (int i = 0; i < 101; i++) {                    // 자기 자신에서 자기 자신으로 가는 경로는 0으로 초기화
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 0; i < m; i++) {                       // 각 간선에 정보를 입력 받아 그 값으로 초기화
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;                             // A와 B가 서로에게 가는 비용은 1이라고 설정
		graph[b][a] = 1;
	}

	int x, k;                                              // 거쳐갈 노드 x와 최종 목적지 k 입력 
	cin >> x >> k;

	for (int k = 1; k <= n; k++) {                   // 플로이드 워셜 알고리즘 수행
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	
	int distance = graph[1][k] + graph[k][x];         // 수행된 결과 출력

	if (distance >= INF) {
		cout << -1 << endl;
	}
	else {
		cout << distance << endl;
	}
}

