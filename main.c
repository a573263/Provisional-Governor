#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int start_func(char input[]);
int event();
void set_soldiers();
void tell_story();
void dead(int days_in_service);
void print_slowly(const char* text);
void fprint_slowly(char text[], int interval);
void player_reg();
void tutorial();

int times_opened = 0;


int main()
{

    int success = 0;
    int days = 1;
    char starting[8];
    char skip_story[3];
    char skip_tutorial[3];

    if(times_opened == 0){
        printf("Provisional Governor\n\n");
    }
    while(1){
        int start = start_func(starting);
        if(start == 0){
            main();
        }
        else if(start == -1){
            break;
        }
        break;
    }
    player_reg();
    set_soldiers();

    printf("Would you like to skip the story? ");
    scanf("%s", skip_story);

    if(strcasecmp(skip_story, "yes") == 0){
        ;
    }
    else{
        tell_story();
    }

    printf("Would you like to skip the tutorial? ");
    scanf("%s", skip_tutorial);

    if(strcasecmp(skip_tutorial, "yes") == 0){
        ;
    }
    else{
        tutorial();
    }

    while(days < 15){
        char days_c[2];
        print_slowly("\n\nDAY ");
        itoa(days, days_c, 10);
        print_slowly(days_c);
        print_slowly(" IN SERVICE OF THE KING\n\n");


        if(days == 1){
            print_slowly("\n\n\nOof... it is my first day as the governor... I hope that there won't be any weird things happening...\n\n\n");
        }
        int event_ret = event();

        if(event_ret == 1){
            success = -1;
        }
        else{
            print_slowly("\n\nThat surely was a tiring day... let's get ready for the next one...");
        }

        if(success == -1){
            goto lost;
        }
        days++;
    }

    print_slowly("\n\n\n\n\nYou wake up early and go to the office. But when you arrive you see Senior Eleazar Rafinios in your chair!\nYour duty of ruling San Rafael is over! You can return to Spain as a low level officer of the King!\nWell done Provisional Governor!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


    lost:
        dead(days);

    return 0;
}

int start_func(char input[])
{
    printf("Where do you embark? ");
    scanf("%s", input);

    if(strcasecmp(input, "play") == 0){
        print_slowly("Captain: Alright sir! Senior Gonzalez left around 2 hours before, but\nthe King said that you can leave whenever you feel ready\n\n");
        return -1;
    }
    else{
        printf("Sir, that's not a valid destination! Try telling me again... ");
        return 0;
    }
}


void tell_story()
{
    char player_nam[50];
    FILE *player_namp;
    player_namp = fopen("player_nam.txt", "r");

    fgets(player_nam, 51, player_namp);

    fclose(player_namp);

    fclose(player_namp);
    print_slowly("\nCaptain: Alright, senior ");
    print_slowly(player_nam);
    print_slowly("! We will arrive at San Rafael in around 1 month!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    print_slowly("1 month later, in San Rafael, a small city close to Villahermosa...\n");
    print_slowly("It is very late, around 03:00. You have just arrived in the city\nYou are too tired to actually meet with senior Gonzalez, so you sleep in the ship\n");
    print_slowly("In the next morning, you woke up at 10:25.\nYou urged to go to senior Gonzalez's office. You arrived in the office but there was nobody there.\nYou asked several secretaries in the office but nobody remembered of senior Gonzalez arriving.\nYou thought of asking the people in the streets, when the captain met you...");
    print_slowly("Captain: Oh... senior ");
    print_slowly(player_nam);
    print_slowly("... or should I say, Provisional governor of San Rafael?\n");
    print_slowly("You: What? What is this which you are saying? Where is senior Gonzalez?\n");
    print_slowly("Captain: Senior Gonzalez's ship was plundered by pirates close to Hispaniola.\nAnd because San Rafael can't remain without a governor, the King decided to bring senior Eleazar Rafinios.\nThe problem is that he will arrive in 15 days, as he was a local army general in Managua.\nSo for those 15 days you need to take control of San Rafael, as you have the highest rank, among the officers of senior Gonzalez.\n");
    print_slowly("You: So... how am I going to do this?\n");
    print_slowly("Captain: Ah! Don't worry! Jorje Camandas will teach you how to give orders! You will meet him in the office.\n\nCaptain: I know... it might be tough. You are very young and it is a big responsibility, but you must do it!\n I wish you the best of luck! I have to leave. I will go to Miami, but I wil make sure to hear how you did as the provisional governor!\n Farewell ");
    print_slowly(player_nam);
    print_slowly(" Provisional Governor of San Rafael!\n\n\n\n");
    print_slowly("You went to the office to meet Senior Camandas\n\n");
}

void dead(int days_in_service)
{
    print_slowly("You tried ruling the small San Rafael but failed... Eitherway it was an honor!\nAnd of course... don't forget that you can always try again...");
}











void print_slowly(const char* text)
{
    int i;

    for(i = 0; text[i] != '\0'; i++){
        printf("%c", text[i]);
        Sleep(95);
    }
}

void fprint_slowly(char text[], int interval)
{
    int i;

    for(i = 0; text[i] != '\0'; i++){
        printf("%c", text[i]);
        Sleep(interval);
    }
}
