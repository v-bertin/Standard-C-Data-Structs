#include <stdio.h>

#include "dict.h"
#include "json_parser.h"

int main(void) 
{
    dict * fileContent;

    fileContent = get_content("test_parser.json");

    if (NULL == fileContent)
    {
       printf("Test parser failed\n");
       return -1;
    }

    print_dict (fileContent);

    suppr (&fileContent);

    print_dict (fileContent);

    return 0;
}