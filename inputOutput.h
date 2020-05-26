/*
 *  Input and Output for Console
 *
 */

//Include primary header files for Decrypting and Encrypting
#include "decryption.h"
#include "encryption.h"

//Declaration of user variables
std::string userWord, userKey;
char userResponse;

//Introduce user to the Vigenere Cipher program
void introduction()
{
    std::cout << "Welcome to the JP Vigenere Cipher Decryption and Encryption Program!\n";
}

//Ask user for key to Decrypt or Encrypt with
void askKey()
{
    std::cout << "What is your key?\t\tEnter here: ";
    std::cin >> userKey;
}

//Ask user for word to Decrypt or Encrypt
void askWord()
{
    std::cout << "What is your word?\t\tEnter here: ";
    std::cin >> userWord;
}

//Process Decryption then display to user
void displayDecrypt() {}

//Process Encryption then display to user
void displayEncrypt()
{
    std::cout << "\nThe original word was: " << userWord;
    std::cout << "\nThe encrypted word is: " << encrypt(userWord, userKey);
}

//Ask user if they want to Decrypt or Encrypt - Otherwise end program
void askScenario()
{
    //Check if Decrypting
    do
    {
        //Reset Reponse
        userResponse = ' ';

        std::cout << "Do you want to Decrypt? (y/n)\t\tEnter here: ";
        std::cin >> userResponse;
    } while (userResponse != 'y' && userResponse != 'n');

    //If yes for previous
    if (userResponse == 'y')
    {
        //Run standard setup and execution
        askWord();
        askKey();
        displayDecrypt();
    }
    else
    {
        //Reset Reponse
        userResponse = ' ';

        //Check if Encrypting
        do
        {
            //Reset Reponse
            userResponse = ' ';

            std::cout << "Do you want to Encrypt? (y/n)\t\tEnter here: ";
            std::cin >> userResponse;
        } while (userResponse != 'y' && userResponse != 'n');

        //If yes for previous
        if (userResponse == 'y')
        {
            //Run standard setup and execution
            askWord();
            askKey();
            displayEncrypt();
        }
    }

    //If no for both previous questions - Terminate
    if (userResponse == 'n')
    {
        std::cout << "All questions rejected. Terminated program.";
    }
}