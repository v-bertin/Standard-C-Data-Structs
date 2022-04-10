struct dict_elem {
    int key;
    char* value;
    struct dict_elem *next;
};

typedef struct dict_elem dict_elem;

struct dict {
    int len;
    struct dict_elem *elem;
};

typedef struct dict dict;

dict* empty_dict (void);
dict* new_dict(int key, char* value);
dict_elem* new_dict_elem(int key, char* value);

void print_dict_from_dict_elem(dict_elem *d);
void print_dict(dict *d);

void add_from_dict_elem(dict_elem **d, int key, char* value);
void add(dict **d, int key, char* value);

char* get(dict* d, int key, char *def);
int find_index(dict* d, char* value);
void delete(dict **d, int key);
void suppr(dict **d);

int* get_keys(dict* d);