#include "libft.h"

void	free_str_array(char **str_array)
{
	int	index;

	index = -1;
	if (str_array)
		while (str_array[++index])
			free(str_array[index]);
	free(str_array);
}
