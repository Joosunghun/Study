// 11_5 볼링공 고르기
// A,B 두 사람이 서로 무게가 다른 볼링 공을 고름
// N개의 볼링 공 1번부터 순서대로 부여, 1부터 M까지
// N개의 볼링공으로 두 사람이 고를 수 있는 경우의 수를 구하기

#include <iostream>
using namespace std;

int n, m;
int arr[11];                                   // 1부터 10까지의 무게를 담을 수 있는 배열

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;

	for (int i = 1; i <= m; i++) {          // 1부터 m까지의 각 무게에 대하여 처리
		n -= arr[i];                          // 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수) 제외
		result += arr[i] * n;               // B가 선택하는 경우의 수와 곱해주기
	}

	cout << result << '\n';
}

