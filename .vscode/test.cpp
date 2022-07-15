#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void floodfill (vector<vector<int>>& image,int sr,int sc ,int color)
{
    const int target =image[sr][sc];
    if(target==color) return ;

    queue<pair<int,int>> q;
    q.push({sr,sc});

    while(!q.empty())
    {
        const auto [x,y]=q.front();
        q.pop();

        if(x<0||y<00||x==image.size()||y==image[0].size()||image[x][y]!=target) continue;

        image[x][y]=color;

        q.push({x+1,y});
        q.push({x-1,y});
        q.push({x,y+1});
        q.push({x,y-1});

    }

    

}
void DFS(vector<vector<int>>& image,int x,int y ,int rw,int cl ,int oldcolor,int newcolor)
{
  

    

    if(x<0||y<0||x==rw||y==cl||image[x][y]!=oldcolor) return ;
    image[x][y]=newcolor;
    DFS(image,x-1,y,rw,cl,oldcolor,newcolor);
    DFS(image,x+1,y,rw,cl,oldcolor,newcolor);
    DFS(image,x,y-1,rw,cl,oldcolor,newcolor);
    DFS(image,x,y+1,rw,cl,oldcolor,newcolor);

}
int main()
{
    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1;
    int color=2;

    for(int i=0;i<image.size();i++)
    {
        for(auto &iter : image[i])
        {
            cout<< iter<<" ";
        }
        cout<<endl;
    }

    //floodfill(image,sr,sc,color);
    DFS(image,sr,sc,image.size(),image[0].size(),image[sr][sc],color);
    
    for(int i=0;i<image.size();i++)
    {
        for(auto &iter : image[i])
        {
            cout<< iter<<" ";
        }
        cout<<endl;
    }

    return 0;
}
