#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> save; //���� �ܾ� ����
    int turn = 1; //�� ��
    char last_word = words[0][words[0].size() - 1];
    char first_word;

    //ù �ܾ� ����
    save.push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {

        if ((i + 1) % n == 1) {
            turn++;
        }

        //���ܾ� ���۴ܾ� üũ
        first_word = words[i][0];

        if (last_word != first_word) {
            int num = (i + 1) % n;
            if (num == 0) {
                num = n;
            }
            answer.push_back(num);
            answer.push_back(turn);
            return answer;
        }
        //������ �ܾ� �� ����
        last_word = words[i][words[i].size() - 1];

        //�ߺ��� �ܾ� üũ
        if (find(save.begin(), save.end(), words[i]) != save.end()) { //�ߺ��Ȱ� ����
            int num = (i + 1) % n;
            if (num == 0) {
                num = n;
            }
            answer.push_back(num);
            answer.push_back(turn);
            return answer;
        }

        //�ܾ� ����
        save.push_back(words[i]);
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}