#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  // สร้าง process ลูก

    if (pid > 0) {
        // Process พ่อ
        printf("Parent process: Sleeping for 10 seconds\n");
        sleep(10);  // รอให้ child process ทำงานเสร็จ
    } else if (pid == 0) {
        // Process ลูก
        printf("Child process: Exiting immediately\n");
        exit(0);  // ปิด process ลูกทันที
    } else {
        // Error
        perror("fork failed");
        return 1;
    }

    return 0;
}
