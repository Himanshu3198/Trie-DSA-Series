struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    
      TrieNode(){
        
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
     TrieNode *root;
  
    Trie() {
       
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string words) {
        
        
        int n=words.length();
        
        TrieNode *curr=root;
        
        for(int i=0;i<n;i++){
            
            int index=words[i]-'a';
            
            if(curr->child[index]==NULL){
                
                TrieNode *newNode =new TrieNode();
                
                curr->child[index]=newNode;
            }
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string words) {
         int n=words.length(); 
        TrieNode *curr=root;
        
        for(int i=0;i<n;i++){
            
            int index=words[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr=curr->child[index];
            
        }
        
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string words) {
           int n=words.length(); 
        TrieNode *curr=root;
        
        for(int i=0;i<n;i++){
            
            int index=words[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr=curr->child[index];
            
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
