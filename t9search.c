#include <stdio.h>
#include <string.h>
#include <ctype.h>

void name_to_number(char* name);
void print_stdout(char* name, char* number);

int main(int argc, char* argv[])
{

    if(argc > 2)
    {
        puts("Invalid number of arguments.");
        return 0;
    }

    if (argc == 2)
    {
        for(int i = 0; argv[1][i] != '\0'; i++)
        {
            if(!isdigit(argv[1][i]))
                {
                    puts("Invalid argument");
                    return 0;
                }
        }
    }

    char name[100], number[100], buffer[100];

    bool isNameSet = false, contactFound = false;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {   
        buffer[strcspn(buffer, "\n")] = '\0';

        if(!isNameSet)
        {
            strcpy(name, buffer);
            isNameSet = true;
            continue;
        }

        strcpy(number, buffer);
        strcpy(buffer, name);
        
        name_to_number(buffer);

        if(argc == 2)
        {
            if(strstr(buffer, argv[1]) || strstr(number, argv[1]))
            {
                print_stdout(name, number);
                contactFound = true;
            }
        }

        else
        {
            print_stdout(name, number);
        }

        isNameSet = false;
    }
    if(!contactFound)
    {
        puts("Not found");
    }
    return 0;
}

void name_to_number(char* name)
{
    char c;
    for(int i = 0; name[i] != '\0'; i++)
    {
        c = tolower(name[i]);

        if(c == '+') name[i] = '0';
        else if(c >= 'a' && c <= 'c') name[i] = '2';
        else if(c >= 'd' && c <= 'f') name[i] = '3';
        else if(c >= 'g' && c <= 'i') name[i] = '4';
        else if(c >= 'j' && c <= 'l') name[i] = '5';
        else if(c >= 'm' && c <= 'o') name[i] = '6';
        else if(c >= 'p' && c <= 's') name[i] = '7';
        else if(c >= 't' && c <= 'v') name[i] = '8';
        else if(c >= 'w' && c <= 'z') name[i] = '9';
    }
}

void print_stdout(char* name, char* number)
{
    fputs(name, stdout);
    fputs(", ", stdout);
    fputs(number, stdout);
    puts("");
}


