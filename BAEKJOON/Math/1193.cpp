// 문제 1193번 분수 찾기
// 무한히 큰 배열에 분수들이 적혀있다
// 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> ... 과 같은 순서로 차례대로 1번, 2번, 3번, 4번,... N번 분수라고 하자
//  X가 주어졌을 때, X번째 분수를 구하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int i = 1;
	while (n > i) {
		n -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - n << '/' << n << '\n';
	else
		cout << n << '/' << i + 1 - n << '\n';
}