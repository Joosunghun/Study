// 12_6 기둥과 보 설치
// 기둥과 보를 이용하여 벽면 구조물을 자동으로 세우는 로봇 개발 계획 시뮬레이션
// 2차원 가상 기둥과 보를 이용한 구조물 설치, 기둥과 보는 길이가 1인 선분으로 표현
// 기둥은 바닥 위에 있거나 보의 한쪽 끝부분 위에 있거나, 또는 다른 기둥 위에 있어야 한다.
// 보는 한쪽 끝부분이 기둥위에 있거나, 또는 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야 한다.
// 바닥은 벽면의 맨 아래 지면
// 2차원 벽면은 n x n 크기 정사각 격자, 각 격자는 1 x 1, 처음 벽면은 비어 있는 상태
// 기둥과 보는 격자 선의 교차점에 걸치지 않고, 격자 칸의 각 변에 정확히 일치하도록 설치할 수 있다.
// 벽면의 크기 n, 기둥과 보를 설치하거나 삭제하는 작업이 순서대로 담긴 2차원 배열 build_frame이 매개변수
// 모든 명령어를 수행한 후 구조물의 상태를 return 하도록 solution 함수 구현

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool possible(vector<vector<int>> answer) {                     // 현재 설치물이 가능한 구조물인지 확인하는 함수
	for (int i = 0; i < answer.size(); i++) {
		int x = answer[i][0];
		int y = answer[i][1];
		int stuff = answer[i][2];
		if (stuff == 0) {                                                        // 설치된 것이 '기둥'인 경우
			bool check = false;
			if (y == 0)                                                           // 바닥이 위라면 정상
				check = true;
			for (int j = 0; j < answer.size(); j++) {                   // 보의 한쪽 끝 부분 위 혹은 다른 기둥 위라면 정상
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
			}
			if (!check)                                                      // 아니라면 false 반환
				return false;
		}
		else if (stuff == 1) {                                             // 설치된 것이 '보'인 경우
			bool check = false;
			bool left = false;
			bool right = false;
			for (int j = 0; j < answer.size(); j++) {               // 한쪽 끝부분이 기둥 위 혹은 양쪽 끝부분이 다른 보와 동시에 연결이라면 정상
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				if (x + 1== answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				if (x - 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					left = true;
				}
				if (x + 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					right = true;
				}
			}
			if (left && right)
				check = true;
			if (!check)                                                  //아니라면 false 반환
				return false; 
		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (int i = 0; i < build_frame.size(); i++) {                               // 작업의 개수는 최대 1000개
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int stuff = build_frame[i][2];
		int operate = build_frame[i][3];
		if (operate == 0) {                                                            // 삭제하는 경우
			int index = 0;                                                              // 일단 삭제를 함
			for (int j = 0; j < answer.size(); j++) {
				if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
					index = j;
				}
			}
			vector<int> erased = answer[index];
			answer.erase(answer.begin() + index);
			if (!possible(answer)) {                                             // 가능한 구조물인지 확인
				answer.push_back(erased);                                  // 가능한 구조물이 아니라면 다시 설치
			}
		} 
		if (operate == 1) {                                                         // 설치하는 경우
			vector<int> inserted;                                                 // 일단 설치를 해 본 뒤
			inserted.push_back(x);
			inserted.push_back(y);
			inserted.push_back(stuff);
			answer.push_back(inserted);
			if (!possible(answer)) {                                            // 가능한 구조물인지 확인
				answer.pop_back();                                             // 가능한 구조물이 아니라면 다시 제거
			}
		}
	}

	sort(answer.begin(), answer.end());                                 // 정렬된 결과를 반환
	return answer;
}

