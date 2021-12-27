// ���� 5430�� AC
// ���� �迭�� ������ �ϱ� ���� ���� AC
// �ΰ��� ���� R(������), D(������) ����
// R�� �迭�� ������ ������ D�� ù��° ���ڸ� ������ �Լ�, �迭�� ����µ� D�� ����ϸ� ���� �߻�
// �迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷� �ۼ�

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T,n;           // �׽�Ʈ ���̽��� ������, �迭�� ����ִ� ���� ����
	string p, arr;   // ������ �Լ���, �迭
	deque<int> dq;   // �迭�� ���� ��ť

	cin >> T;

	for (int i = 0; i < T; i++) {
		dq.clear();          // ���� ��ť�� ����ϱ� ���� ��� ���� ����
		cin >> p;
		cin >> n;
		cin >> arr;
		string temp;       // ���ڸ� ���� ���� ���

		for (int i = 0; i < arr.size(); i++) {        // �迭���� ���ڸ� ��� dq�� �־���
			if (arr[i] == '[')
				continue;
			else if ('0' <= arr[i] && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool print = true;         // ������ �ƴ� ��� true
		bool reverse = true;    // ������������ ������ true
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R')           // ��ɾ R�̸� ������
				reverse = !reverse;
			else {                     // D ��� ť�� ����ٸ� error ��� 
				if (dq.empty()) {
					print = false;
					cout << "error\n";
					break;
				}
				else {
					if (reverse)           // ������������ ������ ��ť�� �� �տ� �� pop
						dq.pop_front();
					else             // �������������� ��ť�� �� �ڿ� �� pop
						dq.pop_back();
				}
			}
		}

		if (print) {                   // ������ �ƴ� ��� �� ���
			if (reverse) {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}