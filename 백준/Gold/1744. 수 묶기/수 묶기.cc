#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;

    int A[50],minus=0,plus=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<=0) minus++;
        else plus++;
    }
    sort(A,A+N);

    int result=0;
    for(int i=0;i<minus/2;i++) result+=A[i*2]*A[i*2+1];
    if(minus%2==1) result+=A[minus-1];

    for(int i=0,j=N-1;i<plus/2;i++){
        if(A[j]==1||A[j-1]==1) result+=A[j]+A[j-1];
        else result+=A[j]*A[j-1];
        j-=2;
    }
    if(plus%2==1) result+=A[N-plus];

    cout<<result<<"\n";

    return 0;
}