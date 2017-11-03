// adapted from https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <tuple>
#include <vector>
#include <list>
#include <sstream>
/// main() must be declared with arguments
/// otherwise command line arguments are ignored
 
    int sint_value=10;

    int nint_value=5;
 
    int lint_value=5;
 
    int cint_value=20;
    int loop_count=0;
static const char alp[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ "
"abcdefghijklmnopqrstuvwxyz";

int mistake_time=0;
char genRandom()  // Random string generator function.
{
	int stringLength = sizeof(alp) - 1;
    return alp[rand() % stringLength];
}
int get_opt(int argc, char **argv);
int random_n(int upper_limit,int);
int main (int argc, char **argv)
{
   
  
    
  	int a=get_opt(argc,argv);
  	
    int srandom=std::abs(random_n(sint_value,2));
    int lrandom=std::abs(random_n(lint_value,5));
    int tmp_s;
	//std::cout<<srandom;
	std::list<std::vector<std::string>> li;
  while(1){
    int string_length=std::abs(random_n(10,5));
	
  	int count_line_segment=std::abs(random_n(nint_value,2));
	
        
	int count_s=0;
	
	char s[srandom][string_length];
	
	tmp_s=srandom;
std::vector<std::string> two_tuple;
    while(tmp_s>0){
	std::vector<std::string> vect;
	
	    std::cout<<"a \"";
	    for(int z=0; z < string_length; z++)
    	{
	s[count_s][z]=genRandom();
        

    	}
	
	 for(int z=0; z < string_length; z++)
    	{
		std::cout<< s[count_s][z];
	}	  
	//std::cout<<"this is the "<<count_s;
	    std::cout<<"\"";
    	while( count_line_segment>0){
	    int x=random_n(cint_value,1);
	    int y=random_n(cint_value,1);
		std::stringstream ss;
		ss << x <<y;
		std::string foo = ss.str();
	    bool flag=true;
	    for (std::vector<std::string>::iterator it=vect.begin(); it!=vect.end(); ++it)
                {
			//std::cout<<*it<<"the before is it"<<std::endl;
			if(*it==foo)
			{//std::cout<<*it<<" "<<foo;
			flag=false;
			mistake_time++;
			std::cerr<<"RGen Warning:it is a cycle, fixed automatically\n";}
						
		}

		std::string two_e;
		if(vect.size()!=0)
			{
			std::stringstream ss_two;
			std::string v=vect.back();
			ss_two << x <<y<<v;
			two_e = ss_two.str();
			}

	    for (std::vector<std::string>::iterator it=two_tuple.begin(); it!=two_tuple.end(); ++it)
                {	
			/*
			if(!two_e.empty())
				std::cout<<*it<<"the two is it"<<two_e<<std::endl;
			*/
			if(*it==two_e)
			{//std::cout<<*it<<" "<<foo;
			flag=false;
			mistake_time++;
			std::cerr<<"RGen Warning:Same line segment, fixed automatically\n";}
			
						
		}


	    if(flag)
	    {
		std::cout<<" ("<<x<<","<<y<<")";
		//std::cout<<foo<<"in the flag"<<std::endl;
		//std::cout<<two_e<<"in the flag"<<std::endl;
		if(!foo.empty())
			vect.emplace_back(foo);
		if(!two_e.empty())
		two_tuple.emplace_back(two_e);
		count_line_segment--;
		}
		if(mistake_time>25)
			{
			std::cerr<<"Error: over 25 times mistaken\n";
			return 0;
			}
/*
	if(count_line_segment==0){
  		for (std::vector<std::string>::iterator it=two_tuple.begin(); it!=two_tuple.end(); ++it)
                {
			std::cout<<*it<<"the sum is it"<<std::endl;
			
			
						
		}
		}
*/
	}

	li.push_back(two_tuple);
	
	std::cout<<std::endl;
	
          
	count_line_segment=std::abs(random_n(nint_value,2));
	tmp_s--;
	count_s++;
	loop_count++;
    }
 //for(int i=0; i < srandom; i++){
//	   for(int z=0; z < string_length; z++)
  //  	{
//	std::cout<<s[i][z]<<"this is "<<i<<"this is"<<z<<std::endl;
        

  //  	}
//	}
    std::cout<<"g"<<std::endl;
	sleep(lrandom);
	int count_r=0;
	int tmp_r=srandom;
	
	while(tmp_r>0){
		 std::cout<<"r \"";
	 for(int z=0; z < string_length; z++)
    	{
		std::cout<< s[count_r][z];
	}	  
	  std::cout<<"\"";	
		//std::cout<<"this is the "<<count_r;
	    std::cout<<std::endl;
		count_r++;
		tmp_r--;
		}
	
}
    return 0;
}



int random_n(int upper_limit,int lower_limit){
	  std::ifstream urandom("/dev/urandom");
  if (urandom.fail()) {
        std::cerr << "Error: cannot open /dev/urandom\n";
        return 1;
    }
    char ch = 'a';
    // cast to integer to see the numeric value of the character
     urandom.read(&ch, 1);
	while(std::abs((int)ch%(upper_limit+1))<lower_limit){
	
    	  urandom.read(&ch, 1);
         // std::cout << "Random character: " << (int)ch << "\n";
	}
	return (int)ch%(upper_limit+1);
}




int get_opt(int argc, char **argv){
 std::string svalue;
    std::string nvalue;
   std::string lvalue;
   std::string cvalue;
int index;
	  int c;
	// expected options are '-a', '-b', and '-c value'
    while ((c = getopt (argc, argv, "s:n:l:c:")) != -1)
        switch (c)
        {
        case 's':
	  
	    svalue = optarg;
	   
            sint_value = atoi(svalue.c_str());
            break;
        case 'n':
            nvalue = optarg;
          
            nint_value = atoi(nvalue.c_str());
            break;
	case 'l':
	    lvalue = optarg;
	  
            lint_value = atoi(lvalue.c_str());
	     break;
        case 'c':
	    
            cvalue = optarg;
		
            cint_value = atoi(cvalue.c_str());
            break;
        case '?':
            if (optopt == 'c')
                std::cerr << "Error: option -" << optopt
                          << " requires an argument." << std::endl;
	    else if (optopt == 's')
                std::cerr << "Error: option -" << optopt
                          << " requires an argument." << std::endl;
            else if (optopt == 'n')
                std::cerr << "Error: option -" << optopt
                          << " requires an argument." << std::endl;
            else if (optopt == 'l')
                std::cerr << "Error: option -" << optopt
                          << " requires an argument." << std::endl;
            else
                std::cerr << "Error: unknown option: " << optopt << std::endl;
            return 1;
        default:
            return 0;
        }
/*	
    std::cout << "sint_value==" << sint_value << " "
              << "nint_value==" << nint_value << " "
              << "lint_value==" << lint_value << " "
              << "cint_value=" << cint_value << std::endl;
 */	 
	
    if (optind < argc) {
        std::cout << "Found positional arguments\n";
        for (index = optind; index < argc; index++)
            std::cout << "Non-option argument: " << argv[index] << "\n";
    }
//std::cout << "sint_value==" << sint_value << " ";
	 return 0;
}
