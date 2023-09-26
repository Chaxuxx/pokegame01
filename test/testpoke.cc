#include "poke.h"
#include <iostream>
int main()
{
    pokecard A;
    for(int i = 0;i<60;i++)
    {
        cout<<A.draw()<<endl;
    }
    // 以下为 getcard为public下的测试
    // pokecard A;
    // int nums[14]={0};//如果不初始化 就有可能不是从0加起
    // int color[7]={0};
    // for(int i = 0;i<54;i++)
    // {
    //     pokecard::card cad = A.getcard();
    //     nums[cad.num]++;
    //     color[cad.color]++;
    //     // cout<<A.draw()<<endl;
    // }
    // for(int &i :nums)cout<<i<<" ";
    // for(int i :color)cout<<i<<" ";

}