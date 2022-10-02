#include <stdio.h>
#include <sys/stat.h>

void print_slowly(const char* text);

void player_reg()
{
    mkdir("Provisional Governor");

    char player_name[50];
    print_slowly("Captain: So, what's your name Senior?\nYou: My name is Senior ");
    scanf("%s", player_name);

    FILE *player_namep;
    player_namep = fopen("player_nam.txt", "w");

    fputs(player_name, player_namep);


    fclose(player_namep);
}
