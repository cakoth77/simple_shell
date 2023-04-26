#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024
/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
char *prompt = "(Wood) $ ";
char *line = NULL;
size_t len = 0;
ssize_t read;
while (1)
{
write(STDOUT_FILENO, prompt, strlen(prompt));
read = getline(&line, &len, stdin);
if (read == -1)
{
break;
}
if (line[read - 1] == '\n')
{
line[read - 1] = '\0';
}
char **tokens = NULL;
char *token = strtok(line, " ");
int num_tokens = 0;
while (token)
{
num_tokens++;
tokens = realloc(tokens, sizeof(char *) * num_tokens);
tokens[num_tokens - 1] = token;
token = strtok(NULL, " ");
}
tokens = realloc(tokens, sizeof(char *) * (num_tokens + 1));
tokens[num_tokens] = NULL;
/* Execute command here */
/* ... */
free(tokens);
}
free(line);
return (0);
}
