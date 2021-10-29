// 7-2 부품찾기
// 가지고 있느 부품N, 손님이 요청한 부품 M
// N,M 확인해서 있으면 yes, 없으면 no 출력

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 이진 탐색
int binarySearch(vector<int>& arr, int target, int start, int end) {

	while (start <= end) {
		int mid = (start + end) / 2;                               // 중간 값
		if (arr[mid] == target)                                     // 타겟을 찾으면 그 값을 출력
			return mid;                      
		else if (arr[mid] > target)                               // 타겟이 중간 값보다 작으면 왼쪽으로 이동
			end = mid - 1;         
		else                                                            // 타겟이 중간 값보다 크면 오른쪽으로 이동
			start = mid + 1;                                       
	}
	return -1;
}

void main() {
	int n, m;
	vector<int> arr;
	vector<int> targets;

	cin >> n;
	for (int i = 0; i < n; i++) {                                    // 가게에 있는 부품 arr 배열에 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                                // 가게에 있는 부품 정렬

	cin >> m;                                                         
	for (int i = 0; i < m; i++) {                                  // 손님이 요청한 부품 target 배열에 넣기
		int y;
		cin >> y;
		targets.push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int check = binarySearch(arr, targets[i], 0, n - 1);   // 탐색을 통해 부품 존재 여부 확인
		if (check != -1)
			cout << "yes ";
		else
			cout << "no ";
	}
}