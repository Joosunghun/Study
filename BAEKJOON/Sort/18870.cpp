// 문제 18870 좌표 압축
// 수직선 위에 N개의 좌표가 있다. 이 좌표를 압축하려고 한다.
// 좌표를 압축한 결과는 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
// 좌표 압축을 적용한 결과를 출력하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int,int>> num;        // 좌표 값과 그 값의 번호를 담는 벡터
	vector<int> ans(1000001);         // 답을 담을 벡터
	cin >> n;
	

	for (int i = 0; i < n; i++) {          // 좌표마다 값,index를 vecotr pair 형태로 저장
		int x;
		cin >> x;
		num.push_back({ x,i });
	}

	sort(num.begin(), num.end());       // 값을 기준으로 오름차순 정렬
	int pivot = num[0].first;                  // 기준값은 제일 작은 원소
	int cnt = 0;
	ans[num[0].second] = 0;             // 제일 작은 원소를 압축하면 0

	for (int i = 0; i < n; i++) {              // 정렬된 상태에서 답을 ans에 중복을 고려하여 저장
		if (pivot == num[i].first)            // 제일 작은 원소면 0
			ans[num[i].second] = cnt;
		else {                                   // 원소 값이 커질때 마다
			ans[num[i].second] = ++cnt;  // cnt 증가시키고 ans에 넣어줌
			pivot = num[i].first;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}