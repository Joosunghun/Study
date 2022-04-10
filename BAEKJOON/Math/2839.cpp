// 문제 2839번 설탕 배달
// 사탕가게에 설탕 정확하게 n킬로램을 배달해야한다.
// 설탕 봉지는 3키로와 5키로가 있다.
// 설탕을 정확하게 N킬로 그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a, b;
	a = n / 5;
	while (1) {
		if (a < 0) {
			cout << "-1";
			return 0;
		}
		if ((n - (5 * a)) % 3 == 0){
			b = (n - (5 * a)) / 3;
			break;
		}
		a--;
	}

	cout << a + b;
	return 0;
}