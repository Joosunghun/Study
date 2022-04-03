// 문제 1712번 손익분기점
// 노트북을 만드는 회사에서 판매 대수에 상관없이 매년 A만원의 고정 비용이 들며, 한대의 노트북을 생산하는데에는 B만원의 가변 비용이든다.
// 총 수입이 총 비용보다 많아져 최초로 이익이 발생하는 지점을 손익분기점이라고 한다.
// A,B,C가 주어졌을 때, 손익분기점을 구하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	int ans = 0;
	cin >> a >> b >> c;
	
	if (b >= c)
		cout << "-1" << '\n';
	else {
		ans = a / (c - b) + 1;        // 고정비용에 이익을 나눈후 한대만 더 팔면 손익분기점
		cout << ans << '\n';
	}
}