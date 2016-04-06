/**
 * David Dvorshak
 * CSCI 112 - Program 2
 * 4/6/2016
 */

#include <stdio.h> 
#include <string.h>

/* prototypes */ 
void pluralize (char word[]);

int main (int argc, char *argv[]) { 
   
   if (argc > 1)
   {
   	
      for (count = 1; count < argc; count++)
		{
	    /* print the noun and plural form of the each word */ 
        printf("noun: %s\n", argv[count]);
	    pluralize (argv[count]);
	    printf("plural: %s\n\n", argv[count]);
		}
	}
	else
	{
		printf("ERROR: You must pass the nouns to be pluralized as program arguments");
	}
  
  /* return successfully */ 
  return 0; 
}

/* pluralize 
 * parameters: char word[] 
 * return values:  none, but word[] will be changed through this function 
 * functionality:  changes word[] to be the plural form of word[] 
 */

void pluralize (char word[]){ 
  
  /* declarations */ 
  int length;

  /* find length of word */ 
  length = strlen(word);

  /* check first rule:  if word ends in "y" then change to "ies" */ 
  if (word[length - 1] == 'y') { 
    word[length - 1] = 'i'; 
    word[length] = 'e'; 
    word[length + 1] = 's'; 
    word[length + 2] = '\0';   /* remember to put '\0' at end of string */ 
  } 
  
  /* check second rule:  if word ends in "s" "ch" or "sh" add "es" */ 
  else if (word[length - 1] == 's' || 
    (word[length - 2] == 'c' && word[length - 1] == 'h') || 
    (word[length - 2] == 's' && word[length - 1] == 'h')){ 
    /* concatenate "es" to word */ 
    strcat(word, "es"); 
  }

  /* otherwise, just add "s" to the end of word */ 
  else { 
    strcat(word, "s"); 
  } 
}
