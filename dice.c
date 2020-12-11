 /* Nathan Fan, Sifat Jamaly */
 /* 040989678, 040842225 */
 /* Assignment 2*/
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Natalize Gluzman */
 /* Due: 12/10/2020 */
 /* Submitted: 12/10/2020 */
 /* Includes: dice.c, Game_Functions.c, Game_Functions.h, Makefile */
/**************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game_Functions.h"

int total, win = 0, lose = 0, totalAmountChanged = 0, roundBet, currentHolding = 20;

/*******************************************************************************************************************************/
/* main */
/* This main function simulates a dice rolling game */
/* Input: N/A */
/* Output: EXIT_SUCCESS */
/* vr. 1.0 */
/* Nathan Fan, Sifat Jamaly */
/*******************************************************************************************************************************/
int main () {
   	char decide; 
   
    /* loops until user quits */
    do{
        printf("\n\nCurrent holdings: $%d", currentHolding) ;
        
        /* player lacks the holdings to play */
        if (currentHolding <= 0){ 
            printf("\nPlayer does not have the necessary funds to continue. Exiting.");
            break;
        }

        /* ask user to play and get answer */
        (win + lose == 0) ? (printf("\nWould you like to play? [y/n]: ")) : (printf("\nAnother Game? [y/n]: ")) ;
        decide = getchar();
        
        /* flush out unnecessary input */
        int ignore;
        while ( (ignore = getchar()) != '\n' && ignore != EOF );

        /* user chooses to play */
        if (decide == 'y' || decide == 'Y'){

            /* loop until correct bet amount */      
            do {
                printf("\nHow much would you like to bet on this round? (multiples of 5): ");

                /* ensure numeric bet */
                if ( scanf("%d", &roundBet) != 1 ){
                    printf("\nPlease enter integer input\n");
                    while ( (ignore = getchar()) != '\n' && ignore != EOF );
                    continue;
                }
                /* incorrect betting amount */
                if (roundBet % 5 != 0) { printf("\nPlease ensure that the bet is in multiples of 5\n");}
                if (roundBet > currentHolding) { printf("\nPlease ensure that the bet is lesser than or equal to current holdings ($%d)\n", currentHolding);}
            } while (roundBet % 5 != 0 || roundBet > currentHolding);

            /* play match and tally/print the results */	
            bettingChanges(playGame());
        }
        /* extraneous choice */
        else if (decide != 'y' && decide != 'Y' && decide != 'n' && decide != 'N'){
            printf("\nPlease only enter y for continue and n for quit");
        }

    } while (decide != 'n' && decide != 'N');

    /* print quit statements */
    endingMessages();
	
    return EXIT_SUCCESS;
}
