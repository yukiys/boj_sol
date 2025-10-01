#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
long long solution[100000];
long long ret1,ret2,ret3;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>solution[i];
    sort(solution,solution+N);
}

void func(int left,int right)
{
    ret1=solution[left];
    ret2=solution[(left+right)/2];
    ret3=solution[right];

    for(int mid=1;mid<N-1;mid++)
    {
        int l=left;
        int r=right;
        while(l<mid and mid<r)
        {
            long long cur=solution[l]+solution[mid]+solution[r];
            if(abs(ret1+ret2+ret3)>abs(cur))
            {
                ret1=solution[l];
                ret2=solution[mid];
                ret3=solution[r];
            }
            
            if(cur==0) break;
            else if(cur<0) l++;
            else r--;
        }
    }
}

void printResult()
{
    cout<<ret1<<" "<<ret2<<" "<<ret3<<"\n";
}

int main()
{
    input();
    func(0,N-1);
    printResult();

    return 0;
}