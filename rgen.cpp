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
static const char alp[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";


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
  
    int srandom=random_n(sint_value,2);
    
   
  
    int string_length=std::abs(random_n(10,5));
	
  	int count_line_segment=random_n(nint_value,1);
    while(srandom>0){
	    std::cout<<"a \"";
	    for(int z=0; z < string_length; z++)
    	{
        std::cout<< genRandom();

    	}
	    std::cout<<"\"";
    	while( count_line_segment>0){
	    int x=random_n(cint_value,1);
	    int y=random_n(cint_value,1);
	    std::cout<<" ("<<x<<","<<y<<")";
		count_line_segment--;
	}
	std::cout<<std::endl;
	count_line_segment=random_n(nint_value,1);
	srandom--;
    }
    std::cout<<"g"<<std::endl;
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
	while((int)ch%(upper_limit+1)<lower_limit){
	
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
}
