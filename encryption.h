/*
 *  Where Text is Encrypted
 *
 */

//Included essential libraries
#include <iostream>

//Declared variables for encrpytion
//Organic is original - Contrived is processed
std::string contrived, organic, key;

//Checks if key is same length as to be encrypted word
void checkKey()
{
    int step = 0;
    while (organic.size() != key.size())
    {
        key.push_back(key[++step]);
    }
}

//Processes the steps of encryption
std::string encrypt(std::string organicWord, std::string keyWord)
{
    //Move parameters to local variables
    organic = organicWord;
    key = keyWord;

    //Check for key length
    checkKey();

    //Performs Vigenere Cipher
    for (int step = 0; step < organic.size(); step++)
    {
        //Math of Vigenere Cipher
        char movement = ((organic[step] + key[step]) % 26) + 65;

        //Add encryped letters to contrived
        contrived.push_back(movement);
    }

    //Return encrypted word
    return contrived;
}