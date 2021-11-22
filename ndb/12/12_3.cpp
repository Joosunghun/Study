// 12_3 문자열 압축
// 문자열에서 같은 값이 연속해서 나타나는 것을 그 문자의 개수와 반복되는 값으로 표현하여 더 짧은 문자열로 줄여서 표현하는 알고리즘 구현

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.size();                                          // 결과값을 현재 사이즈로 초기화
	for (int i = 1; i <= s.size() / 2; i++) {                       // 문자열 1개로 압축할때부터 압축 단위를 늘려가며
		string compressed = "";
		string prev = s.substr(0, i);                               // substr(a,b) => a 부터 b만큼의 문자열 추출 
		int count = 1;                                                  // 최솟값 1

		for (int j = i; j < s.size(); j += i) {                       // 압축 단위 만큼 증가시키면서 이전 문자열과 비교
			if (prev == s.substr(j, i))                              // 앞의 문자와 뒤의 문자가 같으면 count 증가
				count += 1;
			else {                                                       // 다른 문자열이 나왔다면
				compressed += (count >= 2)? to_string(count) + prev : prev;
				prev = s.substr(j, i);                               // 상태 초기화
				count = 1;
			}
		}

		compressed += (count >= 2) ? to_string(count) + prev : prev;          // 남아있는 문자열에 대해서 처리
		answer = min(answer, (int)compressed.size());                           // 만들어지는 압축 문자열 중 가장 짧은것을 반환
	}

	return answer;                          // answer 리턴
}

int main(void) {                            // 정답 확인용 함수
	string s;
	cin >> s;
	cout << solution(s) << '\n';
}