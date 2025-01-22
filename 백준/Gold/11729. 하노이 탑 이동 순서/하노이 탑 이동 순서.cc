#include <iostream>

using namespace std;

void hanoi(int start,int end,int n);

int main()
{
    int N;
    cin>>N;

    int array[21];
    array[1]=1;
    for(int i=2;i<=N;i++) array[i]=2*array[i-1]+1;

    cout<<array[N]<<"\n";

    hanoi(1,3,N);

    return 0;
}

void hanoi(int start,int end,int n)
{
    int c=6/start/end;
    if(n==1)
    {
        cout<<start<<" "<<end<<"\n";
        return;
    }

    hanoi(start,c,n-1);
    cout<<start<<" "<<end<<"\n";
    hanoi(c,end,n-1);
}