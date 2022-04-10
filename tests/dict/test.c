#include "libs.h"

#include "dict.h"

int main (void) 
{
   // Dict creation
   dict * d = new_dict (5, "cinq");
   print_dict (d);

   printf ("**********************************\n");

   // Value modification when key already exists
   add (&d, 5, "five");
   print_dict (d);
   assert (1 == d->len);

   printf("**********************************\n");

   // Add an element
   add (&d, 6, "six");
   print_dict (d);
   assert (2== d->len);

   printf("**********************************\n");

   // Add multiples elements
   add (&d, 7, "seven");
   add (&d, 11, "eleven");
   add (&d, 43, "forty three");
   print_dict (d);
   assert (5 == d->len);

   printf("**********************************\n");

   // Get a value from a key
   int      key   = 43;
   char *   value = get (d, key, NULL);

   printf ("with key %d is associated value \"%s\"\n", key, value);
   assert (0 == strcmp (value, "forty three"));
   assert (NULL == get (d, 8, NULL));

   printf("**********************************\n");

   // Get a key from a value
   char *   value_2  = "eleven";
   int      key_2    = find_index (d, value_2);
   printf ("with value %s is associated key %d\n", value_2, key_2);
   assert (11 == key_2);
   assert (-1 == find_index (d, "pouet"));

   printf("**********************************\n");

   // Delete an element from key
   delete (&d, 11);
   print_dict (d);
   delete (&d, 9);
   print_dict (d);

   printf("**********************************\n");

   // List keys of the dictionary in a table
   int   i;
   int * keys           = get_keys (d);
   int   real_keys[4]   = {5, 6, 7, 43};

   for(i = 0; i < d->len; i++) 
   {
      printf ("%d ", keys[i]);
      assert (keys[i] == real_keys[i]);
   }
   printf ("\n");

   printf("**********************************\n");

   // Suppress an entire dictionary
   suppr_dict (&d);
   print_dict (d);
}