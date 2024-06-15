/**
 * fgets函数是逐行读取文件或输入流的内容，并将每行内容存储在指定的缓冲区中。每次调用fgets函数，它会读取一行内容（包括换行符），
 * 并将其存储在缓冲区中，直到达到以下条件之一：
 * 
 * 1. 读取到文件或输入流的末尾（EOF）。
 * 2. 读取到指定的最大字符数（BUFSIZE - 1）。
 * 3. 读取到换行符（'\n'）。
 * 
 */

#include <stdio.h>

int main() {
    FILE *file;
    char buffer[1024];

    // 打开文件
    file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // 逐行读取文件内容
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // 输出每行内容
        printf("%s", buffer);
    }

    // 关闭文件
    fclose(file);

    return 0;
}
