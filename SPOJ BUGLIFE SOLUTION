#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 2001

bool isbipartiteUTIL(vector<ll> v[],ll src)
{
    unordered_set<ll> U,V;
    queue<ll> bfs;
    bfs.push(src);
    U.insert(src);
    while(!bfs.empty())
    {
        ll x = bfs.front();
        bfs.pop();
        
        if(U.find(x)!=U.end())
        {
            for(ll i=0;i<v[x].size();i++)
            {
                if(U.find(v[x][i])==U.end()&&V.find(v[x][i])==V.end()) {V.insert(v[x][i]);bfs.push(v[x][i]);}
                else if(U.find(v[x][i])!=U.end()) return false;
            }
        }
        else if(V.find(x)!=V.end())
        {
            for(ll i=0;i<v[x].size();i++)
            {
                if(V.find(v[x][i])==V.end()&&U.find(v[x][i])==U.end()) {U.insert(v[x][i]);bfs.push(v[x][i]);}
                else if(V.find(v[x][i])!=V.end()) return false;
            }
        }
    }
    return true;
}

bool isbipartite(vector<ll> v[],ll V)
{
    for(ll i=1;i<=V;i++)
    {
        if(isbipartiteUTIL(v,i)==false) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);    
    ll t;
    cin>>t;
    for(ll r=1;r<=t;r++)
    {
        vector<ll> v[N];
        ll b1,b2,n,i;
        cin>>n>>i;
        for(ll j=0;j<i;j++)
        {
            cin>>b1>>b2;
            v[b1].push_back(b2);
            v[b2].push_back(b1);
        }
        if(isbipartite(v,n))
        {
            cout<<"Scenario #"<<r<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"Scenario #"<<r<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
    }
}
