// Hash_4 ����Ʈ �ٹ�

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {                           // ������ �迭���� ù��° ���Ҹ� �������� ���������ϱ� ���� �Լ�
    return a.first > b.first;
}

bool compare_map_value(pair<string, int> a, pair<string, int> b) {      // ������ �迭���� �ι�° ���Ҹ� �������� ���������ϱ� ���� �Լ�
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> genre_playlist;                 // �帣, vector(���Ƚ��, �뷡 ������ȣ(�ε���) ��)
    map<string, int> genre_play_cnt;                                         // �帣, �� ���Ƚ��
    vector<pair<string, int>> genre_play_cnt_v;                          // genre_play_cnt�� value�� �����ϱ� ���� vector

    for (int i = 0; i < genres.size(); i++) {                                   // hash map�� ������ ����
        genre_playlist[genres[i]].push_back(make_pair(plays[i], i));
        genre_play_cnt[genres[i]] += plays[i];
    }

    for (auto& k : genre_playlist) {                                             // �帣�� ������ǵ� �󵵼��� ���� �������� ����
        sort(k.second.begin(), k.second.end(), compare);
    }

    genre_play_cnt_v.assign(genre_play_cnt.begin(), genre_play_cnt.end());               // assign(������ ����, ��) -> Ư�� ���ҷ� ä���(���� �����ʹ� ���� x)
    sort(genre_play_cnt_v.begin(), genre_play_cnt_v.end(), compare_map_value);        // �帣�� �� ���Ƚ���� ���� �������� ����

    for (int i = 0; i < genre_play_cnt_v.size(); i++) {                              
        string genre_name = genre_play_cnt_v[i].first;                               
        for (int j = 0; (j < genre_playlist[genre_name].size()) && (j < 2); j++) {               // ������ 1���� 1����, 2���̻��̸� 2�������� answer�� ����
            answer.push_back(genre_playlist[genre_name][j].second);
        }
    }
    return answer;
}