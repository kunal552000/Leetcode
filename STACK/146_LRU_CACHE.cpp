/*

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

*/


//CODE


class LRUCache {
public:
    
    struct node
    {
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int keydash, int valdash)
        {
            key = keydash;
            val = valdash;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        
        newnode->next = temp;
        newnode->prev = head;
        
        temp->prev = newnode;
        head->next = newnode;
    }
    
    void deletenode(node* del)
    {
        node* delprev = del->prev;
        node* delnext = del->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) 
    {
        
        if(mp.find(key) != mp.end())
        {
            node* res = mp[key];
            int value = res->val;
            
            mp.erase(key);
            
            deletenode(res);
            addnode(res);
            
            mp[key] = head->next;
            
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        
        if(mp.find(key) != mp.end())
        {
            node* exist = mp[key];
            
            mp.erase(key);
            deletenode(exist);
            
            
        }
        
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */