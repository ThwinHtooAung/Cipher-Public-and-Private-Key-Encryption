//
//  Encryptor.h
//  CryptographySeocndAttempt73
//
//  Created by Thwin Htoo Aung on 1/28/16.
//  Copyright © 2016 Thwin Htoo Aung. All rights reserved.
//

#include <string>
#include <iostream>

#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::strcpy;
#ifndef Encryptor_h
#define Encryptor_h


#endif /* Encryptor_h */

#define private private:
#define protected protected:
#define public public:

char temp[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`1234567890-=~!@#$%^&*()_+[]{}\\|;:\'\"/.,<>?";

class Encryptor
{
    private size_t numberOfRow;
    private size_t numberOfColumn;
    // rows[73][73];
    //1 + 26 + 26 + 13 + 13 + 16 = 95
    private char **rows;
    
    private void initVariableRows();
    private void initARow(int index);
    
    private bool isUpperCaseChar(char);
    private char toLowerCaseChar(char);
    private char toUpperCaseChar(char);

    
    private int getIndexOfTheKey(char);
    public char encryptAChar(char, char);
    
    public Encryptor();
    
    public string encrypt(string, string);
    public void debug();
    
};
#undef private
#undef protected
#undef public

//MARK - constructor
Encryptor::Encryptor()
{
    this->numberOfRow = strlen(temp);
    this->numberOfColumn = strlen(temp);
    this->initVariableRows();
    for (int i = 0 ; i < this->numberOfRow; i++) {
        this->initARow(i);
    }
}




//MARK - initialization methods
void Encryptor::initVariableRows()
{
    this->rows = new char*[this->numberOfRow];
    for(int i = 0 ; i < this->numberOfRow; i++)
    {
        this->rows[i] = new char[this->numberOfColumn];
    }
}
void Encryptor::initARow(int index)
{
    if(index == 0)
    {
        strcpy(this->rows[0],temp);
    }else
    {
        
        for(int i = 0, j = index ; i < this->numberOfColumn; i++)
        {
            this->rows[index][i] = this->rows[0][j];
            if(j == this->numberOfColumn - 1)
            {
                j = 1;
                continue;
            }
            j++;
        }
    }
}

//MARK - character exchange
bool Encryptor::isUpperCaseChar(char charToTest)
{
    bool result = true;
    if(charToTest > 96 && charToTest < 123)
    {
        result = false;
    }
    return result;
}
char Encryptor::toLowerCaseChar(char charToLower)
{
    char result = ' ';
    if(charToLower > 64 && charToLower < 91)
    {
        result = (char)(charToLower + 32);
    }
    return result;
}
char Encryptor::toUpperCaseChar(char charToUpper)
{
    char result = ' ';
    if(charToUpper > 96 && charToUpper < 123)
    {
        result = (char)(charToUpper - 32);
    }
    return result;
}




//MARK - private encryption methdos
int Encryptor::getIndexOfTheKey(char key)
{
    int result = 0;
    for(int i = 0 ; i < this->numberOfColumn; i++)
    {
        if(key == this->rows[0][i])
        {
            result = i;
            break;
        }
    }
    return result;
}
char Encryptor::encryptAChar(char characterToEncrypt, char key)
{
    //key = this->toUpperCaseChar(key);
    int index = this->getIndexOfTheKey(key);
    
    char result = characterToEncrypt;
    if(result == ' ')
    {
        return result;
    }
//    bool isNotUpper = this->isUpperCaseChar(characterToEncrypt);
//    if(!isNotUpper)
//    {
//        characterToEncrypt = this->toUpperCaseChar(characterToEncrypt);
//    }
    for(int i = 0 ; i < this->numberOfRow; i++)
    {
        if(this->rows[i][0] == characterToEncrypt)
        {
            result = this->rows[i][index];
            break;
        }
    }
//    if(!isNotUpper)
//    {
//        result = this->toLowerCaseChar(result);
//    }
    //cout << result << endl;
    return result;
}



//MARK - public encryption methods
string Encryptor::encrypt(string serialKey, string textToEncrypt)
{
    //cout << "Input text to encrypt = " << textToEncrypt << endl;
    //cout << "Serial Key = " << serialKey << endl;
    
    const size_t lengthOfKey = serialKey.length();
    const size_t lengthOfText = textToEncrypt.length();
    
    string __encrypted = "";
    string __toEncrypt = textToEncrypt;
    
    for(int i = 0 ; i < lengthOfKey; i++)
    {
        char key = serialKey.at(i);
        //cout << key << endl;
        for(int ii = 0 ; ii < lengthOfText; ii++)
        {
            //cout << this->encryptAChar(__toEncrypt.at(ii), key);
            __encrypted += this->encryptAChar(__toEncrypt.at(ii), key);
        }
        //cout << __encrypted << endl;
        string temp = __encrypted;
        __encrypted = "";
        __toEncrypt = temp;
    }
    return __toEncrypt;
}
//MARK - Debugging method
// Shows the Decryption table
void Encryptor::debug()
{
    for(int i = 0 ; i < this->numberOfRow; i++)
    {
        cout << this->rows[i] << endl;
    }
}