//Arturo Gonzalez
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//place function prototypes here
void room28game(void);

int main(int argc, char *argv[])
{
	int choice = 0;
	char name[30] = "bob";
	srand(time(NULL));
	
	printf("Please enter your name: ");
	scanf("%s",name);
	printf("Hello %s welcome to the RPG Game!\n",name);
	while(choice != 99)
	{
		puts("You find yourself in a dark room and you are not sure how you got here.");
		puts("As you look around you see the room has 55 doors, each labeled with a number.");
		puts("The room starts filling with water and you must choose a door to open or you will likely drown. you may quit anytime by selecting option 99.");
		puts("What door do you choose?");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 28:
			{
				puts("room28");
				room28game();
				break;
		
			}
		}	
	}		
}

void room28game(void)
{
	srand(time(NULL));
	int choice;
	int paths[5] = {0};
	int keys = 0;
	int keys_collected[5] = {0};
	
	printf("\n - Room 28 Adventure - \n");
	printf("You enter the door labled 28. It is pitch black inside and you cautiously step inside.\n");
	printf("The moment you step in completey, the door behind you shuts. You are unable to see and you then drop and land in a cave.\n");
	printf("You recompose yourself and take aware of your surroundings. You see five branching paths, each lit by a torch.\n");
	printf("Each one contains a key. Collect all 5 keys and you will be able to escape.\n");
	
	while(keys < 5){
		printf("You currently have %d key(s).\n", keys);
		printf("Which path do you choose?\n");
		printf("1.The leftmost path.\n2.The path second from the left.\n3.The middle path.\n4.The path second from the right.\n5.The rightmost path.\n99.If you wish to exit completely.\n");

		while(scanf("%d", &choice) != 1 || choice < 1 || choice > 5){
			while(getchar() != '\n');
			if(choice == 99){
				printf("You decided to completely exit. Thank you for playing\n\n\n");
				return;
			}
			printf("Path a not a valid choice. Choose a from 1 to 5 or 99 to exit.\n");
			continue;
		}

		if(paths[choice - 1] == 1){
			printf("Path has already been explored and key aquired. Please choose another path.\n");
			continue;
		}

		paths[choice - 1] = 1;

		switch(choice){
			case 1:
			{
				int die_roll = (rand() % 20) + 1;
				int die_guess;
				bool correct = false;
				int low_bound = die_roll - 2;
				int up_bound = die_roll + 2;
				if(low_bound < 1) low_bound = 1;
				if(up_bound > 20) up_bound = 20;

				printf("You decide to go down the left most path.\n\n");
				printf("You reach the end of tunnel and enter an open space.\n");
				printf("In the middle of the room, you see a pecuilar old man.\n");
				printf("He calls to you.\" Hello friend, you look lost. I hold a key that will help you on your escape from these caves.\"\n");
				printf("\"I will give the key. BUT. You must best me at a game of chance. You must guess what number this 20 sided die will land on. I will make an exception that if you guess withtin 2 numbers of it, youw win.\".\n");
				printf("\"If you do not guess correctly. Then we will continue to play this game\".");
			
				do{
					printf("Guess what side the die will land on from 1 through 20. You may quit all thogeter by choosing 99.\n");
					if(scanf("%d", &die_guess) != 1 || die_guess < 1 || die_guess > 20){
						while (getchar() != '\n');
						if(die_guess == 99){
							printf("You decided to completely exit. Thank you for playing\n\n");
							return;
						}
						printf("Not a valid choice. Please choose a number from 1 to 20 or 99 to exit\n");
						continue;
					}

					else{
				
						if(die_guess >= low_bound && die_guess <= up_bound){
							correct = true;
							printf("\nThe die landed on %d. You guessed correctly or was within the correct range.\n", die_roll);
							printf("\"Well now, congrats. You did well and I shall let you continue onwards\".\n");
							printf("He hands you the key, he then immedialty crumbles into dust and disappears.\n");
							printf("+++++++ KEY ACQUIRED +++++++\n");
							printf("You then return the way you came.\n\n");
							break;
						}
			
						else{
							printf("\nYou guessed incorrectly nor were you within the correct range.\n");
							printf("\"Hohoho, try again there laddie\".\n");
						}
					}

				}
				while(!correct);
				keys_collected[keys] = choice;
				keys++;
				break;

			}

			case 2:
			{
				int heads_count = 0;
				int coin_guess;
				int coin_flip;
				
				printf("\nYou go down the path that is second from the left.\n");
				printf("You find your self in an open room and notice a robot looking lifeless in the center.\n");
			      	printf("It begins to boot up and glow with a blue hue.\n");
				printf("\"START UP SEQUENCE BEGIN\n10%%\n35%%\n57%%\n72%%\n92%%\n100%% BOOTED\n");
				printf("\"H3LL0 TRAVELER! 1 SHALL FL1P F1VE C01NS!\"\n");
				printf("\"Y0U MUST C0RRECTLY GUESS HOW MANY W1LL LAND 0N HEADS!\"\n");
				printf("\"GUESS CORRECTLY AND YOU W1LL BE G1VEN A KEY! 1F 1NC0RRECT, THE C01NS W1LL FL1P AGA1N!\"\n");
				printf("\"READY?? BEG1N!11!!!1\"\n");	
				
				do{
				printf("Guess how many heads from 1 to 5:\n");

				
				while(scanf("%d", &coin_guess) != 1 || coin_guess < 0 || coin_guess > 5){
					while (getchar() != '\n');
					if(coin_guess == 99){
						printf("You decided to completely exit. Thank you for playing.\n\n");
						return;
					}
					printf("Not a valid choice. Please choose a number from 1 to 5 or 99 to exit.\n");
					continue;
				}

				
					heads_count = 0;
					for(int i = 0; i < 5; i++){
						coin_flip = rand() % 2;
						if (coin_flip == 1){
							heads_count++;
						}
					}
						
					printf("The coins have been flip, heads apppears %d times out of 5.\n", heads_count);
						
					if(heads_count == coin_guess){
						printf("You guessed correctly!\n");
						printf("\"ERR0R ERR0R. N0T P0SS1BLE!!!1!!!1\"\n");
						printf("The robot explodes in to pieces and it drops the key from within its chassis.\n");
						printf("+++++++ KEY ACQUIRED +++++++\n");
						printf("You return the way you came.\n\n");
						break;
					}
					
					else{
						printf("\"1NC0RRECT. TRY AGA1N!\"\n");
						printf("\"FL1PP1NG C01NS AGA1N!\"\n");
						printf("Enter again.\n");

					}	
				}
			
				while(1);
				keys_collected[keys] = choice;
				keys++;
				break;

			}

			case 3:
			{
				printf("\nYou choose to go down the center middle path.\n");
				printf("You go down a path that leads to a dead end.\nAlthough you do notice an odd looking rock formation at the dead.\n");
				printf("Turns out it is a rock golem.\n");
				printf("\"Welcome puny human. I rocky. We play game. We have fun together!\".\n");
   				printf("\"I point in direction. You look away, you get point. We play 3 times\".\n");
				printf("\"Just for playing you get key. If human win 3 times, human get 2 keys\".\n");
				printf("\"OK. We go\".\n");

    				int direction_choice; 
				int opponent_choice;
    				int rounds = 3;
				int player_wins = 0;

    
    				for (int round = 1; round <= rounds; round++) {
        				printf("\nRound %d\n", round);

    
        				printf("Enter your choice (1 = up, 2 = right, 3 = down, 4 = left): ");
        				while (scanf("%d", &direction_choice) != 1 || direction_choice < 1 || direction_choice > 4) {
            					while (getchar() != '\n'); 
            					if(direction_choice == 99){
							printf("You decided to completely exit. Thank you for playing.\n\n");
							return;
							printf("Invalid input. Please enter a number between 1 and 4 for a direction.\n");
        					}	

					}
        				opponent_choice = rand() % 4 + 1; 
					
        
					printf("You chose: %d\n", direction_choice);
        				printf("The opponent chose: %d\n", opponent_choice);

	
        				if (direction_choice == opponent_choice) {
            					printf("\nYou looked in the same direction as the golem pointed! You lose this round.\n");
						printf("\"Haha. My win\".\n");
        				} 
					else {
            					printf("\nYou successfully avoided the golem's direction! You win this round!\n");
						printf("\"Wow. You good. You get point\".\n");
						player_wins++;
        				}
    					

				}

				if(player_wins == 3){
					printf("\"\nOk. Game done. Wow you are very good at game\".\n");
					printf("\"I happy to have new cool friend.\".\n");
					printf("\"I give 2 key now. Bye Bye friend\"!\n");
					printf("The rock golem then burrows itself into the wall of the tunnel.\n");
					printf("+++++++ TWO KEYS ACQUIRED +++++++\n");
					printf("You return the way you came.\n\n");
					keys_collected[keys] = choice;
					keys+= 2;
				}
				else{
					printf("\"\nOk. Game done. It was fun. Thank you new friend\".\n");
					printf("\"I give key now. Bye Bye friend\".\n");
					printf("The rock golem then burrows itself into the wall of the tunnel.\n");
					printf("+++++++ KEY ACAQURIED +++++++\n");
					printf("You return the way you came.\n\n");
    					keys_collected[keys] = choice;
					keys++;
				}

    				break;

			}

			case 4:
			{
				printf("\nYou decide to go down the path second from the right.\n");
			      	printf("This path leads to a pitch black room. You have no idea what is left from right.\n");
				printf("Suddenly a screeching cackle fills the room. A cauldourn lights up in the center and lights up the room dimly.\n");
				printf("\"Hello dearie. I am the Witch of truth. Answer me these 5 questions and see if they are true\".\n");
				printf("\"Since I am in good spirits. I shall reward you with a key no matter what\".\n");
				printf("\"Answer all 5 correctly, you shall recieve another key as well\".\n");	
    				printf("\"Shall we begin\"?\n");

    
   				 char *questions[5] = {
        				"The Earth is flat.",
   				     	"The capital of France is Paris.",
        				"Humans can breathe underwater without any equipment.",
        				"A year on Mars is longer than a year on Earth.",
        				"The moon is made of cheese."
    				};

    				int correct_answers[5] = {0, 1, 0, 1, 0}; 
    				int player_answers[5]; 
    				int correct_count = 0;  

    
    				for (int i = 0; i < 5; i++) {
        				printf("\n\"Question %d: True or False?\n %s\"\n", i + 1, questions[i]);
        				printf("Enter your answer (1 = True, 0 = False) or 99 to exit: ");
		
        
        
        				while (scanf("%d", &player_answers[i]) != 1 || (player_answers[i] != 0 && player_answers[i] != 1 && player_answers[i] != 99)) {
            					while (getchar() != '\n');
					       	if(player_answers[i] == 99){
							printf("You decided to completely exit. Thank you for playing.\n\n");
							return;
						}
            					printf("Invalid input. Please enter 1 for True or 0 for False: ");
        				}

        				if (player_answers[i] == correct_answers[i]) {
            					printf("\"Teeheehee. You're a smart one ain't ya. CORRECT\"!\n");
            					correct_count++; 
        				}

					else {
            					printf("\"WHAHAHAH. Wrong! The correct answer is %s\"\n", correct_answers[i] == 1 ? "True" : "False");
        				}
    				}

    
    				if (correct_count == 5) {
        				printf("\n\"Well now, it seems you know your stuff\".\n");
					printf("\"Congratulations on getting them all correct. As promised, here you go 2 keys\"\n");
					printf("\"I shall now bid you farewell. Good Luck on your journey\".\n");
					printf("The witch laughs one last time and transforms into a bat. Flying up high into the cavern.\n");
					printf("+++++++ 2 KEYS ACQUIRED +++++++\n");
					printf("You return the way you came.\n\n");
        				keys += 2; 
    				} 
				
				else {
        				printf("\n\"Well you got %d out of 5 questions correct.\n", correct_count);
					if(correct_count == 0){
						printf("\"I pity you for being completely wrong\".\n");
					}
					else{
						printf("\"You got some correct at least. Well done\".\n");
					}
					printf("\"I will still give you a key for your troubles\".\n");
					printf("\"I shall now bid you farewll. Good Luck on your journey\".\n");
					printf("The witch laughs one last time and transforms into a bat. Flying up high into the cavern.\n");
					printf("+++++++ KEY ACQUIRED +++++++\n");
					printf("You return the way you came.\n\n");
					keys++;  
    				}
    				
				break;
			}
			
			case 5:
			{
				printf("\nYou choose the rigntmost path.\n");
				printf("You make to the end of the path.\n");
				printf("Your nose burns with the stench of the most fowl smelling swamp.\n");
			    	printf("In the swamp, you encounter a dark elf who goes by the name of Ben C.\n");
				printf("\"Hey what's up, the name is Ben. I'm from upstate Colorado. I was Spanish professer onece.\".\n");
				printf("\"So anyway, I have this key I'm supposed to give away. Couldn't really think of a game for this\".\n");
				printf("\"Well I did see this one movie of these prisoners of war having to play sometype of roulette. So lets try that\".\n");	
				int rr_rounds = 6;
				int passes = 0;
				int survived_rounds = 0;
				int rr_choice;
				int survived = 1;
				
				while(1){
					survived_rounds = 0;
					printf("\"Okay round %d of %d\n", survived_rounds + 1, rr_rounds);
					printf("\"Do you want to take a hit or pass?\".\n");
					printf("To take a hit choose 1, to pass choose 2, or to quit all together choose 99\n");

					for(int i = 1; i <= rr_rounds; i++){
						while(scanf("%d", &rr_choice) != 1 || (rr_choice != 1 && rr_choice !=2)){
							while(getchar() != '\n');
							if(rr_choice == 99){
								printf("You decided to completely quit. Thank you for playing.\n\n");
								return;
							}
							printf("Not a valid choice. Please enter 1 or 2 to play. If you choose to exit, enter 99.\n");
							continue;
						}	

						if(rr_choice == 1){
							int hit = rand() % 6;
							if(hit == 0){
								printf("WHAM!!\n");
								printf("This round was a hit.\n");
								printf("\"Welp. Time to run it again\"!\n");
								survived = 0;
								break;
							}
							else{
								printf("*clunk*\n");
								printf("This round was not a hit.\n");
								printf("\"Nice, you managed to not get hit\".\n");
								survived_rounds++;
								printf("You have survived %d rounds so far.\n", survived_rounds);
							}
						}
						else if(rr_choice == 2){
							printf("You decided to pass the round in hopes of not getting hit.\n");
							printf("\"Aw man, that's weak sauce. Fine whatever\".\n");
							survived_rounds++;
							printf("You have survived %d rounds so far.\n", survived_rounds);
						
						}	
					}

					if(survived_rounds == rr_rounds){
						printf("You managed to survive all rounds!\n");
						printf("\"Okay, okay. You actually did it without getting hit\".\n");
						printf("\"I actually wasn't expecting you do it\".\n");
						printf("\"Well here's that key. I'll just be here.\nWaiting\".\n");
						printf("+++++++ KEY ACQUIRED +++++++\n");
						printf("You return the way you came from.\n\n");
						keys++;
						break;
					}
					else{
						printf("\"Looks like you lost. Run it again\"!\n\n");
					}
				
				}		
		
				break;
			}

			}		
		}

		if(keys >= 5){
			printf("All keys have been collected! As you exit the last tunnel a door has appeared allowing you to use the 5 keys.\n");
			printf("As you leave, a message appears before you.\n");
			printf("\"Thank you for playing!\"\n\n\n");
			
		}

}	
		




