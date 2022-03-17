// 문제 1956번 운동
// V개의 마을과 E개의 도로로 구성되어 있는 도시, 일방통행 도로
// 1번부터 V번까지 번호가 매겨져있음
// 운동을 하기 위한 경로를 찾을때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램

#include <iostream>
#define MAX 401
using namespace std;

const int INF = 987654321;
int v, e, result = INF;
int arr[MAX][MAX];

int main(void) {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {            // 길 없음
		for (int j = 1; j <= v; j++) 
			arr[i][j] = INF;
	}

	for (int i = 0; i < e; i++) {              // 길 있음
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y] = z;
	}

	for (int k = 1; k <= v; k++) {         // 플로이드 워셜 알고리즘 , k = 거쳐가는 노드
		for (int i = 1; i <= v; i++) {         // i = 출발노드
			for (int j = 1; j <= v; j++) {       // j = 도착 노드
				if (arr[i][j] > arr[i][k] + arr[k][j])         // 더 짧은 길 탐색
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= v; i++)                // 다시 시작점으로 돌아온 값중 가장 짧은 길 갱신
		result = min(result, arr[i][i]);

	cout << ((result == INF) ? -1 : result);
}

