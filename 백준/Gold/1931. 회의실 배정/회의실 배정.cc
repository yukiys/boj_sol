#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    vector<pair<int,int>> T;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;

        T.push_back({b,a});
    }

    sort(T.begin(),T.end());

    int count=1,h=T[0].first;
    for(int i=1;i<N;i++){
        if(h<=T[i].second){
            count++;
            h=T[i].first;
        }
    }

    cout<<count<<"\n";

    return 0;
}