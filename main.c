#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
info_t info[] = { INFO_INIT };
int fd = 2;
fd = dup(STDERR_FILENO);
if (fd == -1)
return (EXIT_FAILURE);
if (ac == 2)
{
fd = open(av[1], O_RDONLY | O_CREAT, 0644);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
write(STDERR_FILENO, av[0], strlen(av[0]));
write(STDERR_FILENO, ": 0: Can't open ", 17);
write(STDERR_FILENO, av[1], strlen(av[1]));
write(STDERR_FILENO, "\n", 1);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fd;
}
populate_env_list(info);
read_history(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
