// adapted from https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
/// main() must be declared with arguments
/// otherwise command line arguments are ignored
 
    int sint_value=10;

    int nint_value=5;
 
    int lint_value=5;
 
    int cint_value=20;
static const char alp[]="0123456789 "
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";


char genRandom()  // Random string generator function.
{
	int stringLength = sizeof(alp) - 1;
    return alp[rand() % stringLength];
}
int get_opt(int argc, char **argv);
int random_n(int upper_limit);
int main (int argc, char **argv)
{
   
  
    
  	int a=get_opt(argc,argv);
  
    
  
    int string_length=0;
	while(string_length<5){
	string_length=std::abs(random_n(10));
	
	//std::cout << "Random int for length: " << string_length << "\n";
	}
  	int count_line_segment=nint_value;
    while(sint_value>0){
	std::cout<<"strings:"<<std::endl;
	 for(int z=0; z < string_length; z++)
    	{
        std::cout<< genRandom();

    	}
	std::cout<<std::endl;
	while( count_line_segment>0){
	int x=random_n(cint_value);
	int y=random_n(cint_value);
	std::cout<<"tuples for "<<sint_value<<"street"<<std::endl;
	std::cout<<"("<<x<<","<<y<<")"<<std::endl;
		 count_line_segment--;
	}
	 count_line_segment=nint_value;
	sint_value--;
    }

    return 0;
}



int random_n(int upper_limit){
	  std::ifstream urandom("/dev/urandom");
  if (urandom.fail()) {
        std::cerr << "Error: cannot open /dev/urandom\n";
        return 1;
    }
  char ch = 'a';
    urandom.read(&ch, 1);
    // cast to integer to see the numeric value of the character
    //std::cout << "Random character: " << (int)ch << "\n";
	return (int)ch%(upper_limit);
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
}
