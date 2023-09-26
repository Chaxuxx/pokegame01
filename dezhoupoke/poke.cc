#include "poke.h"

pokecard::pokecard(int joker_in):is_52(joker_in){
    colors ctemp[4] = {
        Spades,
        Hearts,
        Diamonds,
        Clubs};
    int nums[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int k = 0;
    for(colors i : ctemp)
    {
        for(int j :nums)
        {
            // card c{i,j};
            cards.emplace_back(card{i,j});
            k++;
        }
    }
    if(is_52 == 0)
    {
        cards.emplace_back(card{joker,53}); //小王
        cards.emplace_back(card{Joker,54}); //大王
        card_num = 54;
    }
}
pokecard::card pokecard::getcard(){
    uniform_int_distribution<int> dist(0, card_num - 1);//基于指定范围
    int randomIndex = dist(rng);//范围使用随机数生成器
    swap(cards[randomIndex],cards[card_num-1]);
    card_num--;
    return cards[card_num];
}
string pokecard::showcard(pokecard::card cad){
    string result;
    switch(cad.color)
    {
      case Spades:result+="♠";break;
      case Hearts:result+="♥";break;
      case Diamonds:result+="♦";break;
      case Clubs:result+="♣";break;
      case joker:result+="joker";break;
      case Joker:result+="Joker";break;
    }//早知道不用enum了
    
    if(cad.num == 11)result+="J";
    else if(cad.num == 12)result+="Q";
    else if(cad.num == 13)result+="K";
    else if(cad.num == 1)result+="A";
    else if(cad.num!=54&&cad.num!=53)result+=to_string(cad.num);
    
    return result;
}
string pokecard::draw()
{
  if(card_num == 0)return "out of card";
  return showcard(getcard());
}
void pokecard::washcard()
{
  if(is_52 == 0) card_num = 54;
  if(is_52 == 1) card_num = 52;
}

int pokecard::getcardnum(){
    return card_num;
}