class WordDictionary {
public:
    struct Node
    {
        Node* links[26];
        bool flag;
        Node()
        {
            for(int i=0; i<26; i++)
            {
                links[i] = NULL;
            }
            flag = false;
        }
    };
    Node* root;
    WordDictionary() 
    {
        root = new Node();
    }
    
    void addWord(string word) 
    {
        Node* node = root;
        for(char ch : word)
        {
            int index = ch - 'a';
            if(node->links[index] == NULL)
            {
                node->links[index] = new Node;
            }
            node = node->links[index];
        }
        node->flag = true;
    }
    bool dfs(int index,string &word,Node* node)
    {
        if(index == word.size())
        {
            return node->flag;
        }
        char ch = word[index];
        if(word[index] == '.')
        {
            for(int i=0; i<26; i++)
            {
                if(node->links[i] != NULL)
                {
                    if(dfs(index+1,word,node->links[i]))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        int pos = ch - 'a';
        if(node->links[pos] == NULL)
        {
            return false;
        }

        return dfs(index+1,word,node->links[pos]);
    }
    bool search(string word) 
    {
        return dfs(0,word,root);
    }
};
