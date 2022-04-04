// 문제 2292번 벌집
// 육각형으로 이루어진 벌집에 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호로 주소를 매긴다
// 숫자 N이 주어졌을 떄, 벌집 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지를 계산하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int i = 0;
	for (int sum = 2; sum <= n; i++) {        // 바깥 층으로 나갈때 마다 6*층개수 만큼 범위가 늘어난다
		sum += 6 * i;
	}
	if (n == 1)
		i = 1;
	cout << i;
	return 0;
}