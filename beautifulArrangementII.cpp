class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);
        int cnt1=k+1;
        int cnt2=1;
        k+=1;
        for(int i=1;i<=n;i++){
            if(k>0){
                if(i%2!=0){
                result[i-1]=cnt2;
                cnt2++;
                }else{
                    result[i-1]=cnt1;
                    cnt1--;
                }
                k--;
            }else{
                result[i-1]=i;
            }
        }
        return result;
        
    }
};