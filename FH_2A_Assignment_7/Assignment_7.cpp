#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//--------------------------- Class Prototype ----------------------------------
class TripleString
{

private:

   string string1,string2,string3;

   // Method
   bool validString(string str);

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
};

// Static Constants Initialization
const int TripleString::MAX_LEN = 50;
const int TripleString::MIN_LEN = 1;
const string TripleString::DEFAULT_STRING = " (undefined) ";

// Concatenate Three Private Member Strings
string toString(TripleString triple);

//----------------------------- Main Method ------------------------------------
int main()
{

   string String123;

   // Instantiate Four Object
   TripleString TripleObj1;
   TripleString TripleObj2("A","B","C");
   TripleString TripleObj3;
   TripleString TripleObj4("Dad","Mom","Sister");

   // Display All Objects
   String123 = toString(TripleObj1);
   cout << "All strings in TripleString Object 1: " << String123 << endl;
   String123 = toString(TripleObj2);
   cout << "All strings in TripleString Object 2: " << String123 << endl;
   String123 = toString(TripleObj3);
   cout << "All strings in TripleString Object 3: " << String123 << endl;
   String123 = toString(TripleObj4);
   cout << "All strings in TripleString Object 4: " << String123 << endl;
   cout << endl;

   // Mutate Objects
   TripleObj1.setString1("mashed");
   TripleObj2.setString3("potato");
   TripleObj3.setString2("chicken");
   TripleObj4.setString1("fried");

   // Display All Objects
   String123 = toString(TripleObj1);
   cout << "All strings in TripleString Object 1: " << String123 << endl;
   String123 = toString(TripleObj2);
   cout << "All strings in TripleString Object 2: " << String123 << endl;
   String123 = toString(TripleObj3);
   cout << "All strings in TripleString Object 3: " << String123 << endl;
   String123 = toString(TripleObj4);
   cout << "All strings in TripleString Object 4: " << String123 << endl;
   cout << endl;


   // Test Mutator
   if (TripleObj1.setString1(""))
   {
      cout << "Mutation of member string1 of TripleObj1 succesful" << endl;
   }
   else
   {
      cout << "Mutation of member string1 of TripleObj1 failed" << endl;
   }

   if (TripleObj1.setString1("Lego"))
   {
      cout << "Mutation of member string1 of TripleObj1 succesful" << endl;
   }
   else
   {
      cout << "Mutation of member string1 of TripleObj1 failed" << endl << endl;
   }

   // Accessor Calls
   String123 = TripleObj1.getString1();
   cout << "\nString1 of TripleString Object 1: " << String123 << endl;
   String123 = TripleObj4.getString2();
   cout << "String2 of TripleString Object 4: " << String123 << endl;

   return 0;
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
string toString(TripleString triple)
{
   string concatStr;

   concatStr = triple.getString1() + "-" + triple.getString2() + "-"
      + triple.getString3();

   return concatStr;
}
