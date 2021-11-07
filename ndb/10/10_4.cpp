// 10_4 커리큘럼
// N개의 강의, 1번부터 N번까지 번호가 있음, 동시에 여러 강의 수강 가능
// 선수 강의가 있을 때는 선수 강의를 먼저 듣고 강의를 들어야함
// N개의 강의 정보가 주어 졌을 떄 N개의 강의에 대하여 수강하기 까지 걸리는 최소시간을 각각 출력

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;                                                    // 강의의 개수
int indegree[501];                                  // 모든 노드에 대한 진입차수 0으로 초기화
vector<int> graph[501];                          // 각 노드에 연결된 간선 정보를 담기위한 연결 리스트 초기화
int times[501];                                       // 각 강의 시간을 0으로 초기화

void topologysort() {                               // 위상 정렬 함수
	vector<int> result(501);                        // 알고리즘 수행 결과를 담을 리스트
	for (int i = 1; i <= n; i++) {
		result[i] = times[i];
	}

	queue<int> q;                                     // 큐 사용

	for (int i = 1; i <= n; i++) {                     // 처음 시작할 때 진입 차수가 0인 노드를 큐에 삽임
		if (indegree[i] == 0) {
			q.push(1);
		}
	}

	while (!q.empty()) {                             // 큐가 빌 때까지 반복
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {                 // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]] -= 1;
			if (indegree[graph[now][i]] == 0) {                     // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
				q.push(graph[now][i]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << result[i] << endl;
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {                   // 방향 그래프의 모든 간선 정보 입력 받기
		int x;                                           // 첫 번째 수는 시간 정보
		cin >> x;
		times[i] = x;
		while (true) {                               // 해당 강의를 듣기 위해 먼저 들어야 하는 강의들의 번호 입력
			cin >> x;
			if (x == -1) break;
			indegree[i] += 1;
			graph[x].push_back(i);
		}
	}
	topologysort();
}

