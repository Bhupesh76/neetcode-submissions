class PrefixTree {
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

    PrefixTree() 
    {
        root = new Node;
    }
    
    void insert(string word) 
    {
        Node* node = root;
        for(char ch : word)
        {
            int index = ch - 'a';
            if(node->links[index] == NULL)
            {
                node->links[index] = new Node();
            }
            node = node->links[index];
        }
        node->flag = true;
    }
    
    bool search(string word) 
    {
        Node* node = root;
        for(char ch : word)
        {
            int index = ch - 'a';
            if(node->links[index] == NULL)
            {
                return false;
            }
            node = node->links[index];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) 
    {
        Node* node = root;
        for(char ch : prefix)
        {
            int index = ch - 'a';
            if(node->links[index] == NULL)
            {
                return false;
            }
            node = node->links[index];
        }
        return true;
    }
};
