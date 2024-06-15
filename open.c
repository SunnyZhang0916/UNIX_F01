#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[1024];

    // 打开文件
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 读取文件内容,read函数返回实际读取到的字节个数
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    
    if (bytesRead == -1) {
        perror("read");
        return 1;
    }
    
    // 输出文件内容，write函数返回实际写入的字节个数，STDOUT_FILENO
    write(STDOUT_FILENO, buffer, bytesRead); // STDOUT_FILENO 为 1， 是文件描述符

    // 关闭文件
    close(fd);

    return 0;
}
