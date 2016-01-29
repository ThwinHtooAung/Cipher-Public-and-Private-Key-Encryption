//
//  PublicKeyGenerator.h
//  CryptographySeocndAttempt73
//
//  Created by Thwin Htoo Aung on 1/29/16.
//  Copyright © 2016 Thwin Htoo Aung. All rights reserved.
//

#include <cstdlib>
#include <ctime>

#ifndef PublicKeyGenerator_h
#define PublicKeyGenerator_h


#endif /* PublicKeyGenerator_h */


#define private private:
#define protected protected:
#define public public:

class PublicKeyGenerator
{
    private string key;
    private long long int keysRange;
    
    public int random(long long int);
    public char generateOneCharKey();
    
    
    public PublicKeyGenerator();
    
    public string generateKey();
};

#undef private
#undef protected
#undef public

int PublicKeyGenerator::random(long long int __range)
{
    srand((unsigned int)clock());
    return ( rand() % __range ) ;
    
}

char PublicKeyGenerator::generateOneCharKey()
{
    return temp[this->random(this->keysRange)];
}

PublicKeyGenerator::PublicKeyGenerator()
{
    this->keysRange = strlen(temp);
}

string PublicKeyGenerator::generateKey()
{
    string result = "";
    int whiteSpaceRange = 10;
    int whitespaceOccurence = this->random(whiteSpaceRange);
    
    int loopCount = whiteSpaceRange + this->random(300);
    cout << loopCount << endl;
    for(int i = 0 ; i < loopCount; i++)
    {
        result += this->generateOneCharKey();
        whitespaceOccurence--;
        if(whitespaceOccurence == 0)
        {
            result += ' ';
            whitespaceOccurence = this->random(whiteSpaceRange);
        }
    }
    
    return result;
}