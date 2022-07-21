#include <iostream>
#include <string>

using namespace std;


int main()
{
    const string s ="-111111111111111";
    int it=0;
    int len=s.size();
    
    while(it<len&&s[it]==' ') it++;
    if(it==len) return 0;

    int sign=1;
    if(s[it]=='-'||s[it]=='+')
    {
        if(s[it]=='-')
            sign=-1;
        it++;
    }

    int start=it;
    while(it<len&&isdigit(s[it])) it++;

    string num=s.substr(start,it-start);
    int res=0;
    for(char c:num)
    {
        int temp=c-'0';
        if(res>INT_MAX/10||(res==INT_MAX&&temp>7)) 
        {
            cout<<INT_MAX;
            return INT_MAX;
        }
        if(res<INT_MIN/10||(res==INT_MIN&&temp>8)) 
        {
            cout<<INT_MIN;
            return INT_MIN;
        }
        res=res*10+temp*sign;
    }
    cout<<res;
    return 0;
}