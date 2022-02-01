// 문제 2941번 크로아티아 알파벳
// 단어가 주어졌을 때, 몇개의 크로아티아 알파벳으로 이루어져 있는지 출력하는 프로그램

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> arr = { "c=", "c-", "dz=","d-", "lj", "nj", "s=", "z=" };
int cnt = 0;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for (int i = 0; i < arr.size(); i++) {       // 크로아티아 문자 찾기
		while (1) {
			int idx = s.find(arr[i]);          
			if (idx == string::npos)             // 크로아티아 문자열이 없으면 break
				break;

			s.replace(idx, arr[i].length(), "*");          // 크로아티아 문자열은 한글자 인 *로 변경
		}
	}
	cnt = s.length();
	cout << cnt << '\n';
}