#include <string>
#include <vector>

using namespace std;

string grade(double a) {

    if (a >= 90) {
        return "A";
    }
    else if (80 <= a && a < 90) {
        return "B";
    }
    else if (70 <= a && a < 80) {
        return "C";
    }
    else if (50 <= a && a < 70) {
        return "D";
    }
    else {
        return "F";
    }
}

string solution(vector<vector<int>> scores) {
    string answer = "";

    for (int i = 0; i < scores.size(); i++) {

        int sum = 0; //����
        int cnt = 0; //���
        bool check_max = false, check_min = false; //�ߺ�üũ
        double avg = 0; //���
        int max = scores[0][i], min = scores[0][i]; //�ִ�, �ּڰ�
        int maxidx = 0, minidx = 0; //�ִ�, �ּڰ� �ε���

        for (int j = 0; j < scores.size(); j++) {

            sum += scores[j][i];
            cnt++;

            if (max < scores[j][i]) {
                max = scores[j][i];
                maxidx = j;
            }
            if (min > scores[j][i]) {
                min = scores[j][i];
                minidx = j;
            }
        }

        if (maxidx == i) {
            for (int j = 0; j < scores.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (max == scores[j][i]) {
                    check_max = true;
                }
            }

            if (check_max == false) {
                sum -= max;
                cnt--;
            }
        }

        if (minidx == i) {
            for (int j = 0; j < scores.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (min == scores[j][i]) {
                    check_min = true;
                }
            }
            if (check_min == false) {
                sum -= min;
                cnt--;
            }
        }

        //����� ���Ѵ�
        avg = (double)sum / (double)cnt;

        //����� ��ġ��
        answer += grade(avg);
    }

    return answer;
}