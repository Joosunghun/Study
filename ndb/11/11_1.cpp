// 11_1 모험가 길드
// N명의 모험가 공포도 측정
// 공포도가 x 인 모험가는 반드시 x 명 이상으로 파티를 꾸려야함
// N명의 모험가에 대한 정보가 주어졌을때 여행을 떠날 수 있는 그룹 수의 최댓값을 출력

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> character;

	cin >> n;
	for (int i = 0; i < n; i++) {                               // 모험가의 정보 받아오기
		int x;
		cin >> x;
		character.push_back(x);
	}

	sort(character.begin(), character.end());       // 공포도가 낮은 순부터 정렬

	int result = 0;                                               // 총 그룹의 수
	int count = 0;                                               // 현재 그룹에 포함된 모험가 수

	for (int i = 0; i < n; i++) {                                // 공포도를 낮은 것부터 하나씩 확인하며
		count += 1;                                              // 현재 그룹에 모험가 한명 추가
		if (count >= character[i]) {                        // 그룹내 모험가 수가 현재의 공포도 이상이면
			result += 1;                                          // 총 그룹수 하나 추가
			count = 0;                                            // 모험가 수 초기화
		}
	}
	cout << result << '\n';                                  // 총 그룹 수 출력
}