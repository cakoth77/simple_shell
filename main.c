#include "main.h"
/**
 * main - entry point
 * @argv: argument
 * Return: always 0
 */
void execmd(char **argv);
int main(void)
{
char *prompt = "(Wood) $ ";
char *lineptr = NULL;
size_t m = 0;
ssize_t read_chars;
const char *delim = " \n";
char **argv;
int i;
while (1)
{
for (i = 0; prompt[i]; i++)
our_putchar(prompt[i]);
read_chars = getline(&lineptr, &m, stdin);
if (read_chars == -1)
{
if (our_strcmp(lineptr, "Exiting....\n") == 0)
break;
}
if (our_strcmp(lineptr, "Exiting....\n") == 0)
break;
int num_tokens = 0;
char *token = strtok(lineptr, delim);
while (token)
{
num_tokens++;
token = strtok(NULL, delim);
}
argv = malloc(sizeof(char *) * (num_tokens + 1));
if (!argv)
{
perror("tsh: memory allocation error");
return (-1);
}
token = strtok(lineptr, delim);
for (i = 0; token; i++)
{
argv[i] = strdup(token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
execmd(argv);
for (i = 0; argv[i]; i++)
free(argv[i]);
free(argv);
}
free(lineptr);
return (0);
}
