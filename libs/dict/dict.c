#include "libs.h"

#include "dict.h"

struct dict_elem {
   int                  key;
   char *               value;
   struct dict_elem *   next;
};

typedef struct dict_elem dict_elem;

static dict_elem * new_dict_elem (int key, char * value) 
{
   dict_elem * e = (dict_elem *) malloc (sizeof (dict_elem));

   e->key   = key;
   e->value = (char *) malloc (strlen (value));
   strcpy (e->value, value);
   e->next  = NULL;

   return e;
}

dict * empty_dict (void) 
{
   dict * d = (dict *) malloc (sizeof (dict));

   d->len   = 0;
   d->elem  = NULL;

   return d;
}

dict * new_dict (int key, char * value) 
{
   dict * d = (dict *) malloc (sizeof (dict));
   
   d->len   = 1;
   d->elem  = new_dict_elem (key, value);

   return d;
}

void print_dict (dict * d)
{
   if (NULL == d)
   {
      printf ("Empty dict : nothing to print.\n");
      return;
   }

   dict_elem * e = d->elem;

   printf("{");

   while (e != NULL) 
   {
      printf ("%d: %s", e->key, e->value);
      if (NULL == e->next) 
      {
         printf ("}\n");
         break;
      }
      else
      {
         printf (", ");
         e = e->next;
      }
   }
}

void add (dict ** d, int key, char * value)
{
   if (NULL == *d)
   {
      printf ("Non ititialized dict.");
      return;
   }

   dict_elem * current;
   dict_elem * new_elem;

   current  = (*d)->elem;
   new_elem = new_dict_elem (key, value);

   if(NULL == current)
   {
      (*d)->elem = new_elem;
      return;
   }

   while (current->next != NULL)
   {
      if(current->key == key) 
      {
         strcpy (current->value, value);
         return;
      }
      else
      {
         current = current->next;
      }
   }

   if(current->key == key) 
   {
      strcpy (current->value, value);
      return;
   }

   current->next = new_elem;
   (*d)->len++;

   return;
}

char * get (dict * d, int key, char * def) 
{
   dict_elem * e = d->elem;

   while (NULL != e)
   {
      if (e->key == key)
      {
         return e->value;
      }
      else
      {
         e = e->next;
      }
   }

   return def;
}

int find_index (dict * d, char * value)
{
   dict_elem * e = d->elem;

   while (NULL != e) 
   {
      if (0 == strcmp (e->value, value))
      {
         return e->key;
      }
      else
      {
         e = e->next;
      }
   }

   return -1;
}

void delete (dict ** d, int key)
{
   dict_elem * previous;
   dict_elem * current;
   char *      value;

   value = get (*d, key, NULL);
   if(value == NULL) 
   {
      return;
   }

   current = (*d)->elem;
   while(current->key != key) 
   {
      previous = current;
      current = current->next;
   }

   previous->next = current->next;
   free (current);
   (*d)->len--;
}

void suppr_dict (dict ** d) 
{
   int         i;
   int         len;
   dict_elem * previous;
   dict_elem * current;
   dict_elem * next;

   len      = (*d)->len;
   current  = (*d)->elem;
   next     = current->next;

   for (i = 0; i < len; i++) {
      previous = current;
      current  = next;

      if(i == len - 1)
      {
         next = NULL;
      }
      else
      {
         next = current->next;
      }

      free(previous);
   }

   (*d)->len   = 0;
   (*d)->elem  = NULL;
   free (*d);

   // Safety net : I have observed that in some cases there is one element left in the dictionary.
   *d = NULL;
}

int * get_keys (dict * d)
{
   int         i;
   int         len;
   int *       keys;
   dict_elem * current;

   len      = d->len;
   keys     = (int *) malloc (len);
   current  = d->elem;

   for (i = 0; i < len; i++)
   {
      keys[i] = current->key;
      current = current->next;
   }

   return keys;
}
