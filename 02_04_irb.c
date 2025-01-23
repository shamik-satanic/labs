#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int find_substr(const char* str, const char* substr)
{
    int i = 0;
    while (substr[i] && str[i] && str[i] == substr[i])
    {
        ++i;
    }
    return substr[i] == 0;
}

int find_substr_in_file(const char* substr, int count_file, ...)
{
    if (*substr == 0)
    {
        return 1;
    }

    va_list files;
    va_start(files, count_file);

    int file_index, str_number, i, buffer_index;
    const char* file_name;
    char buffer[BUFSIZ], ch;

    for (file_index = 0; file_index < count_file; ++file_index)
    {
        file_name = va_arg(files, const char*);
        FILE* file = fopen(file_name, "r");

        printf("%s.\n", file_name);

        str_number = 1;
        buffer_index = 0;

        while ((ch = fgetc(file)) != EOF)
        {
            if (ch == '\n')
            {
                buffer[buffer_index] = 0;

                for (i = 0; buffer[i] != 0; ++i)
                {
                    if (find_substr(&buffer[i], substr))
                    {
                        printf("	Substring was found in %d string at %d position.\n", str_number, i + 1);
                    }
                }
                buffer_index = 0;
                ++str_number;
            }
            else
            {
                buffer[buffer_index++] = ch;
            }
        }

        if (buffer_index > 0)
        {
            buffer[buffer_index] = 0;
            for (i = 0; buffer[i] != 0; ++i)
            {
                if (find_substr(&buffer[i], substr))
                {
                    printf("	Substring was found in %d string at %d position.\n", str_number, i + 1);
                }
            }
        }

        fclose(file);
    }
    va_end(files);
    return 0;
}

int main()
{
    switch (find_substr_in_file("34", 3, "file1.txt", "file2.txt", "file3.txt"))
    {
        case 0:
            printf("ok\n");
            break;

        case 1:
            printf("Substring is empty\n");
            break;

        default:
            printf("Undefined behavior\n");
            break;
    }
    return EXIT_SUCCESS;
}