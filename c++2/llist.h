#ifndef LLIST_H
#define LLIST_H

#include <iterator>
template <class T>
class List
{
    struct Node
    {
        Node(const T& x,Node* y = 0):m_data(x),m_next(y){}
        T m_data;
        Node* m_next;
    };
    
    Node* m_head;
public:
    
    class iterator
    {
        Node* m_rep;
    public:
        friend class List;
        
        inline iterator(Node* x=0):m_rep(x){}
        inline iterator(const iterator& x):m_rep(x.m_rep) {}
        inline iterator& operator=(const iterator& x)
        {
            m_rep=x.m_rep; return *this;
        }
        inline iterator& operator++()
        {
            m_rep = m_rep->m_next; return *this;
        }
        inline iterator operator++(int)
        {
            iterator tmp(*this); m_rep = m_rep->m_next; return tmp;
        }
        inline T& operator*() const { return m_rep->m_data; }
        inline Node* operator->() const { return m_rep; }
        inline bool operator==(const iterator& x) const
        {
            return m_rep == x.m_rep;
        }
        inline bool operator!=(const iterator& x) const
        {
            return m_rep != x.m_rep;
        }
        
    };
    
    
    List() : m_head(0) {}
    ~List() { clear(); }
    void clear() { while (!empty()) pop_front(); }
    
    inline void push_front(const T&x)
    {
        Node* tmp = new Node(x);
        tmp->m_next = m_head;
        m_head = tmp;
    }
    inline void pop_front()
    {
        if (m_head)
        {
            Node* newhead = m_head->m_next;
            delete m_head;
            m_head = newhead;
        }
    }
    inline bool empty() { return m_head; }
    
    inline T& front() { return *begin(); }
    inline const T& front() const { return *begin(); }
    
    inline iterator begin() { return iterator(m_head); }
    inline iterator end() { return iterator(); }
    
    // insert y before x. Intended to parallel vector operation
    void insert (iterator& x, const T& y) {
        Node *tmp = new Node(y, x.m_rep);		// new node's next will be x's node
        if (x.m_rep==m_head) m_head = tmp;
        else {
            Node *p = m_head;
            while (p && p->m_next != x.m_rep) p = p->m_next;
            if (!p) throw std::exception();
            p->m_next = tmp;
        }
    }
    
    // push back. Intended to parallel vector operation
    void push_back (const T& y) {
        Node *nd = new Node(y, NULL);
        if (!m_head) m_head = nd;
        else {
            Node *p = m_head;
            while (p->m_next) p = p->m_next;
            p->m_next = nd;
        }
    }
    
};

#endif