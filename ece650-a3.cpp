#include<unistd.h>
#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include <signal.h>
#include<vector>
int procB(void) {
    // Process B writing to C
    while (!std::cin.eof()) {
        // read a line of input until EOL and store in a string
        std::string line;
        std::getline(std::cin, line);
        if (line.size () > 0)
            std::cout << line << std::endl;
    }
   // std::cout << "[B] saw EOF" << std::endl;
    return 0;
}
#define MAXLINE 512
int main(int argc, char **argv) {
	
	std::vector<pid_t> kids;
	int AtoB[2];
    pipe(AtoB);
    int AtoC[2];
    pipe(AtoC);
    FILE *fpin;
    FILE *write_a2;
    char line[MAXLINE];
    pid_t kid;
    kid = fork ();
	if (kid == 0) {
		dup2(AtoC[1],STDOUT_FILENO);
		close(AtoC[0]);
		close(AtoC[1]);
 
        //sleep (4);
        execvp ("./rgen",argv);
        // execl("/bin/ls", "ls", "-l", nullptr);
        perror ("Error from arie");
        return 1;
    }
	else if (kid < 0) {
        std::cerr << "Error: could not fork\n";
        return 1;
    }
	kids.push_back(kid);
	kid = fork ();
    if (kid == 0) {
		dup2(AtoC[0],STDIN_FILENO);
		close(AtoC[1]);
		close(AtoC[0]);
	
		dup2(AtoB[1],STDOUT_FILENO);
		close(AtoB[0]);
		close(AtoB[1]);
        //sleep (4);
        execlp ("python", "python", "a1ece650.py", "test", (char*) NULL);
        // execl("/bin/ls", "ls", "-l", nullptr);
        perror ("Error from arie");
        return 1;
    }else if (kid < 0) {
        std::cerr << "Error: could not fork\n";
        return 1;
    }
  	
	kids.push_back(kid);
	//std::cout <<"B start:"<<  std::endl;
	write_a2=popen("./ece650-a2","w");
	kid=fork();
	if(kid==0){
		fpin=fdopen(AtoB[0],"r");
	while(fgets(line, MAXLINE, fpin) != NULL){
			//if(line[0]=='V'||line[0]=='E')			
			//std::cout<<line;
			fputs(line,write_a2);
			fflush(write_a2);
			}
		}
			
	
	
 	/*
    kid = fork ();
    if (kid == 0) {
		dup2(AtoB[0],STDIN_FILENO);
		close(AtoB[1]);
		close(AtoB[0]);
        //sleep (4);
        
        execlp("./ece650-a2", "a2", nullptr);
        perror ("Error from arie");
        return 1;
    }
	else if (kid < 0) {
        std::cerr << "Error: could not fork\n";
        return 1;
    }
	*/
	kids.push_back(kid);
	kid = 0;
	dup2(AtoB[1],STDOUT_FILENO);
    close(AtoB[0]);
    close(AtoB[1]);
//std::cout<<"kids size:"<<kids.size();
    // start process B
    int res =  procB();
   // std::cout <<"B end:"<<  std::endl;
	
	for (pid_t k : kids) {
        int status;
        kill (k, SIGTERM);
        waitpid(k, &status, 0);
    }
//dup2(AtoB[0],STDIN_FILENO);
  //  close(AtoB[1]);
    //close(AtoB[0]);
    std::cout << "ls returned status: " << res << std::endl;

    return 0;
}


