#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void print_slowly(const char* text);
int give_soldiers();
void print_soldiers();
void change_soldiers(int soldiers_lost);
int wrong_soldiers_check(int soldiers);
int check_for_negative_soldiers(int soldiers);
int generic_attack();
int british_attack();
void clean();
int checking_alpha(int soldiers);


int misheard = 10;

int event()
{

    const char* misheard_message = "...I beg your pardon? Senior I don't understand... Please let me say the question again\n";

    int success_check = 0;
 //   char events[6][50] = {"Foreign Traders want to be allowed in the port", "Pirates in the near area", "Animals ruin crops!", "Local Rebels", "Mutinies in the local force!", "British forces get ready for battle!!!"};

    srand(time(NULL));

    int rand_num = 1;

    if(misheard == 0){
        rand_num = 0;
    }
    else if(misheard == 1){
        rand_num = 1;
    }
    else if(misheard == 2){
        rand_num = 2;
    }
    else if(misheard == 4){
        rand_num = 4;
    }


    if(rand_num == 0){
        char ans[3];
        int rand_traders = rand() % 4;
        char countries[4][20] = {"British", "Dutch", "Portuguese", "Danish"};
        print_slowly("Senior! Some ");
        print_slowly(countries[rand_traders]);
        print_slowly(" want to be allowed in the port! Should we allow them? ");

        scanf("%s", ans);

        if(strcasecmp(ans, "yes") == 0){
            int possibilities = rand() % 10;

            if(possibilities < 9){
                print_slowly("\nThey were not traders! They were special forces of our enemies, who showed themselves as traders!\nThe whole city was burnt, and you did together with it...");
                success_check = 1;
            }
            else{
                print_slowly("\nThe merchants entered the city peacefully and traded with the locals");
                return 0;
            }
        }
        else if(strcasecmp(ans, "no") == 0){
            print_slowly("\nWe didn't allow the merchants to enter");
            return 0;
        }
        else{
            print_slowly(misheard_message);

            misheard = 0;
            event();
        }
    }
    else if(rand_num == 1){
        char ans[3];
        print_slowly("Senior! Pirates have been seen in the near area! Should we send men to fight them or not? ");

        scanf("%s", ans);

        if(strcasecmp(ans, "yes") == 0){
            int possibilities = rand() % 10;

            int soldiers = generic_attack();



            if(possibilities < 7 && soldiers >= 100){
                print_slowly("Our army emerged victorious! The ships of the pirates are now house for the fish!\n");
                return 0;
            }
            else if(possibilities < 7 && soldiers < 100 && soldiers != 0){
                int men_lost = rand() % 85;
                print_slowly("The pirate ships were beaten... but we had some losses the battle was tough and we lost some men...\n");

                if(men_lost > soldiers){
                    men_lost = soldiers;
                }

                change_soldiers(men_lost);
                print_soldiers();
                return 0;
            }
            else{
                print_slowly("No matter how hard we fought the battle was lost...\n\n");
                success_check = 1;
            }

        }
        else if(strcasecmp(ans, "no") == 0){
            int possibilities = rand() % 10;

            if(possibilities < 8){
                print_slowly("The pirates plundered the city and massacred the citizens. You were killed together with everyone else...\nSan Rafael became a big pirate haven");
                success_check = 1;
            }
            else{
                print_slowly("We are lucky! The pirates left the nearby waters... what a relief! Right Senior?");
                return 0;
            }
        }
        else{
            print_slowly(misheard_message);

            misheard = 1;
            event();
        }
    }
    else if(rand_num == 2){
        char ans[3];

        print_slowly("Many locals have been making requests for a small defence force to defend crops from some wild ");
        int rand_animals = rand() % 4;
        char animals[4][20] = {"boars", "wolves", "lizards", "crows"};
        print_slowly(animals[rand_animals]);

        if(give_soldiers() != 0){
        print_slowly("\nShould we agree?\n");
        print_slowly("You: ");
        scanf("%s", ans);


        if(strcasecmp("yes", ans) == 0){
            print_slowly("Ok! I will make sure the guards take place");
            return 0;
        }
        else if(strcasecmp(ans, "no") == 0){
            print_slowly("Alright Senior! I understand you may not want to send useful soldiers in such a small mission!");
            return 0;
        }
        else{
            print_slowly(misheard_message);

            misheard = 2;
            event();
        }

    }
    else{
        print_slowly("\nBut since we have 0 soldiers we can't do something about it");
    }

    }
    else if(rand_num == 3){
        int possibilities = rand() % 10;

        print_slowly("Senior! Senior! Some locals have started some sort of 'rebellion'!\nWe can't wait for reinforcements from the crown right now! We will use our guards!\n");

        int soldiers = generic_attack();



        if(soldiers >= 200 && soldiers != 0 && possibilities < 6){
            print_slowly("The battle was hard but we won! It is a miracle that there were no dead guards!");
            return 0;
        }
        else if(soldiers >= 200 && soldiers != 0 && possibilities >= 6){
            int men_lost = rand() % 170;

            print_slowly("We won the battle, but with severe losses... it was very hard\n");
            if(men_lost > soldiers){
                men_lost = soldiers;
             }

            change_soldiers(men_lost);
            print_soldiers();
            return 0;
        }
        else{
            print_slowly("The rebels have succeeded... You managed to escape to Spain, but The King\n decided that you will be killed for your insufficient ruling");
            success_check = 1;
        }
    }
    else if(rand_num == 4){

            if((give_soldiers()) == 0){
                event();
            }

            char ans[3];
            print_slowly("Senior! There are a few soldiers of the guard that want a rise\n on their payment... should we give it?\n");
            print_slowly("You: ");
            scanf("%s", ans);

            if(strcasecmp(ans, "yes") == 0 || strcasecmp(ans, "no") == 0){
                print_slowly("Ummm... ok sir! I will make sure your commands will be followed!");
                return 0;
            }
            else{
                print_slowly(misheard_message);

                misheard = 4;
                event();
            }

    }
    else if(rand_num == 5){
        int soldiers;

        print_slowly("A young man enters your office...\n\n");
        print_slowly("SENIOR! SENIOR! There are british forces that are getting ready for battle near the city!\n");

        soldiers = british_attack();

        if(soldiers > 300){
            int men_lost = rand() % 150;
            print_slowly("The men were just enough to defend against the enemy! Yet, we had some losses...");

            if(men_lost > soldiers){
                men_lost = soldiers;
            }

            change_soldiers(men_lost);
            return 0;
        }


        else{
            print_slowly("The men were too few to defend the city. The british slaughtered all the officers... including you...\n");
            success_check = 1;
        }
    }

    return success_check;
}

int wrong_soldiers_check(int soldiers)
{

    int de_facto_soldiers = give_soldiers();
    int ret_value = 0;

    char soldiers_c[3];

    itoa(soldiers, soldiers_c, 10);

    if(((isdigit(soldiers_c[0]) == 0) && (soldiers_c[0] != '\0')) || ((isdigit(soldiers_c[1]) == 0) && (soldiers_c[1] != '\0')) || ((isdigit(soldiers_c[2]) == 0) && (soldiers_c[2] != '\0'))){ // isdigit considers '-' as a non numeric character so it serves both on not allowing the user to enter letters but also a negative number or even both
        print_slowly("Senior the situation is urgent! Please answer seriously! ");

        ret_value = 1;
    }
    if(de_facto_soldiers < soldiers){
        print_slowly("Senior! We don't have so many soldiers! Let me ask you again...");

        ret_value = 1;
    }

    return ret_value;
}


int generic_attack()
{
    int soldiers;


    if(give_soldiers() == 0){
        print_slowly("Senior... I just checked the last reports... we have no soldiers... Oh no this is terrible! What are we going to do?\n");
        soldiers = 0;
    }
    if(give_soldiers() != 0){
        do{
            print_slowly("\nAlright! How many men should we send?\n");
            print_soldiers();
            print_slowly("You: Let's send ");
            clean();
            scanf("%3d", &soldiers);
        }while(wrong_soldiers_check(soldiers) == 1);

    }

    return soldiers;
}

int british_attack()
{
    int soldiers;

    if(give_soldiers() == 0){
        print_slowly("Senior... I just checked the last reports... we have no soldiers... Oh no this is terrible! What are we going to do?\n");
        soldiers = 0;
    }

    if(give_soldiers() != 0){
        do{
            print_slowly("The field marshal asked me how many men should we send to the field... What should I say to him?\n");
            print_soldiers();
            print_slowly("You: Let's send ");
             clean();
            scanf("%3d", &soldiers);
        }while(wrong_soldiers_check(soldiers) == 1);
    }

     return soldiers;
}

void clean()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {  //keeps picking and discarding and picks up the unneeded character
        ;
    }
}
