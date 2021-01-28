#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct NODE {
    int v;
    int x, y;
    NODE* left;
    NODE* right;
};

bool comp(NODE& a, NODE& b) {
    if (a.y == b.y) { return a.x < b.x; }
    return a.y > b.y;
}

void insertNode(NODE* parent, NODE* child) {
    if (parent->x < child->x) {
        if (parent->right == NULL) { parent->right = child; }
        else { insertNode(parent->right, child); }
    }
    else {
        if (parent->left == NULL) { parent->left = child; }
        else { insertNode(parent->left, child); }
    }
}

void preorder(vector<int>& answer, NODE* node) {
    if (node == NULL) return;
    answer.push_back(node->v);
    preorder(answer, node->left);
    preorder(answer, node->right);
}

void postorder(vector<int>& answer, NODE* node) {
    if (node == NULL) return;
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->v);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer{ {},{} };
    vector<NODE> nodes;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }
    sort(nodes.begin(), nodes.end(), comp);

    NODE* root = &nodes[0];
    for (int i = 1; i < nodeinfo.size(); i++) {
        insertNode(root, &nodes[i]);
    }

    preorder(answer[0], root);
    postorder(answer[1], root);

    return answer;
}