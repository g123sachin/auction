#include "bidder.hpp"
using namespace std;
using namespace bidSystem;

struct Bidder::pvtData
{
    string name;
    int startingBid;
    int maxBid;
    int incrementAmount;
};

Bidder::Bidder(string name, int startingBid, int maxBid, int incrementAmount):
    priv(make_shared<pvtData>())
{
    priv->name = name;
    priv->startingBid = startingBid;
    priv->maxBid = maxBid;
    priv->incrementAmount = incrementAmount;
}

string Bidder::getName() const
{
    return priv->name;
}

bool Bidder::canBeat(int currentBid) const
{
    return priv->maxBid >= currentBid;
}

int Bidder::getBetterBid(int currentBid) const
{
    int bid = priv->startingBid;
    // We need to ensure this to avoid infinte loops
    if ((priv->incrementAmount > 0) && canBeat(currentBid))
    {
        while ((bid <= currentBid) && ((bid + priv->incrementAmount) <= priv->maxBid))
        {
            bid += priv->incrementAmount;
        }
    }
    return bid;
}
