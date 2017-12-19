#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string sentence,word,rem;
std::getline(std::cin, sentence);

int l=0,r=sentence.find(' ');
while(true){
        if(r==string::npos)
            break;
       word = sentence.substr(l,r-l);
       rem=sentence.substr(r+1);
       if(rem.find(word)!=string::npos){
            rem=rem.erase(rem.find(word),word.length());
            sentence = sentence.substr(0,l)+word+rem;
            r=0;

       }
       l=sentence.find(' ',r)+1;
       r=sentence.find(' ',l);
}
std::cout << sentence << "\n";
    return 0;
}