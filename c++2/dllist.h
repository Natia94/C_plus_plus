#ifndef DLLIST_H
#define DLLIST_H

#include <iterator>

template <class T>
class DList
{
    struct Node
    {
        Node(const T& x,Node* y = 0, Node* z =0):m_data(x),m_next(y),m_prev(z){}
        T m_data;
        Node* m_next;
        Node* m_prev;
    };
    
    Node* m_head;
    Node* m_tail;
    
public:
    
    class iterator
    {
        Node* m_rep;
        
    public:
        friend class DList;
        
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
        
        inline iterator& operator--(){
            m_rep = m_rep->prev;
            return *this;
        }
        
        inline iterator operator --(int){
            iterator tmp(*this);
            m_rep=m_rep->prev;
            return tmp;
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
    
    
    DList() : m_head(0), m_tail(0) {}
    ~DList() { clear(); }
    void clear() { while (!empty()) pop_front(); }
    
    
    
    
    inline void push_front(const T&x)
    {
        Node* tmp = new Node(x);
        if(m_head==NULL && m_tail==NULL){
            m_head=tmp;
            m_tail=tmp;
            tmp->m_next=NULL;
        }
        else{
            tmp->m_next = m_head;
            tmp->m_next->m_prev=tmp;
            m_head = tmp;
        }
    }
    
    inline void push_back(const T& y)
    {
        Node* nd = new Node(y,NULL);
        if(!m_head)
        {
            m_head=nd;
            m_tail=nd;
        }
        else{
            nd->m_prev = m_tail;
            nd->m_prev->m_next = nd;
            m_tail = nd;
        }
    }
    
    
    inline void pop_front()
    {
        if (!m_head) throw std::exception();
        else{
            Node* newhead = m_head->m_next;
            delete m_head;
            m_head = newhead;
        }
    }
    
    
    inline void pop_back()
    {
        if(!m_head) throw std::exception();
        else{
            Node* p = m_tail->m_prev;
            delete m_tail;
            m_tail = p;
        }
    }
    
   
    
    inline bool empty() { return m_head; }
    
    inline T& front() { return *begin(); }
    inline const T& front() const { return *begin(); }
    
    inline T& back(){return *m_tail;}
    inline const T& back() const{ return *m_tail;}
    
    inline iterator begin() { return iterator(m_head); }
    inline iterator end() { return iterator(); }
    
    
    
    // insert y before x. Intended to parallel vector operation
    void insert (iterator& x, const T& y) {
        
        Node *temp = new Node(y, x.m_rep);
        
        if (x==m_head){
            temp->m_next->m_prev=temp;
            m_head = temp;
        }
        else {
            if (!m_head) throw std::exception();
            temp->m_prev=x->m_prev;
            temp->m_prev->m_next=temp;
            temp->m_next->m_prev=temp;
        }
        
    }
    
    
};

#endif