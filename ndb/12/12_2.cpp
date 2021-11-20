// 12_2 문자열 재정렬
// 알파벳 대문자와 숫자(0~9)로 이루어진 문자열
// 모든 알파벳을 오름차순으로 정렬해서 출력 후, 그 뒤에 모든 숫자를 더한 값을 이어서 출력

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
vector<char> result;                                 // 알파벳 저장을 위한 결과 리스트
int sum = 0;                                             // 숫자 합을 저장하기 위한 변수 
 
int main(void) {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {              // 문자를 하나 씩 확인
		if (isalpha(s[i]))                              // 알파벳이라면 
			result.push_back(s[i]);                // 결과 리스트에 저장
		else                                               // 숫자라면
			sum += s[i] - '0';                         // 모두 더하기
	}

	sort(result.begin(), result.end());           // 알파벳 오름차순 정렬

	for (int i = 0; i < result.size(); i++) {        // 알파벳 차례대로 출력
		cout << result[i];
	}

	if (sum != 0)                                         // 합이 0이 아니라면 맨 뒤에 출력
		cout << sum;
	cout << '\n';
}