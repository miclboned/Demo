#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


vector<int> Solution(vector<int>& nums, int target)
{
    unordered_map<int,int> hs;
    vector<int> res;
    for(int i=0;i<nums.size();i++)
    {
        int temp=target-nums[i];
        if(hs.find(temp)!=hs.end())
        {
            res.emplace_back(hs[temp]);
            res.emplace_back(i);
            return res;
        }

        hs[nums[i]]=i;
    }

    return {};
}


int main()
{

    vector<int> nums={2,7,11,13};
    const int target =12;
    vector<int> res;
   
    res=Solution(nums,target);
    
   
    if(!res.empty())
    { 
        cout<<"Answer: [ ";
         for(auto &iter : res)
        {
            cout<<iter<<" , ";
            cout<<"]";
        }
    }
    else
    {
        cout<<"Not have Answer.";
    }
   
    return 0;
}


