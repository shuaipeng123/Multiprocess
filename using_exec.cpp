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
	std::cout <<"B:"<< line << std::endl;
        if (line.size () > 0)
            std::cout <<"B:"<< line << std::endl;
    }
    std::cout << "[B] saw EOF" << std::endl;
    return 0;
}

int main(void) {
	std::vector<pid_t> kids;
	int AtoB[2];
    pipe(AtoB);
    int AtoC[2];
    pipe(AtoC);
    

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
	std::cout <<"B start:"<<  std::endl;
 	
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
	kids.push_back(kid);
	kid = 0;
	dup2(AtoB[1],STDOUT_FILENO);
    close(AtoB[0]);
    close(AtoB[1]);
    // start process B
    int res =  procB();
    std::cout <<"B end:"<<  std::endl;
	for (pid_t k : kids) {
        int status;
        kill (k, SIGTERM);
        waitpid(k, &status, 0);
    }
    std::cout << "ls returned status: " << res << std::endl;

    return 0;
}
