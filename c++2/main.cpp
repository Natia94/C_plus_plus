#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

#include "llist.h"
#include "dllist.h"
#include "timing.h"

template <class Iter>
void selectionSort(Iter start, Iter end){
  Iter it1, it2, smallestItr;
    for(Iter it1 = start; it1 != end; ++it1){
        smallestItr=it1;
        it2= it1;
	it2++;
        for(; it2!=end; ++it2){
            if (*it2 < *smallestItr)
                smallestItr = it2;
        }
        
        if (smallestItr!= it1){
            std::swap(*it1, *smallestItr);
        }
    }
}


template <class Container, class T>
void insertNextToMatch(Container& k, const T& value)
{
    if(k.empty()){
        k.push_back(value);
    }
    else{
        typename Container:: iterator it;
        for (it = k.begin(); it!= k.end(); ++it){
            if((*it)==value){
                k.insert(++it,value);
                return;
            }
        }
    }
    
    k.push_back(value);
    
}


struct time {
    uint64 start;
    std::string name;
    time(const std::string& str="") : start(GetTimeMs64()), name(str) {}
    void getTimeElapsed() {
        std::cout << name << "... " << GetTimeMs64() - start << std::endl;
    }
    void startAgain(const std::string& str="") {
        start = GetTimeMs64();
        name = str;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./a.out <FILENAME>\n";
        return 0;
    }
    
    std::ifstream fin;
    
    fin.open(argv[1]);
    
    std::vector<int> v1, v2;
    int x;
    while (fin) {
        fin >> x;
        v1.push_back(x);
        if (v1.size() % 5 > 2) v2.push_back(x);
    }
    
    struct time t("filling list");
    List<int> lst;
    for (int i = 0; i < v1.size(); i++) {	lst.push_front(v1[i]); }
    t.getTimeElapsed();
    
    t.startAgain("filling dlist");
    DList<int> dlst;
    for (int i = 0; i < v1.size(); i++) {	dlst.push_front(v1[i]); }
    t.getTimeElapsed();
    
    t.startAgain("filling vector");
    std::vector<int> v;
    for (int i = 0; i < v1.size(); i++) { v.push_back(v1[i]); }
    t.getTimeElapsed();
    
    t.startAgain("sorting list");
    selectionSort(lst.begin(), lst.end());
    t.getTimeElapsed();
    
    t.startAgain("sorting dlist");
    selectionSort(dlst.begin(), dlst.end());
    t.getTimeElapsed();
    
    t.startAgain("sorting vector");
    selectionSort(v.begin(), v.end());
    t.getTimeElapsed();
    
    t.startAgain("adding more to list");
    for(int i = 0; i < v2.size(); i++) { insertNextToMatch(lst, v2[i]); }
    t.getTimeElapsed();
    
    t.startAgain("adding more to dlist");
    for(int i = 0; i < v2.size(); i++) { insertNextToMatch(dlst, v2[i]); }
    t.getTimeElapsed();
    
    t.startAgain("adding more to vector");
    for(int i = 0; i < v2.size(); i++) { insertNextToMatch(v, v2[i]); }
    t.getTimeElapsed();
}

