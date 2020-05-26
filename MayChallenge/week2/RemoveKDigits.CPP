class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.length();
        if(n<=k){
            return "0";
        }
        int i=0;
        string ans="";
        while(k--){
            n= num.length();
            if(i>0){
                i=i-1;
            }
            for(i=i;i<n-1;i++){
                if(int(num[i])>int(num[i+1])){
                    break;
                }
                if(num[i]==num[i+1]){
                    int j=i+1;
                    while(j+1<n && num[j+1]==num[j]){
                        j++;
                    }
                    // cout<<num[j]<<" "<<num[j+1]<<endl;
                    if(j==n-1){
                        break;
                    }
                    if(int(num[j+1])<int(num[j])){
                        break;
                    }

                }
            }
            if(i==n-1 && num[i]=='0'){
                while(num[i]=='0'){
                    i--;
                }
            }
            num.erase(num.begin()+i);
            // for(char x:num){
            //     cout<<x;
            // }
            // cout<<"\n";
        }
        
        n=0;
        for (int i=0;i<num.length();i++){
            if(num[i]=='0'){
                n++;
            }
            else{
                break;
            }
        }
        num = num.substr(n);
        if (num==""){
            return "0";
        }
        return num;
        
    }
};


/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/