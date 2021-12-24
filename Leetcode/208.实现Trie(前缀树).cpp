class TrieNode{
    public:
        TrieNode* next[26];
        bool isval;
        TrieNode(){
            for (int i = 0; i < 26; i ++ ){
                next[i] = nullptr;
            }
            isval = false;
        }
};

class Trie {
public:
    TrieNode* root;

    Trie():root(new TrieNode) {}
    
    void insert(string word) {
        TrieNode* p = root;
        for (const char& i: word){
            if (p -> next[i - 'a'] == nullptr){
                p -> next[i - 'a'] = new TrieNode();//罪魁祸首是他，没有加上()........
            }
            p = p -> next[i - 'a'];
        }
        p -> isval = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for (const char& i: word){
            if (p -> next[i - 'a']){
                p = p -> next[i - 'a'];
            }else{
                return false;//忘记加上false了....
            }
        }

        return p -> isval;
    }
    
    bool startsWith(string prefix) {//全部相同也叫做前缀吗...
        TrieNode* p = root;
        for (const char& i: prefix){
            if (p -> next[i - 'a']){
                p = p -> next[i - 'a'];
            }else{
                return false;
            }
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