/*
 *  Where Text is Decrypted
 *
 */

//Included essential libraries
#include <iostream>
#include <algorithm>

//Declared variables for encrpytion
//reverseOrganic is original - reverseContrived is processed
std::string reverseContrived, reverseOrganic, reverseKey;

//Checks if key is same length as to be encrypted word
void checkReverseKey()
{
    int step = 0;

    while (reverseOrganic.size() > reverseKey.size())
    {
        if (step == reverseKey.size())
        {
            step = 0;
        }
        reverseKey.push_back(reverseKey[step++]);
    }

    if (reverseOrganic.size() < reverseKey.size())
    {
        int temp = reverseKey.size() - reverseOrganic.size();
        for (int step = 0; step < temp; step++)
        {
            reverseKey.pop_back();
        }
    }
}

//Processes the steps of decryption
std::string decrypt(std::string reverseOrganicWord, std::string reverseKeyWord)
{
    //Move parameters to local variables
    reverseOrganic = reverseOrganicWord;
    reverseKey = reverseKeyWord;

    //Check for key length
    checkReverseKey();

    //Performs Reverse Vigenere Cipher
    for (int step = 0; step < reverseOrganic.size(); step++)
    {
        //Math of Reverse Vigenere Cipher
        char reverseMovement = ((reverseOrganic[step] - reverseKey[step] + 26) % 26) + 65;

        //Add encryped letters to reverseContrived
        reverseContrived.push_back(reverseMovement);
    }

    //Return encrypted word
    return reverseContrived;
}