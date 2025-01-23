#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_plus(int a, int b)
{
    int transition;
    while (b != 0)
    {
        transition = a & b;
        a = a ^ b;
        b = transition << 1;
    }
    return a;
}

int binary_minus(int a, int b)
{
    return binary_plus(a, binary_plus(~b, 1));
}

int conversion_to_base_2r(unsigned int num, unsigned int r, char* output, size_t output_size)
{
    if (r < 1 || r > 5)
    {
        return 1;
    }

    unsigned int base, digit, index = 0, temp_num = num;
    size_t required_digits = 0;
    char temp;
    int i;

    base = (1 << r);
    base = (unsigned int)binary_minus((int)base, 1);

    while (temp_num)
    {
        required_digits = (size_t)binary_plus((int)required_digits, 1);
        temp_num >>= r;
    }

    if (required_digits >= output_size)
    {
        return 2;
    }

    if (num == 0)
    {
        output[index] = '0';
        index = (unsigned int)binary_plus((int)index, 1);
    }
    else
    {
        while (num)
        {
            digit = num & (base);

            output[index] = (digit < 10)
                            ? (char)binary_plus((int)'0', (int)digit)
                            : (char)binary_plus((int)'A', binary_minus((int)digit, 10));

            num >>= r;
            index = (unsigned int)binary_plus((int)index, 1);
        }
    }

    for (i = 0; i < index >> 1;i = binary_plus(i, 1))
    {
        temp = output[i];
        output[i] = output[binary_minus((int)index, binary_plus(i, 1))];
        output[binary_minus((int)index, binary_plus(i, 1))] = temp;
    }

    output[index] = 0;

    return 0;
}

int main() {
    unsigned int num;
    unsigned int r;
    char output[33];

    printf("Enter the number to convert: ");
    scanf("%u", &num);

    printf("Enter the value of r (from 1 to 5): ");
    scanf("%u", &r);

    switch (conversion_to_base_2r(num, r, output, sizeof(output)))
    {
        case 0:
            printf("The number %u in base 2^%u: %s", num, r, output);
            break;

        case 1:
            printf("\nInvalid value for r!");
            break;

        case 2:
            printf("\nNot enough space in output str!");
            break;

        default:
            printf("\nUnknown error");
            break;
    }

    return EXIT_SUCCESS;
}
