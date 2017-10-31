#include<unistd.h>
#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include <signal.h>
/// Entry point of process B
int procB(void) {
    // Process B writing to C
    while (!std::cin.eof()) {
        // read a line of input until EOL and store in a string
        std::string line;
        std::getline(std::cin, line);
	std::cout <<"B:"<< line << std::endl;
        if (line.size () > 0)
            std::cout <<"B:"<< line << std::endl;
    }
    std::cout << std::cin.eof() << std::endl;
    return 0;
}
int procC(void) {
    // Process C reading from both A and B
    while (!std::cin.eof()) {
        // read a line of input until EOL and store in a string
        std::string line;
        std::getline(std::cin, line);
        if (line.size () > 0)
            std::cout << "[C]: " << line << std::endl;
    }
    std::cout << "[C] saw EOF" << std::endl;
    return 0;
}
int main(void) {
 int AtoB[2];
    pipe(AtoB);
    int AtoC[2];
    pipe(AtoC);
    char* argv[3];

    argv[0] = (char*)"python";
    argv[1] = (char*)"a1ece650.py";
    argv[2] = nullptr;
    std::cout << "[exec] executing '/bin/ls -l' using execv" << std::endl;

    pid_t kid;
    kid = fork ();
	if (kid == 0) {
	  dup2(AtoC[1],STDOUT_FILENO);
    close(AtoC[0]);
    close(AtoC[1]);
 
        //sleep (4);
        execlp ("./using_getopt", "rgen", (char*) NULL);
        // execl("/bin/ls", "ls", "-l", nullptr);
        perror ("Error from arie");
        return 1;
    }
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
    }
  

	std::cout <<"B start:"<<  std::endl;
 	
    kid = fork ();
   if (kid == 0) {
	dup2(AtoB[0],STDIN_FILENO);
	close(AtoB[1]);
	close(AtoB[0]);
        //sleep (4);
        
        // execl("/bin/ls", "ls", "-l", nullptr);
        
        return procC();
    }
   dup2(AtoB[1],STDOUT_FILENO);
    close(AtoB[0]);
    close(AtoB[1]);
    // start process B
    int res =  procB();
   std::cout <<"B end:"<<  std::endl;
    waitpid(kid, &res, 0);
    std::cout << "ls returned status: " << res << std::endl;

    return 0;
}
