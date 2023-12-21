// * lesson on how to create structs

#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main (void)
{
    person people[2];
    people[0].name = "Brandon";
    people[0].number = "96981234";
    people[1].name = "Yuan En";
    people[1].number = "84347912";


    string name = get_string("What name are you trying to find? :");

    for (int i = 0; i < 2;i++)
    {
        if (strcmp(people[i].name,name) == 0)
        {
            printf("Found %s\n",name);
            printf("number: %s\n", people[i].number);
        }
    }
}
