// 문제 2562번 최댓값
// 9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int max = 0, cnt = 0;
	vector<int> arr;

	for (int i = 0; i < 9; i++) {            // 벡터에 숫자 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i < arr.size(); i++) {        
		if (arr[i] > max) {                // 현재 값이 max 값보다 크면 max에 현재 값 넣, 현재 위치 저장
			max = arr[i];
			cnt = i;
		}
	}

	cout << max << '\n';
	cout << cnt + 1 << '\n';        // 인덱스는 0부터 시작하기 때문에 1 더해줌
}