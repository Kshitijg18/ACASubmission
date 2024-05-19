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
    ll examScores[10]; ll sum=0;
    ll maxScore = 0,minScore=inf;
    for(int i=0; i<10; i++)
    {
        cin >> examScores[i];
        sum+=examScores[i];
        maxScore = max(maxScore,examScores[i]);
        minScore = min(minScore,examScores[i]);
    }
    ll avg = sum/10;
    ll aboveAvg=0;
    for(int i=0; i<10; i++){aboveAvg+=examScores[i]>=avg;}
    cout << "Average Score: "<<avg<<endl;
    cout << "Highest Score: "<<maxScore<<endl;
    cout << "Lowest Score: "<<minScore<<endl;
    cout << "Number of exam scores above the average: "<<aboveAvg<<endl;
    cout << "Number of exam scores below the average: "<<10-aboveAvg<<endl;
    return 0;
}