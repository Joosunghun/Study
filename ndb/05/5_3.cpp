// 5_3 음료수 얼려먹기
// N X M 얼음틀, 구멍이 뚤린 곳은 0, 칸막이가 존재하는 부분은 1
// 구멍이 뚫린 부분은 상, 하, 좌, 우로 붙어 있는 경우 서로 연결 되어있음
// 첫 번째 줄에 얼음틀의 세로 길이와 가로 길이가 주어진다
// 한 번에 만들 수 있는 아이스크림 개수 출력

#include <iostream>

using namespace std;

int n, m;
int graph[1000][1000];

bool dfs(int x, int y) {                                             // DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
	if (x <= -1 || x >= n || y <= -1 || y >= m) {              // 주어진 범위를 벗어나는 경우 즉시 종료
		return false;
	}
	if (graph[x][y] == 0) {                                         // 현재 노드를 방문하지 않았다면
		graph[x][y] = 1;                                           // 해당 노드 방문 처리
		dfs(x - 1, y);                                                // 상, 하 , 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                                   // 2차원 리스트의 맵 정보 입력 받기
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	int result = 0;               
	for (int i = 0; i < n; i++) {                                   // 모든 노드에 대하여 음료수 채우기
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {                                           // 현재 위치에서 DFS 수행
				result += 1;
			}
		}
	}
	cout << result << endl;
}