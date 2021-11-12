// 문제 10989번 수 정렬하기 3
// N 개의 수가 주어졌을 때, 오름 차순으로 정렬하는 프로그램

#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);                        // 프로그램의 입출력 속도를 증가시키기 위한 코드
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[10001] = { 0, };                                 // 총 크기가 10000이므로 선언과 동시에 0 으로 초기화
	cin >> n;
	for (int i = 0; i < n; i++) {                              // 모든 원소 입력받기
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i < 10001; i++) {                        // 배열의 전체를 조회하는데 0인 값은 제외시키고 배열의 요소 값만큼 인덱스 값을 출력
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
			}
		}
	}
	return 0;
}