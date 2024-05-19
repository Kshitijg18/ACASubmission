#include <iostream>
#include <math.h>
#include <sstream>


using namespace std;

int main()
{
    
    int n;
    cin >> n;
    int flag =1;
    for(int i=1; i<=n; i++)
    {
        int flag = 1;
        for(int j=0; j<n+n/2; j++)
        {
            if(flag == 1)
            {
                for(int k=1; k<=i; k++) 
                cout << k;
                flag =2; continue;
            }
            if(flag == 2)
            {
                for(int k=i+1; k<=n; k++) 
                cout << " ";
                for(int k=i+1; k<=n; k++) 
                cout << " ";
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