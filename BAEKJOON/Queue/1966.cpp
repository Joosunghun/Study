// 문제 1966번 프린터 큐
// 조건에 따라 인쇄하는 프린터기
// 1. 현재 큐의 가장 앞에 있는 문서의 중요도를 확인한다.
// 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있으면, 이 문서를 인쇄하지 않고 큐의 맨 뒤에 재배치, 제일 높다면 인쇄
// 첫 번째 줄에는 문서의 개수, 몇 번째로 인쇄되었는지 궁금한 문서가 현재 큐의 몇 번째에 놓여있는지를 타나내는 정수, 맨 왼쪽은 0번째
// 두 번째 줄에는 N개의 문서의 중요도가 차례대로 주어진다.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int count = 0;
	int test_case;      // 몇회 반복할 건지
	int n, m, ipt;        // 문서의 개수, 필요한 문서의 위치, 중요도
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		count = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++) {
			cin >> ipt;
			q.push({ j,ipt });             // 큐에 필요한 문서의 위치와, 중요도 넣기
			pq.push(ipt);                  // 우선순위 큐에 중요도 넣기
		}
		while (!q.empty()) {
			int index = q.front().first;         // 인덱스 값은 필요한 문서의 위치
			int value = q.front().second;    // value값은 중요도
			q.pop();                            // 첫번재 큐를 뺀다
			if (pq.top() == value) {          // 우선순위 큐의 top 값이 중요도와 같으면
				pq.pop();                        // pop한 후 카운트 증가
				count++;
				if (index == m) {             // 인덱스가 찾는 값이라면 
					cout << count << '\n';      // 카운트 출력
					break;
				}
			}
			else                                     // 우선순위 큐의 top 값이 중요도와 다르면
				q.push({ index,value });            // 큐의 맨뒤에 삽입
		}
	}
}