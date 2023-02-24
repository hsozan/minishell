#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void    *ft_gcollector(void    ptr, bool is_free)
{
    static void **collect;
    static int    size;

    // if (is_free)
    // {
    //     for (int i = 0; i < size; i++)
    //         free(collect[i]);
    //     size = 0;
    //     return NULL;
    // }
    if (size == 0)
        collect = malloc(sizeof(void));
    else
        collect[size] = realloc(collect[0], sizeof(void) * size + 1);
    collect[size] = ptr;
    // printf("%p\n", collect[size]);
    size++;
    return(ptr);
}

int    main()
{
    char    *str;
    char    *str1;

    str = malloc(sizeof(1000));
    ft_gcollector(str,0);
    str1 = malloc(sizeof(1000));
    // ft_gcollector(str1,0);

    // ft_gcollector(NULL,1);
}
