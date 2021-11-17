// 11_2 곱하기 혹은 더하기
// 각 자리가 숫자로만 이루어진 문자열 S
// 왼쪽 부터 오른쪽으로 숫자를 확인해서 숫자 사이에 x 혹은 + 연산자를 넣어 결과적으로 만들어질 수 있는 수의 최댓값을 구하는 프로그램
// 모든 연산은 왼쪽에서 부터 순서대로 이루어짐

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;                                        // 문자열을 저장하기 위한 S선언
	cin >> S;                                       // S 입력
	         
	int result = S[0] - '0';                      // 첫번째 문자를 숫자로 변경한 값을 대입
	for (int i = 1; i < S.size(); i++) {
		int num = S[i] - '0';                     // 두번째 문자부터 숫자로 변경한 값을 대입
		if (result <= 1 || num <= 1) {         // 둘중 하나라도 0 이나 1 이면 더하기 수행
			result += num;
		}
		else
			result *= num;
	}

	cout << result << '\n';
}