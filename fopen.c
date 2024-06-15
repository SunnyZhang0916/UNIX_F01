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

    // 读取文件内容
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // 输出文件内容
        fputs(buffer, stdout);
    }

    // 关闭文件
    fclose(file);

    return 0;
}