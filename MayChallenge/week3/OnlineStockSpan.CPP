class StockSpanner {
public:
    #define pb push_back
    vector<int> v;
    vector<int> dp;
    int t;
    StockSpanner() {
        t=-1;
    }
    
    int next(int price) {
        if(t==-1 || v[t] > price){
            t++;
            v.pb(price);
            dp.pb(1);
            return 1;
        }
        int temp=t;
        int x=1;
        while(temp>=0){
            // cout<<temp<<" "<<x<<" ";
            if(v[temp]<=price){
                x+=dp[temp];
                temp=temp-dp[temp];
            }else{
                break;
            }
        }
        t++;
        v.pb(price);
        dp.pb(x);
        // cout<<endl;
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/