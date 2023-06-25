#include <iostream>
#include "WordManager.h"

// function prototypes
void printMenu();
void runMainMenu(WordManager wordManger);

int main()
{
    WordManager wordManager;                                            // create a wordmanager
    wordManager.loadFromFile("CS210_Project_Three_Input_File.txt");     // load the words from the file
    wordManager.exportToFile("frequency.dat");                          // export word and the count to a file
    runMainMenu(wordManager);                                           // run the application
    
}

void printMenu() {
    
    std::cout << std::endl;                                                         // print a new line
    std::cout << "Menu" << std::endl;                                               // print the menu header
    std::cout << "====" << std::endl;                                               // print the underline
    std::cout << "1 : Get Frequency of a Word" << std::endl;                        // print menu option 1
    std::cout << "2 : Get Word Count of all Words" << std::endl;                    // print menu option 2
    std::cout << "3 : Get Word Count of all Words(print with style)" << std::endl;  // print menu option 3
    std::cout << "4 : Exit" << std::endl;                                           // print menu option 4
    std::cout << "Your choice : ";                                                  // print prompt for the user choice

}

void runMainMenu(WordManager wordManger) {

    std::cout << "Welcome to Grocery Tracking App" << std::endl;    // print welcome message
    std::string input;                                              // get a variable to read user inputs                

    while (true) {                                                  // run this loop until user quits
    
        printMenu();                                                // print the menu
        std::cin >> input;                                          // read the user input
        
        if (input == "1") {                                         // check if user entered 1
            std::string word;                                       // variable to read the word
            std::cout << "What is the word? ";                      // propt to get the word from the user
            std::cin >> word;                                       // read the word

            int occurances = wordManger.getCountOfWord(word);       // get the number of occurances

            std::cout << "Word : " << word << " Count : " 
                << occurances << std::endl;                         // print the word and the count

        }
        else if(input == "2") {                                     // check if user enetered 2
            wordManger.printAllWords(false);                        // if so, print all words with the count
        }
        else if (input == "3") {                                    // check if user enetered 3
            wordManger.printAllWords(true);                         // if so, print all words with the count with styling
        }
        else if (input == "4") {                                    // check if user enetered 4
            break;                                                  // if so, break
        }
        else {                                                      // check for anyother input
            std::cout << "Invalid Entry! Please re-try!" << std::endl;  // if so, print the error message
        }
    }
}


