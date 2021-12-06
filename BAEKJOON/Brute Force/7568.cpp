// 문제 7568번 덩치
// N명의 집단에서 각 사람의 덩치는 자신보다 더 큰 덩치의 사람 수로 저해진다
// 자신보다 덩치큰사람이 k명이면 그 사람의 덩치 등수는 K+1이다 
// n명으로 이루어진 집단에서 각 사람의 덩치 등수를 출력하시오

#include <iostream>
using namespace std;

int main(void) {
	int n, x, y;
	int count;
	int arr[51][3];           // 0열 키, 1열 몸무게, 2열 등수 저장

	cin >> n;

	for (int i = 0; i < n; i++) {         // 사람 수 많큼 몸무게와 키 받아오기
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {        // 사람 수 만큼 돌아가며
		count = 1;                        // 1등부터니 1등으로 초기화
		for (int j = 0; j < n; j++) {               
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])        // 덩치가 더 작으면 카운트 증가
				count++;
		}
		arr[i][2] = count;             // 2열에 등수를 넣어줌
	}

	for (int i = 0; i < n; i++) {        // 모든 등수 출력
		cout << arr[i][2] << ' ';
	}
}
