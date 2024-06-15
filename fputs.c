#include <stdio.h>

int main() {
    FILE *file;
    char str[] = "Hello, World!";

    // 打开文件
    file = fopen("file.txt", "w");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // 将字符串写入文件
    if (fputs(str, file) == EOF) {
        perror("fputs");
        return 1;
    }

    // 关闭文件
    fclose(file);

    return 0;
}