// 문제 11404번 플로이드
// n개의 도시가 있다. 한 도시에서 출발하여 다른 도시에 도착하는 m개의 버스가 있다.
// 모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램

#include <iostream>
#include <algorithm>

#define INF 987654321
#define ARR_SIZE 100+1

using namespace std;

int v, e;
int arr[ARR_SIZE][ARR_SIZE];
int from, to, weight;

void floyd() {
	for (int i = 1; i <= v; i++) {                     // i vertex를 거치는 경우
		for (int j = 1; j <= v; j++) {                 // from vertex를 거치는 경우
			for (int k = 1; k <= v; k++) {           // to vertex를 거치는 경우
				if (arr[j][i] != INF && arr[i][k] != INF)
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int main() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {                    // vertex table 초기화
		for (int j = 1; j <= v; j++) {                  
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {                     // from vertex에서 to vertex입력, 가중치 입력
		cin >> from >> to >> weight;
		if (arr[from][to] > weight)
			arr[from][to] = weight;
	}

	floyd();
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j || arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";

		}
		cout << '\n';
	}
	return 0;
}