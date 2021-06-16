class Solution {
public:
    vector<string> result;
    void bt(int n,int openBrackets,int closedBrackets,string curr){
        if(curr.length()==2*n){
            result.push_back(curr);
            return;
        }
        if(openBrackets<n){
            bt(n,openBrackets+1,closedBrackets,curr+"(");
        }
        if(openBrackets>closedBrackets){
            bt(n,openBrackets,closedBrackets+1,curr+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        bt(n,0,0,"");
        return result;
    }
};