// 문제 1931 회의실 배정
// 한개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만든다.
// 각 회의에 대해 시작시간과 끝나는시간이 주어져있고, 회의가 겹치지 않게 하면서 사용할 수 있는 회의의 최대 갯수
// 한 회의가 끝나는 것과 동시에 다음회의가 시작 가능
// 회의의 시작시간과 끝나는 시간이 같으면, 시작하자마자 긑나는 것으로 생각

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int, int>> time;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		time.push_back(make_pair(y, x));             // 회의가 끝나는 것과 시작하는 순으로 vector에 넣어줌
	}

	sort(time.begin(), time.end());        // 회의가 빨리 끝나는 순서대로 정렬
	int run_time = 0;                            // 회의 시간
	int count = 0;                                // 개수
	for (int i = 0; i < time.size(); i++) {
		if (run_time <= time[i].second) {         // 회의시간이 시작시간보다 작으면 
			run_time = time[i].first;                   // 회의시간에 끝나는 시간을 넣고
			count++;                                      // 회의 개수 한 개 증가
		}
	}
	cout << count << '\n';
}