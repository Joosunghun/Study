// ���� 10814 ���̼� ����
// �¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����.
// ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {        // ����ڰ� ���� ���� ����(ù��° ���Ҹ� �������� ��������)
	return a.first < b.first;
}

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, string>> person;       // ����� ������ ������� ����

	for (int i = 0; i < n; i++) {          // ���̿� �̸� ����ֱ�
		int age;
		string name;
		cin >> age >> name;
		person.push_back({ age, name });
	}

	stable_sort(person.begin(), person.end(),compare);         // ����ڰ� ���� �������� ����

	for (int i = 0; i < n; i++) {         // ���
		cout << person[i].first << ' ' << person[i].second << '\n';
	}
}