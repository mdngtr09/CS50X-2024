// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for your name and where live
    string name;
    string location;

     name = get_string("What is your name? ");
     location = get_string("Where do you live? ");

    // Say hello
    printf("Hello, %s, from %s!", name, location);
}
