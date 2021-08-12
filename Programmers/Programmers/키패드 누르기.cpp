#include <string>
#include <vector>
#include <cmath>
using namespace std;

int distance(int start, int end) {

    int dis = 0;

    dis = abs(((start - 1) / 3) - ((end - 1) / 3));
    dis = dis + abs(((start - 1) % 3) - ((end - 1) % 3));

    return dis;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Leftsave = 10;
    int Rightsave = 12;

    for (int i = 0; i < numbers.size(); i++) {

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer = answer + "L";
            Leftsave = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer = answer + "R";
            Rightsave = numbers[i];
        }
        else {

            if (numbers[i] == 0) {
                numbers[i] = 11;
            }

            int left_dis = distance(Leftsave, numbers[i]);
            int right_dis = distance(Rightsave, numbers[i]);

            if (left_dis > right_dis) {
                answer = answer + "R";
                Rightsave = numbers[i];
            }
            else if (left_dis < right_dis) {
                answer = answer + "L";
                Leftsave = numbers[i];
            }
            else {
                if (hand == "left") { //왼손잡이
                    answer = answer + "L";
                    Leftsave = numbers[i];
                }
                else { //오른손잡이
                    answer = answer + "R";
                    Rightsave = numbers[i];
                }

            }
        }
    }

    return answer;
}