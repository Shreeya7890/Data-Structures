//Difference between si and the maximum strength of any participant other than participant i.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testcases;
    cin>>testcases;

    while (testcases--)
    {
        solve();
    }
    return 0;
}

//Function to find the 1st highest and 2nd highest number and perform subtraction accordingly while traversing
void solve()
{
    int n;
    cin>>n;
    vector<int> s(n);
    int max1=-1;
    int max2=-1;
    for (int i=0; i<n; i++)
    {
        cin>>s[i];
        if (s[i]>max1){
            max2=max1;
            max1=s[i];
        }
        else if(s[i]>max2){
            max2=s[i];
        }
    }

    for (int i=0; i<n; i++)
    {
        if (s[i]==max1)
        {
            cout<<s[i]-max2<< " ";
        }
        else 
        {
            cout<<s[i]-max1<<" ";
        }
    }
}
