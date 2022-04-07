// 문제 2869번 달팽이는 올라가고 싶다
// 달팽이는 높이가 V인 나무 막대를 올라갈 것이다.
// 낮에 A미터 올라가고 밤에 B미터 미끄러진다. 정상에 올라간 후에는 미끄러지지 않는다.
// 달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int a, b, v;
	cin >> a >> b >> v;

	int day = 0;

	day = (v - b - 1) / (a - b) + 1;

	cout << day << '\n';
}