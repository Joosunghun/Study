// 11_7 럭키 스트레이트
// 현재 점수 N
// N을 반으로 나누어 왼쪽 부분의 각 자릿수 합과, 오른쪽 부분의 각 자릿수의 합이 동일하면 럭키 스트레이트 기술 사용 가능
// N이 주어지면 럭키 스트레이트를 사용할 수 있는 상태인지 알려주는 프로그램

#include <iostream>
#include <string>
using namespace std;

string n;
int sum;

int main(void) {
	cin >> n;

	for (int i = 0; i < n.size() / 2; i++) {                       // 왼쪽에서 절반까지 의 합 더하기
		sum += n[i] - '0';
	}

	for (int i = n.size() / 2; i < n.size(); i++) {             // 가운데서 끝까지 합 빼기
		sum -= n[i] - '0';
	}

	if (sum == 0)                                                     // 두 값이 동일하면 0 이므로 출력 
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';
}