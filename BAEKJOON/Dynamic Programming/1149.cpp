// 문제 1149번 RGB거리
// N개의 집, 1번부터 N번 집이 순서대로 있음
// 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 함
// 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 모든 집을 칠하는 비용의 최솟값을 구하라
// 조건 : 양 옆의 집과 색이 달라야함

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int house[1001][3];       // 집을 칠했을 때 비용을 최솟값으로 구하고 저장하기 위한 배열
	int cost[3];
	int result = 0;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {                                             // house[i]가 한 색으로 칠해지기 위해서는 이전 집과 다른 색이어야 한다.
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = min(house[i - 1][1],house[i - 1][2]) + cost[0];        // i번째 집을 빨강색으로 칠할 때의 최소 비용
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];       // 초록색으로 칠할 때의 최소비용
		house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];       // 파란색으로 칠할 때의 최소비용
	}

	result = min(house[n][2], min(house[n][0], house[n][1]));         // 결과값 = n번째 집을 칠했을 때 구해지는 최솟값
	cout << result << '\n';
}