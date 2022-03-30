// 문제 9372번 상근이의 여행
// N개국을 여행하는데 가장 적은 종류의 비행기를 타고 국가들을 이동하려고 한다.
// 비행 스케줄이 주어졌을 때, 가장 적은 종류의 비행기를 타고 모든 국가들을 여행할 수 있는 프로그램
// 다른 국가로 이동할 때, 다른 국가를 거쳐 가도(방문한 국가도 가능) 상관없음

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int a, b;
		while (m--) {
			cin >> a >> b;
		}

		cout << n - 1 << '\n';
	}
}