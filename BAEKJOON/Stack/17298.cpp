// 문제 17298번 오큰수
// 크기가 N인 수열이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
// Ai의 오큰수는 오른쪽에 있으면서 ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 오큰수 라고 한다.
// 오큰수가 없는 경우는 -1 이다.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> v;          // 수열을 입력받을 벡터
	stack<int> s;           // v[i]에 대한 인덱스

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	vector<int> ans(v.size(), -1);               // 기본값 -1을 넣고 각 수열에 대한 오큰수 값을 가질 vector

	for (int i = 0; i < v.size(); i++) {            
		while (!s.empty() && v[s.top()] < v[i]) {         // 스택이 비지않고, top값이 현재 수열보다 작으면
			ans[s.top()] = v[i];                                  // ans에 v[i] 값을 넣고
			s.pop();                                                  // pop
		}
		s.push(i);                                                   // 그렇지 않으면 i값 push
	}   
	for (int i = 0; i < n; i++) {                                   // ans의 모든 값 출력
		cout << ans[i] << ' ';
	}
}