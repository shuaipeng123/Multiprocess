#include <sys/types.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
int main( void )  
{  
    std::vector<std::string> res;
    FILE   *stream;  
    
    char   buf[1024]; 
     
    memset( buf, '/0', sizeof(buf) );//初始化buf,以免后面写如乱码到文件中
    stream = popen( "python a1ece650.py", "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
	char tmp[1024];
	while(fgets(tmp,sizeof(tmp),stream)!=NULL){
		if(tmp[strlen(tmp)-1]=='\n'){
			tmp[strlen(tmp)-1]='\0';		
		}	
		res.push_back(tmp);
	}
	std::cout<<res.size()<<std::endl;
   
    pclose( stream );  
  
    
    return 0;
} 
