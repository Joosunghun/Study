// 문제 1546번 평균
// 점수 중 최고 점을 골라 이 값을 M이라고 한 후 모든 점수를 점수/M*100으로 고쳤다
// 새로운 방법으로 평균을 구하는 프로그램

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	double arr[1001];
	double sum = 0;
	double avg = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {        // 점수 받아오기
		cin >> arr[i];
	}

	sort(arr, arr+n);             // 점수를 오름차순으로 정렬

	for (int i = 0; i < n; i++) {          // 고친 점수들의 합 구하기
		sum += arr[i] / arr[n - 1] * 100;
	}

	avg = sum / n;           // 과목 개수로 나누어 평균 구하기
	cout << avg << '\n';

}