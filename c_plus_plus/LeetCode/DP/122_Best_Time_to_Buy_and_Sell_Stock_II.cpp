class Solution {
public:
    int cal_maxProfit(vector<int>& prices, int s) {
        
        int max_profit = 0;
        for (int idx = s; idx + 1 < prices.size(); idx++) {
            int local_profit = 0;
            for (int i = idx + 1; i < prices.size(); i++) {
                if (prices[i] - prices[idx] > 0) {
                    int profit = (prices[i] - prices[idx]) + cal_maxProfit(prices, i + 1);
                    local_profit = max(local_profit, profit);
                }
            }
            max_profit = max(max_profit, local_profit);
        }
        return max_profit;
    }

    int maxProfit(vector<int>& prices) {
        #if 0
        //Brute force recursively
        return cal_maxProfit(prices, 0);
        
        #endif
        #if 1
        //only consider up trend/crawling over the slope.
        int diff = 0;
        for (int i = 1; i < prices.size(); i++) {
            diff += (prices[i] > prices[i - 1]) ? prices[i] - prices[i - 1] : 0;
        }
        return diff;
        #endif
    }
};

