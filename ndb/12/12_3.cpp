// 12_3 ���ڿ� ����
// ���ڿ����� ���� ���� �����ؼ� ��Ÿ���� ���� �� ������ ������ �ݺ��Ǵ� ������ ǥ���Ͽ� �� ª�� ���ڿ��� �ٿ��� ǥ���ϴ� �˰��� ����

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.size();                                          // ������� ���� ������� �ʱ�ȭ
	for (int i = 1; i <= s.size() / 2; i++) {                       // ���ڿ� 1���� �����Ҷ����� ���� ������ �÷�����
		string compressed = "";
		string prev = s.substr(0, i);                               // substr(a,b) => a ���� b��ŭ�� ���ڿ� ���� 
		int count = 1;                                                  // �ּڰ� 1

		for (int j = i; j < s.size(); j += i) {                       // ���� ���� ��ŭ ������Ű�鼭 ���� ���ڿ��� ��
			if (prev == s.substr(j, i))                              // ���� ���ڿ� ���� ���ڰ� ������ count ����
				count += 1;
			else {                                                       // �ٸ� ���ڿ��� ���Դٸ�
				compressed += (count >= 2)? to_string(count) + prev : prev;
				prev = s.substr(j, i);                               // ���� �ʱ�ȭ
				count = 1;
			}
		}

		compressed += (count >= 2) ? to_string(count) + prev : prev;          // �����ִ� ���ڿ��� ���ؼ� ó��
		answer = min(answer, (int)compressed.size());                           // ��������� ���� ���ڿ� �� ���� ª������ ��ȯ
	}

	return answer;                          // answer ����
}

int main(void) {                            // ���� Ȯ�ο� �Լ�
	string s;
	cin >> s;
	cout << solution(s) << '\n';
}