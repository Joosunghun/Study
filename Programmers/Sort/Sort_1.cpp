// Sort_1 K번째 수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {                               // 반환되어야하는 세트 반복
		vector<int> temp;                                                           // 임시로 빈 벡터 생성
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {      // 필요한 부분만 임시 벡터에 넣는다
			temp.push_back(array[j]); 
		}    
		sort(temp.begin(), temp.end());                                         // 임시 벡터를 정렬
 		answer.push_back(temp.at(commands[i][2] - 1));              // 임시벡터의 index번째를 answer에 넣음
	}
	return answer;
}
