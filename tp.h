typedef struct arbre *Tsystem;
struct arbre
{
    char Name[16];
    int rep;
    int size;
    struct arbre *son;
    struct arbre *bro;
};

typedef struct path *Tpath;
struct path
{
    char Name[16];
    struct path *next;
};

Tsystem creatTree(); // creating the main Tree

Tsystem addSon(Tsystem *l, char n[], int rep, int size); // adding a son to a main element in the Tree

Tsystem addBro(Tsystem *l, char n[], int rep, int size); // adding a brother to the son in the Tree

void printTree(Tsystem l); // printing the Tree

Tpath addToTree(Tpath l, char s[]); // adding a string at the end of the of any element in the Tree

int readPath(Tpath *l, char ch[], int *d); // reading a string that will be added to the tree using addToTree function

void skipSpace(char ch[], int *d); // a structure that skips spaces in any string

Tpath existingList(Tsystem l);

void scanstring(Tsystem l);
