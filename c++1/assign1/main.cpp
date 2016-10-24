#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "vector.h"


int main() {
    
    // generate random array
    srand (time(NULL));
				const int ARRSIZE = rand() % 100;
    int arr[ARRSIZE];
    for (int i = 0; i < ARRSIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    Vector<int> v1;
    //    assert(v1.empty());
				assert(v1.capacity() > v1.size());
    for (int i = 0; i < ARRSIZE; i++) {
        v1.push_back(arr[i]);
        assert(v1.size()==i+1);
        assert(v1.back()==arr[i]);
        assert(v1.front()==arr[0]);
        assert(!v1.empty());
        assert(v1.at(i)==arr[i]);
    }
    
    Vector<int> v2 = v1;
    assert(v2.size()==v1.size());
    for(int i = 0; i < ARRSIZE; i++) {
        assert(v2[i]==v1[i]);
    }
    
    int smallSize = ARRSIZE - rand() % (ARRSIZE/2)+2;
    while (v2.size() > smallSize) {
        int s = v2.size();
        v2.pop_back();
        assert (v2.size()==s-1);
        assert (v2.back()==arr[v2.size()-1]);
    }
    
				// check insertion
    int pos = rand() % v1.size();
    int elt1 = rand() % 100;
    int s = v1.size();
    v1.insert(elt1, pos);
    assert(v1.size()==s+1);
    for (int i = 0; i < pos; i++) {
        assert(v1[i]==arr[i]);
    }
    assert(v1[pos]==elt1);
    for (int i = pos+1; i < v1.size(); i++) {
        assert(v1[i]==arr[i-1]);
    }
    
				// check erase
				s = v1.size();
				v1.erase(pos);
				assert(v1.size()==s-1);
				for (int i = 0; i < v1.size(); i++) {
                    assert(v1[i]==arr[i]);
                }
    
				// check that boundaries are checked
				bool atleft=false, atright=false, insertleft=false, insertright=false, eraseleft=false, eraseright=false;
				try { v1.insert(elt1, -1); } catch (std::exception e) { insertleft = true; }
				try { v1.insert(elt1, v1.size()+1); } catch (std::exception e) { insertright = true; }
				try { v1.erase(-1); } catch (std::exception e) { eraseleft = true; }
				try { v1.erase(v1.size()); } catch (std::exception e) { eraseright = true; }
				try { v1.at(-1); } catch (std::exception e) { atleft = true; }
				try { v1.at(v1.size()); } catch (std::exception e) { atright = true; }
				assert(atleft);
				assert(atright);
				assert(insertleft);
				assert(insertright);
				assert(eraseleft);
				assert(eraseright);
}
