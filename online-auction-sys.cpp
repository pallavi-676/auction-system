#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string itemName;
    double basePrice;
    double highestBid;
    string highestBidder = "No bids yet";
    int choice;

    cout << "===== ONLINE AUCTION SYSTEM =====" << endl;

    cout << "Enter Item Name: ";
    getline(cin, itemName);

    cout << "Enter Base Price: ";
    cin >> basePrice;

    highestBid = basePrice;

    do
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Place Bid" << endl;
        cout << "2. View Highest Bid" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string bidderName;
                double bidAmount;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nEnter Bidder Name: ";
                getline(cin, bidderName);

                cout << "Enter Bid Amount: ";
                cin >> bidAmount;

                if (bidAmount > highestBid)
                {
                    highestBid = bidAmount;
                    highestBidder = bidderName;
                    cout << "Bid placed successfully!" << endl;
                }
                else
                {
                    cout << "Bid must be higher than current highest bid ("
                         << highestBid << ")." << endl;
                }
                break;
            }

            case 2:
                cout << "\nCurrent Highest Bid: " << highestBid << endl;
                cout << "Highest Bidder: " << highestBidder << endl;
                break;

            case 3:
                cout << "\nAuction Winner Declared!" << endl;
                cout << "Winning Bidder: " << highestBidder << endl;
                cout << "Winning Bid: " << highestBid << endl;
                cout << "Thank you for using the Auction System." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}