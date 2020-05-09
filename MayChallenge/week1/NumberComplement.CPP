class Solution {
public:
    long int findComplement(int num) {
        if(num==0){
            return 1;
        }
        vector<long int> v;
        int P[32];
        int sum=1;
        P[0] = sum;
        for(int i=1;i<31;i++){
            sum=sum*2;
            P[i]=sum;
        }
        int m=num;
        while(m!=0){
            v.push_back(m%2);
            m=m/2;
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                ans+=P[i];
            }
        }
        return ans;
    }
};
/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010.
*/