// 문제 1436번 영화감독 숌
// 6이 적어도 3개이상 연속으로 들어가는 수
// 제일 작은 수는 666. 그 다음으로 큰 수는 1666,2666,3666...
//  N번째 영화 제목에 들어갈 숫자를 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	int start = 666;
	int cnt = 0;
	int temp;
	cin >> n;

	while (1) {
		temp = start;
		
		while (temp > 0) {          // 숫자 안에 666이 있는지 확인
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}

		if (cnt == n) {              // n번째 숫자를 찾으면 출력
			cout << start << '\n';
			break;
		}

		start++;                      // 찾는 숫자가 아니라면 start 증가해서 다시 루프
	}
}