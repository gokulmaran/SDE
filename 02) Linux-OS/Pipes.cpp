#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == 0) { // Child process
        close(pipefd[0]); // Close unused read end
        const char* message = "Hello from child process";
        write(pipefd[1], message, strlen(message));
        close(pipefd[1]);
    } else { // Parent process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Parent received: " << buffer << std::endl;
        close(pipefd[0]);
    }

    return 0;
}
