#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//--------------------------- Class Prototype ----------------------------------
class TripleString
{
private:

   string string1,string2,string3;

   // Method
   static bool validString(string str);

public:

   // Default Constructor
   TripleString();

   // 3-parameter Constructor
   TripleString(string str1,string str2,string str3);

   // Static Constants
   static const int MAX_LEN;
   static const int MIN_LEN;
   static const string DEFAULT_STRING;

   // Accessors
   string getString1();
   string getString2();
   string getString3();

   // Mutators
   bool setString1(string initString);
   bool setString2(string initString);
   bool setString3(string initString);

   // Concatenate Three Private Member Strings
   string toString(TripleString triple);
};

// Static Constants Initialization
const int TripleString::MAX_LEN = 50;
const int TripleString::MIN_LEN = 1;
const string TripleString::DEFAULT_STRING = " (undefined) ";

//
const int MIN_BET = 0;
const int MAX_BET = 50;
const int PROB_CHERRY = 40;
const int PROB_BAR = 38;
const int PROB_SEVEN = 15;
const int PROB_SPACE = 7;

//
int getBet();

//
TripleString pull();

//
string randString();

//----------------------------- Main Method ------------------------------------
int main()
{

   /* initialize random seed: */
   srand (time(NULL));

   //getBet();

   randString();
   randString();
   randString();
   randString();
   randString();
   randString();
   randString();
   randString();
   randString();

   return 0;
}

//
int getBet()
{
   string betString;
   int betInt;

   do
   {
      cout << "How much would you like to bet (1 - 50) or 0 to quit? ";
      getline(cin,betString);
      istringstream(betString) >> betInt;
   }
   while ((betInt < MIN_BET) || (betInt > MAX_BET));

   return (betInt);
}

//
TripleString pull()
{
   TripleString pullTripleString;

   return (pullTripleString);
}

// 1 -  7: SPACE   (7%)
// 8 - 22: 7      (15%)
//23 - 60: BAR    (35%)
//61 -100: CHERRY (40%)
string randString()
{
   int randomNumber;
   string randomString;

   randomNumber = (rand() % 100) + 1;

   if (randomNumber > (100 - PROB_CHERRY))
      randomString = "CHERRY";
   else if (randomNumber > (100 - PROB_CHERRY - PROB_BAR))
      randomString = "BAR";
   else if (randomNumber > (100 - PROB_CHERRY - PROB_BAR - PROB_SEVEN))
      randomString = "7";
   else if (randomNumber > (100 - PROB_CHERRY - PROB_BAR - PROB_SEVEN - PROB_SPACE))
      randomString = "SPACE";

   cout << randomNumber << " - " << randomString << endl;

   return randomString;
}

//---------------- TripleString Member Functions Defintions  -------------------
// Default Constructor
TripleString::TripleString()
{
   //Constructor Definition
   string1 = TripleString::DEFAULT_STRING;
   string2 = TripleString::DEFAULT_STRING;
   string3 = TripleString::DEFAULT_STRING;
}

// 3-parameter Constructor
TripleString::TripleString(string str1,string str2,string str3)
{
   if (!setString1(str1))
      string1 = TripleString::DEFAULT_STRING;

   if (!setString2(str2))
      string2 = TripleString::DEFAULT_STRING;

   if (!setString3(str3))
      string3 = TripleString::DEFAULT_STRING;
}

// Accessor "get" Methods
string TripleString::getString1()
{
   return string1;
}

string TripleString::getString2()
{
   return string2;
}

string TripleString::getString3()
{
   return string3;
}

// Mutators "set" Methods
bool TripleString::setString1(string initString)
{
   if (!validString(initString))
      return false;

   string1 = initString;
   return true;
}

bool TripleString::setString2(string initString)
{
   if (!validString(initString))
      return false;

   string2 = initString;
   return true;
}

bool TripleString::setString3(string initString)
{
   if (!validString(initString))
      return false;

   string3 = initString;
   return true;
}

// Check String Validity (min/max length)
bool TripleString::validString(string str)
{
   if (str.length() < MIN_LEN || str.length() > MAX_LEN)
      return false;
   else
      return true;
}

// Concatenate All 3 String Members
string TripleString::toString(TripleString triple)
{
   string concatStr;

   concatStr = string1 + string2 + string3;

   return concatStr;
}

/*
// ***  I got a pull of all BARS in pull 37 and all cherries in pull 15 ***

How much would you like to bet (1 - 50) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 BAR  cherries  BAR
sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 2
whirrrrrr .... and your pull is ...
 cherries  BAR  cherries
congratulations, you win: 10


How much would you like to bet (1 - 50) or 0 to quit? -1
How much would you like to bet (1 - 50) or 0 to quit? 1000
How much would you like to bet (1 - 50) or 0 to quit? 3
whirrrrrr .... and your pull is ...
 BAR  (space)  7
sorry, you lose.
*/
