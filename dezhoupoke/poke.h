#ifndef __POKE_H__
#define __POKE_H__

#include <vector>
#include <string>
#include <random>
// #include <chrono>
// #include <ctime>
using namespace std;
class pokecard{
public:
    enum colors{
        Spades,
        Hearts,
        Diamonds,
        Clubs,
        joker,
        Joker
    };
    struct card{
    colors color;
    int num;
    };
    pokecard(int joker_in = 0);//初始化 参数是is_52
    card getcard();//抽一张牌
    string showcard(card cad);//显示一张牌 
    void washcard();//洗牌
    string draw();//抽一张牌，返回string
    int getcardnum();//查看剩余牌量
private:
    
    vector<card> cards;
    int card_num = 52;
    bool is_52 = 0;
    random_device rd;//随机数种子
    default_random_engine rng{rd()};
};
//用一下单例模式 每个程序中只有一副牌？ 对于52和54如何切换？ 52继承54
//设想在服务器场景下 一个线程支持一种54玩法 一个线程支持一种52玩法 单例了父类和单例了子类是可以的。
// 其实可以使用抽到大小王了就再抽一张的策略 is_52 == 1 则执行这样的抽牌策略
// 如果服务器开多局，牌库不可能是单例，有多少局肯定有多少副牌
// class pokecard52 :public pokecard
// {
//     int card_num = 52; //这样调用基类的getcardnum()是54
// };

#endif