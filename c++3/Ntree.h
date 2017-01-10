#ifndef NTREE_H_INCLUDED
#define NTREE_H_INCLUDED
#define ENDCHILD "\n"

#include <vector>
#include <fstream>
#include <queue>

// Natela Khomasuridze

template <class T>
struct tnode
{
    T data;
    std::vector<tnode<T>*> child;
    tnode(): data(" "),child(std::vector<tnode<T>*>()){}    //constructor default, empty
    tnode(const T& value):data(value),child(std::vector<tnode<T>*>()){}
    tnode<T>* addChild(const T& value){
        tnode<T>* newn=new tnode<T>(value);                 // newn - new node, allocates with the (value)
        child.push_back(newn);                             //adds newnode
        return newn;
    }
};

template<class T>
class Ntree
{
    tnode<T>* root;
    public:
    Ntree(): root(NULL){} //constructor that sets root to 0
    Ntree(const T& value){
        tnode<T>* newn=new tnode<T>(value);
        root=newn;     //assignes new node to the root
    } 
    
    tnode<T>* getRoot(){return root;}   //getter cause root is private
    
    void printToFile(tnode<T>* n, std::ostream& out){
        if(!n)
        return;
        else{
            out<<n->data<<" ";                    // prints out values “data”
            for(int i=0; i<n->child.size(); i++) //loop over children vectors, n->child.size()- size of the node vectors
            printToFile(n->child[i],out);       //recursion—prints out each node vector     
            out<<ENDCHILD;
           }
    }
    
    void printFromFile(tnode<T>* n, std::istream& in){
        T val;
        if(!(in>>val) || val==ENDCHILD) 
        return;
        printFromFile (n->addChild(val),in);  //recursion
     }
    

    void serialize(const T& b){             //has one  object as It was mentioned in main.cpp
        std::ofstream outfile (b.c_str()); //outputs file, string.c_str() to convert
        if(outfile){                      //checks if file exists 
            tnode<T>* temp=root;         //declare new variable(pointer) temp that takes root, I think Its like an array, whenI point to the first element I point to entire tree
            printToFile(temp, outfile); //call printToFile function
        }
        outfile.close();              //close file
    }
    
    void deserialize(const T& b){
        std::ifstream infile (b.c_str());         // opens/implements input file
        if(infile){                              //cheks if file is open/exists
            T val;
            infile>>val;                       //cin>>val
            root=new tnode<T>(val);            //allocates root with val, root has value “val”
            tnode<T>* temp = root;         //pointer temp, points to the root (entire tree)
            printFromFile(temp,infile);   //calls function print from file which prints element from the file
        }
            infile.close();                  // closes file
    }
    
    friend std::ostream& operator<<(std::ostream& out, const T& x){     // overload <<, friend function
        out<<x;
        return out;
    }
    

    
    bool operator==(const Ntree<T>& k)const {   // == operator that takes one argument  and have three options
        if(!root && !k.root)      //and returns true if food tree and food tree have no roots, if they do not exist/empty
        return true;

        else if (root->data==k.root->data) //returns true two trees are == equal , I mean foodtree and foodtree2, intree and intree2
        return true;

        return false;                    //otherwise returns false, if does not equal
    }
    
    tnode<T>* searchStart(T val){       // says to the program to start searching where to add a new child on the tree
      return search(root, val);   
    }

  tnode<T>*  search(tnode<T>* n, T val){  // search function which finds the exact sport to add a child of the tree
    if(n == NULL)     
    return NULL;
      else{
    if(n->data == val)        
      return n;
    tnode<T> * m;                      //declares a pointer m that will keep the node and pass(give) it to the add children function
    for( int i = 0;i < n->child.size(); i++){
      m = search(n->child[i], val);   //m keeps the result of m after it calls recursively search function
      if(m != NULL)                  //makes sure that m is not NULL
	return m;    
       }
  }
  return NULL;
  }

 void addChildren (T val, std::initializer_list<T> members){
   tnode<T>* m = searchStart(val);     //calls the search function 
   if(m != NULL){                     //makes sure that m is not NULL
     for(int i = 0; i< members.size(); i++){ //loops over the tree and adds the children 
       m.addChild(members[i]);               
     }
   }
   
 }
    
};
#endif // NTREE_H_INCLUDED
