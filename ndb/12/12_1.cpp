// 11_7 ��Ű ��Ʈ����Ʈ
// ���� ���� N
// N�� ������ ������ ���� �κ��� �� �ڸ��� �հ�, ������ �κ��� �� �ڸ����� ���� �����ϸ� ��Ű ��Ʈ����Ʈ ��� ��� ����
// N�� �־����� ��Ű ��Ʈ����Ʈ�� ����� �� �ִ� �������� �˷��ִ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

string n;
int sum;

int main(void) {
	cin >> n;

	for (int i = 0; i < n.size() / 2; i++) {                       // ���ʿ��� ���ݱ��� �� �� ���ϱ�
		sum += n[i] - '0';
	}

	for (int i = n.size() / 2; i < n.size(); i++) {             // ����� ������ �� ����
		sum -= n[i] - '0';
	}

	if (sum == 0)                                                     // �� ���� �����ϸ� 0 �̹Ƿ� ��� 
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';
}