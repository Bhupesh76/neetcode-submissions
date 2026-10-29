class LRUCache {
public:
    struct Node
    {
        int key,value;
        Node* next;
        Node* prev;

       Node(int k,int v)
       {
           key = k;
           value = v;
           next = NULL;
           prev = NULL;
       }
    };

    int capacity;

    unordered_map<int,Node*> mpp;

    Node* head;
    Node* tail;

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void InsertAfterHead(Node* node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void MoveToHead(Node* node)
    {
        removeNode(node);
        InsertAfterHead(node);
    }

    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];

        MoveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) 
    {
        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            node->value = value;
            MoveToHead(node);
            return;
        }

        if(mpp.size() == capacity)
        {
            Node* lru = tail->prev;
            removeNode(lru);
            mpp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key,value);
        InsertAfterHead(node);
        mpp[key] = node;
    }
};
