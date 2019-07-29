//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <set>
#include <time.h>
#include <map>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <numeric>
#include <unordered_map>
using namespace std;
#define sz(a)               int((a).size())
#define ll                  long long
#define pb                  push_back
#define ld                  long double
#define pi                  pair<ll,ll>
#define mp                  make_pair
#define vi                  vector<ll>
#define vii                  vector<pi>
#define endl                "\n"
#define ff                  first
#define ss                  second
#define all(c)              (c).begin(),(c).end()
#define allr(c)             (c).rbegin(),(c).rend()
#define rep(i,n)            for(ll i=0;i<n;i++)
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define inputt(a,n,m)       for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>a[i][j]
#define outputt(a,n,m)      for(ll i=0;i<n;i++){for(ll j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
#define inf                 1e10
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock();
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;

/************************************Debugging Steps*****************************************/

// If aplying ceil,floor,pow,etc convert it into integer (might make you eat shit if you don't
// Whenever using stacks,queues,etc always check that their top / front / back elements are not accessed when they are empty, thus causing runtime error
// Think twice before using greedy
// Remember losing 1 or 2 minutes is better than a penalty of 10 minutes
// Use log2 instead of log()/log(2) to avoid shitty errors
// If MLE occurs, try declaring the large array in int instead of long long
// Always initialise anything while declaring, which will not be taken as input
// In case of a problem having decimal calculations, try declaring everything in double rather than typecasting in each step
// always declare the array with n+5 elements to avoid unexpected errors
// Every problem cannot be solved by DFS easily, think of BFS too
/********************************************************************************************/

/********************************************************************************************/

// Your code need to originate from the deepest of your intellectual mind
// Best of Luck, may there never be "Wrong answer on test ##"

bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
bool _sortbyfirst(const pair<ll,pair<ll,ll> > &a, const pair<ll,pair<ll,ll> > &b)
{
    return (a.first>b.first);
}
bool _sortbysec(const pair<ll,pair<ll,ll> > &a, const pair<ll,pair<ll,ll> > &b)
{
    return (a.second.first>b.second.first);
}
bool _sortbythird(const pair<ll,pair<ll,ll> > &a, const pair<ll,pair<ll,ll> > &b)
{
    return (a.second.second>b.second.second);
}
ll gcd(ll a,ll b)
{
    return b?gcd(b, a % b):a;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
vi adj[N],score(N,-INT_MIN),win(N,0),loss(N,0),draw(N,0);
ll board[N][3][3]={};
set<ll> s;
void print(ll index)
{
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(board[index][i][j]==1)
                cout<<"X ";
            else if(board[index][i][j]==2)
                cout<<"O ";
            else
                cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
}
ll check(ll index)
{
    for(ll h=1;h<=2;h++)
    {
        for(ll i=0;i<3;i++)
            if(board[index][i][0]==h && board[index][i][1]==h && board[index][i][2]==h)
                return h;
        for(ll i=0;i<3;i++)
            if(board[index][0][i]==h && board[index][1][i]==h && board[index][2][i]==h)
                return h;
        if(board[index][0][0]==h && board[index][1][1]==h && board[index][2][2]==h)
            return h;
        if(board[index][0][2]==h && board[index][1][1]==h && board[index][2][0]==h)
            return h;
    }
    return 0;
}
void build(ll index,ll turn)
{
    if(check(index))
        return;
    ll current[3][3];
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++)
            current[i][j]=board[index][i][j];
    vector<pair<ll,ll> > v;
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++)
            if(!current[i][j])
                v.pb(mp(i,j));
    for(ll ii=0;ii<v.size();ii++)
    {
        ll next[3][3];
        for(ll i=0;i<3;i++)
            for(ll j=0;j<3;j++)
                next[i][j]=current[i][j];
        next[v[ii].ff][v[ii].ss]=turn;
        ll next_turn=1,next_index=*s.begin();
        if(turn==1)
            next_turn=2;
        s.erase(s.begin());
        for(ll i=0;i<3;i++)
            for(ll j=0;j<3;j++)
                board[next_index][i][j]=next[i][j];
        adj[index].pb(next_index);
        build(next_index,next_turn);
    }
}
void calculate(ll index)
{
    if(adj[index].size()==0)
    {
        if(check(index)==1)
            win[index]=1;
        else if(check(index)==2)
            loss[index]=1;
        else
            draw[index]=1;
        return;
    }
    for(ll i=0;i<adj[index].size();i++)
    {
        calculate(adj[index][i]);
        loss[index]+=loss[adj[index][i]];
        draw[index]+=draw[adj[index][i]];
    }
}
ll get_best(ll index)
{
    ll l=INT_MAX;
    for(ll i=0;i<adj[index].size();i++)
    {
        l=min(loss[adj[index][i]],l);
    }
    vii v;
    for(ll i=0;i<adj[index].size();i++)
    {
        if(loss[adj[index][i]]==l)
            v.pb(mp(draw[adj[index][i]],adj[index][i]));
    }
    sort(all(v));
    return v[0].ss;
}
bool check_draw(ll ind)
{
    ll c=0;
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++)
            if(board[ind][i][j]==0)
                c++;
    if(c==0)
        return 1;
    return 0;
}
ll get_next_index(ll ind,ll c_board[3][3])
{
    for(ll i=0;i<adj[ind].size();i++)
    {
        ll co=0;
        ll k=adj[ind][i];
        for(ll j=0;j<3;j++)
        {
            for(ll h=0;h<3;h++)
            {
                if(board[k][j][h]==c_board[j][h])
                    co++;
            }
        }
        if(co==9)
        {
            return k;
        }
    }
    return ind;
}
int32_t main()
{
    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    for(ll i=1;i<N;i++)
        s.insert(i);
    ll current[3][3]={};
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++)
            board[0][i][j]=current[i][j];
    build(0,2);
    calculate(0);
    ll ind=0;
    map<ll,pair<ll,ll> > key;
    key[1]=mp(0,0);
    key[2]=mp(0,1);
    key[3]=mp(0,2);
    key[4]=mp(1,0);
    key[5]=mp(1,1);
    key[6]=mp(1,2);
    key[7]=mp(2,0);
    key[8]=mp(2,1);
    key[9]=mp(2,2);
    while(1)
    {
        print(ind);
        ll x;
        cin>>x;
        ll current_board[3][3];
        for(ll i=0;i<3;i++)
            for(ll j=0;j<3;j++)
                current_board[i][j]=board[ind][i][j];
        ll i=key[x].ff,j=key[x].ss;
        if(current_board[i][j]!=0)
        {
            cout<<"Invalid move\n";
            continue;
        }
        current_board[i][j]=2;
        ind=get_next_index(ind,current_board);
        if(check(ind))
        {
            print(ind);
            if(check(ind)==1)
                cout<<"You Lose\n";
            else
                cout<<"You Win\n";
            return 0;
        }
        if(check_draw(ind))
        {
            print(ind);
            cout<<"Tied\n";
            return 0;
        }
        ind=get_best(ind);
        if(check(ind))
        {
            print(ind);
            if(check(ind)==1)
                cout<<"You Lose\n";
            else
                cout<<"You Win\n";
            return 0;
        }
        if(check_draw(ind))
        {
            print(ind);
            cout<<"Tied\n";
            return 0;
        }
    }
}
