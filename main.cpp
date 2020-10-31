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

ll min(ll a,ll b){
    return a<b?a:b;
}
ll max(ll a,ll b){
    return a>b?a:b;
}
struct board{
    char arr[3][3];
    int score;
    int index;
    board(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                arr[i][j]='-';
    }
};
vector<int> game[1000000];
vector<board> store;
map<int,int> mapping;       // from index to store index
char check(board b){
    for(int i=0;i<3;i++){
        int count=0;
        for(ll j=0;j<3;j++){
            if(b.arr[i][j]=='X'){
                count++;
            }
        }
        if(count==3){
            return 'X';
        }
        count=0;
        for(ll j=0;j<3;j++){
            if(b.arr[i][j]=='O'){
                count++;
            }
        }
        if(count==3){
            return 'O';
        }
        count=0;
        for(ll j=0;j<3;j++){
            if(b.arr[j][i]=='O'){
                count++;
            }
        }
        if(count==3){
            return 'O';
        }
        count=0;
        for(ll j=0;j<3;j++){
            if(b.arr[j][i]=='X'){
                count++;
            }
        }
        if(count==3){
            return 'X';
        }
    }
    if(b.arr[0][0]=='X' && b.arr[1][1]=='X' && b.arr[2][2]=='X'){
        return 'X';
    }
    if(b.arr[0][0]=='O' && b.arr[1][1]=='O' && b.arr[2][2]=='O'){
        return 'O';
    }
    if(b.arr[0][2]=='X' && b.arr[1][1]=='X' && b.arr[2][0]=='X'){
        return 'X';
    }
    if(b.arr[0][2]=='O' && b.arr[1][1]=='O' && b.arr[2][0]=='O'){
        return 'O';
    }
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b.arr[i][j]=='-')
                count++;
        }
    }
    if(count==0){
        return 'D';
    }
    else{
        return '-';
    }
}
int len=0,win=0,lose=0,draw=0;
void build(board b,char turn,int index,int depth){
    if(check(b)=='X'){
        store[mapping[index]].score=10;
        win++;
        return;
    }
    if(check(b)=='O'){
        store[mapping[index]].score=-10;
        lose++;
        return;
    }
    if(check(b)=='D'){
        store[mapping[index]].score=0;
        draw++;
        return;
    }
    int ma=-10000,mi=10000;
    if(turn=='C'){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b.arr[i][j]=='-'){
                    board next=b;
                    next.arr[i][j]='X';
                    next.index=len;
                    store.pb(next);
                    mapping[len]=store.size()-1;
                    len++;
                    game[index].pb(len-1);
                    int x=len-1;
                    build(next,'P',len-1,depth+1);
                    ma=max(ma,store[mapping[x]].score);
                }
            }
        }
        store[mapping[index]].score=ma-depth;
    }
    if(turn=='P'){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b.arr[i][j]=='-'){
                    board next=b;
                    next.arr[i][j]='O';
                    next.index=len;
                    store.pb(next);
                    mapping[len]=store.size()-1;
                    len++;
                    game[index].pb(len-1);
                    int x=len-1;
                    build(next,'C',len-1,depth+1);
                    mi=min(mi,store[mapping[x]].score);
                }
            }
        }
        store[mapping[index]].score=mi+depth;
    }
}
void print(board b){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<b.arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool compare(board b1,board b2){
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b1.arr[i][j]==b2.arr[i][j]){
                count++;
            }
        }
    }
    return count==9;
}
bool over(board b){
    if(check(b)=='X'){
        print(b);
        cout<<"You Lost\n";
        return 1;
    }
    if(check(b)=='O'){
        print(b);
        cout<<"You Win\n";
        return 1;
    }
    if(check(b)=='D'){
        print(b);
        cout<<"Tie\n";
        return 1;
    }
    return 0;
}
int main(){
    board b;
    b.index=0;
    store.pb(b);
    mapping[0]=0;
    store.pb(b);
    len++;
    build(b,'P',0,0);
    map<int,pair<int,int> > m;
    m[1]={0,0};                                             //    1 2 3
    m[2]={0,1};                                             //    4 5 6
    m[3]={0,2};                                             //    7 8 9
    m[4]={1,0};
    m[5]={1,1};
    m[6]={1,2};
    m[7]={2,0};
    m[8]={2,1};
    m[9]={2,2};
    cout<<"\t\t\t\t\tYou can't beat me, but you can try!!\n";
    while(1){
        if(over(b)){
            return 0;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<b.arr[i][j]<<" ";
            }
            cout<<endl;
        }
        int chose;
        cin>>chose;
        while(chose<1 || chose>9){
            cout<<"Invalid Move, Enter again\n";
            cin>>chose;
        }
        int i=m[chose].ff,j=m[chose].ss;
        while(b.arr[i][j]!='-'){
            cout<<"Invalid Move, Enter again\n";
            cin>>chose;
            i=m[chose].ff;
            j=m[chose].ss;
        }
        b.arr[i][j]='O';
        if(over(b)){
            return 0;
        }
        for(int i=0;i<game[b.index].size();i++){
            if(compare(b,store[mapping[game[b.index][i]]])){
                b=store[mapping[game[b.index][i]]];
                int ma=-1;
                board temp;
                for(int j=0;j<game[b.index].size();j++){
                    if(store[mapping[game[b.index][j]]].score>ma){
                        ma=store[mapping[game[b.index][j]]].score;
                        temp=store[mapping[game[b.index][j]]];
                    }
                }
                b=temp;
                break;
            }
        }
    }
}
