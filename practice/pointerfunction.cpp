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

int add(int a, int b) {return a+b;}
int multi(int a, int b){return a*b;}

int main()
{
    //void (*Fun)();
    typedef void(*HelloworldFunction)(int a);
    std::vector<int> values={1,5,4,3,2};
    
    std::function<int(int,int)> fun[]={add,multi};

    std::cout<<fun[0](1,2)<<std::endl;
    std::cout<<fun[1](1,2)<<std::endl;

    auto value=std::count_if(values.begin(),values.end(),[](int value){return value%2==0;});
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