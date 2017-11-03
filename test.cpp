#include <sstream>
#include <iostream>
#include <vector>
#include <string>


int main()
{
    std::vector<std::string> vect ;
     std::stringstream ss;
ss << "1" <<"1";
std::string s = ss.str();
    vect.emplace_back(s);
   
    for(std::vector<std::string>::iterator it=vect.begin();it!=vect.end();++it)
        if(*it==s)
	    {
		std::cout<<*it;
            std::cerr<<"Error:it is a cycle";}
}
