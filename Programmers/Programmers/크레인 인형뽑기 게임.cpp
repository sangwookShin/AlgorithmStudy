#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;

    for (int i = 0; i < moves.size(); i++) {

        int t = 0;
        int c = moves[i] - 1;

        while (board[t][c] == 0) {
            t++;
            if (t == board.size() - 1) {
                break;
            }
        }

        if (board[t][c] != 0) {
            if (!basket.empty() && basket.top() == board[t][c]) { //같은 거면
                basket.pop();
                answer = answer + 2;
            }
            else {
                basket.push(board[t][c]);
            }
        }

        board[t][c] = 0;
    }

    return answer;
}