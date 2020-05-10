class Solution {
public:
    bool isPerfectSquare(int num) {
        long int L=0,R=num;
        while(L<=R){
            // cout<<L<<" "<<R<<"\n";
            long int mid = L +(R-L)/2;
            if(mid*mid==num){
                return true;
            }
            if(mid*mid > num){
                R=mid-1;
            }else{
                L=mid+1;
            }
        }  
        return false;
    }
};
/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/