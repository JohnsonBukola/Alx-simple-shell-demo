#include "shell.h"

int main(void)
{
    /* Here we declare variables*/
    int read_char;
    char *line = NULL;
    size_t len = 0;

/* String tokenization*/
    char *line_argument[1024];
    char *delimiters = " "; /* Set an empty string as a delimiter*/
    char *token;

    /*to show that our shell ius active and ready to take input. Command Prompt line*/
    write(1, "prompt$ ", 8);

    /* Getting the user's input*/
    read_char = getline(&line, &len, stdin);
    if (read_char == -1)
    {
        perror("There is error reading input");
        return (-1);
    }
    else 
    {
         /* Process the input using string tokenization*/
         token = strtok(line, delimiters);

         while(token != NULL)
         {
            write("%s\n", token);
            token = strtok(NULL, delimiters);
         }

        return(0);
    }
