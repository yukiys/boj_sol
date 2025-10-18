#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int solution[100000];
int ret1,ret2;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>solution[i];
    sort(solution,solution+N);
}

void func(int left,int right)
{
    ret1=solution[left];
    ret2=solution[right];

    while(left<right)
    {
        int cur=solution[left]+solution[right];
        if(abs(ret1+ret2)>abs(cur))
        {
            ret1=solution[left];
            ret2=solution[right];
        }
        
        if(cur==0) break;
        else if(cur<0) left++;
        else right--;
    }
}

void printResult()
{
    cout<<ret1<<" "<<ret2<<"\n";
}

int main()
{
    input();
    func(0,N-1);
    printResult();

    return 0;
}