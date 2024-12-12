#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void password_gen(const unsigned int);
void help();

int main(int argc,char *argv[])
{
   for(int i=1;i<argc;i++)
   {
      if(strcmp(argv[i],"-h") == 0)
         help();
      else if(strcmp(argv[i],"-l") == 0)
      {
         if(i+1 < argc)
         {
            char *endptr;
            long number = strtol(argv[i+1],&endptr,10);

            if(*endptr != '\0')
            {
               printf("ERROR: This is not valid number %s\n",argv[i+1]);
               return 1;
            }
            else
            {
               unsigned int length = (unsigned int)number;
               if(length < 32 || length > 100)
               {
                  printf("ERROR: The number is not between 32 and 100\n");
                  return 1;
               }
               else
               {
                  printf("You entered -> %d\n",length);
                  password_gen(length);
               }
            }
         }
         else
         {
            printf("ERROR: after -l is not number valid\n");
         }
      }
   }
}

void password_gen(const unsigned int number)
{
   //created srand() function for random number
   srand(time(0));

   //set min and max value
   unsigned int min = 32,max = 126;

   for(int i=0;i<number;i++)
   {
      //created letter variable for integer number
      unsigned int letter;
      //created password array with length of the input value from the user
      char password[number];

      //generate random number between 32 and 126. Then write it to letter variable
      letter = (rand() % (max - min + 1) + min);

      //check if previous or last second character is equal to actuell character.
      //if yes, generate random number and write it to letter variable
      if(password[i-1] == password[i])
         letter = (rand() % (max - min + 1) + min);
      else if(password[i-2] == password[i])
         letter = (rand() % (max - min + 1) + min);

      //convert letter variable to char and write it to index of the password variable
      password[i] = (char)letter;

      //print to the console the generated character
      printf("%c",letter);
   }
}

//help sequence
void help()
{
   printf("   -l\tgive length for your password. Password length between 32 and 100\n");
   printf("   -h\tview the help sequence\n");
}
