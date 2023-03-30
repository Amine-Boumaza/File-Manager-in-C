#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

Tsystem creatTree() /*creating the main tree*/
{
    Tsystem p, r, t;
    Tsystem sys = malloc(sizeof(struct arbre));
    sys->rep = 1;
    strcpy(sys->Name, "/");
    sys->size = 0;
    sys->bro = NULL;
    sys->son = NULL;
    p = addSon(&sys, "bin", 1, 0);
    p = addBro(&p, "home", 1, 0);
    r = addSon(&p, "univGuelma", 1, 0);
    t = addSon(&r, "Desktop", 1, 0);
    t = addBro(&t, "documents", 1, 0);
    t = addBro(&t, "Download", 1, 0);
    p = addBro(&p, "root", 1, 0);
    p = addBro(&p, "run", 1, 0);
    return sys;
}

Tsystem addSon(Tsystem *l, char n[], int rep, int size) // adding the first son to the main elemnt in the main tree
{
    Tsystem sys = malloc(sizeof(struct arbre));
    sys->bro = NULL;
    sys->son = NULL;
    sys->rep = rep;
    sys->size = size;
    strcpy(sys->Name, n);
    if ((*l)->son == NULL)
    {
        (*l)->son = sys;
    }
    else
    {
        Tsystem r = (*l)->son;
        while (r->bro != NULL)
            r = r->bro;
        (r)->bro = sys;
    }
    return sys;
}

Tsystem addBro(Tsystem *l, char n[], int rep, int size) // adding brother to the son of the main element
{
    Tsystem sys = malloc(sizeof(struct arbre));
    sys->bro = NULL;
    sys->son = NULL;
    sys->rep = rep;
    sys->size = size;
    strcpy(sys->Name, n);
    if (*l == NULL)
    {
        *l = sys;
    }
    else
    {
        Tsystem r = (*l);
        while (r->bro != NULL)
            r = r->bro;

        (r)->bro = sys;
    }
    return sys;
}

void printTree(Tsystem l) // function to print the main tree and/or the changed tree
{
    if (l != NULL)
    {
        printf("%s\n", l->Name);
        printTree(l->son);
        printTree(l->bro);
    }
}

Tpath addToTree(Tpath l, char s[]) /*adding a new string to the end of any tree*/
{
    Tpath p = malloc(sizeof(struct path));
    p->next = NULL;
    strcpy(p->Name, s);
    if (l == NULL)
        l = p;
    else
    {
        Tpath q = l;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

int readPath(Tpath *l, char ch[], int *d) // reading a string that will be added to the tree using addToTree function
{
    int i = 0;
    int j = 0;

    if (ch[*d] != '\0')
        return -1;

    if (ch[*d] == ' ')
        return 0;
    else
    {
        (*d)++;
        j++;
    }

    if ((ch[*d] == '\0' || ch[*d] == ' ') && j == 1)
        return 2;
    else
    {
        char str[16];
        while ((ch[*d] != ' ' || j != 0) && ch[*d] != '\0')
        {
            if (ch[*d] == '/')
            {
                j = 0;
                (*d)++;
                str[i] = '\0';
                i = 0;
                *l = addToTree(*l, str);
            }
            else
            {
                j++;
                str[i] == ch[*d];
                i++;
                (*d)++;
            }
        }
        if (ch[*d] == '\0' && j != 0)
        {
            return 0;
        }
    }
}

void skipSpace(char ch[], int *d) // skip spaces in the opath list
{
    while (ch[*d] != '\0' && ch[(*d)] != ' ')
    {
        (*d)++;
    }
}

void scanstring(Tsystem l)
{

    Tsystem sys = l;
    gets(sys->Name);
    for (int i = 0; i < sizeof(sys->Name); i++)
    {
        if (sys->Name[i] == ' ')
            sys->Name[i] = sys->Name[i + 1];
    }
}
