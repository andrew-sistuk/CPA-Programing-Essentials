#include <string>
#include <iostream>

using namespace std;
int main()
{
std::string sentence;
std::getline(std::cin, sentence);
// manipulate the sentence here
//origin=sentence;
int p=sentence.find(' '), l=sentence.find(' ',p+1);
while(true){
    if(p==std::string::npos||l==std::string::npos){
        break;
    }
    if(l-p==1)
    {
        sentence=sentence.erase(p,1);
        p=sentence.find(' ');
        l=sentence.find(' ',p+1);
    }
    else{
        p=sentence.find(' ',p+1);
        l=sentence.find(' ',p+1);
    }
}
std::cout << sentence << "\n";
return 0;
}