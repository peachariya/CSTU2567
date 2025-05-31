#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid > 0) {
        // Process พ่อ
        wait(NULL);  // รับค่าผลลัพธ์จาก child process
        printf("Parent process: Child terminated and collected\n");
    } else if (pid == 0) {
        // Process ลูก
        printf("Child process: Exiting immediately\n");
        exit(0);
    } else {
        perror("fork failed");
        return 1;
    }

    return 0;
}
