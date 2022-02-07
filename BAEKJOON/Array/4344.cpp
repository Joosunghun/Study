// 문제 4344번 평균은 넘겠지
// 첫째 줄에 테스트 케이스의 개수 C
// 둘째 줄부터 각 케이스마다 학생 수, N명의 점수
// 각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수 셋째 자리까지 출력

#include <iostream>
using namespace std;

int main(void) {
	int c, n, num, avg;
	int score[1000] = { 0 };
	double result;
	cin >> c;

	for (int i = 0; i < c; i++) {
		avg = 0;
		num = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {            // 평균을 구하기 위해 전체 합 구하기
			cin >> score[j];
			avg += score[j];
		}
		avg /= n;                                  // 전체 합에 사람 수를 나눠 평균 구하기
		
		for (int j = 0; j < n; j++) {             // 평균보다 높은 사람의 수 구하기
			if (score[j] > avg)
				num++;
		}
		result = (double)num / n * 100;

		cout << fixed;             // fixed = 소수점을 고정시켜 표현
		cout.precision(3);        // 소수점 3자리 까지 표현
		cout << result << '%' << '\n';
	}
}