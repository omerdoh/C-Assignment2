/*********************************/
 /* Name: Game_Functions.c */
 /* Vr. 1.0 */
 /* Author: Nathan Fan, Sifat Jamaly */
 /* Student number: 040989678, 040842225 */
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Assignment 2 */
 /* Dice Game */
 /* Due: 12/10/2020 */
 /* Submitted: 12/10/2020 */
 /* Professor: Natalie Gluzman */
 /* This file contains the game functions for running a dice simulation*/
 /**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WON 0
#define LOSE 1

extern int total, pointMatch, win, lose, totalAmountChanged , roundBet, currentHolding;

/*******************************************************************************************************************************/
/* rollDice */
/* This simulates a random roll of the dice */
/* Input: N/A */
/* Output: random number from 1-6 */
/* vr. 1.0 */
/* Nathan Fan, Sifat Jamaly */
/*******************************************************************************************************************************/
int rollDice () {
    int dice = (1 + rand() % 6);
	return dice;	
}
                        
/*******************************************************************************************************************************/
/* playGame */
/* This function rolls the dice and compares the values to determine win or loss*/
/* Input: N/A */
/* Output: WON for win and LOSE for loss*/
/* vr. 1.0 */
/* Nathan Fan, Sifat Jamaly */
/*******************************************************************************************************************************/
int playGame() {
	
	int dice1, dice2, sum, pointMatch, stopPlaying, rollNum = 1;

	/*seeding random number with time so its different each time*/
	srand(time(NULL));
	printf("\n                     ROLL THE DICE [ENTER]\n\n");

	/*roll the two dice and add the results*/ 
	dice1 = rollDice();
	dice2 = rollDice();
	sum = dice1 + dice2;
	pointMatch = sum;

	/*print statement with format*/
	printf("------------------------------------------------------------------------\n");
	printf(" ROLL NUM     DICE #1     DICE #2     TOTAL ROLL     POINT MATCH\n");
	printf("------------------------------------------------------------------------\n");

	/*printing the numbers so far*/
	printf("%9d %11d %11d              %d              %d\n", rollNum, dice1, dice2, sum, pointMatch);

	/*win if first roll is a 7 or 11*/
	if (sum == 7 || sum == 11) {
		printf("\nCongratulations you roll %10d and WON at your first try" , sum);
		win++;			
		return WON;
	
	/*game is lost if roll is 2, 3, or 12*/			
   	} else if (sum == 2 || sum == 3 || sum == 12) {
		printf("\nSorry, you roll %10d and you lose!!!" , sum);
		lose++;				
		return LOSE;
				
	} else {
		/*if neither top conditions activate*/
		/*the pointMatch is used*/
        rollNum = 1;	
		do {
			dice1 = rollDice();
			dice2 = rollDice();
			sum = dice1 + dice2;
			rollNum++;

			printf("        %d           %d           %d              %d              %d				\n", rollNum, dice1, dice2, sum, pointMatch);

            /* losing conditions */
			if (sum == 2 || sum == 3 || sum == 12) {
				printf("\nSorry, you roll %10d and you lose!!!" , sum);
				lose++;				
				return LOSE;

            /* winning conditions */
			} else if (sum == pointMatch) {
				printf("\nCongratulations! You have won with a roll of %3d." ,							sum);
				win++;						
				return WON;	
	    	}
		
		/*keep playing until win or lose condition*/				
		} while (stopPlaying != WON || stopPlaying != LOSE);			
				
		return;			
	}		
}

/*******************************************************************************************************************************/
/* bettingChanges */
/* This functions makes the appropriate changes to the accounts based on the rolls */
/* Input: result of the match*/
/* Output: N/A */
/* vr. 1.0 */
/* Nathan Fan, Sifat Jamaly */
/*******************************************************************************************************************************/
void bettingChanges(int result){
    printf("\nBetting results of the round:");
    
    /* player has won */ 
    if (result == WON){
        currentHolding += (2 * roundBet);
        totalAmountChanged += (2 * roundBet);
        printf(" Player has won $%d", 2 * roundBet);
    }
    /* player has lost */
    else {
        currentHolding -= roundBet;
        totalAmountChanged += roundBet;
        printf(" Player has lost $%d", roundBet);
    }
}

/*******************************************************************************************************************************/
/* endingMessages */
/* This function prints the ending statements of the program based on the player's performance */
/* Input: N/A */
/* Output: N/A */
/* vr. 1.0 */
/* Nathan Fan, Sifat Jamaly */
/*******************************************************************************************************************************/
void endingMessages(){
    /*Exiting message*/
	printf("\n\nThank you for playing!\n");
	printf("You won %1d games and lost %d games!\n", win, lose);
    printf("\nA total of $%d amount was won/lost in %d rounds.", totalAmountChanged, win+lose);

	/* statement depending on win/loss */
   	(win > lose) ? (printf("\nWhat a winner!\n")) : (printf("\nBetter luck next time!\n")) ;
}