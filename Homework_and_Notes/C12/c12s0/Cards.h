#include <string>
#include <vector>
struct Card
{
    int suit, rank;

    Card();
    Card(int s, int r);
    std::string to_string();
    bool operator==(const Card& c2) const;
    bool operator>(const Card& c2) const;
    bool operator>=(const Card& c2) const;
    bool operator!=(const Card& c2) const;
};

std::vector<Card> build_deck();