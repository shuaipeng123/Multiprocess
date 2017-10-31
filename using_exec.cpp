#include<unistd.h>
#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include <signal.h>
int main(void) {

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
	dup2(AtoC[0],STDIN_FILENO);
	close(AtoC[1]);
	close(AtoC[0]);
        sleep (4);
        execlp ("python", "python", "a1ece650.py", "test", (char*) NULL);
        // execl("/bin/ls", "ls", "-l", nullptr);
        perror ("Error from arie");
        return 1;
    }
    dup2(AtoC[1],STDOUT_FILENO);
    close(AtoC[0]);
    close(AtoC[1]);
    std::cout<<"a \"Weber Street\" (2,-1) (2,2) (5,5) (5,6) (3,8)"<<std::endl;
    int res;
    waitpid(kid, &res, 0);
    std::cout << "ls returned status: " << res << std::endl;

    return 0;
}
