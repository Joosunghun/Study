// 문제 10809번 알파벳 찾기
// 알파벳 소문자로만 이루어진 단어 S
// 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 위치를, 포함 되어 있지 않은 경우에는 -1을 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";         // 각 자리의 알파벳과 비교를 위한 전체 알파벳 문자열

	for (int i = 0; i < alphabet.size(); i++) {                       // 돌리면서 자리 찾기
		cout << (int)s.find(alphabet[i]) << ' ';
	}


}