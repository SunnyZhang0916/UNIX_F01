#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE	1024

void readfile(FILE *);

int main(int argc, char *argv[])
{
	FILE *inputfile;

	/* 如果命令行参数的数量为1，表示没有提供文件名，则将inputfile指针指向标准输入。*/
	if (argc == 1) {
		readfile(stdin);

	/* 如果命令行参数的数量大于1，表示提供了一个或多个文件名，则依次打开这些文件并读取内容*/
	} else {

		/* 尝试打开每个文件。如果打开文件失败，则输出错误信息并继续处理下一个文件。 */
		for (int i = 1; i < argc; i++) {
			if ((inputfile = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Skipping ");
				perror(argv[i]);
				continue;
			} 

			readfile(inputfile);
			fclose(inputfile);
		}
	}
	exit(0);
}

void readfile(FILE *in)
{
	/* 声明一个字符数组buf，用于存储读取的行 */
	char buf[BUFSIZE];

	/* 声明一个静态变量counter，用于记录读取的文件数量。*/
	static int counter = 0;

	/* 输出当前文件的编号 */
	printf("File number %d:\n", ++counter);


	while (fgets(buf, BUFSIZE, in) != NULL) {
		fputs(buf, stdout);
	}
	return;
}
