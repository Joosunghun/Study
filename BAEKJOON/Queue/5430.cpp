// 문제 5430번 AC
// 정수 배열에 연산을 하기 위해 마든 AC
// 두가지 연산 R(뒤집기), D(버리기) 존재
// R은 배열의 순서를 뒤집고 D는 첫번째 숫자를 버리는 함수, 배열이 비었는데 D를 사용하면 에러 발생
// 배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램 작성

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T,n;           // 테스트 케이스의 개수와, 배열에 들어있는 수의 개수
	string p, arr;   // 수행할 함수와, 배열
	deque<int> dq;   // 배열을 담을 디큐

	cin >> T;

	for (int i = 0; i < T; i++) {
		dq.clear();          // 다음 디큐를 사용하기 위한 모든 원소 제거
		cin >> p;
		cin >> n;
		cin >> arr;
		string temp;       // 두자리 수를 위해 사용

		for (int i = 0; i < arr.size(); i++) {        // 배열에서 숫자만 골라 dq에 넣어줌
			if (arr[i] == '[')
				continue;
			else if ('0' <= arr[i] && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool print = true;         // 에러가 아닐 경우 true
		bool reverse = true;    // 뒤집어져있지 않으면 true
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R')           // 명령어가 R이면 뒤집기
				reverse = !reverse;
			else {                     // D 라면 큐가 비었다면 error 출력 
				if (dq.empty()) {
					print = false;
					cout << "error\n";
					break;
				}
				else {
					if (reverse)           // 뒤집어져있지 않으면 디큐의 맨 앞에 값 pop
						dq.pop_front();
					else             // 뒤집어져있으면 디큐의 맨 뒤에 값 pop
						dq.pop_back();
				}
			}
		}

		if (print) {                   // 에러가 아닐 경우 값 출력
			if (reverse) {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}