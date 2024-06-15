#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE	1024

void readfile(FILE *);

int main(int argc, char *argv[])
{
	FILE *inputfile;

	/* 如果命令行参数的数量为1，表示没有提供文件名，则将inputfile指针指向标准输入。*/
	if (argc == 1) {
		inputfile = stdin;

	/* 如果命令行参数的数量为2，表示提供了文件名，则将inputfile指针指向该文件。*/
	} else if (argc == 2) {

		/* 如果打开文件失败，则输出错误信息并退出程序 */
		if ((inputfile = fopen(argv[1], "r")) == NULL) {
			perror(argv[1]);
			exit(1);
		}
	} else {

		/* 如果命令行参数的数量不是1或2，则输出错误信息并退出程序 */
		fprintf(stderr, "Wrong number of arguments.\n");
		fprintf(stderr, "usage: %s file\n", argv[0]);
		
		/* OBS! ej: perror("eget felmeddelande"); */
		exit(1);
	}

	readfile(inputfile);
	
	/* 关闭文件指针inputfile */
	fclose(inputfile);

	/*exit(0) 是一个系统调用，用于终止整个进程。它会立即退出程序，并将状态码（退出状态）设置为0，表示成功。这个状态码会传递给操作系统，供其他程序检索。
	  exit(0) 通常用于在C或C++程序中从main函数中退出，以指示程序成功运行完成。
      当程序调用 exit(0) 时，它会执行一些清理工作（如关闭文件、释放内存等），然后终止进程。 
	 */
	exit(0);
}

void readfile(FILE *in)
{
	char buf[BUFSIZE];

	/* Read and write
	   使用fgets函数逐行读取文件或标准输入的内容 */
	while (fgets(buf, BUFSIZE, in) != NULL) {

		/* 如果读取成功，则将该行写入标准输出 */
		fputs(buf, stdout);
	}
	return;
}
