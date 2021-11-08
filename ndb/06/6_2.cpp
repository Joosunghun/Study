// 6_2 위에서 아래로
// 하나의 수열에서 큰수 부터 작은 수로 내림차순으로 정렬하는 프로그램

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;

bool compare(int a, int b) {                                   // 그냥 정렬하면 오름차순이므로 내림차순을 위해 만듬
	return a > b;
}

int main(void) {
	cin >> n;                                                       // n 입력 받기
	for (int i = 0; i < n; i++) {                                  // n 개의 정수를 입력받아 리스트에 저장
		int x; 
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end(), compare);                // 내림차순 저렬

	for (int i = 0; i < n; i++) {                                   // 출력
		cout << arr[i] << ' ';
	}
}