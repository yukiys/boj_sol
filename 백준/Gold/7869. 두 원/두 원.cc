#include <iostream>
#include <cmath>

const double PI = acos(-1.0);

using namespace std;

double x1_, y1_, r1_, x2_, y2_, r2_;
double ans;

void init();
void solve();
double getDist();
double getArea(double);
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> x1_ >> y1_ >> r1_ >> x2_ >> y2_ >> r2_;
}

void solve()
{
    double dist = getDist();

    if(dist >= r1_ + r2_)
        ans = 0;
    else if(abs(r1_ - r2_) < dist and dist < r1_ + r2_)
        ans = getArea(dist);
    else
        ans = PI * pow(min(r1_, r2_), 2);
}

double getDist()
{
    double dist = (x1_ - x2_) * (x1_ - x2_);
    dist += (y1_ - y2_) * (y1_ - y2_);
    dist = sqrt(dist);

    return dist;
}

double getArea(double dist)
{
    double theta1 = acos((dist * dist + r1_ * r1_ - r2_ * r2_) / (2 * dist * r1_));
    double area1 = r1_ * r1_ * theta1;
    area1 -= 0.5 * r1_ * r1_ * sin(2 * theta1);
    
    double theta2 = acos((dist * dist + r2_ * r2_ - r1_ * r1_) / (2 * dist * r2_));
    double area2 = r2_ * r2_ * theta2;
    area2 -= 0.5 * r2_ * r2_ * sin(2 * theta2);

    return area1 + area2;
}

void printAns()
{
    cout << fixed;
    cout.precision(3);
    cout << ans << "\n";
}