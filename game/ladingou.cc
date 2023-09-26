#include "poke.h"
#include <iostream>
using namespace std;
class ladingou{
    pokecard cards;
    vector<pokecard::card> desk;//在类内部没法用（）初始化vector<int>
    vector<pokecard::card> playerA;
    vector<pokecard::card> playerB;
    int numA;
    int numB;
    // 终止情况 一个人手里有所有牌 一个人手里0张牌
    // 一个人手里只有j
    // 一个人手里0张牌 桌子上有牌 没必要继续了
    int a = 0;
    int b = 0;//指向a、b当前牌首
    int al = 27;
    int bl = 27;//指向a,b排尾
    int d = 0;
public:
    ladingou()//如果把构造函数放在private我们应该如何构造对象
    {
        int n = 27;
        vector<pokecard::card>temp;
        for(int i = 0;i<54;i++)
        {
            temp.emplace_back(pokecard::card{pokecard::colors(0),0});
        }
        desk = temp;
        playerA = temp;
        playerB = temp;
        numA = 27;
        numB = 27;
        for(int i = 0;i<n;i++)
        {
            pokecard::card c = cards.getcard();
            playerA[i]=c;
            c = cards.getcard();
            playerB[i]=c;
        }
    }
    void displaydesk()
    {
        cout<<numA<<" "<<numB<<" ";
        for(int i = 0;i<=d;i++)
        {
            if(desk[i].num==0)break;
            cout<<cards.showcard(desk[i])<<" ";
        }
        //这个display写的有问题 runA里一个在显示d 一个显示到d之前一个元素 所以需要两个条件
        // 一个是i<=d 一个是 num==0
        cout<<endl;
    }
    void runA()
    {
        desk[d]=playerA[a];
        playerA[a++].num=0;
        if(a==54)a=0;
        numA--;
        displaydesk();
    
        if(desk[d].num==53){
            int i = 3;
            while(i--){
                playerA[al++]=playerB[b];
                playerB[b].num=0;
                b++;
                if(al==54)al=0;
                if(b==54)b=0;
            }
            numA+=3;
            numB-=3;
            d++;
            return;
        }
        if(desk[d].num==54){
            int i = 5;
            while(i--){
                playerA[al++]=playerB[b];
                playerB[b].num=0;
                b++;
                if(al==54)al=0;
                if(b==54)b=0;
            }
            numA+=5;
            numB-=5;
            d++;
            return;
        }

        int cat = -1;
        if(desk[d].num==11)cat = 0;
        for(int i = d-1;i>=0;i--)
        {
            if(desk[i].num==desk[d].num) {cat = i;break;}
        }
        if(cat!=-1)
        {
            for(int i = cat;i<=d;i++)
            {
                playerA[al++]=desk[i];
                desk[i].num = 0;
                if(al==54)al = 0;
            }
            numA+=d-cat+1;
            d=cat;
            if(numA==countj(playerA))return;
            displaydesk();
            runA();
        }
        else d++;
        return;
    }
    void runB()
    {
        desk[d]=playerB[b];
        playerB[b++].num=0;
        if(b==54)b=0;
        numB--;
        displaydesk();
        
        if(desk[d].num==53){
            int i = 3;
            while(i--){
                playerB[bl++]=playerA[a];
                playerA[a].num=0;
                a++;
                if(a==54)a=0;
                if(bl==54)bl=0;
            }
            numA-=3;
            numB+=3;
            d++;
            return;
        }
        if(desk[d].num==54){
            int i = 5;
            while(i--){
                playerB[bl++]=playerA[a];
                playerA[a].num=0;
                a++;
                if(a==54)a=0;
                if(bl==54)bl=0;
            }
            numA-=5;
            numB+=5;
            d++;
            return;
        }

        int cat = -1;
        if(desk[d].num==11)cat = 0;
        for(int i = d-1;i>=0;i--)
        {
            if(desk[i].num==desk[d].num) {cat = i;break;}
        }
        if(cat!=-1)
        {
            for(int i = cat;i<=d;i++)
            {
                playerB[bl++]=desk[i];
                desk[i].num = 0;
                if(bl==54)bl = 0;
            }
            numB+=d-cat+1;
            if(numB==countj(playerB))return;
            d=cat;
            displaydesk();
            runB();
        }
        else d++;
        return;
    }
    int countj(vector<pokecard::card> cv)
    {
        int count = 0;
        for(pokecard::card c :cv)
        {
            if(c.num==11)count++;
        }
        return count;
    }
    void run(){
        cards.washcard();
        ladingou();
        
        while(1)
        {
            cout<<"A turn:"<<endl;
            runA();
            cout<<"B turn:"<<endl;
            runB();
            if(numA==0||numA==countj(playerA)){cout<<"B win"<<endl;break;}
            if(numB==0||numB==countj(playerB)){cout<<"A win"<<endl;break;}
            //如果是以只剩J结束最好输出输家的牌库？
            //
        }

    }
};
int main(){
    // 把拉丁勾封装成类 然后class ladingou.start();
    ladingou lj;

    lj.run();
    //如果要实现重复游玩，可以重复利用ladingou类对象，洗牌card_num置为0,然后重新调用构造函数分牌
    // cin>>n while(n==1){lj.cards.washcard();lj.ladingou()}
}