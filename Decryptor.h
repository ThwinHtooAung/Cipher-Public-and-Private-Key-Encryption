//
//  Decryptor.h
//  CryptographySeocndAttempt73
//
//  Created by Thwin Htoo Aung on 1/28/16.
//  Copyright © 2016 Thwin Htoo Aung. All rights reserved.
//

#include <string>

using std::string;

#ifndef Decryptor_h
#define Decryptor_h


#endif /* Decryptor_h */


#define private private:
#define protected protected:
#define public public:
class Decryptor
{
    private size_t numberOfRow;
    private size_t numberOfColumn;
    private char **rows;
    
    private void initVariableRows();
    private void initARow(int index);
    
    private bool isUpperCaseChar(char);
    private char toLowerCaseChar(char);
    private char toUpperCaseChar(char);

    
    public char decryptAChar(char, char);
    private char getIndexOfTheKey(char);
    
    public Decryptor();
    
    public string decrypt(string,string);
    public void debug();
};
#undef private
#undef protected
#undef public


//MARK - initialization methods
void Decryptor::initVariableRows()
{
    this->rows = new char*[this->numberOfRow];
    for(int i = 0 ; i < this->numberOfRow; i++)
    {
        this->rows[i] = new char[this->numberOfColumn];
    }
}
void Decryptor::initARow(int index)
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
bool Decryptor::isUpperCaseChar(char charToTest)
{
    bool result = true;
    if(charToTest > 96 && charToTest < 123)
    {
        result = false;
    }
    return result;
}
char Decryptor::toLowerCaseChar(char charToLower)
{
    char result = ' ';
    if(charToLower > 64 && charToLower < 91)
    {
        result = (char)(charToLower + 32);
    }
    return result;
}
char Decryptor::toUpperCaseChar(char charToUpper)
{
    char result = ' ';
    if(charToUpper > 96 && charToUpper < 123)
    {
        result = (char)(charToUpper - 32);
    }
    return result;
}



//MARK - constructor
Decryptor::Decryptor()
{
    this->numberOfRow = strlen(temp);
    this->numberOfColumn = strlen(temp);
    this->initVariableRows();
    for (int i = 0 ; i < this->numberOfRow; i++) {
        this->initARow(i);
    }

}


//private decryption methods
char Decryptor::getIndexOfTheKey(char key)
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
char Decryptor::decryptAChar(char encryptedChar, char key)
{
//    key = this->toUpperCaseChar(key);
    int indexOfTheKey = this->getIndexOfTheKey(key);
    
//    bool isNotUpper = this->isUpperCaseChar(encryptedChar);
//    if(!isNotUpper)
//    {
//        encryptedChar = this->toUpperCaseChar(encryptedChar);
//    }
    int initialIndex = 0;
    if(encryptedChar == key)
    {
        initialIndex = 1;
    }
    char decryptedChar = encryptedChar;
    for(int i = initialIndex ; i < this->numberOfRow; i++)
    {
        if(this->rows[i][indexOfTheKey] == encryptedChar)
        {
            decryptedChar = this->rows[i][0];
            break;
        }
    }
//    if(!isNotUpper)
//    {
//        decryptedChar = this->toLowerCaseChar(decryptedChar);
//    }
    return decryptedChar;
}

//public decryption methods
string Decryptor::decrypt(string serialKey, string encryptedText)
{
//    cout << "Input text to decrypt = " << encryptedText << endl;
//    cout << "Serial Key = " << serialKey << endl;
    
    const size_t lengthOfKey = serialKey.length();
    const size_t lengthOfText = encryptedText.length();
    
    char targetKey = ' ';
    
    string __decrypted = "";
    string __toDecrypt = encryptedText;
    
    for(long i = lengthOfKey-1; i >= 0; i--)
    {
        targetKey = serialKey.at(i);
        for(int ii = 0 ; ii < lengthOfText; ii++)
        {
            __decrypted += this->decryptAChar(__toDecrypt.at(ii), targetKey);
        }
        //cout << targetKey << " is used = "<< __decrypted << "  "<< __toDecrypt<< endl;
        //cout << targetKey << " "<< __decrypted << endl;
        string temp = __decrypted;
        __decrypted = "";
        __toDecrypt = temp;
    }
    //cout << endl;
    return __toDecrypt;
}



//MARK - Debugging method
void Decryptor::debug()
{
    for(int i = 0 ; i < this->numberOfRow; i++)
    {
        cout << this->rows[i] << endl;
    }
}