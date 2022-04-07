// 문제 2775번 부녀회장이 될테야
// 아파트에 거주하려면 조건이 있다.
// a층 b호에 살려면 자신의 아래층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야한다 라는 조건이다
// 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을때, 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하는 프로그램
// 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.

#include <iostream>
using namespace std;

int t;
int arr[15][15];

int main(void) {
	cin >> t;

	for (int i = 0; i < 15; i++)
		arr[0][i] = i;

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++)
				arr[i][j] += arr[i - 1][k];
		}
	}

	while (t--) {
		int k, n;
		cin >> k >> n;

		cout << arr[k][n] << '\n';
	}
}