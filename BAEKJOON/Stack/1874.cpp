// 문제 1874 스택 수열
// 1부터 n까지의 수를 스택에 넣었다가 봅아 늘어놓음으로써 하나의 수열을 만든다
// 스택에 push하는 순서는 오름차순을 지킨다
// 임의의 수열이 주어졌을 때 그 수열을 만들 수 있는 지 없는 지, 있다면 어떤 순서로 push와 pop을 해야하는 지 계산하는 프로그램

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	stack<int> s;
	vector<char> result;

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int x;                          
		cin >> x;                     // 수열 넣어주기

		while (cnt <= x) {         // cnt 가 원하는 값보다 작다면 
			s.push(cnt);            // cnt를 1씩 증가시키면서 스택에 push
			cnt++;
			result.push_back('+');      // push된 개수많큼 result 벡터에 + 넣기
		}
		
		if (s.top() == x) {           // 스택의 제일 위에 값이 x와 같다면
			s.pop();                   // pop 시키고
			result.push_back('-');      // result 벡터에 - 넣기
		}
		else {                       // 둘다 성립하지 않으면 NO 출력
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++) {          // result 모든 원소 출력
		cout << result[i] << '\n';
	}
}