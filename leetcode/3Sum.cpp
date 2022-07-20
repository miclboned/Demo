#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

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
    //auto start=chrono::steady_clock::now();
    clock_t start_t,end_t;
    start_t=clock();
    for(int i=0;i<1000;i++)
        res=Solution(nums,target);
    
    end_t=clock();
    double total=static_cast<double>(end_t-start_t)/CLOCKS_PER_SEC;
    printf("%f\n",total);
    //auto end =chrono::steady_clock::now();
    //auto diff =(end-start);
    //cout<<chrono::duration<double,milli>(diff).count() <<"ms"<<endl;
    for(auto &iter1:res)
    {
        for(auto &iter2:iter1)
        {
            cout<< iter2<<" ";
        }
    }

    return 0;
}