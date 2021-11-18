// 11_4 만들수 없는 금액
// N개의 동전
// 이 동전을 이용하여 만들 수 없는 양의 정수 금액 중 최솟값


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> price;

	cin >> n;
	for (int i = 0; i < n; i++) {                        // 모든 동전의 가격 받아오기
		int x;
		cin >> x;
		price.push_back(x);
	}

	sort(price.begin(), price.end());             // 동전을 가격이 작은 수 부터 정렬
	
	int result = 1;                                        // 최솟값 1
	for (int i = 0; i < n; i++) {                        
		if (result < price[i])                           // 최솟값이 현재 가격보다 낮으면 거기서 멈춤
			break;
		result += price[i];                              // 최솟값에 가격만큼 더해줌
	}

	cout << result << '\n';                          // 결과 출력
}