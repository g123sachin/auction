#include <string>
#include <memory>
using namespace std;

// auto-bidder auction system
namespace bidSystem
{

class Bidder
{
public:
    Bidder(string name, int startingBid, int maxBid, int incrementAmount);
    string getName() const;
    bool canBeat(int currentBid) const;
    int getBetterBid(int currentBid) const;
private:
    struct pvtData;
    shared_ptr<pvtData> priv;
};

}
