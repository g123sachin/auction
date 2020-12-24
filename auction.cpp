#include "auction.hpp"
#include <iostream>
using namespace std;
using namespace bidSystem;

struct Auction::pvtData
{
    string itemName;
    list<shared_ptr<Bidder>> bidders;
};

Auction::Auction(string name):
    priv(make_shared<pvtData>())
{
    priv->itemName = name;
}

void Auction::addBidder(shared_ptr<Bidder> bidder)
{
    priv->bidders.push_back(bidder);
}

string Auction::getItemName() const
{
    return priv->itemName;
}

Auction::Result Auction::getResult() const
{
    Auction::Result result;
    result.bid = 0;
    int priorityOfBestBid = 0;
    bool betterBidProposed;
    do
    {
        betterBidProposed = false;
        int candidatePriority = 0;
        for (auto candidate: priv->bidders)
        {
            if (candidate == result.winner)
                continue;
            if (candidate->canBeat(result.bid))
            {
                int proposedBid = candidate->getBetterBid(result.bid);
                // We need to ensure bidder proposes better (not same or equal) bid, just in case.
                if ((proposedBid > result.bid) || ((proposedBid == result.bid) && (candidatePriority < priorityOfBestBid)))
                {
                    result.winner = candidate;
                    result.bid = proposedBid;
                    priorityOfBestBid = candidatePriority;
                    betterBidProposed = true;
                }
            }
            candidatePriority++;
        }
    }
    while (betterBidProposed);
    return result;
}

