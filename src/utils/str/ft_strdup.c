#include "../../../include/minishell.h"

/*
	gönderilen karakter dizisi icin heap bellekte 
	yer ayrilir ve ardindan return edilir.
*/

char	*ft_strdup(char *ptr)
{
	char	*new_ptr;
	char	*return_new_ptr;

	if (!ptr)
		return (NULL);
	new_ptr = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	return_new_ptr = new_ptr;
	while (*ptr)
		*(new_ptr++) = *(ptr++);
	*new_ptr = 0;
	return (return_new_ptr);
}
