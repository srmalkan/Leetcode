class Trie {
public:
    /** Initialize your data structure here. */
    int ALPHABET_SIZE = 26; 
    struct TrieNode 
    { 
        struct TrieNode *children[26]; 
        bool isEndOfWord; 
    }; 
    
    struct TrieNode *root = getNode(); 
    
    TrieNode* getNode(){
        struct TrieNode *temp = new TrieNode();
        temp->isEndOfWord = false;
        
        for(int i=0;i<ALPHABET_SIZE;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        string key=word;
        struct TrieNode *pCrawl = root; 
  
        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode(); 

            pCrawl = pCrawl->children[index]; 
        } 

        // mark last node as leaf 
        pCrawl->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        string key=word;
        struct TrieNode *pCrawl = root; 
  
        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                return false; 

            pCrawl = pCrawl->children[index]; 
        } 

        return (pCrawl != NULL && pCrawl->isEndOfWord); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        string key = prefix;
        struct TrieNode *pCrawl = root; 
  
        for (int i = 0; i < key.length(); i++) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                return false; 

            pCrawl = pCrawl->children[index]; 
        } 

        return (pCrawl != NULL); 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */