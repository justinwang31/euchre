#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct playing_card
{
    string suit;
    char card;
    int value;
    size_t index;
};

class player
{
public:
    char hand[5][5] = {};
    string name;
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
};

constexpr size_t NumOfSuits = 4;
constexpr size_t NumOfCardsPerSuit = 6;
constexpr size_t NumOfCards = NumOfSuits * NumOfCardsPerSuit;

using standardDeck = playing_card[NumOfCards];

void init(standardDeck &fresh_deck)
{
    static const string suits[NumOfSuits] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    static constexpr char letters[NumOfCardsPerSuit + 1] = "9TJQKA";

    for (size_t index = 0; index < NumOfCards; ++index)
    {
        fresh_deck[index].index = index;
        fresh_deck[index].suit = suits[index / NumOfCardsPerSuit];
        fresh_deck[index].value = index % NumOfCardsPerSuit;
        fresh_deck[index].card = letters[fresh_deck[index].value];
    }
}
void give3(const playing_card &card)
{
}

void print(const playing_card &card)
{
    cout << card.card << " of " << card.suit << '\n';
}

void print(const standardDeck &deck)
{
    for (const auto &card : deck)
    {
        print(card);
    }
    cout << "-------------------------\n";
}

void shuffle(standardDeck &deck)
{
    random_shuffle(deck, deck + NumOfCards);
}

// void deal(standardDeck &deck)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {

//         }
//     }
// }

//need players with data for  5 cards at the start
//24 cards (done)
//deck -- with ability to shuffle (done)
//dealer is able to 3,2, or 1 card at a time. this applies to all players.
//after dealer gives all cards, the next card is face up

int main()
{
    std::srand(std::time(nullptr));

    //initialize players
    player p1, p2, p3, p4;
    p1.setName("person 1 ");
    p2.setName(" person 2 ");
    p3.setName(" person 3 ");
    p4.setName(" person 4 ");
    cout << p1.getName() << p2.getName() << p3.getName() << p4.getName();
    cout << endl;

    //initialize & shuffle the deck
    standardDeck theDeck;
    init(theDeck);
    print(theDeck);
    shuffle(theDeck);
    print(theDeck);
    //give cards to players
}