// 12_2 ���ڿ� ������
// ���ĺ� �빮�ڿ� ����(0~9)�� �̷���� ���ڿ�
// ��� ���ĺ��� ������������ �����ؼ� ��� ��, �� �ڿ� ��� ���ڸ� ���� ���� �̾ ���

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
vector<char> result;                                 // ���ĺ� ������ ���� ��� ����Ʈ
int sum = 0;                                             // ���� ���� �����ϱ� ���� ���� 
 
int main(void) {
	cin >> s;

	for (int i = 0; i < s.size(); i++) {              // ���ڸ� �ϳ� �� Ȯ��
		if (isalpha(s[i]))                              // ���ĺ��̶�� 
			result.push_back(s[i]);                // ��� ����Ʈ�� ����
		else                                               // ���ڶ��
			sum += s[i] - '0';                         // ��� ���ϱ�
	}

	sort(result.begin(), result.end());           // ���ĺ� �������� ����

	for (int i = 0; i < result.size(); i++) {        // ���ĺ� ���ʴ�� ���
		cout << result[i];
	}

	if (sum != 0)                                         // ���� 0�� �ƴ϶�� �� �ڿ� ���
		cout << sum;
	cout << '\n';
}