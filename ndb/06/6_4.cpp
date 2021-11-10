// 6_4 두 배열의 원소 교체
// 두 배열은 N개 의 원소로 구성 되어 있고 K번 바꿔치기 연산 수행 가능
// 바꿔치기가 끝났을 때 배열 A의 모든 원소 합이 최댓값이 되도록 프로그램 작성

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
vector<int> b;

bool compare(int x, int y) {                                   // 내림 차순을 위해 만듬
	return x > y;
}

int main() {
	cin >> n >> k;                                                 // n, k 입력받기

	for (int i = 0; i < n; i++) {                                   // 배열 A의 모든 원소 입력받기
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; i++) {                                    // 배열 B의 모든 원소 입력받기
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());                                    // A 오름차순 정렬
	sort(b.begin(), b.end(), compare);                      // B 내림차순 정렬

	for (int i = 0; i < k; i++) {                                     // 첫 번째 인덱스 부터 확인하며, 두 배열의 원소를 K번 까지 비교
		if (a[i] < b[i])                                               // A의 원소가 B 워소보다 작을경우
			swap(a[i], b[i]);                                       // 두 원소를 교체
		else break;                                                    // 크거나 같으면 반복문 탈출
	}

	int result = 0;
	for (int i = 0; i < n; i++) {                                       // 배열 A의 모든 원소의 합을 출력
		result += a[i];
	}

	cout << result << endl;
}