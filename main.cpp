#include<bits/stdc++.h>
using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");
vector<int> component[100001];
vector<int> v[100001],rev[100001];
int n,m;

void add(int node1,int node2){
    v[node1].push_back(node2);
}
void first_DFS(int node,int vis[100001],stack<int>& st)
{
    vis[node]=1;
    for(auto i:v[node])
        if(vis[i]==0)
            first_DFS(i,vis,st);
        //cout<<"aici";}

    st.push(node);
}
void reverse(){

    for(int i=0;i<n;i++){
        for(auto j:v[i])
            rev[j].push_back(i);

    }
}
void second_DFS(int node,int vis[100001],int nr){
    //cout<<node+1<<" ";
    component[nr].push_back(node+1);
    vis[node]=1;
    for(auto i:rev[node])
        if(vis[i]==0)
        {
            second_DFS(i,vis,nr);
        }
        //cout<<"aici";

}
void nr_SCCs(int &nr){
    nr=0;
    int vis[100001];
    stack<int> st;
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            first_DFS(i,vis,st);
    }
    /*while(!st.empty()){
        //cout<<st.top()<<" ";
        st.pop();
    }*/

    reverse();

    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    while(!st.empty()){

        int a=st.top();
        //cout<<a<<" ";
        st.pop();
        if(vis[a]==0){
            nr++;
            second_DFS(a,vis,nr);
            //cout<<'\n';

        }
    }
    //cout<<nr;
}

int main(){
    int x,y;
//cin>>n>>m;
f>>n>>m;
for(int i=0;i<m;i++){
    //cin>>x>>y;
    f>>x>>y;
    add(x-1,y-1);
}
int nr=0;
nr_SCCs(nr);

//cout<<nr<<endl;
g<<nr<<'\n';
for(int i=1;i<=nr;i++)
{
    for(auto j:component[i])
        //cout<<j<<" ";
        g<<j<<" ";
    //cout<<endl;
    g<<'\n';
}

}