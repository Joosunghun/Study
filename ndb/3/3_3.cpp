// 숫자카드게임

#include <iostream>
using namespace std;

int main() {
	int card[100][100];
	int n, m;
	int i, j;
	cin >> n >> m;

	for (i = 0; i < n; i++) {                      // 2 차원 배열에 숫자 넣기
		for (j = 0; j < m; j++) {
			cin >> card[i][j];
		}
	}


}
