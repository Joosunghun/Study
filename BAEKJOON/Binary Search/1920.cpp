// 문제 1920 수 찾기
// N개의 정수가 주어져 있을 때, 이 안에 X라는 정수가 존재하는 지 알아내는 프로그램 작성

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& arr, int target, int start, int end) {       // 이진탐색
	while (start <= end) {                  
		int mid = (start + end) / 2;                  // 중간 값
		if (arr[mid] == target)                        // 중간 값이 타겟이면 
			return 1;                                      // 1을 리턴
		else if (arr[mid] > target)                   // 중간 값이 타겟보다 크면 왼쪽 절반에서 탐색
			end = mid - 1;                             
		else                                                // 중간 값이 타겟보다 작으면 오른쪽 절반에서 탐색
			start = mid + 1;
	}
	return 0;
}

int main(void) {
	int n, m;
	vector<int> arr;
	vector<int> target;
	
	cin >> n;
	for (int i = 0; i < n; i++) {            // n값 받아오기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());       // n 값 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {           // m값 받아오기
		int x;
		cin >> x;
		target.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		int check = binary_search(arr, target[i], 0, n - 1);     // 이진탐색 수행
		if (check == 1)                   // 1을 반환하면 1 출력
			cout << 1 << '\n';
		else                                 // 그렇지 않으면 0 출력
			cout << 0 << '\n';
	}

}