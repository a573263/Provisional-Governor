#include <stdio.h>

void print_slowly(const char* text);

void tutorial()
{
    char player_nam[50];
    FILE *player_namp;
    player_namp = fopen("player_nam.txt", "r");

    fgets(player_nam, 51, player_namp);
    fclose(player_namp);

    print_slowly("Senior Camandas: Oh! Hello senior ");
    print_slowly(player_nam);
    print_slowly(". Even though it might sound weird, guiding our little colony\n is not as hard as you think! There will be officers during your 15 days of service as the Provisional Governor of San Rafael\nthat will bring you news about local events. You will either be asked to give them a number, or just answer to their questions with yes or no! As simple as that!\n\nIf you need any help, visit me at any time! Hope you will have an easy time ruling...\n\n\n");
}
