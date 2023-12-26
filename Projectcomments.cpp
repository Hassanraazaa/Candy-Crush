#include<iostream>	 //Standard C++ header file that contains declarations for input and output.
#include<Windows.h>  // headerfile for Windows-specific functions, constants, and data types(eg. ,GetStdHandle,SetConsoleTextAttribute, HANDLE )
#include<fstream>	 //header file for file handling functions
#include<conio.h>	 //headerfile for Console input/output functions (e.g., getch, clrscr)
#include<cstring>	 // headerfile for C-style string manipulation functions(eg. , char[] etc)
#include<string>	 //headerfile for C++ string class and its functions
#include<ctime>	     // headerfile  time and date functions and structures
using namespace std; /*The Standard C++ Library (STL) places its elements, such as cout, cin, string, etc.,
					 within the std namespace.as a standard to not write std:: multiple times*/
#define KEY_UP 72	 // defiined constant KEY_UP represent the ASCII code 72  for corresponds to arrow key code on a keyboard when pressed
#define KEY_DOWN 80	 // defiined constant KEY_DOWN represent the ASCII code 80  for corresponds to arrow key code on a keyboard when pressed
#define KEY_LEFT 75	 // defiined constant KEY_LEFT represent the ASCII code 75  for corresponds to arrow key code on a keyboard when pressed
#define KEY_RIGHT 77 // defiined constant KEY_RIGHT represent the ASCII code 77  for corresponds to arrow key code on a keyboard when pressed
char crushrand(char cand)
{ // Function to generate a random character for a 2D-array (easy mode)
	int c;
	c = rand() % 5 + 1; // Generate a random number between 1 and 5
	// Assign specific characters to the variable 'cand' based on the random number
	if (c == 1)
		cand = '@'; // If 'c' is 1, assign '@' to 'cand'
	else if (c == 2)
		cand = '#'; // If 'c' is 2, assign '#' to 'cand'
	else if (c == 3)
		cand = '$'; // If 'c' is 3, assign '$' to 'cand'
	else if (c == 4)
		cand = '%'; // If 'c' is 4, assign '%' to 'cand'
	else if (c == 5)
		cand = '&'; // If 'c' is 5, assign '&' to 'cand'
	return cand; // Return the generated character
}
char crushrandhard(char cand) { // creates random key in 2D-array hard mode
	int c;
	c = (rand() % 7) + 1;
	if (c == 1)
		cand = '@';
	else if (c == 2)
		cand = '#';
	else if (c == 3)
		cand = '$';
	else if (c == 4)
		cand = '%';
	else if (c == 5)
		cand = '&';
	else if (c == 6)
		cand = '!';
	else if (c == 7)
		cand = '*';
	return cand;
}
void fill(char arr[8][8])
{
	char cand = ' '; // Initialize a character 'cand' with space (' ')
	
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (arr[x][y] == ' ') // Check if array element has a space value
			{
				// Replace the space value with a randomly generated candy
				arr[x][y] = crushrand(cand);

				// Check for matching candies in various directions (horizontal, vertical, diagonal)
				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||			// column-wise horizontal
					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] ||			// row-wise vertical
					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || // forward diagonal
					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])	// backward diagonal
				{
					// If there is a match after replacing, replace again with another random candy
					char c = ' ';
					arr[x][y] = crushrand(c);
				}
			}
		}
	}
}
void fillhard(char arr[10][10]) // check if array element has space value and replace with random candy it is executed after swpspacehard function
{
	char cand = ' ';
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = crushrandhard(cand);
				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||//column wise horizontal
					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] || // row wise vertical
					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || //forward diagonal
					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])  //backward diagonal
				{
					arr[x][y] = crushrandhard(cand);
				}
			}
		}
	}
}
void FILLcandies(char arr[8][8])
{
	char c = ' '; //*it will not effect in this code if we remove it

	// Loop through each cell in the 8x8 array
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// Fill each cell with a randomly generated candy
			arr[i][j] = crushrand(c);

			// Check for immediate matches in all directions after filling
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					// Check for matching candies in various directions (horizontal, vertical, diagonal)
					if (
						arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||			// column-wise horizontal
						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] ||			// row-wise vertical
						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1] || // forward diagonal
						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1]	// backward diagonal
					)
					{
						// If there is a match after filling, replace the candy again with another random candy
						char ch = ' ';
						arr[i][j] = crushrand(ch);
					}
				}
			}
		}
	}
}
void FILLcandieshard(char arr[10][10])    // fill random cadies in table for 1st time hard mode
{
	char c = ' ';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			arr[i][j] = crushrandhard(c);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] ||//column wise horizontal
						arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] || // row wise vertical
						arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1] || //forward diagonal
						arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])  //backward diagonal
					{
						char ch = ' ';
						arr[i][j] = crushrandhard(ch);
					}
				}
			}
		}
	}
}
void swpspaceEASY(char arr[8][8])
{
	// Loop through each cell in the 8x8 array
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == ' ') // Check if the array element has a space value
			{
				int l = i, m = j; // Initialize variables l and m with current indices

				// Shift elements above the space to move the space character towards the top
				while (l > 0) // While l (row index) is greater than 0
				{
					arr[l][m] = arr[l - 1][m]; // Move the element above to the current position
					l--;					   // Move to the row above
				}
			}
		}
	}
}
void swpspaceHARD(char arr[10][10]) //swap spaces to top in hard mode 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == ' ')
			{
				int l = i, m = j;
				while (l > 0)
				{
					arr[l][m] = arr[l - 1][m];
					l--;
				}
			}
		}
	}
}
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Retrieve handle to console window
	char replay = 'y'; // Initialize a character variable for replay
	while (replay == 'y' || replay == 'Y') // Loop while replay is 'y' or 'Y'
	{
		SetConsoleTextAttribute(h, 6); // function for text color yellow
		int game; // Declare variable for game choice
		cout << endl << endl << endl;  
		cout << "\t\t\t\t|+++++++++++++++++++++|" << endl;
		cout << "\t\t\t\t|______GAME MENU______|" << endl;
		cout << "\t\t\t\t|                     |" << endl;
		cout << "\t\t\t\t|    1. Play Game     |" << endl;
		cout << "\t\t\t\t|    2. Credits       |" << endl;    // Display the game menu options
		cout << "\t\t\t\t|    3. Instructions  |" << endl;
		cout << "\t\t\t\t|    4. Scores        |" << endl;
		cout << "\t\t\t\t|    5. Quit          |" << endl;
		cout << "\t\t\t\t|   Give Your choice  |" << endl;
		cout << "\t\t\t\t|_____________________|" << endl;
		cout << "\t\t\t\t";
		cin >> game; // Input user's choice
		SetConsoleTextAttribute(h, 15); //function for text color default
		srand(time(0)); // Seed random number generator with current time
		if (game == 1) // If user chooses to play the game
		{
			string name; // Declare a string variable for player name
			system("CLS"); // Clear the console screen
			SetConsoleTextAttribute(h, 6); // Set text color to yellow
			cout << endl << endl << endl;   
			// Display message prompting for player's name
			cout << "\t\t\t\t\t|         PLEASE ENTER YOUR NAME:          |" << endl;
			cout << "\t\t\t\t\t          ";
			cin.ignore();// Ignore any previous input and without this control ignores user to input his name..
			getline(cin, name); // Get player's name including spaces
			SetConsoleTextAttribute(h, 7);// Set text color to white
			int mode; // Declare variable for game mode
			SetConsoleTextAttribute(h, 6);// Set text color to yellow
			cout << "\n\t\t\t\t\t Select MODE:" << endl;
			SetConsoleTextAttribute(h, 2);/// Set text color to green for easy mode
			cout << " \t\t\t\t\t 1. Easy Mode" << endl;
			SetConsoleTextAttribute(h, 4);// Set text color to red for hard mode
			cout << " \t\t\t\t\t 2. Hard Mode" << endl;
			cout << "\t\t\t\t\t ";
			SetConsoleTextAttribute(h, 6); // Set text color to yellow
			cin >> mode;  // Input user's mode choice
			SetConsoleTextAttribute(h, 7); // Set text color to default
			if (mode == 1) // Check if the selected mode is Easy Mode
			{
				system("CLS"); // Clear the console screen
				SetConsoleTextAttribute(h, 2); // Set text color to green
				cout << "\t\t\t\t\t " << name << " selected Easy Mode." << endl << endl; // Display player's name and selected mode
				SetConsoleTextAttribute(h, 7); // Set text color to default
				int count = 0;// Variable to control filling of random candies in the table (to be done only once)
				int score = 0; // Initialize score
				int turn = 5; // Initialize number of turns
				char arr[8][8]; // Initialize an 8x8 array for the game grid
				int stoptimer = 60; // Initialize a timer
				if (count == 0)
					FILLcandies(arr);// Fill the table with candies if count is zero (to be done only once)
				count++;
				// Game loop to continue the game until the timer or turns run out
				while (stoptimer >= 0 && turn > 0)
				{   // Display game information: timer, turns, and score
					cout << "\t\tTIMER : " << stoptimer << endl;
					cout << "\t\tTurns :" << turn << endl;
					cout << "\t\tScore :" << score << endl;
					stoptimer--;
					// Display the grid with row and column indicators
					cout << "    |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
					cout << "    -------------------------------------------------" << endl;
					for (int i = 0; i < 8; i++) // Loop through each row of the grid
					{    // Display row number and separator
						cout << " " << i << " " << " | ";
						for (int j = 0; j < 8; j++) // Loop through each column of the grid
						{    // Set console text color based on the candy symbol
							if (arr[i][j] == '@')
								SetConsoleTextAttribute(h, 1); // Set color for '@' symbol  blue
							else if (arr[i][j] == '#')
								SetConsoleTextAttribute(h, 2); // Set color for '#' symbol  green
							else if (arr[i][j] == '$')
								SetConsoleTextAttribute(h, 3); // Set color for '$' symbol  red
							else if (arr[i][j] == '%')
								SetConsoleTextAttribute(h, 4); // Set color for '%' symbol  yellow
							else if (arr[i][j] == '&')
								SetConsoleTextAttribute(h, 5); // Set color for '&' symbol  purple
							cout << " " << arr[i][j] << " "; // Display the candy symbol and separators
							SetConsoleTextAttribute(h, 15); // Set text color back to default 
							cout << " | ";
						}
						cout << endl; // Move to the next line after each row
						cout << "    -------------------------------------------------";
						cout << endl;
					}
					SetConsoleTextAttribute(h, 3); // Set console text color to highlight instructions
					cout << "Press Rshift To select Candy..." << endl;
					SetConsoleTextAttribute(h, 7); // Set console text color back to default
					if (GetAsyncKeyState(VK_RSHIFT))// this function checks when user enters right shift .. otherwise ignore and control moves forward 
					{
						int i, j; // Declaration of variables to store row and column indices
						bool found = 1; //for check controls
						bool valid = 1;// for check input validation
						while (valid == 1) // Enters a loop for input validation, continues until valid input is received
						{
							cout << "Which Element You want to swap?"; // Asks the user for the element to swap
							cout << "\nInput i:"; // Prompts for the row index
							cin >> i; // Reads the row index input by the user
							cout << "\nInput j:"; // Prompts for the column index
							cin >> j; // Reads the column index input by the user
							if (i >= 0 && i < 8 && j >= 0 && j < 8)// Checks if the entered indices are within the valid range
								valid = 0; // If the indices are valid, sets the 'valid' flag to 0 to exit the loop
							else
							{
								cout << "\nInvalid Input... Enter Between 0 and 7." << endl; // If indices are invalid, prompts the user to enter valid indices
								valid = 1; // Sets 'valid' flag to 1 to continue the loop for re-entering valid indices
							}
						}
						cout << "Selected Sybmol: " << arr[i][j] << endl; // Displays the selected symbol based on the entered indices
						cout << "Press Arrow Keys to swipe :"; // Instructs the user to press arrow keys for further action
						while (found == 1) { // Enters a loop until the desired action is completed
							int c; // Declares an integer variable 'c'
							switch (c = _getch()) // Takes input from the keyboard and assigns it to 'c'
							{
							case KEY_UP: // Checks if the input key is the up arrow key
							{
								if (i == 0) // Checks if the selected row is at the top edge of the grid
								{
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the top edge)
								}
								else
								{
									char swp = arr[i][j]; // Temporarily stores the current candy symbol
									arr[i][j] = arr[i - 1][j]; // Moves the candy symbol from the row above to the current position
									arr[i - 1][j] = swp; // Places the temporarily stored symbol in the row above
									turn--; // Decrements the number of turns remaining
									found = 0; // Sets 'found' to 0 to exit the loop, indicating the movement is done
									break; // Exits the switch statement
								}
							}
							case KEY_DOWN: // Checks if the input key is the down arrow key
							{
								if (i == 7) // Checks if the selected row is at the bottom edge of the grid
								{
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the bottom edge)
								}
								else
								{
									char swp = arr[i][j]; // Temporarily stores the current candy symbol
									arr[i][j] = arr[i + 1][j]; // Moves the candy symbol from the row below to the current position
									arr[i + 1][j] = swp; // Places the temporarily stored symbol in the row below
									turn--; // Decrements the number of turns remaining

								}
								found = 0; // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break; // Exits the switch statement
							}
							case KEY_LEFT: // Checks if the input key is the left arrow key
							{
								if (j == 0) // Checks if the selected column is at the left edge of the grid
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the left edge)
								else
								{
									char swp = arr[i][j]; // Temporarily stores the current candy symbol
									arr[i][j] = arr[i][j - 1]; // Moves the candy symbol from the column to the left to the current position
									arr[i][j - 1] = swp; // Places the temporarily stored symbol in the column to the left
									turn--; // Decrements the number of turns remaining
								}
								found = 0; // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break; // Exits the switch statement
							}
							case KEY_RIGHT: // Checks if the input key is the right arrow key
							{
								if (j == 7) // Checks if the selected column is at the right edge of the grid
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the right edge)
								else
								{
									char swp = arr[i][j]; // Temporarily stores the current candy symbol
									arr[i][j] = arr[i][j + 1]; // Moves the candy symbol from the column to the right to the current position
									arr[i][j + 1] = swp; // Places the temporarily stored symbol in the column to the right
									turn--; // Decrements the number of turns remaining
								}
								found = 0; // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break; // Exits the switch statement
							}

							cout << endl;  // Outputs a new line
							}
						}
						int pikachuu = 10;
						while (pikachuu >= 0)
						{
							for (int i = 0; i < 8; i++) // Iterate through the rows of the grid
							{
								for (int j = 0; j < 8; j++) // Iterate through the columns of the grid
								{   // Check for a specific L-shaped pattern within the grid
									if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
									{   // If the pattern is found, replace specific elements with spaces to clear the L-shaped pattern
										arr[i][j] = ' ';
										arr[i + 1][j] = ' ';
										arr[i + 2][j] = ' ';
										arr[i][j + 1] = ' ';
										arr[i][j + 2] = ' ';
										score += 25; // Increment the player's score by 25
										system("CLS"); // Clear the console screen
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;    // Display a loading animation or message to indicate processing
										cout << "|  lshape       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pause the program for 500 milliseconds (half a second)
										system("CLS"); // Clear the console screen again after the animation
									}
									else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])// vertical condition check 
									{   // If a vertical condition is met (three consecutive elements in a column are the same)
									    // Replace those elements with spaces to clear the vertical line
										arr[i][j] = ' ';
										arr[i + 1][j] = ' ';
										arr[i + 2][j] = ' ';
										score += 10;  // Increase the player's score by 10
										system("CLS"); // Clear the console screen
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl; // Display a loading message or animation
										cout << "|   vert        loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pause the program for 500 milliseconds (0.5 seconds)
										system("CLS"); // Clear the console screen again after the animation
									}
									else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
									{   // If a horizontal condition is met (three consecutive elements in a row are the same)
                                        // Replace those elements with spaces to clear the horizontal line
										arr[i][j] = ' ';
										arr[i][j + 1] = ' ';
										arr[i][j + 2] = ' ';
										score += 10; // Increase the player's score by 10
										system("CLS"); // Clear the console screen
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;    // Display a loading message or animation
										cout << "|    hori       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pause the program for 500 milliseconds (0.5 seconds)
										system("CLS"); // Clear the console screen again after the animation
									}
									else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
									{   // If a forward diagonal condition is met (three consecutive elements in a diagonal line are the same)
                                        // Replace those elements with spaces to clear the diagonal line
										arr[i][j] = ' ';
										arr[i - 1][j + 1] = ' ';
										arr[i + 1][j - 1] = ' ';
										score += 15; // Increase the player's score by 15
										system("CLS"); // Clear the console screen
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl; // Display a loading message or animation
										cout << "|   fdia        loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pause the program for 500 milliseconds (0.5 seconds)
										system("CLS"); // Clear the console screen again after the animation
									}
									else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])// backward diagonal condition
									{   // Check for a backward diagonal condition where three consecutive elements are the same.
                                        // If the condition is met, replace the matching elements with spaces to eliminate the backward diagonal line
										arr[i][j] = ' '; // Current element
										arr[i - 1][j - 1] = ' '; // Element in the upper-left position
										arr[i + 1][j + 1] = ' ';  // Element in the lower-right position
										score += 15;   // Increase the player's score by 15
										system("CLS");  // Clear the console screen to display a message or animation
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;  // Display a loading message or animation 
										cout << "|    bdia       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pause the program execution for 500 milliseconds (0.5 seconds) to visualize the loading effect
										system("CLS");  // Clear the console screen again for further gameplay updates or displays
									}
								}
							}
							// Execute a series of game operations a certain number of times (controlled by 'pikachuu)
							swpspaceEASY(arr); // Perform a swapping operation in the game grid
							fill(arr); // Fill the game grid with new elements after swapping
							pikachuu--; // Decrement the counter to control the loop's iterations
						}
					}
					Sleep(1000);   // Pause the program execution for 1000 milliseconds (1 second)
					system("CLS"); // Clear the console screen to update the display or prepare for the next iteration
				}
				if (stoptimer <= 0 || turn <= 0)   // Check if either the game timer has reached zero or the turn count has become zero
				{
                    // Display the player's name and their final score
					cout << name << " scored :" << score << endl;
					fstream file;/// ifstream  fin..../// ofstream out  ... fout ... fin.>>  (Declare a file stream object)
					file.open("SCOREBOARD.txt", ios::app); // fin.open , ios::in.  Open a file named "SCOREBOARD.txt" in append mode to store scores
					file << name << " " << score << endl;    // Write the player's name, a space, their score, and a newline to the file
					file.close(); // Close the file stream
				}
			}
			else if (mode == 2)// Checks if the mode is set to 'hard mode'
			{
				int count = 0; // Initializes a counter variable
				int score = 0; // Initializes a score variable
				int turn = 15; // Initializes a turn limit variable
				char arr[10][10];// Declares a 10x10 array to store characters
				int stoptimer = 40; // Initializes a stop timer variable
				if (count == 0) // Checks if the count is equal to 0
					FILLcandieshard(arr);// Calls a function to fill the table with candies
				count++; // Increments the count variable by 1 for tracking purposes
                         // This line likely keeps track of how many times this block of code has been executed.
				while (stoptimer >= 0 && turn > 0) // Loop continues while the stop timer is not negative and turns remain
				{
					system("CLS"); // Clears the console screen
					SetConsoleTextAttribute(h, 4); // Sets text attribute for color in console
					cout << "\t\t\t\t " << name << " selected Hard Mode." << endl << endl; // Displays a message for the selected mode
					SetConsoleTextAttribute(h, 7); // Resets text attribute for color to default
					cout << "TIMER : " << stoptimer << endl; // Displays the timer value
					cout << "Turns :" << turn << endl; // Displays the remaining turns
					cout << "Score :" << score << endl; // Displays the current score
					stoptimer--; // Decrements the stop timer value by 1
					cout << "   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;  // Displaying the game grid
					cout << "   -------------------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) // Iterating through the 2D array and displaying its content
					{
						cout << " " << i << " | "; // Displays row number
						for (int j = 0; j < 10; j++)
						{   // Setting console text attribute based on array content for symbol coloring
							if (arr[i][j] == '@')
								SetConsoleTextAttribute(h, 1);//colouring symbols
							else if (arr[i][j] == '#')
								SetConsoleTextAttribute(h, 2);
							else if (arr[i][j] == '$')
								SetConsoleTextAttribute(h, 3);
							else if (arr[i][j] == '%')
								SetConsoleTextAttribute(h, 4);
							else if (arr[i][j] == '&')
								SetConsoleTextAttribute(h, 5);
							else if (arr[i][j] == '!')
								SetConsoleTextAttribute(h, 6);
							else if (arr[i][j] == '*')
								SetConsoleTextAttribute(h, 7);
							cout << " " << arr[i][j] << " "; // Displays array content
							SetConsoleTextAttribute(h, 15);   // Resets text attribute to default
							cout << "  |"; // Separates array elements visually
						}
						cout << endl;
						cout << "   -------------------------------------------------------------"; // Separates rows visually
						cout << endl;
					}
					SetConsoleTextAttribute(h, 3); // Sets the console text attribute to color 3
					cout << "Press Rshift To select Candy..." << endl;  // Displays a message prompting the user to press Right Shift
					SetConsoleTextAttribute(h, 7); // Resets the console text attribute to the default color
					if (GetAsyncKeyState(VK_RSHIFT)) // Checks if the Right Shift key is pressed
					{
						int i = 0, j = 0; // Initializes variables for row and column
						bool found = 1;   // Initializes a boolean variable for checking existence
						bool valid = 1;   // Initializes a boolean variable for validity checking
						while (valid == 1) // Loop to input valid row and column values
						{   
							cout << "Which Element You want to swap?";  // Prompts the user for element swap
							cout << "\nInput i:"; // Prompts for input of 'i'
							cin >> i; // Takes input for 'i'
							cout << "\nInput j:"; // Prompts for input of 'j'
							cin >> j;  // Takes input for 'j'
							if (i >= 0 && i < 10 && j >= 0 && j < 10)  // Checks if input values are within the valid range (0-9)
								valid = 0; // If the inputs are valid, exits the loop
							else
							{
								cout << "\nInvalid Input... Enter Between 0 and 7." << endl; // Displays a message for invalid input
								valid = 1; // If the inputs are invalid, continues the loop 
							}
						}
						cout << "Selected Sybmol: " << arr[i][j] << endl; // Displays the selected symbol
						cout << "Press Arrow Keys to swipe :"; // Prompts the user to use arrow keys for a swipe
						while (found == 1) { // Enters a loop until the desired action is completed
							int c;  // Declares an integer variable 'c'
							switch (c = _getch()) // Takes input from the keyboard and assigns it to 'c'
							{
							case KEY_UP: // Checks if the input key is the up arrow key
							{
								if (i == 0) // Checks if the selected row is at the top edge of the grid
								{
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the top edge)
								}
								else
								{
									char swp = ' ';
									swp = arr[i][j];  // Temporarily stores the current candy symbol
									arr[i][j] = arr[i - 1][j]; // Swaps the selected symbol with the one above
									arr[i - 1][j] = swp; // Places the temporarily stored symbol in the row above
									turn--; // Decrements the number of turns remaining
									found = 0;  // Sets 'found' to 0 to exit the loop, indicating the movement is done
									break;  // Exits the switch statement
								}
							case KEY_DOWN: // Checks if the input key is the down arrow key
							{
								if (i == 9) // Checks if the selected row is at the bottom edge of the grid
								{
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the bottom edge)
								}
								else
								{
									char swp = ' ';
									swp = arr[i][j];  // Temporarily stores the current candy symbol
									arr[i][j] = arr[i + 1][j];  // Swaps the selected symbol with the one below
									arr[i + 1][j] = swp;  // Places the temporarily stored symbol in the row below
									turn--; // Decrements the number of turns remaining
								}
								found = 0;  // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break; // Exits the switch statement
							}
							case KEY_LEFT: // Checks if the input key is the left arrow key
							{
								if (j == 0) // Checks if the selected column is at the left edge of the grid
									cout << "Invalid Move." << endl; // Displays an error message for an invalid move (already at the left edge)
								else
								{
									char swp = ' ';
									swp = arr[i][j];  // Temporarily stores the current candy symbol
									arr[i][j] = arr[i][j - 1]; // Moves the candy symbol from the column to the left to the current position
									arr[i][j - 1] = swp; // Places the temporarily stored symbol in the column to the left
									turn--; // Decrements the number of turns remaining
								}
								found = 0;  // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break;  // Exits the switch statement
							}
							case KEY_RIGHT:  // Checks if the input key is the right arrow key
							{
								if (j == 9)  // Checks if the selected column is at the right edge of the grid
									cout << "Invalid Move." << endl;  // Displays an error message for an invalid move (already at the right edge)
								else
								{
									char swp = arr[i][j];  // Temporarily stores the current candy symbol
									arr[i][j] = arr[i][j + 1]; // Moves the candy symbol from the column to the right to the current position
									arr[i][j + 1] = swp; // Places the temporarily stored symbol in the column to the right
									turn--; // Decrements the number of turns remaining
								}
								found = 0; // Sets 'found' to 0 to exit the loop, indicating the movement is done
								break;  // Exits the switch statement
							}
							}
							cout << endl;   // Outputs a new line
							}
						}
						int pikachu = 10; // Declaring and initializing the variable 'pikachu' with a value of 10.
						while (pikachu > 0) // While loop that executes as long as the condition (pikachu > 0) is true.
						{
							for (int i = 0; i < 10; i++) // Nested for loop to iterate through rows (i) from 0 to 9.
							{
								for (int j = 0; j < 10; j++) // Another nested for loop to iterate through columns (j) from 0 to 9.
								{
                                    // Checking if certain conditions for an 'L' shape in the 'arr' array are met.
									if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
									{   // If the conditions are met, performing the following actions:
                                        // Changing specific elements in the 'arr' array to empty spaces (' ').
										arr[i][j] = ' ';
										arr[i + 1][j] = ' ';
										arr[i + 2][j] = ' ';
										arr[i][j + 1] = ' ';
										arr[i][j + 2] = ' ';
										score += 25;    // Increasing the 'score' variable by 25.
										system("CLS");  // Clearing the console screen.
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl; // Displaying a loading animation message.
										cout << "|  lshape       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pausing execution for 500 milliseconds (0.5 seconds).
										system("CLS"); // Clearing the console screen again.
									}
									else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])// Checking for a vertical pattern in the 'arr' array.
									{   // If the vertical pattern condition is met, perform the following actions:
										// Changing specific elements in the 'arr' array to empty spaces (' ').
										arr[i][j] = ' ';
										arr[i + 1][j] = ' ';
										arr[i + 2][j] = ' ';
										score += 10; // Increasing the 'score' variable by 10.
										system("CLS"); // Clearing the console screen.
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;  // Displaying a loading message for the vertical pattern.
										cout << "|   vert        loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pausing execution for 500 milliseconds (0.5 seconds).
										system("CLS");  // Clearing the console screen again.
									}
									else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
									{   // If the horizontal pattern condition is met, perform the following actions:
                                        // Changing specific elements in the 'arr' array to empty spaces (' ').
										arr[i][j] = ' ';
										arr[i][j + 1] = ' ';
										arr[i][j + 2] = ' ';
										score += 10; // Increasing the 'score' variable by 10.
										system("CLS"); // Clearing the console screen.
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;   // Displaying a loading message for the horizontal pattern.
										cout << "|    hori       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pausing execution for 500 milliseconds (0.5 seconds).
										system("CLS"); // Clearing the console screen again.
									}
									else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
									{   // If the forward diagonal pattern condition is met, perform the following actions:
                                        // Changing specific elements in the 'arr' array to empty spaces (' ').
										arr[i][j] = ' ';
										arr[i - 1][j + 1] = ' ';
										arr[i + 1][j - 1] = ' ';
										score += 15; // Increasing the 'score' variable by 15
										system("CLS");  // Clearing the console screen.
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl;   // Displaying a loading message for the forward diagonal pattern.
										cout << "|   fdia        loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pausing execution for 500 milliseconds (0.5 seconds).
										system("CLS"); // Clearing the console screen again.
									}
									else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1]) // backward diagonal condition
									{   // If the backward diagonal pattern condition is met, perform the following actions:
                                        // Changing specific elements in the 'arr' array to empty spaces (' ').
										arr[i][j] = ' ';
										arr[i - 1][j - 1] = ' ';
										arr[i + 1][j + 1] = ' ';
										score += 15; // Increasing the 'score' variable by 15
										system("CLS");  // Clearing the console screen.
										cout << "------------------------" << endl;
										cout << "|                      |" << endl;
										cout << "|         SWEET        |" << endl; // Displaying a loading message for the backward diagonal pattern.
										cout << "|    bdia       loading|" << endl;
										cout << "------------------------" << endl;
										Sleep(500); // Pausing execution for 500 milliseconds (0.5 seconds).
										system("CLS"); // Clearing the console screen again.
									}
								}
							}
							swpspaceHARD(arr); // Function call to 'swpspaceHARD' passing 'arr' as an argument.
							fillhard(arr);     // Function call to 'fillhard' passing 'arr' as an argument.
							pikachu--;         // Decrementing the 'pikachu' variable by 1.
						}

					}
					Sleep(1000);   // Pausing execution for 1000 milliseconds (1 second).
					system("CLS"); // Clearing the console screen.
				} 
				if (stoptimer <= 0 || turn <= 0) // Condition check for 'stoptimer' or 'turn' reaching 0 or below.
				{
					cout << name << " scored :" << score << endl; // Display the player's name and score.
					fstream file; // Open a file stream in append mode to "SCOREBOARD.txt".
					file.open("SCOREBOARD.txt", ios::app);
					// Append the player's name and score to the file.
					file << name; 
					file << " ";
					file << score;
					file << "\n"; // Add a newline character after appending the score.
				}
			}
		}
		else if (game == 2)   // Check if the game variable is set to 2
		{
			system("CLS");   // Clear the console screen
			char b = ' ';  
			while (b == ' ') // Loop to display credits until 'b' is not equal to ' '
			{
				if (GetAsyncKeyState(VK_ESCAPE))   // Check if the ESC key is pressed using GetAsyncKeyState
				{
					b = 'a'; // Change the value of 'b' to exit the loop
				}
				SetConsoleTextAttribute(h, 6); // Set console text color
				cout << "\t\t\t\t |----------CREDITS-----------|" << endl;
				cout << "\t\t\t\t |                            |" << endl;
				cout << "\t\t\t\t |    Name : Hassan Raza      |" << endl;
				cout << "\t\t\t\t |                            |" << endl;
				cout << "\t\t\t\t |     Roll NO :  231976      |" << endl;  // ... (Displaying the name, roll number, and instructions to go back)
				cout << "\t\t\t\t |                            |" << endl;
				cout << "\t\t\t\t |                            |" << endl;
				cout << "\t\t\t\t |   Press ESC to go back.    |" << endl;
				cout << "\t\t\t\t |----------------------------|" << endl;
				Sleep(1000);    // Pause the execution for 1 second
				system("CLS");  // Clear the console screen
				SetConsoleTextAttribute(h, 7); // Reset console text color
			}
		}
		else if (game == 3)
		{
			char b = ' ';
			system("CLS");  // Clear the console screen
			while (b == ' ')
			{
				if (GetAsyncKeyState(VK_ESCAPE)) // Check if the ESC key is pressed using GetAsyncKeyState
				{
					b = 'a';  // Change the value of 'b' to exit the loop when ESC is pressed
				}
				SetConsoleTextAttribute(h, 6);  // Set console text color
				cout << "\t\t\t\t |---------------------Instructions---------------------|" << endl;
				cout << "\t\t\t\t |                                                      |" << endl;
				cout << "\t\t\t\t | How to Play:                                         |" << endl;
				cout << "\t\t\t\t |                                                      |" << endl;
				cout << "\t\t\t\t |   1. Select Play Mode By pressing 1 or 2             |" << endl;
				cout << "\t\t\t\t |   2. Press Right Shift to Select Candy.              |" << endl;
				cout << "\t\t\t\t |   3. Give Candy address.                             |" << endl;
				cout << "\t\t\t\t |   3. Press Arrow Key To Swap with.                   |" << endl;
				cout << "\t\t\t\t |                                                      |" << endl;  // Displaying game instructions
				cout << "\t\t\t\t | GamePlay:                                            |" << endl;
				cout << "\t\t\t\t |                                                      |" << endl;
				cout << "\t\t\t\t |   1. When Player Swipe Candy and candy not crushes,  |" << endl;
				cout << "\t\t\t\t |  Turn will be lost and Candy will swipe.             |" << endl;
				cout << "\t\t\t\t |   2.If condition Matches Upper Candies Will move down|" << endl;
				cout << "\t\t\t\t |   and new Candies will be generated above.           |" << endl;
				cout << "\t\t\t\t |                                                      |" << endl;
				cout << "\t\t\t\t |    Press ESC for go back..                           |" << endl;
				cout << "\t\t\t\t |------------------------------------------------------|" << endl;
				Sleep(1000); // Pause the execution for 1 second
				system("CLS"); // Clear the console screen
				SetConsoleTextAttribute(h, 7); // Reset console text color
			}
		}
		else if (game == 4)  
		{
			SetConsoleTextAttribute(h, 6);   // Set console text color
			system("CLS");  // Clear the console screen
			char b = ' ';   // Initialize a character 'b' with a space
			while (b == ' ')    // Enters a loop to display the scoreboard until 'b' changes
			{   // Prompt user to press ESC to exit
				cout << "Press ESC to go back." << endl;
				if (GetAsyncKeyState(VK_ESCAPE))   // Checks if ESC key is pressed
				{
					b = 'a';   // Change the value of 'b' to exit the loop when ESC is pressed
				}
				int score;      // Variable to store score
				char ch = ' ';  // Character variable 'ch'
				string record;  // String to hold records from the file
				string nam;     // String to hold names
				fstream disp;    // Filestream object
				disp.open("SCOREBOARD.txt", ios::in);  // Open "SCOREBOARD.txt" for reading
				while (!disp.eof())     // Loop to read lines from the file
				{
					getline(disp, record);   // Read each line from the file
					cout << endl << record;  // Display the content of each line (presumably the scoreboard)
				}
				Sleep(1000);  // Pause execution for 1 second
				system("CLS");   // Clear the console screen for the next iteration
			}
		}
		else if (game == 5)
		{
			replay = 'N'; // If 'game' equals 5, set 'replay' variable to 'N' for exit thr loop
		}
	}
	SetConsoleTextAttribute(h, 7); 
	for (int z = 1; z < 7; z++)  // Loop through colors using console text attributes
	{
		SetConsoleTextAttribute(h, z);  // Set console text color based on 'z' value
		string str = "Thanks Alot Happy Coding...";    // Create a string variable
		cout << str << endl; // Output the string "Happy Coding" to the console
		Sleep(500);  // Pause for 500 milliseconds (0.5 seconds)
		if (z == 6) { // When 'z' reaches 6 (the last iteration)
			system("start https://www.linkedin.com/in/𝐇𝐚𝐬𝐬𝐚𝐧-𝐑𝐚𝐳𝐚-997430297/"); // Open a browser window and navigate to Linkedin
		}   // The 'start' command in 'system' function opens a new process with the given URL in the default browser.
	}
	SetConsoleTextAttribute(h, 15);    // Set console text color to default white
	return 0; // Exit the program , program is successfully executed...
}
