#include <iostream>
#include "auction.hpp"

int main(int argc, char *argv[])
{
    bidSystem::Auction bike("Bike");
    bike.addBidder(std::make_shared<bidSystem::Bidder>("Bob", 10, 20, 1));
    bike.addBidder(std::make_shared<bidSystem::Bidder>("Jon", 5, 15, 1));
    auto result = bike.getResult();
    assert(result.winner->getName() == "Bob");
    assert(result.bid == 16);

    bidSystem::Auction apple("Apple");
    assert(!apple.getResult().winner);
    assert(apple.getItemName() == "Apple");
    // Check zero-bidding guy
    auto john = std::make_shared<bidSystem::Bidder>("John", 0, 0, 0);
    apple.addBidder(john);
    assert(!apple.getResult().winner);
    // Check first result
    auto jane = std::make_shared<bidSystem::Bidder>("Jane", 10, 20, 3);
    apple.addBidder(jane);
    result = apple.getResult();
    assert(result.winner);
    assert(result.winner->getName() == "Jane");
    assert(result.winner == jane);
    // Check obvious looser
    auto joe = std::make_shared<bidSystem::Bidder>("Joe", 9, 15, 2);
    apple.addBidder(joe);
    assert(apple.getResult().winner);
    assert(apple.getResult().winner->getName() == "Jane");
    assert(apple.getResult().winner == jane);
    // Check new winner
    auto bob = std::make_shared<bidSystem::Bidder>("Bob", 20, 30, 3);
    apple.addBidder(bob);
    assert(apple.getResult().winner);
    assert(apple.getResult().winner->getName() == "Bob");
    assert(apple.getResult().winner == bob);
    // Ensure first bidder wins in case of equal subsequent bids
    auto jack = std::make_shared<bidSystem::Bidder>("Jack", 20, 30, 3);
    apple.addBidder(jack);
    assert(apple.getResult().winner);
    assert(apple.getResult().winner->getName() == "Bob");
    assert(apple.getResult().winner == bob);
    // Ensure auctions do not interact with each other and bidders can be reused
    bidSystem::Auction pear("Pear");
    assert(!pear.getResult().winner);
    assert(apple.getResult().winner);
    pear.addBidder(jack);
    assert(pear.getResult().winner);
    assert(pear.getResult().winner->getName() == "Jack");
    assert(pear.getResult().winner == jack);
    assert(apple.getResult().winner);
    assert(apple.getResult().winner->getName() == "Bob");
    assert(apple.getResult().winner == bob);
    // Ensure wrong numbers cause no crashes
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B1", 10, 50, -2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B2", 10, -50, 2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B3", 10, -50, -2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B4", -10, 50, 2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B5", -10, 50, -2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B6", -10, -50, 2));
    assert(pear.getResult().winner);
    pear.addBidder(std::make_shared<bidSystem::Bidder>("B7", -10, -50, -2));
    assert(pear.getResult().winner);
    std::cout << "All tests passed" << std::endl;
    return 0;
}
