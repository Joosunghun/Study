// 문제 2798번 블랙잭
// 카드의 합이 한도 내에서, 최대한 크게 만드는 게임
// N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 최대한 가까운 카드 3장의 합 구하기

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	vector<int> card;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {                      // 모든 카드 값 받아오기
		int x;
		cin >> x;
		card.push_back(x);
	}

	int result = 0;                                      // 결과 값 초기화
	for (int i = 0; i < n; i++) {                       // 3장의 합의 모든 경우의 수를 구하기 위해 3중 for문 사용
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((card[i] + card[j] + card[k] <= m) && (card[i] + card[j] + card[k] > result))                       // 3장의 합이 m보다 작고 그 전의 결과 값 보다 클 때 
					result = card[i] + card[j] + card[k];                                                                                // 결과 값은 3장의 합
			}
		}
	}

	cout << result << '\n';                         // 결과 출력
}