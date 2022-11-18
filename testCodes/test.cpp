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

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                count++;
            }
        }
        
        int num[count];

        int no_sign = n-count;
        int no = 0;

        int add = 0;
        int sub = 0;

        for (int i = 0; i < n; i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                num[no++] = s[i]-'0';
            }
            else
            {
                if(s[i]=='+')
                {
                    add++;
                }
                else
                {
                    sub++;
                }
            }
        }

        sort(num, num+count);

        char ans[n];

        int i = 0;

        int j = count-1;
        int k = 0;
        

        while (count>no_sign+1)
        {
           ans[i++] = num[j--] + '0'; 
        }

        int flag = i%2;
        int flag2;

        for (i ; i < n; i++)
        {
            flag2 = i%2;
            if(flag2==flag2)
            {
                ans[i] = num[j--] + '0';
            }
            else
            {
                if(add!=0)
                {
                    ans[i] = '+';
                    add--;
                }
                else
                {
                    ans[i] = '-';
                }
            }
        }
        
        for (int t = 0; t < n; t++)
        {
            cout<<ans[t];
        }
        cout<<endl;
        

        // int j = 0;
        // int v = 0;
        // int f = 0;

        // int ans[n];

        // while(count-j==no_sign)
        // {
        //     ans[v++] = num[j++];
        // }

        // int g = v;

        // for (int i = 0; i < n-g; i++)
        // {
        //     if(i%2==0)
        //     {
        //         ans[v++] = sign[f++];
        //     }
        //     else
        //     {
        //         ans[v++] = num[j++];
        //     }
        // }
        
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}