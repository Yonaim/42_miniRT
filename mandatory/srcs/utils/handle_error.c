#include <stdio.h>
#include <stdlib.h>

int	handle_error(char *err_msg)
{
	printf("Error\n: %s\n", err_msg);
	exit(1);
	return (1);
}
