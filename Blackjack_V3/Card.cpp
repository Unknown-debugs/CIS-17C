
#include "Card.h"

string Card:: ranks[13] = {"ACE", "TWO", "THREE", "FOUR","FIVE", "SIX", "SEVEN", 
                                      "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
string Card:: suits[4] = {"SPADES", "HEARTS", "DIAMONDS", "CLUBS"};


Card::Card(int rank, int suit){
    this->rank = rank;
    this->suit = suit;
}

ostream& operator<<(ostream &out, const Card &c) {
  return out << Card::ranks[c.rank] << " of " << Card::suits[c.suit] << "\n";
}

void Card::prntCard() const{
    std::cout<< ranks[rank] + " of " + suits[suit]<<std::endl;
}
