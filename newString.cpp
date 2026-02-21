//files: newString.cpp
//description: Creating my own String class.
//author: Yohance Flager Jr

#include <iostream>
using namespace std;

class String {
    private:
        //attributes
        char * charptr;

    public:
        //destructor
        ~String()   {   delete [] charptr;  }

        //constructors
        String();                       //default constructor
        String( const char* );          //argument constructor
        String( const String& );        //argument constructor
        String( char, int );            //argument constructor
        String( String&, int, int );    //argument constructor

        //member functions
        String append( int, char );                 //appends characters to the end of the string
        String append( const String& );             //appends the whole data to the end of the data that is calling
        String append( const String&, int );        //appends characters from a string to the end of the data for a specificed amount
        String append( const String&, int, int );   //appends a certain number of letters at a specificed position for a specificed number of chracters from one data to the next
        void assign( int, char );                   //assigns characters to the data
        void assign( const char* );                 //assigns data to the data
        void assign( String& );                     //assigns data to the data
        void assign( const char*, int );            //assigns a certain amount of data to the data
        void assign( const char*, int, int );       //assigns a certain amount of data to the data at a certain position
        char at( int );                             //returns the character at the position
        void clear();                               //clears the data
        int compare( const String& );               //returns a number based on compared data
        int compare( int, int, const String& );     //returns a number based on compared data
        bool empty();                               //returns true or false is data is empty
        char front();                               //returns the first character in the data
        int find( char, int );                      //finds the position of a character
        int find( const char*, int );               //finds the position of a character
        int find( String&, int );                   //finds the position of a character
        void insert( int, int, char );              //inserts characters into data
        void insert( int, const char* );            //inserts data into data
        bool palindrome();                          //checks if data is palindrome
        bool palindrome( int, int );                //checks if data is palindrome
        String projection( char );                  //removes a character from the data
        String projection( const String& );         //removes all characters from the data passed from the original data
        int length();                               //returns the size of the data
        String reverse();                           //reverses the data
        int size();                                 //returns the size of the data
        char * substr( int, int );                  //returns a copy of sub string

        //overloaded operators
        String operator=( const String &obj ) {          //overloaded assignment operator
            //local variable declaration
            int count = 0;                          //counter variable to obtain size

            //finding size of the passed variable
            while( obj.charptr[ count ] != '\0' ) {
                count++;
            }

            delete [] charptr;      //clearing memory

            charptr = new char[ count + 1 ];     //re-allocating memory
            
            //coppying data
            for( int i = 0; i < count; i++ ) {
                charptr[ i ] = obj.charptr[ i ];
            }

            //setting null terminator
            charptr[ count ] = '\0';

            return charptr;
        }

        String operator+( String const &obj ) {          //overloaded addition operator
            //local variable declaration
            int countOne = 0;                       //counter variable to obtain size
            int countTwo = 0;                       //counter variable to obtain size
            int countThree = 0;                     //holds position of elements in passed array
            int newSize = 0;                        //holds new size

            //finding size of the passed variable
            while( charptr[ countOne ] != '\0' ) {
                countOne++;
            }

            //finding size of the passed variable
            while( obj.charptr[ countTwo ] != '\0' ) {
                countTwo++;
            }

            //creating array to temporairly hold values
            char placeHolder[ countOne + 1 ];

            //coppying data
            for( int i = 0; i < countOne; i++ ) {
                placeHolder[ i ] = charptr[ i ];
            }

            newSize = countOne + countTwo;      //computing new size

            delete [] charptr;                  //clearing memory

            charptr = new char[ newSize + 1 ];  //recreating newly allocated data with updated size

            //coppying data back
            for( int i = 0; i < newSize; i++ ) {
                //normal data
                if( i < countOne ) {
                    charptr[ i ] = placeHolder[ i ];
                }
                //added letters
                else {
                    charptr[ i ] = obj.charptr[ countThree ];
                    countThree++;
                }
            }

            //setting null terminator
            charptr[ newSize ] = '\0';

            return charptr;
        }

        String operator-( const String &obj ) {          //overloaded subtraction operator
            String temp;            //new String which will be returned
            int lenchar = 0;        //length of charptr (original)
            int lenobj = 0;         //length of obj
            int checkamount;        //holds number of times charptr will be checked for obj
            int count;              //counter in for loop
            int tally;              //counter in for loop
            bool match = true;      //holds if true obj matches charptr, false otherwise
            int objamount = 0;      //number of times that obj is in charptr
            int charcount = 0;      //holds counter for charptr when checking for obj
            int size;               //holds size of temp String
            int i;                  //counter in for loop
            int j;                  //counter in for loop
            bool make = true;       //holds if true obj matches charptr, false otherwise
            int matchcheck = 0;     //holds element which is being checked in charptr
            int ptrcheck = 0;       //holds element which is being copied from charptr to temp
            
            //find size of charptr (left side)
            while( charptr[ lenchar ] != '\0' ) {
                lenchar++;
            }
            
            //find size of obj (right side)
            while( obj.charptr[ lenobj ] != '\0' ) {
                lenobj++;
            }

            //calculate number of times obj will be checked in charptr
            checkamount = lenchar - lenobj + 1;
            
            //loop through charptr checkamount times to check how many times obj is in charptr
            for( count = 0; count < checkamount; count++ ) {
                //set match, tally, and charcount after for loop starts/loops
                match = true;
                tally = 0;
                charcount = count;
                
                //loop to check if obj matches lenobj characters of charptr
                while( tally < lenobj && match == true ) {
                    //if the character of charptr matches character of str, increment tally and charcount
                    if( charptr[ charcount ] == obj.charptr[ tally ] ) {
                        tally++;
                        charcount++;
                    }
                    //otherwise, set match to false to end the while loop
                    else {
                        match = false;
                    }
                }
                
                //if match is true after while loop, increment objamount
                if( match == true ) {
                    objamount++;
                }
            }
            
            //find size for temp String which will be returned
            size = lenchar - ( objamount * lenobj );
            
            //allocated memory for temp
            temp = new char[ size ];
            
            //initalize i as 0
            i = 0;
            
            //loop to put String, which has dropped all of obj, into temp
            while( i < size ) {
                //initalize charcount as 0 and make as true after loop starts over
                charcount = 0;
                make = true;
                
                //loop to check if obj matches lenobj characters of charptr
                for( int j = 0; j < lenobj; j++ ) {
                    //if the character of charptr matches character of str, increment charcount and matchcheck
                    if( charptr[ matchcheck ] == obj.charptr[ j ] ) {
                        charcount++;
                        matchcheck++;
                    }
                    // otherwise, set make to false break loop
                    else {
                        make = false;
                        break;
                    }
                }
                
                //if make is false, run code
                if( make == false ) {
                    //set ptrcheck to matchcheck - charcount
                    ptrcheck = matchcheck - charcount;
                    
                    //if charcount is 0, increment matchcheck
                    if( charcount == 0 ) {
                        matchcheck++;
                    }
                    
                    //set ptrcheck element of chaptr to i element of temp
                    temp.charptr[ i ] = charptr[ ptrcheck ];
                    
                    //increment i
                    i++;
                }
            }
            
            //return temp
            return temp.charptr;
        }

        void operator+=( const String &str ) {       //overloaded += operator
            int lenstr = 0;
            int lenchar = 0;
            char * temp = nullptr;
            int strcount = 0;
            
            //find size of str
            while( str.charptr[ lenstr ] != '\0' ) {
                lenstr++;
            }
            
            //find size of charptr
            while( charptr[ lenchar ] != '\0' ) {
                lenchar++;    
            }
            
            temp = new char[ lenchar ];
            
            for( int count = 0; count < lenchar; count++ ) {
                temp[ count ] = charptr[ count ];
            }
            
            delete [] charptr;
            
            charptr = new char[ lenchar + lenstr ];
            
            for( int count = 0; count < lenchar; count++ ) {
                charptr[ count ] = temp[ count ];
            }
            
            for( int count; count < lenchar + lenstr; count++ ) {
                charptr[ count ] = str.charptr[ strcount ];
                strcount++;
            }
        }

        friend ostream &operator<<( ostream &out, const String &obj ) {      //overloaded insertion operator
            //local variable declaration
            int count = 0;                          //counter variable to obtain size
            
            if( obj.charptr != nullptr ) {
                //finding size of the passed variable
                while( obj.charptr[ count ] != '\0' ) {
                    count++;
                }
            
                //printing the data
                for( int i = 0; i < count; i++ ) {
                    out << obj.charptr[ i ];
                }
            }
            cout << endl;   //spacing line

            return out;
        }

        friend istream &operator>>( istream &input, String &obj ) {  //overloaded extraction operator
            //check if obj.charptr is null
            if( obj.charptr == nullptr ) {
                //allocate memory for obj.charptr
                obj.charptr = new char[ 100 ];
                
                //move obj.charptr into input
                input >> obj.charptr;
            }
            else {
                //move obj.charptr into input
                input >> obj.charptr;
            }
            
            //return input
            return input;
        }
        
};

int main() {
    //test objects for the constructor
    String defaultTest;
    String argumentOne( "Hello" );
    String argumentTwo( argumentOne );
    String argumentThree( 'x', 10 );
    String argumentFour( argumentOne, 2, 2 );

    //test objects for the member functions
    String appendTestOne( "Yohance" );
    String appendTestTwo( "Yogi " );
    String appendTestThree( "Amanda " );
    String appendTestFour( "Rayona " );
    String compareTestOne( "AABBCCDD" );
    String compareTestTwo( "aabb" );
    String projectionTestOne( "AABBCCDD" );
    String projectionTestTwo( "Hello World" );
    String reverseTest( "Fla.ger" );

    //test objects for overloaded operators
    String assignmentOperatorTest = projectionTestTwo;
    String additionOperatorTestOne( "Yohance " );
    String additionOperatorTestTwo( "Flager Jr." );

    //displaying test for constructors
    cout << "TESTING CONSTRUCTORS" << endl;
    cout << defaultTest;
    cout << argumentOne;
    cout << argumentTwo;
    cout << argumentThree;
    cout << argumentFour;

    cout << endl;           //spacing line

    //displaying test for member functions
    cout << "TESTING MEMBER FUNCTIONS" << endl;
    cout << "APPEND 1: " << appendTestOne.append( 3, 'x' );
    cout << "APPEND 2: " << appendTestTwo.append( argumentOne );
    cout << "APPEND 3: " << appendTestThree.append( argumentOne, 4 );
    cout << "APPEND 4: " << appendTestFour.append( argumentOne, 2, 3 );

    cout << "COMPARE 1: " << compareTestOne.compare( compareTestTwo ) << endl;
    cout << "COMPARE 2: " << compareTestOne.compare( 2, 3, "BbCCDD" ) << endl;

    cout << "FRONT: " << argumentOne.front() << endl;

    cout << "LENGTH: " << argumentOne.length() << endl;

    cout << "PROJECTION 1: " << projectionTestOne.projection( 'B' );
    cout << "PROJECTION 2: " << projectionTestTwo.projection( "eol" );

    cout << "REVERSE: " << reverseTest.reverse();

    cout << "SIZE: " << argumentOne.size() << endl;

    cout << "SUBSTR: " << argumentOne.substr( 0, 4 ) << endl;

    cout << endl;           //spacing line

    //displaying test for overloaded operators
    cout << "TESTING OVERLOADED OPERATORS" << endl;
    cout << assignmentOperatorTest;
    cout << additionOperatorTestOne + additionOperatorTestTwo;
    
    return 0;
}

//constructor definitions

/**************************************************************************************
 * Default constructor that initalizes object to nullptr
**************************************************************************************/
String::String() {
    charptr = nullptr;
}

/**************************************************************************************
 * Argument constructor that initalizes object to the passed value
 * temp is the passed value
**************************************************************************************/
String::String( const char * temp ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed variable
    while( temp[ count ] != '\0' ) {
        count++;
    }

    //creating dynamic array
    charptr = new char[ count + 1 ];

    //coppying the data over
    for( int i = 0; i < count; i++ ) {
        charptr[ i ] = temp[ i ];
    }
    
    //setting null terminator
    charptr[ count ] = '\0';

}

/**************************************************************************************
 * Argument constructor that copies the passed object to the new object
 * copy is the passed object
**************************************************************************************/
String::String( const String &copy ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed variable
    while( copy.charptr[ count ] != '\0' ) {
        count++;
    }

    //creating dynamic array
    charptr = new char[ count + 1 ];

    //copying the data over
    for( int i = 0; i < count; i++ ) {
        charptr[ i ] = copy.charptr[ i ];
    }
    
    //setting null terminator
    charptr[ count ] = '\0';
}

/**************************************************************************************
 * Argument constructor that initializes the object with number numbers of letter
 * letter is the letter that will be put in the object
 * number is the number of letters that will be in the object
**************************************************************************************/
String::String( char letter, int number ) {
    //creating dynamic array
    charptr = new char[ number + 1 ];

    //initializing object with number numbers of letter
    for(int i = 0; i < number; i++ ) {
        charptr[ i ] = letter;
    }
    
    //setting null terminator
    charptr[ number ] = '\0';
}

/**************************************************************************************
 * Argument constructor that initializes the object with substring of passed object
 * copy is the passed object
 * position is the where the new object will start copying relative to the passed object
 * length is the length of the substring of the passed object
**************************************************************************************/
String::String( String &copy, int position, int length ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed variable
    while( copy.charptr[ count ] != '\0' ) {
        count++;
    }
    
    //creating dynamic array
    charptr = new char[ count + 1 ];

    //copying the data over
    for( int i = 0; i < length; i++ ) {
        charptr[ i ] = copy.charptr[ position ];

        position++;     //incrementing position
    }
    
    //setting null terminator
    charptr[ count ] = '\0';
}

//member functions

/**************************************************************************************
 * Member function that appends letter to the end of a string
 * number is the number of letters being added
 * letter is the character that is being added
**************************************************************************************/
String String::append( int number, char letter ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size
    int newSize = 0;                        //holds new size

    //finding size of the passed variable
    while( charptr[ count ] != '\0' ) {
        count++;
    }

    //creating array to temporairly hold values
    char temp[ count + 1 ];

    //coppying data
    for( int i = 0; i < count; i++ ) {
        temp[ i ] = charptr[ i ];
    }

    newSize = count + number;           //computing new size

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //recreating newly allocated data with updated size

    //coppying data back
    for( int i = 0; i < newSize; i++ ) {
        //normal data
        if( i < count ) {
            charptr[ i ] = temp[ i ];
        }
        //added letters
        else {
            charptr[ i ] = letter;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that appends data to the end of another data
 * temp is the data being appened
**************************************************************************************/
String String::append( const String &temp ) {
    //local variable declaration
    int countOne = 0;                       //counter variable to obtain size
    int countTwo = 0;                       //counter variable to obtain size
    int countThree = 0;                     //holds position of elements in passed array
    int newSize = 0;                        //holds new size

    //finding size of the passed variable
    while( charptr[ countOne ] != '\0' ) {
        countOne++;
    }

    //finding size of the passed variable
    while( temp.charptr[ countTwo ] != '\0' ) {
        countTwo++;
    }

    //creating array to temporairly hold values
    char placeHolder[ countOne + 1 ];

    //coppying data
    for( int i = 0; i < countOne; i++ ) {
        placeHolder[ i ] = charptr[ i ];
    }

    newSize = countOne + countTwo;      //computing new size

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //recreating newly allocated data with updated size

    //coppying data back
    for( int i = 0; i < newSize; i++ ) {
        //normal data
        if( i < countOne ) {
            charptr[ i ] = placeHolder[ i ];
        }
        //added letters
        else {
            charptr[ i ] = temp.charptr[ countThree ];
            countThree++;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that appends a certain number of letter from one data to another
 * temp is the data being appened
 * number is how many charcter is being appened
**************************************************************************************/
String String::append( const String &temp, int number )
{
    //local variable declaration
    int countOne = 0;                       //counter variable to obtain size
    int countTwo = 0;                       //counter variable to obtain size
    int newSize = 0;                        //holds new size

    //finding size of the passed variable
    while( charptr[ countOne ] != '\0' )
    {
        countOne++;
    }

    //creating array to temporairly hold values
    char placeHolder[ countOne + 1 ];

    //coppying data
    for( int i = 0; i < countOne; i++ ) {
        placeHolder[ i ] = charptr[ i ];
    }

    newSize = countOne + number;      //computing new size

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //recreating newly allocated data with updated size

    //coppying data back
    for( int i = 0; i < newSize; i++ ) {
        //normal data
        if( i < countOne ) {
            charptr[ i ] = placeHolder[ i ];
        }
        //added letters
        else {
            charptr[ i ] = temp.charptr[ countTwo ];
            countTwo++;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that appends charcters from one data to another
 * temp is the data being appended
 * position is the starting position of data being appened
 * number is the number of charcters being appened
**************************************************************************************/
String String::append( const String &temp, int position, int number ) {
    //local variable declaration
    int countOne = 0;                       //counter variable to obtain size
    int newSize = 0;                        //holds new size

    //finding size of the passed variable
    while( charptr[ countOne ] != '\0' ) {
        countOne++;
    }

    //creating array to temporairly hold values
    char placeHolder[ countOne + 1 ];

    //coppying data
    for( int i = 0; i < countOne; i++ ) {
        placeHolder[ i ] = charptr[ i ];
    }

    newSize = countOne + number;      //computing new size

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //recreating newly allocated data with updated size

    //coppying data back
    for( int i = 0; i < newSize; i++ ) {
        //normal data
        if( i < countOne ) {
            charptr[ i ] = placeHolder[ i ];
        }
        //added letters
        else {
            charptr[ i ] = temp.charptr[ position ];
            position++;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that assigns letters to data
 * copies is the number of letters
 * letter is the letter
**************************************************************************************/
void String::assign( int copies, char letter ) {
    int count;      // counter in for loop
    
    //if user enters less than zero for copies, display message and end program
    if( copies < 0 ) {
        cout << "You are unable to assign this number of copies.";
        exit( EXIT_FAILURE );
    }
    
    //if charptr has anything in it (is not nullptr), delete memory allocated for charptr
    if( charptr != nullptr ) {
        delete [] charptr;
    }
    
    //allocate memory for charptr with size being number of copies
    charptr = new char[ copies ];
    
    //for loop to assign letter to charptr count number of times
    for( count = 0; count < copies; count++ ) {
        charptr[ count ] = letter;
    }
    
    //set null terminator
    charptr[ count ] = '\0';
}

/**************************************************************************************
 * Member function that assigns data to data
 * str is the data being added
**************************************************************************************/
void String::assign( const char * str ) {
    int count;          //counter in for loop
    int lenstr = 0;     //holds size of str
    
    //find size of str
    while( str[ lenstr ] != '\0' ) {
        lenstr++;
    }
    
    //charptr is not null, delete memory allocated to charptr
    if( charptr != nullptr ) {
        delete [] charptr;
    }
    
    //allocate memory for charptr with size of str
    charptr = new char[ lenstr ];
    
    //for loop to assign str to charptr
    for( count = 0; count < lenstr; count++ ) {
        charptr[ count ] = str[ count ];
    }
    
    //set null terminator
    charptr[ count ] = '\0';
}

/**************************************************************************************
 * Member function that assigns data to data
 * str is the data being added
**************************************************************************************/
void String::assign( String &str ) {
    int count;          //counter in for loop
    int lenstr = 0;     //holds size of str
    
    //find size of str
    while( str.charptr[ lenstr ] != '\0' ) {
        lenstr++;
    }
    
    //charptr is not null, delete memory allocated to charptr
    if( charptr != nullptr ) {
        delete [] charptr;
    }
    
    //allocate memory for charptr with size of str
    charptr = new char[ lenstr ];
    
    //for loop to assign str to charptr
    for( count = 0; count < lenstr; count++ ) {
        charptr[ count ] = str.charptr[ count ];
    }
    
    //set null terminator
    charptr[ count ] = '\0';
}

/**************************************************************************************
 * Member function that assigns data to data
 * str is the data
 * number is the number of data
**************************************************************************************/
void String::assign( const char * str, int number ) {
    int count;
    int lenstr = 0;
    
    //find size of str
    while( str[ lenstr ] != '\0' ) {
        lenstr++;
    }
    
    //check if number is less than 0, if so display message and end program
    if( number < 0 ) {
        cout << "Error: The integer you have enter is invalid.";
        exit( EXIT_FAILURE );
    }
    
    //check if lenstr is number than lenstr, if so assign value of lenstr to number
    if( number > lenstr ) {
        number = lenstr;
    }
    
    //check if charptr is not null,  if so delete memory allocated to charptr
    if( charptr != nullptr ) {
        delete [] charptr;
    }
    
    //allocate memory for charptr with size of str
    charptr = new char[ number ];
    
    //for loop to assign str to charptr
    for( count = 0; count < number; count++ ) {
        charptr[ count ] = str[ count ];
    }
    
    //set null terminator
    charptr[ count ] = '\0';
}

/**************************************************************************************
 * Member function that assigns data to another data at a specifided position
 * str is the data
 * position is the position
 * number is the amount
**************************************************************************************/
void String::assign( const char * str, int position, int number ) {
    int lenstr = 0;         //holds size of str
    int charcount = 0;      //counter for charptr, when str is being assigned to charptr
    int count;              //counter in for loop, will have value of position assigned to it
    
    // find size of str
    while( str[ lenstr ] != '\0' ) {
        lenstr++;
    }
    
    //check if number is less than 0, if so assign value of number as size of str - position
    if( number < 0 ) {
        number = lenstr - position;
    }
    
    //check if lenstr is number than lenstr, if so assign value of lenstr to number
    if( number > lenstr ) {
        number = lenstr;
    }
    
    //check if position is not within bounds, if so display message and end program
    if( position < 0 || position > lenstr ) {
        cout << "Error: The position you have entered is outside the bounds.";
        exit( EXIT_FAILURE );
    }
    
    //if charptr is not null, delete memory allocated to charptr
    if( charptr != nullptr ) {
        delete [] charptr;
    }
    
    //allocate memory for charptr with size of str
    charptr = new char[ number ];
    
    //assign position to count
    count = position;
    
    //for loop to assign str to charptr
    for( int count; count < number + position; count++ ) {
        charptr[ charcount ] = str[ count ];
        charcount++;                        //increment charcount by 1
    }
    
    //set null terminator
    charptr[ charcount ] = '\0';
}

/**************************************************************************************
 * Member function that returns character at specified position
 * check is the position
**************************************************************************************/
char String::at( int check ) {
    int size;          // to hold size of object
    
    // check if charptr is not null; if so continue, otherwise display message
    if( charptr != nullptr ) {
        // find size of object
        while( charptr[size] != '\0' ) {
            size++;
        }
            
        //check if user entry if within the size of the string; if so display message, otherwise return character
        if( check > size - 1 || check < 0 ) {
            // display message to user stating their input is not within bounds
            cout << "Error: The position which is to be looked for does not exist.";
            
            // end program
            exit( EXIT_FAILURE );
        }
        else {
            // return character in user's input
            return charptr[ check ];
        }
    }
    else {
        //display message to user stating there is no data in the object
        cout << "Error: There is no data in the object.";
        
        //end program
        exit( EXIT_FAILURE );
    }
}

/**************************************************************************************
 * Member function that clears the data
**************************************************************************************/
void String::clear() {
    if( charptr != nullptr ) {
        delete [] charptr;
        charptr = nullptr;
    }
}

/**************************************************************************************
 * Member function that returns 0 if data is equal and -1 if not
 * temp is the data being compared
**************************************************************************************/
int String::compare( const String &temp ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed variable
    while( charptr[ count ] != '\0' ) {
        count++;
    }

    //checking if equal
    for( int i = 0; i < count; i++ ) {
        //checking if characters are not equal return the difference
        if( charptr[ i ] != temp.charptr[ i ] ) {
            return ( charptr[ i ] - temp.charptr[ i ] );
        }
    }

    //went through loop with everything correct
    return 0;
}

/**************************************************************************************
 * Member function that returns 0 if data is equal and -1 if not
 * position is the start position of comparing
 * length is how many charcter to compare
 * temp is the data being compared
**************************************************************************************/
int String::compare( int position, int length, const String &temp ) {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed temp variable
    while( temp.charptr[ count ] != '\0' ) {
        count++;
    }

    //comparing the specific section of data
    for( int i = 0; i < length; i++ ) {
        //if not equal return the difference
        if( charptr[ position ] != temp.charptr[ i ] ) {
            return ( charptr[ position ] - temp.charptr[ i ] );
        }

        position++;     //incrementing position
    }
    
    //went through loop with everything correct
    return 0;
}

/**************************************************************************************
 * Member function that checks if data is empty
**************************************************************************************/
bool String::empty() {   
    //check if charptr is not set to nullptr, if so return false
    if( charptr != nullptr ) {
        return false;
    }
    //otherwise, if charptr is set to nullptr, return true
    else {
        return true;
    }
}

/**************************************************************************************
 * Member function that return the postion of the character
 * letter is the letter
 * position is the starting position
**************************************************************************************/
int String::find( char letter, int position ) {
    int size = 0;      // to hold size of object
    
    //check if charptr does not have any memory allocation, if so return -1
    if( charptr == nullptr ) {
        return -1;
    }
    else {
        //to find size of object
        while( charptr[ size ] != '\0' ) {
            size++;
        }
        
        //for loop to go through each element of charptr
        for( int position; position < size - 1; position++ ) {
            //check if element is letter, if so return position
            if( charptr[ position ] == letter ) {
                return position;
            }
        }
        
        //if letter has not been found, return -1
        return -1;
    }
}

/**************************************************************************************
 * Member function that return the postion of the character
 * str is the data
 * position is the starting position
**************************************************************************************/
int String::find( const char * str, int position ) {
    int lenstr = 0;         // holds size of str
    int lenchar = 0;        // holds size of charptr
    bool match = true;      // to check if charptr and str match
    int checkamount;        // holds number of times charptr will be checked for str
    int count;              // counter in for loop
    int charcount = 0;      // holds count of charptr
    int tally = 0;          // holds count for str
    int strpos;             // holds position of str
    
    //check if charptr is null, if so return -1
    if( charptr == nullptr ) {
        return -1;
    }
    else {
        // find size of charptr
        while( charptr[ lenchar ] != '\0' ) {
            lenchar++;
        }
        
        //find size of str
        while( str[ lenstr ] != '\0' ) {
            lenstr++;
        }
        
        //check if length of str is greater than charptr, if so return -1
        if( lenstr > lenchar - position ) {
            return -1;
        }
        
        // check if position is not within search bounds, if so return -1
        if( position > lenchar - 1 || position < 0 ) {
            return -1;
        }
        
        //calculate number of times charptr will be checked for str
        checkamount = lenchar - position - lenstr + 1;
        
        // loop through number of time charptr is being checked (checkamount)
        for( count = 0; count < checkamount; count++ ) {
            //set charcount, tally, match, and strpos after for loop starts/loops
            charcount = position + count;
            tally = 0;
            match = true;
            strpos = charcount;
            
            //loop to check if str matches what is being checked in charptr
            while( tally < lenstr && match == true ) {
                //if the character of charptr matches character of str, increment tally and charcount
                if( charptr[ charcount ] == str[ tally ] ) {
                    tally++;
                    charcount++;
                }
                //otherwise, set match to false to end the while loop
                else {
                    match = false;
                }
            }
            
            //if match is true after while loop, return starting position of last check (position of str)
            if( match == true ) {
                return strpos;
            }
        }
        
        //return -1 if loop ends and nothing is returned (match must be false if loop ended)
        return -1;
    }
}

/**************************************************************************************
 * Member function that return the postion of the character
 * str is the data
 * position is the starting position
**************************************************************************************/
int String::find( String &str, int position ) {
    int lenstr = 0;         // holds size of str
    int lenchar = 0;        // holds size of charptr
    bool match = true;      // to check if charptr and str match
    int checkamount;        // holds number of times charptr will be checked for str
    int count;              // counter in for loop
    int charcount = 0;      // holds count of charptr
    int tally = 0;          // holds count for str
    int strpos;             // holds position of str
    
    // check if charptr is null, if so return -1
    if( charptr == nullptr ) {
        return -1;
    }
    else {
        //find size of charptr
        while( charptr[ lenchar ] != '\0' ) {
            lenchar++;
        }
        
        // find size of str
        while( str.charptr[ lenstr ] != '\0' ) {
            lenstr++;
        }
        
        //check if length of str is greater than charptr, if so return -1
        if( lenstr > lenchar - position ) {
            return -1;
        }
        
        //check if position is not within search bounds, if so return -1
        if( position > lenchar - 1 || position < 0 ) {
            return -1;
        }
        
        //calculate number of times charptr will be checked for str
        checkamount = lenchar - position - lenstr + 1;
        
        //loop through number of time charptr is being checked (checkamount)
        for( count = 0; count < checkamount; count++ ) {
            //set charcount, tally, match, and strpos after for loop starts/loops
            charcount = position + count;
            tally = 0;
            match = true;
            strpos = charcount;
            
            //loop to check if str matches what is being checked in charptr
            while( tally < lenstr && match == true ) {
                //if the character of charptr matches character of str, increment tally and charcount
                if( charptr[ charcount ] == str.charptr[ tally ] ) {
                    tally++;
                    charcount++;
                }
                // therwise, set match to false to end the while loop
                else {
                    match = false;
                }
            }
            
            //if match is true after while loop, return starting position of last check (position of str)
            if( match == true ) {
                return strpos;
            }
        }
        
        //return -1 if loop ends and nothing is returned (match must be false if loop ended)
        return -1;
    }
}

/**************************************************************************************
 * Member function that returns the first character of the data
**************************************************************************************/
char String::front() {
    return charptr[ 0 ];
}

/**************************************************************************************
 * Member function inserts letters into the data
 * position is the starting position
 * copies is the number of letters
 * letter is the letter
**************************************************************************************/
void String::insert( int position, int copies, char letter ) {
    int count;              //counter in for loop
    int size = 0;           //holds size of object
    char *temp = nullptr;   //temporary char pointer used to hold original object data
    int tally;              //counter in for loop
    int tempcount = 0;      //counter for temp elements used
    
    //check if charptr is null; if so continue, otherwise run other code
    if( charptr == nullptr ) {
        // check is position is not 0, if so display message and end program
        if( position != 0 ) {
            cout << "This position (" << position << ") is not in the bounds.";
            exit( EXIT_FAILURE );
        }
        
        // heck if copies is less than 0, if so display message and end program
        if( copies < 0 ) {
            cout << "You are unable to insert this number of copies (" << copies << ").";
            exit( EXIT_FAILURE );
        }
        
        //allocate memory for charptr, character array
        charptr = new char[ copies ];
        
        //for loop to insert letters into charptr
        for( count = 0; count < copies; count++ ) {
            charptr[ count ] = letter;
        }
        
        //add null terminator
        charptr[ count ] = '\0';
    }
    else {
        //find size of object
        while( charptr[ size ] != '\0' ) {
            size++;
        }
        
        //check if position is within size of object, if so display message and end program
        if( position > size || position < 0 ) {
            cout << "Error: This position (" << position << ") is not within bounds.";
            exit( EXIT_FAILURE );
        }
        
        //check if copies is less than 0, if so display message and end program
        if( copies < 0 ) {
            cout << "You are unable to insert this number of copies (" << copies << ").";
            exit( EXIT_FAILURE );
        }
        
        //for loop to transfer data from charptr to temp
        for( tally = 0; tally < size; tally++ ) {
            temp[ tally ] = charptr[ tally ];
        }
        
        //delete memory allocated to charptr
        delete [] charptr;
        
        //allocate new memory for charptr
        charptr = new char[ size + copies ];
        
        //for loop to transfer data from 0 to position from temp to charptr
        for( count = 0; count < position; count++ ) {
            charptr[ count ] = temp[ tempcount ];
            tempcount++;                            //increment tempcount by 1
        }
        
        //for loop to insert letter from count to position + copies
        for( int count; count < position + copies; count++ ) {
            charptr[ count ] = letter;
        }
        
        //for loop to transfer the rest of data from temp to charptr
        for( int count; count < size + copies; count++ ) {
            charptr[ count ] = temp[ tempcount ];
            tempcount++;                            //increment tempcount by 1
        }
        
        //add null terminator
        charptr[ count ] = '\0';
    }
}

/**************************************************************************************
 * Member function that inserts data into another data
 * position is the starting position
 * str is the data being inserted
**************************************************************************************/
void String::insert( int position, const char * str ) {
    char *temp = nullptr;       //pointer character variable, hold what user is passing
    int lenstr = 0;             //hold length of str
    int lenchar = 0;            //hold length of charptr
    int count;                  //counter in for loop
    int tally;                  //counter in for loop
    int tempcount = 0;          //counter for temp pointer
    int strcount = 0;           //counter for str variable
    
    //check if str is null
    if( str != nullptr ) {
        //check if charptr is null
        if( charptr == nullptr ) {
            //check if position is not 0, if so display message and end program
            if( position != 0 ) {
                cout << "This position (" << position << ") is not in the bounds.";
                exit( EXIT_FAILURE );
            }
            
            //find size of str
            while( str[ lenstr ] != '\0' ) {
                lenstr++;
            }
            
            //allocate memory for charptr
            charptr = new char[ lenstr ];
            
            for( count = 0; count < lenstr; count++ ) {
                charptr[ count ] = str[ count ];
            }
            
            charptr[ count ] = '\0';
        }
        else {
            //find size of str
            while( str[ lenstr ] != '\0' ) {
                lenstr++;
            }
            
            //find size of charptr
            while( charptr[ lenchar ] != '\0' ) {
                lenchar++;
            }
            
            //check if position is within size of object, if so display message and end program
            if( position > lenchar || position < 0 ) {
                cout << "Error: This position (" << position << ") is not within bounds.";
                exit( EXIT_FAILURE );
            }
            
            //allocate memory for temp
            temp = new char[ lenchar ];
            
            //move charptr data into temp
            for( count = 0; count < lenchar; count++ ) {
                temp[ count ] = charptr[ count ];
            }
            
            //delete memory allocated to charptr
            delete [] charptr;
            
            //allocate memory for temp
            charptr = new char[ lenchar + lenstr ];
            
            //for loop to transfer information from temp to charptr from 0 to position
            for( tally = 0; tally < position; tally++ ) {
                charptr[ tally ] = temp[ tempcount ];
                tempcount++;                            //increment tempcount by 1
            }
            
            //for loop to transfer information from str to charptr from tally to position + lenstr
            for( int tally; tally < position + lenstr; tally++ ) {
                charptr[ tally ] = str[ strcount ];
                strcount++;                             //increment strcount by 1
            }
            
            //for loop to transfer information from temp to charptr from tally to total size
            for( int tally; tally < lenchar + lenstr; tally++ ) {
                charptr[ tally ] = temp[ tempcount ];
                tempcount++;                            //increment tempcount by 1
            }
            
            // add null terminator
            charptr[ tally ] = '\0';
        }
    }
}

/**************************************************************************************
 * Member function that checks if data is palindrome
**************************************************************************************/
bool String::palindrome() {
    int start = 0;          // initalize start as 0, holds first character being checked
    int end;                // holds final character being checked
    int size = 0;           // initalize size as 0, holds size of charptr
    
    // get size of charptr
    while( charptr[ size ] != '\0' ) {
        size++;
    }
    
    //set end as size of charptr - 1
    end = size - 1;
    
    //loop to check for palindrome; while start is less then end, loop
    while( start < end ) {
        //if start character and end character of charptr do not match, return false; otherwise increment start and decrement end
        if( charptr[ start ] != charptr[ end ] ) {
            return false;
        }
        else {
            start++;
            end--;
        }
    }
    
    //return true when loop is done (if looped through fully, it is a palindrome)
    return true;
}

/**************************************************************************************
 * Member function that checks if data is palindrome
 * start is the starting position
 * length is how many characters
**************************************************************************************/
bool String::palindrome( int start, int length ) {
    int end;        // holds final character being checked
    int size = 0;   // initalize size as 0, holds size of charptr
    
    // find size of charptr
    while( charptr[ size ] != '\0' ) {
        size++;
    }
    
    //check if start is negative, if so display message and end program
    if( start < 0 ) {
        cout << "Error: The number which has been entered as the start of the check is invalid (neagtive).";
        exit( EXIT_FAILURE );
    }
    
    //check if length is negative, if so display message and end program
    if( length < 0 ) {
        cout << "Error: The number which has been entered as the length of the check is invalid (neagtive).";
        exit( EXIT_FAILURE );
    }
    
    //check if start + length is outside greater then size, if so display message and end program
    if( start + length > size ) {
        cout << "Error: You have entered a start and/or length that has caused the check to be outside the bounds.";
        exit( EXIT_FAILURE );
    }
    
    // assign end as start + length - 1
    end = start + length - 1;
    
    //loop to check for palindrome; while start is less then end, loop
    while( start < end ) {
        //if start character and end character of charptr do not match, return false; otherwise increment start and decrement end
        if( charptr[ start ] != charptr[ end ] ) {
            return false;
        }
        else {
            start++;
            end--;
        }
    }
    
    //return true when loop is done (if looped through fully, it is a palindrome)
    return true;
}

/**************************************************************************************
 * Member function that deletes characters that is passed from the data
 * letter is the letter being removed from data
**************************************************************************************/
String String::projection( char letter ) {
    //local variable declaration
    int countOne = 0;                           //counter variable to obtain size
    int countTwo = 0;                           //holds number of letter in the data
    int countThree = 0;                         //holds index of new array
    int newSize = 0;                            //holds size of new array

    //finding size of the passed temp variable
    while( charptr[ countOne ] != '\0' ) {
        countOne++;
    }

    char temp[ countOne ];      //temp to hold data

    //coppying data
    for( int i = 0; i < countOne; i++ ) {
        temp[ i ] = charptr[ i ];
    }

    //finding how many letters are in the data
    for( int i = 0; i < countOne; i++ ) {
        if( charptr[ countOne ] == letter ) {
            countTwo++;
        }
    }

    //computing new size
    if( countOne > countTwo ) {
        newSize = countOne - countTwo;
    }
    else {
        newSize = countTwo - countOne;
    }

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //re-allocating memory
    
    //creating new array
    for( int i = 0; i < countOne; i++ ) {
        if( temp[ i ] != letter ) {
            charptr[ countThree ] = temp[ i ];
            countThree++;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that deletes characters that is passed from the data
 * temp holds the letters being removed
**************************************************************************************/
String String::projection( const String &temp ) {
    //local variable declaration
    int countOne = 0;                           //counter variable to obtain size
    int countTwo = 0;                           //holds number of letter in the data
    int newSize = 0;                            //holds size of new array
    int tempSize = 0;                           //holds the size of temp

    //finding size of the passed temp variable
    while( charptr[ countOne ] != '\0' ) {
        countOne++;
    }

    //finding size of the temp array
    while( temp.charptr[ tempSize ] != '\0' ) {
        tempSize++;
    }

    char originalData[ countOne ];      //temp to hold data

    //coppying data
    for( int i = 0; i < countOne; i++ ) {
        originalData[ i ] = charptr[ i ];
    }

    //counting instances of same character to determine new size of the data
    for( int i = 0; i < countOne; i++ ) {
        for( int j = 0; j < tempSize; j++ ) {
            if( charptr[ i ] == temp.charptr[ j ] ) {
                countTwo++;
            }
        }
    }

    //computing new size of array
    if( countOne > countTwo ) {
        newSize = countOne - countTwo;
    }
    else {
        newSize = countTwo - countOne;
    }

    delete [] charptr;                  //clearing memory

    charptr = new char[ newSize + 1 ];  //re-allocating memory
    
    //creating new array
    for( int i = 0; i < countOne; i++ ) {
        bool flag = false;
        static int index = 0;
        for( int j = 0; j < tempSize; j++ ) {
            if( originalData[ i ] == temp.charptr[ j ] ) {
                flag = false;
                break;
            }
            else {
                flag = true;
            }
        }

        if( flag == true ) {
            charptr[ index ] = originalData[ i ];
            index++;
        }
    }

    //setting null terminator
    charptr[ newSize ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that returns the length of the data
**************************************************************************************/
int String::length() {
    //local variable declaration
    int length = 0;                 //holds the length of the data

    //finding size of the passed variable
    while( charptr[ length ] != '\0' ) {
        length++;
    }

    return length;
}

/**************************************************************************************
 * Member function that reverses the data
**************************************************************************************/
String String::reverse() {
    //local variable declaration
    int count = 0;                          //counter variable to obtain size

    //finding size of the passed temp variable
    while( charptr[ count ] != '\0' ) {
        count++;
    }

    int casePosition[ count ];          //hold the position of the case of the letters

    int countDown = count - 1;          //hold the position of the last element in the data

    //creating temp array to hold values
    char temp[ count ];

    //coppying data over
    for( int i = 0; i < count; i++ ) {
        //if lowercase
        if( charptr[ i ] >= 97 && charptr[ i ] <= 122 ) {
            temp[ i ] = charptr[ i ];
            casePosition[ i ] = 0;          //set to 0 to symbolize the lowercase
        }
        //if uppercase
        else if( charptr[ i ] >= 65 && charptr[ i ] <= 90 ) {
            temp[ i ] = charptr[ i ];
            casePosition[ i ] = 1;          //set to 1 to symbolize the uppercase
        }
        //if other character
        else {
            temp[ i ] = charptr[ i ];
            casePosition[ i ] = 2;          //set to 2 to symbolize not letter
        }
    }

    delete [] charptr;                      //clearing memory

    charptr = new char[ count + 1 ];        //re-allocating memory

    //reversing data
    for( int i = 0; i < count; i++ ) {
        //needs to be lowercase
        if( casePosition[ i ] == 0 ) {
            //if already lowercase
            if( temp[ countDown ] >= 97 && temp[ countDown ] <= 122 ) {
                charptr[ i ] = temp[ countDown ];
            }
            //if uppercase
            else if( temp[ countDown ] >= 65 && temp[ countDown ] <= 90 ) {
                charptr[ i ] = ( temp[ countDown ] + 32 );
            }
        }
        //needs to be uppercase
        else if( casePosition[ i ] == 1 ) {
            //if lowercase
            if( temp[ countDown ] >= 97 && temp[ countDown ] <= 122 ) {
                charptr[ i ] = ( temp[ countDown ] - 32 );
            }
            //if already uppercase
            else if( temp[ countDown ] >= 65 && temp[ countDown ] <= 90 ) {
                charptr[ i ] = temp[ countDown ];
            }
        }
        //if other character
        else if( casePosition[ i ] == 2 ) {
            charptr[ i ] = temp[ countDown ];
        }
        countDown--;
    }

    //setting null terminator
    charptr[ count ] = '\0';

    return charptr;
}

/**************************************************************************************
 * Member function that returns the size of the data
**************************************************************************************/
int String::size() {
    //local variable declaration
    int size = 0;                   //hold size of data

    //finding size of the passed variable
    while( charptr[ size ] != '\0' )
    {
        size++;
    }

    return size;
}

/**************************************************************************************
 * Member function that returns a sub string of the data
 * position is the place the user want to begin the sub string
 * length is how long the sub string is
**************************************************************************************/
char * String::substr( int position, int length ) {
    //local variable declaration
    char * temp = nullptr;

    //creating dynamic array
    temp = new char[ length + 1 ];

    //copying the data over
    for( int i = 0; i < length; i++ ) {
        temp[ i ] = charptr[ position ];

        position++;     //incrementing position
    }
    
    //setting null terminator
    temp[ length ] = '\0';

    return temp;
}