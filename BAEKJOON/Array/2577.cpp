// 문제 2577번 숫자의 개수
// 세 개의 자연수 A, B, C가 주어질 때, A x B x C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지 구하는 프로그램

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int a, b, c;
	int arr[10] = { 0 };

	cin >> a >> b >> c;

	int result = a * b * c;

	while (result != 0) {                 // 1의 자리를 받아오기
		arr[result % 10] += 1;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}
