#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i = 1;
    int j = n-i;
    
    int count = 0;

    while (i<=n && j>=1)
    {
        j = n-i;
        if(j>=1)
        {
            count++;
        }
        i++;
    }

    cout<<count<<endl;
    
    return 0;
}
