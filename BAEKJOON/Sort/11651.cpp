// 문제 11651번 좌표 정렬하기2
// 2차원 평면 위의 점 N개가 주어진다. 좌표를 y가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한다음 출력하는 프로그램 작성

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> com;             // 좌표를 담기 위한 벡터

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;                          // x값과 y값 입력
		com.push_back({ y,x });           // y 의 크기순으로 정렬하기 위해 y를 먼저 담는다
	}

	sort(com.begin(), com.end());       // 오름차순으로 정렬

	for (int i = 0; i < n; i++) {
		cout << com[i].second << ' ' << com[i].first << '\n';           // second가 x고 first가 y이므로 second 먼저 출력 후 first 출력
	}
}