// Sort_1 K��° ��

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {                               // ��ȯ�Ǿ���ϴ� ��Ʈ �ݺ�
		vector<int> temp;                                                           // �ӽ÷� �� ���� ����
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {      // �ʿ��� �κи� �ӽ� ���Ϳ� �ִ´�
			temp.push_back(array[j]); 
		}    
		sort(temp.begin(), temp.end());                                         // �ӽ� ���͸� ����
 		answer.push_back(temp.at(commands[i][2] - 1));              // �ӽú����� index��°�� answer�� ����
	}
	return answer;
}
