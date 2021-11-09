// 6_3 ������ ���� ������ �л� ����ϱ�
// N ���� �л�����, ������ �̸��� �л��� �������� ����
// ������ ���� ������ �̸��� ���

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator<(Student& other) {                           // ���� ������ '������ ���� ����'
		return this->score < other.score;
	}

};

int n;
vector<Student> v;                                                  // ������ ���� ����Ʈ ����

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {                                       // N���� �л��� �̸��� ������ ����Ʈ�� ����
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());                                       // �������� ����

	for (int i = 0; i < n; i++) {                                        // ���ĵ� ��� ���
		cout << v[i].name << ' ';
	}
}
