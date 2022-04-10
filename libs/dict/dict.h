#if ! defined _DICT_H_
#define _DICT_H_

struct dict {
   int                  len;
   struct dict_elem *   elem;
};

typedef struct dict dict;

dict *   empty_dict (void);
dict *   new_dict (int key, char * value);
void     suppr_dict (dict ** d);

void     print_dict (dict * d);

void     add (dict ** d, int key, char * value);
char *   get (dict * d, int key, char * def);
int      find_index (dict * d, char * value);
void     delete (dict ** d, int key);

int *    get_keys (dict * d);

#endif /* _DICT_H_ */
