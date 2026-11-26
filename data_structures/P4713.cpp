#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    deque<pair<int,int>>competition;
    for(int i=1;i<=(1<<n);i++){
        int s;cin>>s;
        competition.push_back({s,i});
    }
    while((int)competition.size()>2){
        auto a=competition.front();competition.pop_front();
        auto b=competition.front();competition.pop_front();
        competition.push_back(max(a,b));
    }
    auto secondary=min(competition[0],competition[1]);
    cout<<secondary.second<<'\n';
    return 0;
}