//Made by Robert
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
char name[50];
int choiceOne_Path; //I put the choice variables here, outside of any function, because I want them callable from anywhere within the adventure as old choices can affect new ones

void choice_One() {
retry: //Retry allows the function to loop back in case of player failure, or an input was placed that the game didn't like.
	cout << ">You hear your heart beating through your ears" << endl;
	cout << ">You're scared. The world around you deafens. Knowing the threat and where you are, you only have 2 real choices..." << endl;
	cout << "# Choose your fate" << endl;
	cout << "\t >> Enter '1' to jump out the window" << endl;
	cout << "\t >> Enter '2' to run out the door" << endl;
	cout << "\nEnter your choice: ";
	cin >> choiceOne_Path;
	if (choiceOne_Path == 1) //This choice moves the game forward
	{
		cout << "\n!!!----------------------Chapter One: Escape----------------------!!!" << endl;
		cout << "\n>You hear a sound of goblins running up your stairs" << endl;
		cout << ">In a panic, you open your second story window and peer to the world below" << endl;
		cout << ">Screaming townsfolk, billowing flames, and the clatter of weaponry invade your ears." << endl;
		cout << ">You look at to the neighboring homes and see rooftops you can access" << endl;
		cout << ">With a courageous leap, you fly out your window and land on the thatched rooftops, softening your landing" << endl;
		cout << ">No time to rest, thatch can catch on fire" << endl;


	}
	else if (choiceOne_Path == 2) //This choice ends with the player's death and calls for a retry
	{
		cout << "\n!!!----------------------Chapter One: Escape----------------------!!!" << endl;
		cout << "\n>In a panic, with no thought, you open the door exiting the room" << endl;
		cout << "???: Did you hear that? Fresh meat!" << endl;
		cout << ">Before you even had a chance to panic" << endl;
		cout << ">Before you can scream" << endl;
		cout << ">The last thing you see is a green abomination laughing as your vision blurs and fades to black" << endl;
		cout << "You have died." << endl;
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();
		cout << "\033[2J\033[1;1H"; //Clears the screen. OS agnostic
		goto retry; //Restarts from the last choice. Contained within the function, so it's usable with all binary choice events

	}
	else
	{
		cout << "\033[2J\033[1;1H"; //Clears screen to make fail state more legible
		cout << ">You're panicked. You keep thinking of what if's instead of the choice laid bare in front of you" << endl; //If the player doesn't input an accepted character
		cout << ">You have to make a choice to ensure your own survival" << endl;
		cout << "\n----------------------Press any key to continue----------------------" << endl;
		_getch();
		cout << "\033[2J\033[1;1H";
		goto retry;
	}

	cout << "\n----------------------Press any key to continue----------------------" << endl;
	_getch();
}

int main()
{
	
	cout << "What is thy name?" << endl;
	cin.getline(name, 50); 
	//This allows name input, up to fifty characters. Need to figure out a way to physically limit key presses past the limit. Currently only ignores characters past 50
	cout << "What is that noise? " << name << "! The goblins are attacking the city!" << endl;
	cout << "\n----------------------Press any key to continue----------------------" << endl;
	_getch(); //This allows the press any key to continue. Getch just passes in any input to continue
	cout << "\033[2J\033[1;1H"; //OS agnostic way to clear the screen. Should work with Linux and Mac with testing on a VM
	choice_One(); //Calls on the first choice, goes through that function, and returns here when it completes outside the loop through its Getch
	return 0;
}


