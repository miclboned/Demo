#include <iostream>
#include <unordered_map>
#include <chrono>
#include <string>
using namespace std;

bool isAnagram(string s,string t)
{
    int alphabet[26]={0};

    for(int i=0;i<s.size();i++)
    {
       alphabet[s[i]-'a']++;
       alphabet[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(alphabet[i])
            return false;
    }
    
   
    return true;
}


int main()
{
    string s="rat";
    string t="cat";


    if(isAnagram(s,t))
        cout<<"Anagram"<<endl;
    else
        cout<<"is not anagram"<<endl;

    return 0;
}