#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "dict.h"

#define MAX_LINE_LENGTH 256

static int fgetline (FILE * fd, char * s, int lim)
{
   int      i;
   int      c;

   if ((!fd) || (!s) || (lim < 2))
   {
      printf ("Invalid parameters\n");
      return -1;
   }

   for (i = 0; i < (lim - 1) && (c = fgetc (fd)) != EOF && c != '\n'; i++)
   {
      s[i] = c;
   }

   s[i] = '\0';

   return i;
}

int parseLine (char * line, char ** key, char ** value)
{
   char * content;

   if ('{' == line[0])
   {
      return 1;
   } 
   else if ('}' == line[0])
   {
      return 2;
   }


   content = strpbrk (line, "\"");
   if (NULL == content)
   {
      printf ("Invalid key in line %s\n", line);
      return -1;
   }

   *key = strtok (content, "\"");
   *value = strtok (NULL, "\"");
   *value = strtok (NULL, ":");
   *value = strtok (*value, "\"");

   if ((NULL == *key) || (NULL == *value))
   {
      printf ("Unable to parse line %s\n", line);
      return -1;
   }

   return 0;
}

dict* get_content(char *filename) {
    int ret;
    FILE *f;
    char line[MAX_LINE_LENGTH];
    char * key;
    char * value;
    int keyInt;
    dict * fileContent;

    f = fopen(filename, "r");
    if(NULL == f) {
        printf("Unable to open file.\n");
        return NULL;
    }

    // fileContent = empty_dict ();
    fileContent = new_dict (0, "zero");

    while (1) {
        fgetline(f, line, MAX_LINE_LENGTH);
        ret = parseLine (line, &key, &value);
        if (-1 == ret)
        {
           printf ("Error while getting the content of %s\n", filename);
           return NULL;
        }
        else if (1 == ret)
        {
           printf ("Parsing first line ... Continuing.\n");
           continue;
        }
        else if (2 == ret)
        {
           printf ("Parsing last line ... Leaving.\n");
           break;
        }

        {
           char * endPtr;
           keyInt = (int) strtol (key, &endPtr, 0);
           if (key == endPtr)
           {
              printf ("Error while casting key %s\n", key);
              return NULL;
           }
        }
        printf ("key = %d, value = %s\n", keyInt, value);
        // printf ("count = %d\n", count);
        // sprintf (s, "pouet %d", count);
        // printf ("s = %s\n", s);
        add (&fileContent, keyInt, value);
    }

    fclose(f);
    print_dict (fileContent);
    return fileContent;   
}