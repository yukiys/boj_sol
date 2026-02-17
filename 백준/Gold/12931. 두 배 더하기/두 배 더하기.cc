#include <iostream>

using namespace std;

int N, ans;
int numOfOdd;
int B[50];

void init();
void solve();
bool isEnd();
void countOdds();
void divB();
void calculateAns();
void printAns();

int main()
{
    init();
    solve();
    printAns();
}

void init()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> B[i];
}

void solve()
{
    while(!isEnd())
    {
        countOdds();
        calculateAns();
    }
}

bool isEnd()
{
    for(int i = 0; i < N; i++)
        if(B[i] != 0)
            return false;
    
    return true;
}

void countOdds()
{
    numOfOdd = 0;
    for(int i = 0; i < N; i++)
    {
        if(B[i] % 2 !=0)
        {
            B[i]--;
            numOfOdd++;
        }
    }
}

void divB()
{
    for(int i = 0; i < N; i++)
        B[i] /= 2;
}

void calculateAns()
{
    if(numOfOdd != 0)
        ans += numOfOdd;
    else{
        divB();
        ans += 1;
    }
}

void printAns()
{
    cout << ans << "\n";
}