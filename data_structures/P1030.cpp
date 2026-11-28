//老套路，先利用中序与后序构建树然后再先序遍历出答案
//这题要注意的是要将中序后序的左右子树对齐：中序：左根右 后序：左右根
#include <bits/stdc++.h>
using namespace std;
vector<int> post, in;
vector<pair<int, int>> tree(26, {-1, -1});
int build(int postL, int postR,
          int inL, int inR,
          const unordered_map<int, int>& pos) {
    if (postL > postR) {
        return -1;
    }
    int root = post[postR];
    int middle = pos.at(root);
    int leftSize = middle - inL;
    tree[root].first = build(postL,postL + leftSize - 1,inL,middle - 1,pos);
    tree[root].second = build(postL + leftSize,postR - 1,middle + 1,inR,pos);
    return root;
}
void preTraverse(int root) {
    if (root == -1) {
        return;
    }
    cout <<(char)('A' + root);
    preTraverse(tree[root].first);
    preTraverse(tree[root].second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string inString, postString;
    cin >> inString >> postString;
    int n =(int)(postString.size());
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        int inNode = inString[i] - 'A';
        int postNode = postString[i] - 'A';
        in.push_back(inNode);
        post.push_back(postNode);
        pos[inNode] = i;
    }
    int root = build(0, n - 1,0, n - 1,pos);
    preTraverse(root);
    cout << '\n';
    return 0;
}