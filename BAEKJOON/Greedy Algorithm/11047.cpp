// 문제 11047번 동전 0
// 가지고 있는 동전의 종류 N, 각각의 동전 개수는 매우 많음
// 동전을 적절히 사용해서 합을 K로 만드려고 함
// 이때 필요한 동전 개수의 최솟값

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

bool compare(int a, int b) {                                 // 내림차순으로 정렬하기 위해 만들어 줌 
	return a > b;
}

int main(void) {
	cin >> n >> k;                                               // 동전 개수 및 총 가격
	for (int i = 0; i < n; i++) {                                 // 동전의 모든 원소 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int result = 0;
	sort(arr.begin(), arr.end(), compare);               // 동전의 크기가 큰 것부터 정렬
	for (int i = 0; i < n; i++) {                               
		while (k - arr[i] >= 0) {                               // 총 가격에서 크기가 큰 동전부터 뺀 값이 0이 넘을 경우
			result++;                                                // 동전 하나 더하고
			k -= arr[i];                                             // 그 가격만큼 빼기
		}
	} 

	cout << result << endl;                                    // 총 결과 출력
}