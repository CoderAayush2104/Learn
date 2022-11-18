#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        int arr[10];
        int add = 0;
        int sub = 0;
        int num = 0;

        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
        

        for (int i = 0; i < n; i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                arr[s[i]-48]++;
                num++;
            }
            if(s[i]=='+')
            {
                add++;
            }
            if(s[i]=='-')
            {
                sub++;
            }
        }

        // char ans[n];

        int i = 9;
        int j = 0;

        while (num>(add+sub+1))
        {
            if(arr[i]!=0)
            {
                cout<<(char)(i + 48);
                j++;
                arr[i]--;
                num--;
            }
            else
            {
                i--;
            }
        }

        int check = j%2;

        for ( j ; j < n; j++)
        {
            if(j%2==check)
            {
                while(arr[i]==0)
                {
                    i--;
                }
                cout<<(char)(i + 48);
                arr[i]--;
            }
            else
            {
                if(add!=0)
                {
                    cout<<'+';
                    add--;
                }
                else
                {
                    cout<<'-';
                }
            }
        }
    }
    return 0;
}