#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> plu,minu;
int main()
{
    int n,i,j,k,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        if(j>0)
            plu.push(-j);
        else if(j<0) minu.push(j);

        else if(j==0)
        {
            if(plu.empty()&&minu.empty())
                cout<<0;
            else if(plu.empty())
            {
                cout<<minu.top();
                minu.pop();
            }
            else if(minu.empty())
            {
                cout<<-plu.top();
                plu.pop();
            }
            else {
                if(minu.top()==plu.top())
                {
                    cout<<minu.top();
                    minu.pop();
                }
                else if(plu.top()>minu.top())
                    {
                     cout<<-plu.top();
                    plu.pop();
                }
                else
                {
                cout<<minu.top();
                plu.pop();
                }
            }
            if(i<n-1) cout<<endl;


        }



    }
}
