#include <string>
#include <cstring>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int visit[12][12][12][12]; //fromx, fromy, tox, toy

    memset(visit, 0, sizeof(visit));

    int from_x = 5;
    int from_y = 5;
    int to_x, to_y;

    for (int i = 0; i < dirs.size(); i++) {

        if (dirs[i] == 'U') {
            if (from_x - 1 >= 0) {
                to_x = from_x - 1;
                to_y = from_y;
                if (visit[from_x][from_y][to_x][to_y] == 0) {
                    answer++;
                }
                visit[from_x][from_y][to_x][to_y] = 1;
                visit[to_x][to_y][from_x][from_y] = 1;
                from_x = to_x;
                from_y = to_y;
            }
        }
        else if (dirs[i] == 'D') {
            if (from_x + 1 < 11) {
                to_x = from_x + 1;
                to_y = from_y;
                if (visit[from_x][from_y][to_x][to_y] == 0) {
                    answer++;
                }
                visit[from_x][from_y][to_x][to_y] = 1;
                visit[to_x][to_y][from_x][from_y] = 1;
                from_x = to_x;
                from_y = to_y;
            }
        }
        else if (dirs[i] == 'R') {
            if (from_y + 1 < 11) {
                to_x = from_x;
                to_y = from_y + 1;
                if (visit[from_x][from_y][to_x][to_y] == 0) {
                    answer++;
                }
                visit[from_x][from_y][to_x][to_y] = 1;
                visit[to_x][to_y][from_x][from_y] = 1;
                from_x = to_x;
                from_y = to_y;
            }
        }
        else if (dirs[i] == 'L') {
            if (from_y - 1 >= 0) {
                to_x = from_x;
                to_y = from_y - 1;
                if (visit[from_x][from_y][to_x][to_y] == 0) {
                    answer++;
                }
                visit[from_x][from_y][to_x][to_y] = 1;
                visit[to_x][to_y][from_x][from_y] = 1;
                from_x = to_x;
                from_y = to_y;
            }
        } //else if
    } //for

    return answer;
}