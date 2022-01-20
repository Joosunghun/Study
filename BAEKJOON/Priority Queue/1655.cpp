// 문제 1655번 가운데를 말해요
// 정수를 하나씩 외칠 때 마다 지금까지 나온 수 중에서 중간 값을 출력하는 프로그램
// 만약 외친 개수가 짝수라면 가운데 있는 두 수 중 작은 수를 말해야 한다.

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (maxq.empty())        // 처음 큐가 비었을 경우
			maxq.push(x);
		else {
			if (maxq.size() > minq.size())         // 최대힙의 크기가 더 크면 최소 힙에 값을 넣는다
				minq.push(x);
			else                                             // 크기가 같으면 최대 힙에 값을 넣는다 
				maxq.push(x);


			if (maxq.top() > minq.top()) {          // 최대 힙의 top값이 최소 힙의 top보다 크다면 교환
				int maxtop = maxq.top();
				int mintop = minq.top();
				maxq.pop();
				minq.pop();
				maxq.push(mintop);
				minq.push(maxtop);
			}
		}

	cout << maxq.top() << '\n';
	}


}