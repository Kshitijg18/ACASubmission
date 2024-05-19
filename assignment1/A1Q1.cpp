#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#define ll long long
#define all(c) c.begin(),c.end()
#define sz(c) int(c.size())
#define tr(a,it) for(auto it=a.begin(); it!=a.end(); it++)
#define present(c, x)(c.find(x) != c.end())
#define cpresent(c, x)(find(all(c), x) != c.end())
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define inf 10e9
#define MOD %(1000000007)
#define loop(i,s,e) for(int i=s; i<e; i++)
#define revloop(i,s,e) for(int i=s; i>=e; i--)

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int flag =1;
    for(int i=1; i<=n; i++)
    {
        int flag = 1;
        for(int j=0; j<n+n/2; j++)
        {
            if(flag == 1)
            {
                for(int k=1; k<=i; k++) cout << k;
                flag =2; continue;
            }
            if(flag == 2)
            {
                for(int k=i+1; k<=n; k++) cout << " ";
                for(int k=i+1; k<=n; k++) cout << " ";
                flag =3; continue;
            }
            if(flag == 3)
            {
                for(int k=i; k>=1; k--) cout << k;
                flag =1; continue;
            }
        }cout << endl;
    }
    return 0;
}