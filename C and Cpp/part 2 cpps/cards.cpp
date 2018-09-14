#include<iostream>
#include<array>

enum Cardrank
{
  RANK_ACE,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_MAX
};
enum Cardsuit
{
  SUIT_CLUB,
  SUIT_SPADES,
  SUIT_HEART,
  SUIT_DIAMOND,
  SUIT_MAX
};

struct Card
{
  Cardrank rank;
  Cardsuit suit;
};

void printcard(const Card &card)
{
   switch(card.rank)
   {
      case RANK_ACE:  std::cout<<'A';break;
      case RANK_2:    std::cout<<'2';break;
      case RANK_3:    std::cout<<'3';break;
      case RANK_4:    std::cout<<'4';break;
      case RANK_5:    std::cout<<'5';break;
      case RANK_6:    std::cout<<'6';break;
      case RANK_7:    std::cout<<'7';break;
      case RANK_8:    std::cout<<'8';break;
      case RANK_9:    std::cout<<'9';break;
      case RANK_10:   std::cout<<'T';break;
      case RANK_JACK: std::cout<<'J';break;
      case RANK_QUEEN:std::cout<<'Q';break;
      case RANK_KING: std::cout<<'K';break;
   }
   
   switch(card.suit)
   {
      case SUIT_CLUB: std::cout<<'C';break;
      case SUIT_SPADES: std::cout<<'S';break;
      case SUIT_HEART: std::cout<<'H';break;
      case SUIT_DIAMOND: std::cout<<'D';break;
   }
}

void swapCard(Card &card1,Card &card2)
{
   Card temp;
   temp=card1;
   card1=card2;
   card2=temp;
   
}

void printdeck(const std::array<Card,52>&deck)
{
   for(const auto &card : deck)
   {
      printcard(card);
      std::cout<<" ";
   }
  std::cout<<"\n";
   
}


int main()
{
  
  std::array<Card,52>deck;
  Card c1={RANK_5,SUIT_HEART};
  Card c2={RANK_5,SUIT_DIAMOND};
  int card=0;
  for(int i=0;i<SUIT_MAX;i++) 
 {
     for(int j=0;j<RANK_MAX;j++)
     {
        deck[card].suit=static_cast<Cardsuit>(i);
        deck[card].rank=static_cast<Cardrank>(j);
        card++;
     }
  }
  /*int i;
  std::cout<<"Enter Card No: ";
  std::cin>>i;
  Card s=deck[i];
  printcard(s);
  //printdeck(deck);
  printcard(c1);
  printcard(c2);
  swapCard(c1,c2);
  printcard(c1);
  printcard(c2);
 */
  Card s2=deck[10];
  printcard(s2);
}

