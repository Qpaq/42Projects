#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	int fd = open(av[1], O_RDONLY);

	int ret;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf("error main");
			return (0);
		}
		printf("%s\n", line);
	}
}
