//先序/后序+中序可以还原出整棵树
//leftpart必须写，因为pre，in是两个并行的数组，p=pos[...]不能正确反映pre中相应情况的关键字
//将字符（spre，sin）转换成数字（pre，in）更好操作。
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>tree(26,{-1,-1});
vector<int>pre,in;
int build(int prel,int prer,int inl,int inr,unordered_map<int,int> pos){
    if(prel>prer)return -1;
    int node=pre[prel];
    int p=pos[node];
    int leftpart=p-inl;
    tree[node].first=build(prel+1,prel+leftpart,inl,inl+leftpart-1,pos);
    tree[node].second=build(prel+leftpart+1,prer,inl+leftpart+1,inr,pos);
    return node;
}
void backtraverse(int node){
    if(node==-1)return;
    backtraverse(tree[node].first);
    backtraverse(tree[node].second);
    cout<<(char)(node+'A');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string sin;cin>>sin;
    string spre;cin>>spre;
    int len=(int)spre.size();
    unordered_map<int,int>pos;
    for(int i=0;i<len;i++){
        int a=spre[i]-'A';
        int b=sin[i]-'A';
        pos[b]=i;
        pre.push_back(a);
        in.push_back(b);
    }
    int s=build(0,len-1,0,len-1,pos);
    backtraverse(s);
    return 0;
}