// 문제 10814 나이순 정렬
// 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
// 회원들의 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {        // 사용자가 정한 정렬 기준(첫번째 원소를 기준으로 오름차순)
	return a.first < b.first;
}

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, string>> person;       // 사람의 정보를 담기위한 벡터

	for (int i = 0; i < n; i++) {          // 나이와 이름 담아주기
		int age;
		string name;
		cin >> age >> name;
		person.push_back({ age, name });
	}

	stable_sort(person.begin(), person.end(),compare);         // 사용자가 정한 기준으로 정렬

	for (int i = 0; i < n; i++) {         // 출력
		cout << person[i].first << ' ' << person[i].second << '\n';
	}
}