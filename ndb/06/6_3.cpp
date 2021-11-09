// 6_3 성적이 낮은 순서로 학생 출력하기
// N 명의 학생정보, 정보는 이름과 학생의 성적으로 구분
// 성적이 낮은 순부터 이름을 출력

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

	bool operator<(Student& other) {                           // 정렬 기준은 '점수가 낮은 순서'
		return this->score < other.score;
	}

};

int n;
vector<Student> v;                                                  // 정보를 받을 리스트 생성

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {                                       // N명의 학생의 이름과 점수를 리스트에 저장
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());                                       // 오름차순 정렬

	for (int i = 0; i < n; i++) {                                        // 정렬된 결과 출력
		cout << v[i].name << ' ';
	}
}
