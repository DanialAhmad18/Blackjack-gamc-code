//Danial Ahmad
//BSCS 8-B
//249912

#include <stdio.h>
#include<stdlib.h>

char cards[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'J', 'Q', 'K' };
int valueOfCards[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 11, 10, 10, 10, 10 };

int player = 0;//Number of games player has won 

int dealer = 0;//Number of games dealer has won 
int i, j, sum_player, sum_dealer;

char choice = ' ';

char player_hand[20] = { ' ' };//All the cards in the hand of the player

char dealer_hand[20] = { ' ' };//All the cards in the hand of the player

int counter1 = 0;

int counter2 = 0;

void player_turn();

void dealer_turn();

void winner();

void playerHand();

void dealerHand();

void points();

int main(){
	srand(time(NULL));
	char play = ' ';

	while (play != 'q')
	{
		counter1 = 0;
		counter2 = 0;
		i = 0;
		j = 0;
		sum_player = 0;
		sum_dealer = 0;
		choice = ' ';

		player_turn();

		if (sum_player > 21)
		{
			printf("\nYou BURST ! \n The dealer wins !");
			dealer++;
		}
		else
		{
			dealer_turn();

			if (sum_dealer> 21)
			{
				printf("\n The dealer BURSTS !\n");
			}
			winner();//The function to check the winner is called.
		}
		points();

		printf(" \nEnter q to quit, anything else to play another hand : ");
		scanf(" %c\n", &play);

	}
	points();
	


}

void player_turn()

    {
	i = rand() % 13;
	player_hand[counter1] = cards[i];//The first card the player receives
	counter1++;
	sum_player = sum_player + valueOfCards[i];

	i = rand() % 13;
	player_hand[counter1] = cards[i];//The second card the player receives
	if (sum_player > 10)
	{
		valueOfCards[0] = 1;
	}

	sum_player = sum_player + valueOfCards[i];//The total sum of the values of all cards at this point
	valueOfCards[0] = 11;

	printf("\n Player's Hand : ");
	playerHand();//Displays all the cards player currently have. 
	counter1++;

	printf("\n Dealer's Hand : ");

	j = rand() % 13;
	dealer_hand[counter2] = cards[j];//The first card the dealer receives
	dealerHand();
	counter2++;
	printf(" X");//This card of the dealer is not revealed.
	sum_dealer = sum_dealer + valueOfCards[j];//The total sum of the value of the cards dealer have at this point 

	printf("\nEnter command ('s' to stay and 'h' to hit): ");
	scanf(" %c", &choice);

	while (choice != 's' && choice != 'S' && sum_player <= 21)//The loop runs until the player choses to stay and the sum of his cards excedes 21.
	{
		i = rand() % 13;
		player_hand[counter1] = cards[i];//Player picks a card
		printf("\n Player's Hand : ");
		playerHand();
		counter1++;
		if (sum_player > 10)
		{
			valueOfCards[0] = 1;
		}
		sum_player = sum_player + valueOfCards[i];
		valueOfCards[0] = 11;

		if (sum_player > 21)
		{
			break;
		}

		printf("\n Enter the command (s to stay and h to hit ): ");
		scanf(" %c", &choice);

	}
	printf("\nYour sum is %d", sum_player);

}

void dealer_turn()
{
	while (sum_dealer <= 17 && sum_dealer <= sum_player)
	{
		printf("\n Dealer's Hand : ");
		j = rand() % 13;
		dealer_hand[counter2] = cards[j];//Dealer picks a card.
		dealerHand();//All the cards in the hand of the dealer is displayed.
		counter2++;
		if (sum_dealer > 10)
		{
			valueOfCards[0] = 1;

		}
		sum_dealer = sum_dealer + valueOfCards[j];
		valueOfCards[0] = 11;

	}
	printf("\n The dealer's sum is %d ", sum_dealer);

}

void winner()//This fuction is used the winner.
{
	if (sum_dealer >= sum_player && sum_dealer < 22)
	{
		dealer++;
		printf("\n Dealer Wins");
	}
	else
	{
		player++;
		printf("\n You Wins");

	}
}

void playerHand()//This function is used to display all the cards in the hand of the player.
{
	int k;
	for (k = 0; k <= counter1; k++)
	{
		if (player_hand[k] == cards[10])
		{
			printf(" 10 ");
		}
		else
			printf(" %c ", player_hand[k]);
	}

}

void dealerHand()//This function is used to display all the cards in the hand of the dealer.
{
	int d;
	for (d = 0; d <= counter2; d++)
	{
		if (dealer_hand[d] == cards[10])
		{
			printf(" 10 ");
		}
		else
			printf(" %c ", dealer_hand[d]);
	}
}
void points()//This function is used to to display the total score
{
	printf(" \n\t\t Total score\n \t\t Player = %d \n \t\t Dealer = %d ", player, dealer);
}
