#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int MAX_ITEMS = 1e5;
const int BEGIN_COINS = 100;

int main()
{
    int n;
    cin >> n;
    vector<int> prices = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    
    vector<int> holdCoins = vector<int>(n);
    vector<int> soldCoins = vector<int>(n);

    vector<int> soldItems = vector<int>(n);

    holdCoins[0]=BEGIN_COINS;
    soldItems[0]=min(BEGIN_COINS/prices[0],MAX_ITEMS);
    soldCoins[0]=BEGIN_COINS-soldItems[0]*prices[0];

    for(int i=1;i<prices.size();i++){
        holdCoins[i]=max(holdCoins[i-1],soldItems[i-1]*prices[i]);
        soldItems[i]=min(holdCoins[i]/prices[i],MAX_ITEMS);
        soldCoins[i]=max(soldCoins[i-1],holdCoins[i]-soldItems[i]*prices[i]);
    }
    cout<<max(holdCoins.back(),soldCoins.back())<<endl;
}