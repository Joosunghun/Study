// 문제 5622번 다이얼
// 전화를 걸기 위해, 숫자를 하나 눌러 다음 금속 핀이 있는곳까지 시계방향으로 돌려야한다.
// 숫자를 하나 누르려면 다이얼을 처음 위치에서 다시 돌려야한다.
// 전화 번호에 있는 문자로 각 숫자를 외웠을 때, 외운 단어가 주어지고, 그 전화를 걸기위해 필요한 최소 시간을 구하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int arr[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };        // 각 알파벳에 대한 시간을 미리 설정
	int sum = 0;
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 65;             // 아스키 코드로 계산
		sum += arr[index];
	}

	cout << sum << '\n';
}