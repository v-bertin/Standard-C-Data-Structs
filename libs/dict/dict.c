#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "dict.h"

dict_elem* new_dict_elem(int key, char* value) {
    dict_elem *e = (dict_elem*) malloc(sizeof(dict_elem));
    e->value = (char *) malloc (strlen (value));

    e->key = key;
    strcpy (e->value, value);
    e->next = NULL;

    return e;
}

dict * empty_dict (void) 
{
   dict *d = (dict*) malloc(sizeof(dict));

   d->len = 0;
   d->elem = NULL;

   return d;
}

dict* new_dict(int key, char* value) {
    dict *d = (dict*) malloc(sizeof(dict));
    
    d->len = 1;
    d->elem = new_dict_elem(key, value);

    return d;
}

void print_dict_from_dict_elem(dict_elem *d) {
    dict_elem *e = d;
    while(e != NULL) {
        printf("{%d: %s}\n", e->key, e->value);
        e = e->next;
    }
}

void print_dict(dict *d) {
    if (NULL == d)
    {
       printf ("Empty dict : nothing to print.\n");
       return;
    }
    dict_elem *e = d->elem;
    printf("{");
    while (e != NULL) {
        printf("%d: %s", e->key, e->value);
        if(e->next == NULL) {
            printf("}\n");
            break;
        } else {
            printf(", ");
            e = e->next;
        }
    }
}

void add_from_dict_elem(dict_elem **d, int key, char* value) {
    dict_elem *current = *d;
    dict_elem *new_elem = new_dict_elem(key, value);
    if(*d == NULL) {
        *d = new_elem;
    }

    while(current->next != NULL) {
        printf("%d\n", current->key);
        if(current->key == key) {
            printf("we are in if\n");
            current->value = value;
            return;
        } else {
            printf("we are in else\n");
            current = current->next;
        }
    }
    printf("we are out of while loop\n");
    printf("%d\n", new_elem->key);
    current->next = new_elem;
    printf("%d\n", current->key);
    
    return;
}

void add(dict **d, int key, char* value) {
    dict_elem *current = (*d)->elem;
    dict_elem *new_elem = new_dict_elem(key, value);

    if(current == NULL) {
        (*d)->elem = new_elem;
        return;
    }

    while(current->next != NULL) {
        if(current->key == key) {
            strcpy (current->value, value);
            return;
        } else {
            current = current->next;
        }
    } 
    if(current->key == key) {
        strcpy (current->value, value);
        return;
    }
    current->next = new_elem;
    (*d)->len++;    
    return;
}

char* get(dict* d, int key, char *def) {
    dict_elem *e = d->elem;
    while (e != NULL) {
        if(e->key == key) return e->value;
        else e = e->next;
    }
    return def;
}

int find_index(dict* d, char* value) {
    dict_elem *e = d->elem;
    while (e != NULL) {
        if (e->value == value) return e->key;
        else e = e->next;
    }
    return -1;
}

void delete(dict **d, int key) {
    char* value = get(*d, key, NULL);
    if(value == NULL) return;

    dict_elem *previous;
    dict_elem *current = (*d)->elem;
    while(current->key != key) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    (*d)->len--;
}

void suppr(dict **d) {
    int len = (*d)->len;
    dict_elem *previous;
    dict_elem *current = (*d)->elem;
    dict_elem *next = current->next;

    for(unsigned int i = 0; i < len; i++) {
        previous = current;
        current = next;
        if(i == len - 1) next == NULL;
        else next = current->next;
        free(previous);
    }
    (*d)->len = 0;
    (*d)->elem = NULL;
    free (*d);
    *d = NULL;
}

int* get_keys(dict* d) {
    int len = d->len;
    int* keys = (int*) malloc(len * sizeof(int));
    dict_elem* current = d->elem;

    for (unsigned int i = 0; i < len; i++) {
        keys[i] = current->key;
        current = current->next;
    }
    return keys;
}