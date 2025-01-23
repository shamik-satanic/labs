#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    delete_memory = 0,
    close_file = 1
} Flagtype;

void clean( void* resource, ...)
{
    va_list arg;
    va_start(arg, resource);
    size_t count_ptr = 0, count_files = 0;

    while (resource != NULL)
    {
        Flagtype flag = va_arg(arg, Flagtype);
        if (flag == delete_memory)
        {
            free(resource);
            ++count_ptr;
        }
        else if (flag == close_file)
        {
            fclose((FILE*)resource);
            ++count_files;
        }
        resource = va_arg(arg, void*);
    }
    va_end(arg);

    printf("%zu memory deallocated\n"
           "%zu file closed\n",
           count_ptr, count_files);
}

int main()
{
    char* dynamic_memory_example = (char*)malloc(10 * sizeof(char));

    FILE* file_example = fopen("file.txt", "w");

    clean(dynamic_memory_example, delete_memory, file_example, close_file, NULL);
    return EXIT_SUCCESS;
}
