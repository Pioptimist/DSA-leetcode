class LRUCache {
  public:
    class node {  // using a doubly LL
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);   // dummy head and tail nodes
  node * tail = new node(-1, -1);

  int cap; // capacit of the cache
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) { //if the key is there
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode); // delete this node and add it to the very front
      addnode(resnode); // whenevr we are told to get this key , it is recently used so put it ahead ie next to the head pointer
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {

    if (m.find(key_) != m.end()) { // if its alr in the cache , update the key and bring it to the top since it's recently used
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }

    if (m.size() == cap) {  // if cap is full , then erase the LRU 
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};
