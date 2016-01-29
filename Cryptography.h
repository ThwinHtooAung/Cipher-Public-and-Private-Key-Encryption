//
//  Cryptography.h
//  CryptographySeocndAttempt73
//
//  Created by Thwin Htoo Aung on 1/28/16.
//  Copyright © 2016 Thwin Htoo Aung. All rights reserved.
//

#include <string>
#include <fstream>

#include "Encryptor.h"
#include "Decryptor.h"
#include "PublicKeyGenerator.h"

using std::string;
using std::ifstream;
using std::ofstream;

#ifndef Cryptography_h
#define Cryptography_h


#endif /* Cryptography_h */


#define private private:
#define protected protected:
#define public public:

class Cryptography
{
    private Encryptor           *encryptor;
    private Decryptor           *decryptor;
    private PublicKeyGenerator  *keyGenerator;
    public Cryptography();
    
    public string encrypt(string, string);
    public string decrypt(string, string);
    
    public void encryptFile(string, string);
    public void decryptFile(string, string);
    
    public void publiclyEncryptFile(string);
    public void publiclyDecryptFile(string);
};

#undef private
#undef protected
#undef public

Cryptography::Cryptography()
{
    this->encryptor = new Encryptor();
    this->decryptor = new Decryptor();
    this->keyGenerator = new PublicKeyGenerator();
}

string Cryptography::encrypt(string serial, string text)
{
    return this->encryptor->encrypt(serial, text);
}
string Cryptography::decrypt(string serial, string text)
{
    return this->decryptor->decrypt(serial, text);
}


void Cryptography::encryptFile(string serialKey, string filename)
{
    ifstream inputStream;
    ofstream outputStream;
    string targetFilename = filename + ".encrypted";
    
    string oneLineOfData;
    string encryptedLineOfData;
    
    inputStream.open(filename.c_str());
    outputStream.open(targetFilename.c_str());
    
    getline(inputStream, oneLineOfData);
    encryptedLineOfData = this->encrypt(serialKey, oneLineOfData);
    outputStream << encryptedLineOfData << endl;
    
    while(!inputStream.eof())
    {
        getline(inputStream, oneLineOfData);
        encryptedLineOfData = this->encrypt(serialKey, oneLineOfData);
        outputStream << encryptedLineOfData << endl;
    }
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    
    inputStream.open(targetFilename.c_str());
    outputStream.open(filename.c_str());
    
    getline(inputStream, oneLineOfData);
    outputStream << oneLineOfData << endl;
    
    while(!inputStream.eof())
    {
        getline(inputStream, oneLineOfData);
        outputStream << oneLineOfData << endl;
    }
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    remove(targetFilename.c_str());
}
void Cryptography::decryptFile(string serialKey, string filename)
{
    ifstream inputStream;
    ofstream outputStream;
    string targetFilename = filename + ".decrypted";
    
    string oneLineOfData;
    string decryptedLineOfData;
    
    inputStream.open(filename.c_str());
    outputStream.open(targetFilename.c_str());
    
    getline(inputStream, oneLineOfData);
    decryptedLineOfData = this->decrypt(serialKey, oneLineOfData);
    outputStream << decryptedLineOfData << endl;
    
    while(!inputStream.eof())
    {
        getline(inputStream, oneLineOfData);
        decryptedLineOfData = this->decrypt(serialKey, oneLineOfData);
        outputStream << decryptedLineOfData << endl;
    }
    
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    
    
    
    inputStream.open(targetFilename.c_str());
    outputStream.open(filename.c_str());
    
    getline(inputStream, oneLineOfData);
    outputStream << oneLineOfData << endl;
    
    while(!inputStream.eof())
    {
        getline(inputStream, oneLineOfData);
        outputStream << oneLineOfData << endl;
    }
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    remove(targetFilename.c_str());
}

void Cryptography::publiclyEncryptFile(string filename)
{
    string publicKey = this->keyGenerator->generateKey();
    
    
    ifstream fileInputStream;
    ofstream fileOutputStream;
    
    string data;
    
    string targetFileName = filename + ".encrypted";
    
    
    fileInputStream.open(filename.c_str());
    fileOutputStream.open(targetFileName.c_str());
    
    fileOutputStream << publicKey << endl;
    
    getline(fileInputStream , data);
    fileOutputStream << this->encrypt(publicKey, data) << endl;
    
    while(!fileInputStream.eof())
    {
        getline(fileInputStream , data);
        fileOutputStream << this->encrypt(publicKey, data) << endl;
    }
    
    
    
    fileInputStream.close();
    fileOutputStream.flush();
    fileOutputStream.close();
    
    
    fileInputStream.open(targetFileName.c_str());
    fileOutputStream.open(filename.c_str());
    
    getline(fileInputStream , data);
    fileOutputStream << data << endl;
    while(!fileInputStream.eof())
    {
        getline(fileInputStream , data);
        fileOutputStream << data << endl;
    }
    
    fileInputStream.close();
    fileOutputStream.flush();
    fileOutputStream.close();
    remove(targetFileName.c_str());
    
}
void Cryptography::publiclyDecryptFile(string filename)
{
    string targetFileName = filename + ".decrypted";
    
    string data;
    string theKey;
    
    ifstream inputStream;
    ofstream outputStream;
    
    inputStream.open(filename);
    outputStream.open(targetFileName);
    
    getline(inputStream , data);
    theKey = data;
    
    getline(inputStream , data);
    outputStream << this->decrypt(theKey, data) << endl;
    
    while(!inputStream.eof())
    {
        getline(inputStream , data);
        outputStream << this->decrypt(theKey, data) << endl;
    }
    
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    
    inputStream.open(targetFileName);
    outputStream.open(filename);
    
    getline(inputStream, data);
    outputStream << data << endl;
    while(!inputStream.eof())
    {
        getline(inputStream, data);
        outputStream << data << endl;
    }
    
    inputStream.close();
    outputStream.flush();
    outputStream.close();
    remove(targetFileName.c_str());
}