// 문제 10773 제로
// 첫 번재 줄에 정수 K
// K개 줄에 정수가 1개씩 주어지는데, 정수가 0일 경우 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
// 모든 수를 받아 적은 후 그 수의 합 구하기

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int k;
	stack<int> num;         // 숫자를 저장하기 위한 스택

	cin >> k;
	for (int i = 0; i < k; i++) {       // 숫자를 하나씩 입력받으면서
		int x;
		cin >> x;
		if (x == 0) {                     // x가 0이면 pop
			num.pop();
		}
		else                              // 그렇지 않다면 push
			num.push(x);
	}

	int sum = 0;                       // 총 합을 저장하기 위한 변수
	while (!num.empty()) {       // 스택이 빌때까지 돌면서
		sum += num.top();         // 제일 위에 값을 더해주고
		num.pop();                   // pop
	}

	cout << sum << '\n';        // 결과 출력
}

