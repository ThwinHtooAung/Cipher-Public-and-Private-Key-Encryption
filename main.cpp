//
//  main.cpp
//  CryptographySeocndAttempt73
//
//  Created by Thwin Htoo Aung on 1/28/16.
//  Copyright © 2016 Thwin Htoo Aung. All rights reserved.
//

#include <iostream>
#include <cstring>

#include "Cryptography.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Cryptography * cryptography = new Cryptography();
    
    int choice;
    cout << "1.terminal input text encryption" << endl;
    cout << "2.file encryption with private key" << endl;
    cout << "3.file decryption with private key" << endl;
    cout << "4.file encryption with public key" << endl;
    cout << "5.file decryption with public key" << endl;
    cout << "Enter choice >> ";
    cin >> choice;
    cin.ignore();
    //terminal encryption
    if(choice == 1)
    {
        cout << endl << endl;
        string serialKey;
        string text;
        cout << "Enter the serial key : ";
        getline(cin, serialKey);
        cout << "Enter the text to encrypt : ";
        getline(cin, text);
        
        cout << "Entered text       = " << text << endl;
        cout << "Encryted code    = "<< cryptography->encrypt(serialKey, text ) << endl;
        cout << endl ;
        
        string secondSerialKey;
        cout << "Enter the serial key again : ";
        getline(cin, secondSerialKey);
        cout << "Second code      = " << secondSerialKey << endl;
        cout << endl;
        cout << "Text to Decrypt back = " << cryptography->encrypt(serialKey, text) << endl;
        cout << endl;
        cout << "Decrypted text   = " << cryptography->decrypt(secondSerialKey, cryptography->encrypt(serialKey, text)) << endl;
        cout << endl;
        //cout << de.decrypt(serialKey, en.encrypt(serialKey, text)) << endl;
    }
    else if(choice == 2)// file encryption
    {
        string filename;
        string serialKey;
        
        cout << "Enter the file name : ";
        getline(cin, filename);
        cout << "enter serial key : ";
        getline(cin, serialKey);
        
        cryptography->encryptFile(serialKey, filename);
    }else if(choice == 3)
    {
        string filename;
        string serialKey;
        
        cout << "Enter the file name : ";
        getline(cin, filename);
        cout << "enter serial key : ";
        getline(cin, serialKey);
        
        cryptography->decryptFile(serialKey, filename);
    }else if(choice == 4)
    {
        string filename;
        
        cout << "Enter the file name to encrypt : ";
        getline(cin, filename);
        cryptography->publiclyEncryptFile(filename);
    }else
    {
        string filename;
        
        cout << "Enter the file name to decrypt : ";
        getline(cin, filename);
        cryptography->publiclyDecryptFile(filename);
    }
    
    
}
//UfYr Rfc Dsai Gq RfYr
