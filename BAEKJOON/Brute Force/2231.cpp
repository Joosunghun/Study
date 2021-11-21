// 문제 2231번 분해합
// 어떤 자연수 N, 분해합은 N과 N을 이루는 각 자리수 합
// M의 분해합이 N인경우, M을 N의 생성자라 함
// 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램 작성

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int sum = 0;
	int part = 0;
	for (int i = 0; i < n; i++) {                    // n보다 작은 모든 자연수를 비교해가며
		sum = i;
		part = i;

		while (part) {                                // part 동안 반복
			sum += part % 10;                      // 합에다가 10으로 나눈 나머지를 더함
			part /= 10;                                 // part에 10을 나눔
		}

		if (n == sum) {                               // while 문이 끝나고 n이 sum과 같다면
			cout << i << '\n';                      // i 출력
			return 0;
		}
	}
	cout << "0" << '\n';                           // 값이 없다면 0 출력
}