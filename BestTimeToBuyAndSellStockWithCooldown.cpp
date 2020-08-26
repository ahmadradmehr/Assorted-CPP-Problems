/* Best Time to Buy and Sell Stock with Cooldown
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 * Example:
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */
 
class MaxProfit_Cooldown {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        else if (prices.size() == 2)
            return max(0, prices.at(1) - prices.at(0));
        int max_profit {0};
        vector<int> buy (prices.size(), 0), sell (prices.size(), 0);
        buy.at(0) = -prices.at(0);
        sell.at(0) = 0;
        buy.at(1) = -prices.at(1);
        sell.at(1) = max(0, buy.at(0) + prices.at(1));
        buy.at(2) = -prices.at(2);
        sell.at(2) = max(buy.at(1) + prices.at(2), sell.at(1) - prices.at(1) + prices.at(2));
        max_profit = max(sell.at(1), sell.at(2));
        for (int i {3}; i < prices.size(); i++) {
            buy.at(i) = max(sell.at(i-2) - prices.at(i), buy.at(i-1) + prices.at(i-1) - prices.at(i));
            sell.at(i) = max(buy.at(i-1) + prices.at(i), sell.at(i-1) - prices.at(i-1) + prices.at(i));
            if (max_profit < sell.at(i))
                max_profit = sell.at(i);
        }
        return max_profit;
    }
};