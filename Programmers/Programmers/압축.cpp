#include <string>
#include <vector>
#include <map>;
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> word;
    vector<string> alpha = { "A", "B", "C", "D", "E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

    for (int i = 0; i < 26; i++) {
        word.insert({ alpha[i], i + 1 });
    }

    int idx = 1;
    int num = 27;

    while (1) {

        string w = msg.substr(0, idx);
        string c = msg.substr(idx, 1);
        string wc = w + c;
        auto iter_w = word.find(w);
        auto iter_wc = word.find(wc);

        if (iter_w != word.end()) {

            if (iter_wc != word.end()) {
                if (idx < msg.size()) {
                    idx++;
                }
            } //if
            else {

                answer.push_back(iter_w->second);
                word.insert({ wc, num });
                num++;
                msg.erase(0, idx);
                idx = 1;
            } //else   
        } //if

        if (c == "\0") {
            answer.push_back(iter_w->second);
            break;
        } //if
    } //while

    return answer;
}