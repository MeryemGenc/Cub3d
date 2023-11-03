#include "cube3d.h"

int print_err(char *str)
{ // exit yapılması gerekmez mi
    printf("%s", str);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return print_err("Wrong argument");

    map_init(argv[1]);

    return 0;
}