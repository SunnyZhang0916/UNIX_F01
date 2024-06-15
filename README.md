# UNIX_F01

1. **open**：**`open`** 函数是用于在C程序中打开文件的系统调用。它允许您指定打开文件的标志，如只读、只写、读写等，并且可以选择其他标志，如追加、创建文件等。
    - F**laggor**（标志）：在打开文件时，您可以选择不同的标志来指定文件的打开方式。Välj en av **O_RDONLY**, **O_WRONLY** eller **O_RDWR**
        - **O_RDONLY**：只读模式，用于打开文件以进行读取。
        - **O_WRONLY**：只写模式，用于打开文件以进行写入。
        - **O_RDWR**：读写模式，用于打开文件以进行读取和写入。
    
    - Sedan kan man "or'a" dem med 0 eller flera av följande konstanter. 在设置文件打开标志时，您可以使用按位或（"or"）操作将它们与以下常量之一或多个常量组合在一起。这些常量用于在文件打开时指定不同的行为或属性。
        - **O_APPEND**：写文件时，数据添加到文件末尾
        - **O_CREAT**：创建标志，如果文件不存在，则创建该文件。使用此选项时需使用mode说明文件的权限。
        - **O_TRUNC**：如果文件存在，则清空文件内容

2. 对于 **`getc`** 和 **`putc`** 这两个函数，是否是宏（宏是一种在编译时展开的代码片段）。在标准C库中，通常会将它们实现为宏，以提高执行效率。

宏通常是在编译时展开的，而不是在运行时调用的函数。它们允许进行一些简单的、高效的操作，但也可能会导致一些潜在的问题，因此在使用时需要小心。

对于 **`getc`** 和 **`putc`**，它们通常会被定义为宏，以便进行一些额外的操作，例如错误检查或缓冲处理。但具体实现可能因编译器和平台而异。

fgets：从文件中获取一行文本。
(gets)：（已不推荐使用的函数）从标准输入获取一行文本。
fputs：将一行文本写入文件。
puts：将一行文本写入标准输出。

fread：用于从文件中读取二进制数据。
fwrite：用于向文件中写入二进制数据。
