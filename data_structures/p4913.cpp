//非常简单的建树然后用max维护最深深度


#include <bits/stdc++.h>
using namespace std;
struct Tree {
    int lchild = 0;
    int rchild = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Tree> tr(n + 1);
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        tr[i] = {l, r};
    }
    vector<int> depth(n + 1, 1);
    vector<int> st = {1};
    int best = 0;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        best = max(best, depth[u]);
        int left = tr[u].lchild;
        int right = tr[u].rchild;
        if (left > 0) {
            depth[left] = depth[u] + 1;
            st.push_back(left);
        }
        if (right > 0) {
            depth[right] = depth[u] + 1;
            st.push_back(right);
        }
    }
    cout << best << '\n';
    return 0;
}