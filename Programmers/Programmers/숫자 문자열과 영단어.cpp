#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string word = "";

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == 'z') {
            word = word + "0";
            i = i + 3;
        }
        else if (s[i] == 'o') {
            word = word + "1";
            i = i + 2;
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                word = word + "2";
                i = i + 2;
            }
            else {
                word = word + "3";
                i = i + 4;
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] == 'o') {
                word = word + "4";
                i = i + 3;
            }
            else {
                word = word + "5";
                i = i + 3;
            }
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                word = word + "6";
                i = i + 2;
            }
            else {
                word = word + "7";
                i = i + 4;
            }
        }
        else if (s[i] == 'e') {
            word = word + "8";
            i = i + 4;
        }
        else if (s[i] == 'n') {
            word = word + "9";
            i = i + 3;
        }
        else {
            word = word + s[i];
        }
    }

    answer = stoi(word);

    return answer;
}