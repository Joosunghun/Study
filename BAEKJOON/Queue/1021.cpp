// 문제 1021번 회전하는 큐
// N개의 원소를 포함하고 있는 양방향 순환 큐
// 큐에서 몇 개의 원소를 뽑아냄
// 3가지 연산 가능, 1. 첫 번째 원소 뽑아냄. 2. 왼쪽으로 한칸 이동 3. 오른쪽으로 한칸 이동
// 큐에 처음에 포함되어있던 수 N이 주어지고, 뽑아 내려고 하는 원소의 위치가 주어진다. 
// 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램

#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	int n,m;        // 큐의 크기, 찾으려하는 갯수
	deque<int> dq;
	int cnt = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {        // dq에 1부터 N까지 순서대로 넣기
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {          // m번 만큼 회전
		int x;
		cin >> x;
		int index;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == x) {
				index = i;            // 인덱스에 찾으려고 하는 수 저장
				break;
			}
		}
		if (index < dq.size() - index) {          // 인덱스 값이 deque 크기의 절반 보다 아래면
			while (true) {
				if (dq.front() == x) {                  // 찾는 값이라면 맨 앞의 값 pop
					dq.pop_front();
					break;
				}
				cnt++;                                     // 아니라면 카운트 증가시키고
				dq.push_back(dq.front());         // 맨 앞에 값 맨 뒤에 저장
				dq.pop_front();                        // 맨 앞에 값 pop
			}
		}
		else                                              // 인덱스 값이 deque 크기의 절반 보다 크면
			while (true) {
				if (dq.front() == x) {                 // 찾는 값이라면 맨 앞의 값 pop
					dq.pop_front();
					break;
				}
				cnt++;                                    // 아니라면 카운트 증가시키고
				dq.push_front(dq.back());        // 맨 뒤의 값 맨 앞에 저장
				dq.pop_back();                       // 맨 뒤의 값 pop
			}
	}
	cout << cnt << '\n';                           // 카운트 출력
}