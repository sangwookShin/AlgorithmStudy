#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool check[8] = { 0, };
set<set<string>> cnt;

bool same(string user, string banned) {

    if (user.length() != banned.length())
        return false;

    for (int i = 0; i < user.length(); i++) {
        if (banned[i] == '*')
            continue;
        if (user[i] != banned[i])
            return false;
    }

    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int start, set<string> result) {

    if (start == banned_id.size()) {
        cnt.insert(result);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {

        if (check[i] == true)
            continue;

        if (same(user_id[i], banned_id[start]) == false)
            continue;

        check[i] = true;

        set<string> a = result;
        a.insert(user_id[i]);

        dfs(user_id, banned_id, ++start, a);

        check[i] = false;
        start--;

    }

}
int solution(vector<string> user_id, vector<string> banned_id) {

    set<string> result;

    dfs(user_id, banned_id, 0, result);

    return cnt.size();
}