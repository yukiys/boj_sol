#include <iostream>
#include <queue>

using namespace std;

int N;
int result;

int main()
{
    cin>>N;
    priority_queue<int> pq;
    for(int n=0;n<N;n++)
    {
        int num;
        cin>>num;
        pq.push(-num);
    }
    
    while(pq.size()!=1)
    {
        int a=-pq.top(); pq.pop();
        int b=-pq.top(); pq.pop();
        int c=a+b;

        result+=c;
        pq.push(-c);
    }
    
    cout<<result<<"\n";

    return 0;
}