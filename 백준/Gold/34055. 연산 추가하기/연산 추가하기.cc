#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,Q;
long long H;
vector<pair<long,long>> F;
vector<pair<long,long>> S;
vector<long long> Len;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>H;

    for(int i=0;i<N;i++)
    {
        long long A,B;
        cin>>A>>B;
        F.push_back({A,B});
    }
    sort(F.begin(),F.end());

    for(int i=0;i<N;i++)
    {
        if(S.empty() or S.back().second<F[i].first-1) S.push_back(F[i]);
        else S.back().second=max(S.back().second,F[i].second);
    }

    for(int i=0;i<=S.size();i++)
    {
        long long a,b;
        if(i==0) a=0;
        else a=S[i-1].second;
        if(i==S.size()) b=H+1;
        else b=S[i].first;
        
        Len.push_back(b-a-1);
    }
    sort(Len.begin(),Len.end());

    vector<long long> LenSum(Len.size());
    LenSum[0]=Len[0];
    for(int i=1;i<Len.size();i++) LenSum[i]=LenSum[i-1]+Len[i];

    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        long long t,ret;
        cin>>t;

        int idx=lower_bound(Len.begin(),Len.end(),t)-Len.begin();

        if(idx==0) ret=LenSum.back()-(t-1)*(Len.size()-idx);
        else ret=LenSum.back()-LenSum[idx-1]-(t-1)*(Len.size()-idx);

        cout<<ret<<"\n";
    }

    return 0;
}