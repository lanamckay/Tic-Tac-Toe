//  Project: Tic Tac Toe Game
//  Purpose: To let two players play tic tac toe

#include <iostream>
using namespace std;
 
void display_array (string array [][4], int array_size);
//PURPOSE: Set up the array display for the game
//     INPUTS: array_size - size of the array
//     OUTPUTS: Nothing
 
void winner_output (string winning_player = "");
//PURPOSE: Generates and outputs the winner of the game
//     INPUTS: Nothing
//     OUTPUTS: Outputs of the winner provided via the console
 
bool move_check (string array [][4], int array_size, string tester, string var);
//PURPOSE: Check if the generated value already exists in the array
//     INPUTS: array_size - size of the array, string tester, and string var
//     OUTPUTS: True, if the value already exists; false, otherwise
 
bool vertical_check (string array [][4], int array_size, string tester);
//PURPOSE: Check if the generated output forms a vertical line
//     INPUTS: array_size - size of the array, string tester
//     OUTPUTS: True if any of the column is crossed with the same player's move
 
bool horizontal_check (string array [][4], int array_size, string tester);
//PURPOSE: Check if the generated output forms a horizontal line
//     INPUTS: array_size - size of the array, string tester
//     OUTPUTS: True if any of the row is crossed with the same player's move
 
bool diagonal_check (string array [][4], int array_size, string tester);
//PURPOSE: Check if the generated output forms a diagonal line
//     INPUTS: array_size - size of the array, string tester
//     OUTPUTS: True if any of the diagonal is crossed with the same player's move
 
void execute ();
//PURPOSE: Output the array display for the game
//     INPUTS: array_size - size of the array
//     OUTPUTS: Outputs of the array provided via the console
 
int main () {
execute ();
}
 
// Output the array display for the game and run the program
void execute () {
    //Declare and initialize variables
    int game_counter = 1;
    bool continue_game = true;
    int x_wins = 0;
    int o_wins = 0;
    int ties_wins = 0;
    string first_player = "";
    string second_player = "";
    string move;
    
    do {
    //Declare and initialize gameboard as an array
    string array [4][4] = {{"1","2","3","4"},
                            {"5","6","7","8"},
                            {"9","10","11","12"},
                            {"13","14","15","16"}};
    cout << "Welcome to the Game: 4x4 Tic-Tac-Toe!\n\n"; // Output welcoming to the game
    cout << "\nGame Configuration: \n"; //Output the gameboard: 4 x 4
    display_array (array, 4);
        
        //Initialize starting player
        for (int i = 1; i <= 16; i++)
        {
            if (game_counter % 2 == 1) {
                if (i % 2 == 1) //Player X will play first and O will play second for the first game
                {first_player = "X";
                 second_player = "O";}
                else //For further games, the starting players will alternate
                {first_player = "O";
                 second_player = "X";}
            }
            else
            {    if (i % 2 == 1)
                {first_player = "O"; //
                 second_player = "X";}
                else
                {first_player = "X";
                 second_player = "O";}
            }
            
            bool enter_move = false;
            while (enter_move == false)
            {
                cout << "Player " << first_player << ", please enter the location you would like to reserve: ";
                cin >> move;
                cout << endl;
                
                enter_move = move_check (array, 4, move, first_player);
            }
        
            cout << "Gameboard\n"; // Output gameboard
            display_array (array, 4);
 
            //Check to see if a vertical, horizontal, or diagonal 4x4 is found
            bool winner = vertical_check (array, 4, first_player) || horizontal_check (array, 4, first_player) || diagonal_check (array, 4, first_player);
            if (winner) //, If 4x4 is found, output player that formed it as the winner.
            {winner_output (first_player);
                if (first_player == "X")
                    {x_wins++;}
                else
                    {o_wins++;}
                break;
            }
            
            if (i==16 && winner == false)
            {winner_output ();
            ties_wins++;}
        }
        
        int decision = 0; //The player is asked if they would like to play again
        cout << "If you would like to stop the game here, enter a 0. Otherwise enter any other number and continue! ";
        cin >> decision;
        
        continue_game = decision;
    
        
        game_counter++;
    }
    while (continue_game); //Once the player exits the game, the final score is outputted
    
    cout << "\nNumber of times X won: " << x_wins << endl;
    cout << "Number of times O won: " << o_wins << endl;
    cout << "Number of ties: " << ties_wins << endl;
 
}
 
// Declare the format of the game
void display_array (string array [][4], int array_size)
{
for (int row = 0; row < array_size; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << array [row][col] << "\t"; //Output game board 4 by 4 display
        }
        
        cout << "\n";
    }
}
 
// Declare the winner of the game
void winner_output (string winning_player)
{
    // Output the winner of the game
    if (winning_player == "")
        cout << "\nIt is a tie! No winner this time\n\n";
    else
        cout << "\n" << winning_player << " is the winner! Congratulations!\n\n";
}
 
// Check if the player’s move already exists
bool move_check (string array [][4], int array_size, string tester, string var)
{
    // Declare and initialize variables
    bool is_there = false;
    
    // Iterate while the value is unique
    for (int row = 0; row < array_size; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (array [row][col] == tester)
                {
                    is_there = true;  // Stop if a duplicate value is found
                    array [row][col] = var;
                    break;
                }
        }
        
    }
    // Return the uniqueness status
    return is_there;
    
}
 
// Check if the player’s move forms a vertical line
bool vertical_check (string array [][4], int array_size, string tester)
{
    // Declare and initialize variables
    bool is_there = false;
    
    // Iterate while the value is unique
    for (int col = 0; col < array_size; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            if (array [row][col] != tester)
                {
                    break;
                }
            else if (array [row][col] == tester && row ==3)
                {
                    is_there = true; // Stop if a duplicate value is found
                }
        }
        
    }
    
    // Return the uniqueness status
    return is_there;
 
}
 
// Check if the player’s move forms a horizontal line
bool horizontal_check (string array [][4], int array_size, string tester)
{
    // Declare and initialize variables
    bool is_there = false;
    
    // Iterate while the value is unique
    for (int row = 0; row < array_size; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (array [row][col] != tester)
                {
                    break;
                }
            else if (array [row][col] == tester && col ==3)
                {
                    is_there = true;  // Stop if a duplicate value is found
                }
        }
        
    }
    // Return the uniqueness status
    return is_there;
    
}
 
// Check if the player’s move forms a diagonal line
bool diagonal_check (string array [][4], int array_size, string tester)
{
    // Declare and initialize variables
    bool is_there = false;
    
    // Iterate while the value is unique
    for (int dim = 0; dim < array_size; dim++)
    {
        if (array [dim][dim] != tester)
        {
            break;
        }
        else if (array [dim][dim] == tester && dim == 3)
        {
            is_there = true; // Stop if a duplicate value is found
        }
    }
    // Iterate while the value is unique
    int opposite_counter = array_size - 1;
    for (int dimen = 0; dimen < array_size; dimen++)
    {
        if (array [dimen][opposite_counter] != tester)
        {
            break;
        }
        else if (array [dimen][opposite_counter] == tester && dimen == 3)
        {
            is_there = true; // Stop if a duplicate value is found
        }
        opposite_counter--;
    }
    // Return the uniqueness status
    return is_there;
}

