#include "main.h"
/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
char *prompt = "(Wood) $ ";
char *lineptr = NULL;
size_t m = 0;
ssize_t read_chars;
while (1)
{
for (size_t i = 0; prompt[i] != '\0'; i++)
{
our_putchar(prompt[i]);
}
read_chars = getline(&lineptr, &m, stdin);
if (read_chars == -1)
{
our_putchar('\n');
break;
}
lineptr[read_chars - 1] = '\0';
if (lineptr[0] == '\0')
{
continue;
}
/* Execute command */
if (access(lineptr, X_OK) == -1)
{
perror("tsh: command not found");
continue;
}
if (fork() == 0)
{
execl(lineptr, lineptr, NULL);
perror("tsh: exec error");
_exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
free(lineptr);
return (0);
}
