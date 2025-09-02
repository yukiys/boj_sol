#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int T,N;
string p;
string arr;

void test()
{
    getline(cin,p);

    cin>>N; cin.ignore();
    
    getline(cin,arr);
    arr=arr.substr(1,arr.size()-2);
    stringstream ss(arr);
    string s;
    deque<int> d;
    while(getline(ss,s,','))
        d.push_back(stoi(s));

    bool r=false;
    for(char c:p)
    {
        if(d.empty() and c=='D')
        {
            cout<<"error"<<"\n";
            return;
        }

        if(c=='R') r=!r;
        else if(!r)
        {
            d.pop_front();
            N--;
        }
        else
        {
            d.pop_back();
            N--;
        }
    }

    if(N==0) cout<<"[]"<<"\n";
    else
    {
        cout<<"[";
        if(!r)
        {
            for(int i=0;i<N-1;i++) cout<<d[i]<<",";
            cout<<d[N-1];
        }
        else
        {
            for(int i=N-1;i>0;i--) cout<<d[i]<<",";
            cout<<d[0];
        }
        cout<<"]";
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>T; cin.ignore();
    while(T--) test();

    return 0;
}