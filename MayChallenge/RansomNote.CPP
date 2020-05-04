class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length()==0 && ransomNote.length()==0){
            return true;
        }
        unordered_map<char,int> mp;
        for(char x:magazine){
            mp[x]++;
        }
        int j=0;
        for(int i=0;i<ransomNote.length();i++){
            if(mp.find(ransomNote[i])!=mp.end()){
                if(mp[ransomNote[i]]-1>=0){
                    mp[ransomNote[i]]--;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};
/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/