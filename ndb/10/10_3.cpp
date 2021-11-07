// 10_3 도시 분할 계획
// N개의 집과 M개의 길, 길을 유지하는 유지비, 길의 방향성 x
// 마을을 2개로 분할 하려고 함, 마을에는 꼭 하나의 집이 있어야하고, 마을 안에 있는 두 집 사이에 경로가 항상 존재해야 함
// 겹치는 길을 모두 없애고 나머지 길의 유지비를 최소로 하고 싶음
// 집의 개수 N, 길의 개수 M
// A, B, C -> A와 B를 연결하는 길의 유지비
// 유지비 합의 최솟값 출력

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;                                                 // 집의 개수와 길의 개수
int parent[100001];                                  // 부모 테이블 초기화
vector<pair<int, pair<int, int>>> edge;        // 모든 간선을 담을 리스트
int result = 0;                                          // 최종 비용을 담을 변수

int findParent(int x) {                               // 루트 노드가 아니라면, 루트 노드를 찾을 때 까지 재귀 
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int n, int m) {                 // 두 원소가 속한 집합 합치기
	n = findParent(n);
	m = findParent(m);
	if (n < m) parent[m] = n;
	else parent[n] = m;
}

int main(void) {
	cin >> n >> m;                                   // 집의 개수와, 길의 개수

	for (int i = 0; i < n; i++) {                      //  부모 테이블상에서, 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {                      // 모든 길에 대한 정보 입력 받기
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back({ cost,{a,b} });      // 비용 순으로 정렬하기 위해 튜플의 첫 번째 원소를 비용으로 설정
	}

	sort(edge.begin(), edge.end());            // 비용 순으로 정렬
	int last = 0;                                          // 최소 신장 트리에 퐇마되는 간선 중 비용이 가장 큰 간선

	for (int i = 0; i < edge.size(); i++) {         // 간선을 하나씩 확인
		int cost = edge[i].first;
		int n = edge[i].second.first;
		int m = edge[i].second.second;
		if (findParent(n) != findParent(m)) {     // 사이클이 발생하지 않으면 집합에 포함
			unionParent(n, m);
			result += cost;
			last = cost;
		}
	}

	cout << result - last << endl;
}