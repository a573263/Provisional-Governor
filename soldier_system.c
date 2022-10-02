#include <stdio.h>
#include <stdlib.h>

void print_slowly(const char* text);



void set_soldiers()
{
    char *fname = "soldiers.txt";
    FILE *file_pointer = fopen(fname, "w");
    if(file_pointer == NULL) {
        fprintf(stderr, "Cannot open '%s'... Exiting\n", fname);
        exit(EXIT_FAILURE);
    }

    fputs("450", file_pointer);

    fclose(file_pointer);
}

void change_soldiers(int soldiers_lost)
{
    FILE* soldiersp;

    soldiersp = fopen("soldiers.txt", "r");

    char cur_soldiers[3];

    fgets(cur_soldiers, 4, soldiersp);

    fclose(soldiersp);

    int soldiers_num = atoi(cur_soldiers);

    soldiers_num -= soldiers_lost;

    itoa(soldiers_num, cur_soldiers, 10);

    soldiersp = fopen("soldiers.txt", "w");

    fputs(cur_soldiers, soldiersp);

    fclose(soldiersp);
    print_slowly("\nNow we only have ");
    print_slowly(cur_soldiers);
    print_slowly(" remaining!\n");
}

void print_soldiers()
{
    FILE* soldiersp;

    soldiersp = fopen("soldiers.txt", "r");
    char soldiers[3];

    fgets(soldiers, 4, soldiersp);
    print_slowly("(we have ");
    print_slowly(soldiers);
    print_slowly(" remaining)\n");

    fclose(soldiersp);
}

int give_soldiers() {
    char *fname = "soldiers.txt"; // make name prominent
    FILE *file_pointer = fopen(fname, "rt"); // local, so use local variable
    if(file_pointer == NULL) {
        fprintf(stderr, "Cannot open '%s'... Exiting\n", fname);
        exit(EXIT_FAILURE);
    }

    char str[32]; // Be generous
    str[0] = '\0'; // Is a 'string' even if source file is zero length
    fgets(str, sizeof str, file_pointer); // Should test for EOF condition, probably.

    fclose(file_pointer);

    return atoi( str ); // fgets() insures null terminated string
}
