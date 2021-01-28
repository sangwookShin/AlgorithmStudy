#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

struct Trie {
    Trie* next[26];
    int cnt;

    Trie() : cnt(0) {
        memset(next, 0, sizeof(next));
    }

    void insert(string key) {
        Trie* cur = this;

        for (char ch : key) {
            cur->cnt++;
            if (cur->next[ch - 'a'] == NULL) {
                cur->next[ch - 'a'] = new Trie();
            }
            cur = cur->next[ch - 'a'];
        }
        cur->cnt++;
    }

    int find(string key) {
        Trie* cur = this;
        for (char ch : key) {
            if (ch == '?') { return cur->cnt; }

            cur = cur->next[ch - 'a'];
            if (cur == NULL) {
                return 0;
            }
        }
        return cur->cnt;
    }
};

Trie root[10001];
Trie Reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {

    vector<int> answer;
    int size;

    for (string str : words) {
        size = str.size() - 1;
        root[size].insert(str);

        reverse(str.begin(), str.end());
        size = str.size() - 1;
        Reroot[size].insert(str);
    }

    for (string str : queries) {
        if (str[0] != '?') { //앞이 '?'가 아닌경우
            size = str.size() - 1;
            answer.push_back(root[size].find(str));
        }
        else {  //앞이 '?'인 경우
            reverse(str.begin(), str.end());
            size = str.size() - 1;
            answer.push_back(Reroot[size].find(str));
        }
    }
    return answer;
}