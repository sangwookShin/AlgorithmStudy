#include <string>
#include <vector>

using namespace std;

string change_melody(string melody) {

    string result = "";

    for (int i = 0; i < melody.size(); i++) {

        string tmp = "";
        if (melody[i + 1] == '#' && i <= melody.size() - 2) {
            tmp = tolower(melody[i]);
            result += tmp;
            i++;
        }
        else {
            result += melody[i];
        }
    }

    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int bTime = 0;
    int time = 0;

    for (int i = 0; i < musicinfos.size(); i++) {

        //시간 구하기
        int ahour, bhour, aminute, bminute;
        ahour = stoi(musicinfos[i].substr(0, 2)) * 60;
        aminute = stoi(musicinfos[i].substr(3, 2));
        bhour = stoi(musicinfos[i].substr(6, 2)) * 60;
        bminute = stoi(musicinfos[i].substr(9, 2));
        time = (bhour + bminute) - (ahour + aminute);

        string title = ""; //제목
        string melody = ""; //멜로디
        int j = 12;

        while (musicinfos[i][j] != ',') { //제목 구하기
            title += musicinfos[i][j];
            j++;
        }

        melody = change_melody(musicinfos[i].substr(j + 1));

        if (melody.size() < time) { //멜로디보다 더 긴시간
            string tmp = "";
            tmp = melody;

            for (int k = 1; k < time / tmp.size(); k++) {
                melody += tmp;
            }
            for (int k = 0; k < time % tmp.size(); k++) {
                melody += tmp[k];
            }
        } //if
        else {
            melody = melody.substr(0, time);
        } //else

        string m_change = change_melody(m); //들은 멜로디를 바꿈

        if (melody.find(m_change) != string::npos)
        {
            if (bTime < time)
            {
                answer = title;
                bTime = time;
            }
        }

    }

    return answer;
}