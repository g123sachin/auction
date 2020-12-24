#include <list>
#include <string>
#include <memory>
#include "bidder.hpp"
#include <cassert>
using namespace std;

// auto-bidder auction system
namespace bidSystem
{

class Auction
{
public:
    Auction(string itemName);
    void addBidder(shared_ptr<Bidder> bidder);
    string getItemName() const;
    struct Result
    {
        shared_ptr<Bidder> winner;
        int bid;
    };
    Result getResult() const;
private:
    struct pvtData;
    shared_ptr<pvtData> priv;
};

}
