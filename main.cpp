#include <list>
#include <iostream>
#include "auction.hpp"
using namespace std;
using namespace bidSystem;

int main(int argc, char *argv[])
{
    cout << "Enter the number of auctions: ";
    int numAuctions;
    cin >> numAuctions;
    list<shared_ptr<Auction>> auctions;
    // Reading input
    for (int i = 0; i < numAuctions; i++)
    {
        cout << "Enter the item name for auction #" << (i + 1) << ": ";
        string itemName;
        cin >> itemName;
        shared_ptr<Auction> auction = make_shared<Auction>(itemName);
        cout << "Enter the number of bidders for " << itemName << ": ";
        int numBidders;
        cin >> numBidders;
        for (int j = 0; j < numBidders; j++)
        {
            cout << "Enter the name of bidder for bid #" << (j + 1) << ": ";
            string bidderName;
            cin >> bidderName;
            cout << "Enter the starting bid of " << bidderName << " for " << itemName << ": ";
            int startingBid;
            cin >> startingBid;
            while (startingBid <= 0)
            {
                cout << "Minimum bid should be greater than 0. Please re-enter minimum bid amount for bidder " << bidderName << ": ";
                cin >> startingBid;
            }
            cout << "Enter the maximum bid of " << bidderName << " for " << itemName << ": ";
            int maxBid;
            cin >> maxBid;
            while (maxBid <= startingBid)
            {
                cout << "Maximum bid must be more than starting bid. Please re-enter maximum bid amount for bidder " << bidderName << ": ";
                cin >> maxBid;
            }
            cout << "Enter the bid increment amount: ";
            int incrementAmount;
            cin >> incrementAmount;
            shared_ptr<Bidder> bidder = make_shared<Bidder>(bidderName, startingBid, maxBid, incrementAmount);
            auction->addBidder(bidder);
        }
        auctions.push_back(auction);
    }
    for (auto& auction: auctions)
    {
        auto result = auction->getResult();
        cout << "Auction for " << auction->getItemName();
        if (result.winner)
        {
            cout << " won by " << result.winner->getName() << " with bid of $" << result.bid << endl;
        }
        else
        {
            cout << " has no winner" << endl;
        }
    }
    return 0;
}

