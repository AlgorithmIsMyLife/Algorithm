dclass LRUCache
{
public:
    struct Node
    {
        int val;
        int key;
        Node *next;
        Node *pre;

        Node(int k, int value)
        {
            key = k;
            val = value;
            next = nullptr;
            pre = nullptr;
        }
    };

    LRUCache(int capacity)
        : cap{capacity}
    {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->pre = left;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Remove(m[key]);
            Insert(m[key]);
            return m[key]->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        { // update the value
            Node *update = m[key];
            Remove(update);
            Insert(update);
            update->val = value;
        }
        else
        { // Insert new node
            if (m.size() >= cap)
            { // remove LRU
                Node *LRU = left->next;
                Remove(LRU);
                m.erase(LRU->key);
                delete LRU;

                m[key] = new Node(key, value);
                Insert(m[key]);
            }
            else
            {
                Node *n = new Node(key, value);
                m[key] = n;
                Insert(n);
            }
        }
    }

private:
    int cap;
    unordered_map<int, Node *> m;
    Node *left;
    Node *right;

    void Remove(Node * node)
    {
        Node *pre = node->pre;
        Node *next = node->next;

        pre->next = next;
        next->pre = pre;
    }

    void Insert(Node * node)
    {
        Node *pre = right->pre;
        node->next = right;
        right->pre = node;
        pre->next = node;
        node->pre = pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
