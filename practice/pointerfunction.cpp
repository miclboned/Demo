#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void PrintValue(int value)
{
    std::cout<<"Value: "<<value<<std::endl;
}
/*void For_each(const std::vector<int>&values,void(*func)(int))
{
    for(int value:values)
    {
        func(value);
    }
}*/
void For_each(const std::vector<int>&values,const std::function<void(int)>& func)
{
    for(int value:values)
    {
        func(value);
    }
}


int main()
{
    //void (*Fun)();
    typedef void(*HelloworldFunction)(int a);
    std::vector<int> values={1,5,4,3,2};

    int value=std::count_if(values.begin(),values.end(),[](int value){return value%2==0;});
    std::cout<<value<<std::endl;
    auto it= std::find_if(values.begin(),values.end(), [](int value){return value>3;});
    std::cout<<*it<<std::endl;
    
    int a=5;
    auto Lambda=[=](int value){std::cout<<"Value: "<<a<<std::endl;};

    //For_each(values,PrintValue);
    //For_each(values,[](int value){std::cout<<"Value: "<<value<<std::endl;});
    For_each(values,Lambda);

   
    return 0;
}