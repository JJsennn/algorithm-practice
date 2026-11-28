//非常简单的二叉数构建和前序遍历
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>tree(26,{-1,-1});
void posttraverse(int p){
    if(p==-1)return;
    cout<<(char)(p+'a');
    posttraverse(tree[p].first);
    posttraverse(tree[p].second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int s;
    for(int i=1;i<=n;i++){
        char a,lc,rc;cin>>a>>lc>>rc;
        int node=a-'a';if(i==1)s=node;
        if(lc!='*')tree[node].first=(lc-'a');
        if(rc!='*')tree[node].second=(rc-'a');
    }
    posttraverse(s);
    return 0;
}