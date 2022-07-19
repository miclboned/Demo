#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> Solution(vector<int>& nums,int target)
{
    if(nums.size()<3) return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;

    for(int i=0;i<nums.size();i++)
    {
        if(i>0&&nums[i]==nums[i-1]) 
            continue;
        int left=i+1;
        int right=nums.size()-1;

        while(left<right)
        {
            if(left>i&&right<nums.size())
            {
                if(nums[left]==nums[left-1]&&nums[right]==nums[right+1])
                    continue;
            }

            int sum=nums[i]+nums[left]+nums[right];

            if(sum==target)
            {
                res.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                left++;
                right--;
            }
            else if(sum>target)
            {
                right--;
            }
            else
            {
                left++;
            }
            
        }
    }
    return res;
    
}


int main()
{
    vector<int> nums={-1,1,0,2,-1};
    vector<vector<int>> res;
    const int target=0;

    res=Solution(nums,target);
    
    for(auto &iter1:res)
    {
        for(auto &iter2:iter1)
        {
            cout<< iter2<<" ";
        }
    }

    return 0;
}