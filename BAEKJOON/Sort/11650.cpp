// 문제 11650번 좌표 정렬하기
// 2차원 평면 위에 점 N개 주어짐
// 좌표를 x좌표가 증가하는 순으로, 좌표가 같으면 y좌표가 증가하는 순서로 정렬하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int, int>> arr;                                                  // 좌표를 저장하기 위한 2차원 배열 

	cin >> n;
	for (int i = 0; i < n; i++) {                                                   // 모든 좌표값 받아오기
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end());                                             // first를 기준으로 오름차순 정렬 후 같으면 second를 기준으로 오름차순 정렬

	for (int i = 0; i < n; i++) {                                                  // 결과값 출력
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}