// 문제 2908번 상수
// 세 자리 수 두 개가 주어진다.
// 두 수를 거꾸로 읽어, 더 큰 수를 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string x, y;
	string nx, ny;

	cin >> x >> y;
	for (int i = 2; i >= 0; i--) {          // 두 수를 역으로 저장 
		nx += x[i];
		ny += y[i];
	}

	cout << max(nx, ny);          // 두 값중 큰 값 출력
}