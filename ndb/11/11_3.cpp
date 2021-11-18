// 11_3 문자열 뒤집기
// 0과 1로만 이루어진 문자열 s
// 연속된 하나 이상의 숫자를 잡고 모두 뒤집는다
// 모두 같은 숫자로 만들려고 할때 해야하는 행동의 최소 횟수

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	int count0 = 0;                                    // 전부 0으로 바뀌는 경우
	int count1 = 0;                                    // 전부 1로 바뀌는 경우

	if (s[0] == '1') {                                 // 첫 번째 원소가 1이라면
		count0 += 1;                                   // 전부 0으로 바뀌는 경우 1증가
	}
	else {                                               // 첫 원소가 0이면 전부 1로 바뀌는 경우가 1증가
		count1 += 1;
	}

	for (int i = 0; i < s.size(); i++) {              // 두 번째 원소부터 모든 원소들을 확인
		if (s[i] != s[i + 1]) {                         // 바로 앞과 원소가 다르다면
			if (s[i + 1] == '1')                         // 다음 수가 0으로 바뀌면 전부 0으로 바뀌는 경우 1증가
				count0 += 1;
			else                                            // 다음 수가 1로 바뀌면 전부 1로 바뀌는 경우 1증가
				count1 += 1;
		}
		
	}
	cout << min(count0, count1) << '\n';       // 전부 0으로 바뀌는 경우와 전부 1로 바뀌는 경우 중 최솟값 출력
}