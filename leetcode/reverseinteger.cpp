#include <iostream>



using namespace std;

int main()
{
    int x=INT32_MAX;
    int res=0;
    while(x!=0)
    {
        if(res>INT_MAX||res<INT_MIN) return 0;

        res=res*10+x%10;
        x/=10;
    }
    cout<<res;
    return 0;
}