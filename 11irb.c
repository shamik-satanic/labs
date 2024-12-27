#include <stdio.h>

size_t my_strlen(const char *str) {
    const char *p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

int main() {
    char *example_str = "sfsdfgsfи";
    size_t length = my_strlen(example_str);
    printf("Длина строки: %zu\n", length);
    return 0;
}