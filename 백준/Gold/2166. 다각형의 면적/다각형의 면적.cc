#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<pair<double,double>> points(10001,{0,0});

int main()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>points[i].first>>points[i].second;

    double area;
    for(int i=0;i<N;i++)
    {
        int j=(i+1)%N;

        area+=(points[i].first*points[j].second-points[i].second*points[j].first);
    }
    area/=2.0;
    
    cout<<fixed;
    cout.precision(1);
    cout<<fabs(area)<<"\n";

    return 0;
}