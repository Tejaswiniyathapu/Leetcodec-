class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> count(maxCost + 1, 0);

        for(int cost : costs) {
            count[cost]++;
        }

        int bars = 0;

        for(int price = 1; price <= maxCost; price++) {

            while(count[price] > 0 && coins >= price) {

                coins -= price;
                bars++;
                count[price]--;
            }
        }

        return bars;
    }
};