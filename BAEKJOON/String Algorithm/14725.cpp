// 문제 14725번 개미굴
// 첫 번째 줄은 로봇 개미가 각 층을 따라 내려오면서 알게 된 먹이의 정보 개수 N개가 주어진다.
// 두 번째 줄부터 n+1 번째 줄까지, 각 줄의 시작은 로봇 개미 한마리가 보내준 먹이 정보 개수 K가 주어진다.
// K개의 입력은 로봇 개미가 왼쪽부터 순서대로 각 층마다 지나온 방에 있는 먹이 정보이며 먹이 이름이다.
//  개미굴의 시각화된 구조를 출력하는 프로그램

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
vector<string> arr[1001];

int main(void) {
	cin >> n;
	string temp;

	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	sort(arr, arr + n);

	vector<string> stack;

	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < arr[i].size() && j < stack.size(); j++) {
			if (arr[i][j] == stack[j])
				count++;
			else
				break;
		}
		int size = stack.size();
		for (int j = count; j < size; j++)
			stack.pop_back();

		for (int j = count; j < arr[i].size(); j++) {
			for (int k = 0; k < stack.size(); k++)
				cout << "--";
			cout << arr[i][j] << '\n';
			stack.push_back(arr[i][j]);
		}
	}

	return 0;
}