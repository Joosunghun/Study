// 문제 3052번 나머지
// 두 자연수 A와 B가 있을 때, A % B는 A를 B로 나눈 나머지이다.
// 수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int num;
	int rm[42] = { 0 };
	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num;
		rm[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (rm[i] != 0)
			cnt++;
	}

	cout << cnt << '\n';
}