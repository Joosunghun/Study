// ���� 10809�� ���ĺ� ã��
// ���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S
// ������ ���ĺ��� ���ؼ�, �ܾ ���ԵǾ� �ִ� ��쿡�� ó�� ��ġ��, ���� �Ǿ� ���� ���� ��쿡�� -1�� ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";         // �� �ڸ��� ���ĺ��� �񱳸� ���� ��ü ���ĺ� ���ڿ�

	for (int i = 0; i < alphabet.size(); i++) {                       // �����鼭 �ڸ� ã��
		cout << (int)s.find(alphabet[i]) << ' ';
	}


}