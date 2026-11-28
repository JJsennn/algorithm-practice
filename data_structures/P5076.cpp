//本题要找第k小的关系，用普通nth_element速度太慢。
//记录某数的大小关系，然后前缀和求出一共有多少在他前面的数就可以知道他是第几小。利用树状数组可以极大加快前缀和运算。
//用Switch与case组合可以跟直观的表现操作的选择。
//用离线操作将所有涉及比较的数据先处理，方便离散化然后建立树状数组。
//用队列模拟操作顺序。
#include<bits/stdc++.h>
using namespace std;
struct query{
    int op;
    int x;
};
struct Fenwick{
    int n;
    vector<int>tr; 
    Fenwick(int n_){
        n=n_;
        tr.assign(n+1,0);
    }
    void add(int x,int v){
        for(;x<=n;x+=x&-x)tr[x]+=v;
    }
    int prefixsum(int x){
        int sum=0;
        for(;x>0;x-=x&-x)sum+=tr[x];
        return sum;
    }
    int kth(int k)const{
        int step=1,next=0;
        int index=0;
        while((step<<1)<=n)step<<=1;
        for(;step>0;step>>=1){
            next=index+step;
            if(next<=n&&k>tr[next]){
                index=next;
                k-=tr[index];
            }
        }
        return index+1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>q;
    queue<query>que;
    vector<int>num;
    for(int i=1;i<=q;i++){
        int op,x;cin>>op>>x;
        que.push({op,x});
        if (op != 2)num.push_back(x);
    }
    auto order=num;
    sort(order.begin(),order.end());
    order.erase(unique(order.begin(),order.end()),order.end());
    int n=order.size();
    auto get_rank=[&order](int x){
        return (int)(lower_bound(order.begin(),order.end(),x)-order.begin()+1);
    };
    Fenwick bit(n);
    while (!que.empty()) {
    auto [op, x] = que.front();
    que.pop();
    if (op == 2) {
        cout << order[bit.kth(x) - 1] << '\n';
        continue;
    }
    int r = get_rank(x);
    switch (op) {
        case 1: {
            int cnt = bit.prefixsum(r - 1);
            cout << cnt + 1 << '\n';
            break;
        }
        case 3: {
            int cnt = bit.prefixsum(r - 1);
            if (cnt == 0) {
                cout << -2147483647 << '\n';
            } else {
                cout << order[bit.kth(cnt) - 1] << '\n';
            }
            break;
        }
        case 4: {
            int cnt = bit.prefixsum(r); 
            int total = bit.prefixsum(n);
            if (cnt == total) {
                cout << 2147483647 << '\n';
            } else {
                cout << order[bit.kth(cnt + 1) - 1] << '\n';
            }
            break;
        }
        case 5: {
            bit.add(r, 1);
            break;
        }
    }
}
    return 0;
}