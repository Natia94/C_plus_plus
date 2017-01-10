//Khomasuridze, Natela
#include <iostream>
#include <map>
#include <fstream>
#include <string>#include <algorithm>

std::string normalizeString(const std::string& ); //prototype

int main(int argc, char* argv[])
{
    std::map<std::string,int> m1; 
    std::map<std::string,int> m2;
    std::string w1,w2;
    double freq;

    const std::string str;

    for(int i=1;i<argc;i++){      //for loop which goes over the entire text file 
        normalizeString(str);    //call the normalizeString which ignores capital letters, and other grammar things.
        std::ifstream infile(argv[i]); //opens the file and takes the argument, argv is like an array.
        if(infile>>w1>>w2){     //while reads first and the second words from the file…
            m1[w1]++;           //takes the first word and puts it in a first map
            m1[w2]++;           //takes the second word and puts it in a first map
            m2[w1+' '+w2]++;   //takes the first and second word together and puts it in a second map
        }

       while(infile>>w1){    //while the program reads the first word
            m1[w1]++;        // first word goes to the map1
            m2[w2+' '+w1]++;  
            w2=w1;          //second word becomes the first one, 
 “second word takes the first words place”, like if I have “C++ is object oriented program” sentence I want program to read words like (c++ is) (is object) (object oriented)…
        }

        infile.close(); //closes text file
    }
    char x;
    while(x!='q'){ //when I enter q in stead of words to check the program quits. 
    std::cout<<"Please enter a pair of words"<<std::endl; 
    std::cin >> w1 >> w2;
    std::map<std::string,int>::iterator it1=m1.find(w1);  //declared 3 iterators, used find() with give us 1 is it finds the word we want or 0 otherwise. in the map we have a pair: (example: if word “king” is in the file 30 times I will have m1(“king”, 30), so iterator.second points to the int 30;
    std::map<std::string,int>::iterator it2=m1.find(w2);
    std::map<std::string,int>::iterator it3=m2.find(w1+' '+w2);
    if(it1 != m1.end() && it2!=m2.end()){
        freq=(double)it3->second/(it1->second+it2->second); //formula 
        std::cout<<freq<<std::endl;
    }

    else
    std::cout<<0<<std::endl; // if the word we cin is not in the text file the output on the screen will be 0;
    std::cout << "Enter any character to continue; enter 'q' to quit"<<std::endl;
    std::cin >> x; //cin the words I want to search in the text file. 

    }
    return 0;
}
std::string normalizeString(const std::string& str) {     std::string res = str;   std::cout << str << " ";   std::transform(res.begin(), res.end(), res.begin(), ::tolower);   res.erase(std::remove_if(res.begin(), res.end(), std::ptr_fun<int,int>(ispunct)), res.end());   std::cout << res << "\n";   return res;}