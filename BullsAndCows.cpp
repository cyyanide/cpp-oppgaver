/* Bulls and cows game

The program chooses a 4-digit secret number, and you need to guess it.
After each guess, the program tells you how many "bulls" and how many "cows" are in
your guess, interpreted as:
- Each bull indicates a digit in your guess that exactly matches the value and
position of a digit in the program's secret number.
 - Each cow indicates a digit in your guess that matches the value of a digit in
 program's secret number, but is in the wrong position.
*/

#include "../../std_lib_facilities.h"

int amount_cows = 0, amount_bulls = 0; 

vector<int> get_new_vector()
{
    vector<int> solution(4);
    solution[0] = rand() % 10;
    solution[1] = rand() % 10;
    solution[2] = rand() % 10;
    solution[3] = rand() % 10;
    return solution;
}

int main()
try {
    vector<int> v_in(4);    
    while (amount_bulls < 4) 
    {
        vector<int> solution = get_new_vector();
        // Denne for-lokken er bare for å vise at logikken funker
        cout << "The random numbers to guess: (just to check if the program works correctly) \n";  
        for (int i = 0; i < solution.size(); i++) 
        {
            cout << solution[i] << endl;
        }
        cout << "Enter 4 digits and discover the hidden code: ";
        cin >> v_in[0] >> v_in[1] >> v_in[2] >> v_in[3];
        for (int i = 0; i <= 3; i++) {
            if (v_in[i] == solution[i]) 
            {
                amount_bulls = amount_bulls + 1;
            }
            else {
                for (int a = 0; a <= 3; a++) {
                    if (v_in[i] == solution[a])
                        amount_cows = amount_cows + 1;
                }
            }
        }
        cout << "Number of bulls: " << amount_bulls << endl << "Number of cows: " << amount_cows << endl;
        amount_cows = 0;
        amount_bulls = 0;
    }

    return 0;
}

catch (exception & e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
}

catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}
