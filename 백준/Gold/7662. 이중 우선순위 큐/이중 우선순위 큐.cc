#include <iostream>
#include <set>

using namespace std;

int T,k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--)
    {
        multiset<int> ms;

        cin>>k;
        for(int i=0;i<k;i++)
        {
            char op;
            int num;
            cin>>op>>num;

            if(op=='I') ms.insert(num);
            else
            {
                if(ms.empty()) continue;
                
                if(num==1) ms.erase(--ms.end());
                else ms.erase(ms.begin());
            }
        }

        if(ms.empty()) cout<<"EMPTY"<<"\n";
        else cout<<*ms.rbegin()<<" "<<*ms.begin()<<"\n";
    }

    return 0;
}