// 문제 1427번 소트인사이드
// 수가 주어지면 그 수의 각 자리수를 내림차순으로 정렬하기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> num;

bool compare(int a, int b) {                                     // 내림차순으로 만들기 위한 함수
	return a > b;
}

int main(void) {
	cin >> n;
	while (n != 0) {                                                  // n이 0이 아닐 때까지 num에 한자리씩 넣고 10으로 나누어 줌
		int x;
		x = n % 10;
		num.push_back(x);
		n /= 10;
	}

	sort(num.begin(), num.end(),compare);                // 내림차순으로 정렬
	 
	for (int i = 0; i < num.size(); i++) {                        // num의 사이즈만큼 정렬된 값 출력
		cout << num[i];
	}
}