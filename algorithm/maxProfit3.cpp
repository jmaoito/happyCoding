/*************
  LeetCode Best Time to Buy and Sell Stock III

  Say you have an array for which the ith element is the price of a 
  given stock on day i.

  Design an algorithm to find the maximum profit. You may complete at 
  most two transactions.

  Note:
  You may not engage in multiple transactions at the same time (ie, 
  you must sell the stock before you buy again).

  Discussion:
  Dynamic Programming.

  First consider the case that when we are only allowed to make one transaction. we can handle this easily with DP. If we move forward, any new price we meet will only affect our history result by two ways:

will it be so low that it beats our previous lowest price? will it be so high that we should instead sell on this time to gain a higher profit (than the history record)? Similarly, we can move backward with the highest price and profit in record. Either way would take O(n) time. Now consider the two transaction case. Since there will be no overlaps, we are actually dividing the whole time into two intervals.

We want to maximize the profit in each of them so the same method above will apply here. We are actually trying to break the day at each time instance, by adding the potential max profit before and after it together. By recording history and future for each time point, we can again do this within O(n) time.
  
************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const size_t n = prices.size();
        if (n < 2) return 0;
        
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);
        int low = prices[0];
        int high = prices[n-1];
        int maxPro = 0;
        
        for (int i=1; i<n; ++i) {
            low = min(low, prices[i]);
            forward[i] = max(forward[i-1], prices[i] - low);
        }
        
        for (int i=n-2; i>=0; --i) {
            high = max(high, prices[i]);
            backward[i] = max(backward[i+1], high - prices[i]);
        }
        
        for (int i=0; i<n; ++i)
            maxPro = max(maxPro, forward[i] + backward[i]);
            
        return maxPro;
    }
};
