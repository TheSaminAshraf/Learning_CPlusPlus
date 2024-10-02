#include <iostream>

int main()
{
    /*
    For advanced readers:
    Types of statements:
    1. Declaration statements
    2. Jump statements
    3. Expression statements
    4. Compound statements
    5. Selection statements (conditionals)
    6. Iteration statements
    7. Try blocks   
    
    Rule:
    Every C++ program must have a special function named main (all lower case letters). When
    the program is run, the statements inside of main are executed in sequential order.
    */
    
    std::cout << "Hello World!";    
    
    /*
    Warning:
    Do not use multi-line comments inside other multi-line comments. Wrapping
    single-line comments inside a multi-line comment is okay.

    Best practice:
    Comment your code liberally, and write your comments as if speaking to someone who has
    no idea what the code does. Do not assume you will remember why you made specific
    choices.    
    
    Tip:
    If you always use single line comments for your normal comments, then you can always
    use multi-line comments to comment out your code without conflict. If you use
    multi-line comments to document your code, then commenting out code using comments
    can become more challenging.
    If you do not need to comment out a code block that contains multi-line comments,
    you can also consider using the #if 0 preprocessor directive.
    */  
    
    /*
    Key insight:
    An object is used to store a value in memory. A variable is an object that has a name
    (identifier). Naming our objects let us refer to them again later in the program.   
    
    Best practice:
    Although the language allows you to do so, avoid defining multiple variables of the same
    type in a single statement. Instead, define each variable in a seperate statement
    on its own line (and then use a single-line comment to document what it is used for).
    */  
    
    // There are 6 basic ways to initialize variables in C++:
    int a;          // no initializer (default initialization)
    int b = 5;      // initializer after equals sign (copy initialization)
    int c(6);       // initializer in parenthesis (direct initialization)
    //List initialization methods ((C++11) preferred)
    int d{7};       // initializer in braces (direct list initialization)
    int e = {8};    // initializer in braces after equals sign (copy list initialization)
    int f {};       // initializer is empty braces (value initialization)   
    
    /*
    For advanced readers:
    Copy initialization is also used whenever values are implicitly copied or converted,
    such as when passing arguments to a function by value, returning from a function
    by value, or catching exceptions by value.  
    
    For advanced readers:
    Direct initialization is also used when values are explicitly cast to another type.
    One of the reasons direct initialization had fallen out of favor is because it makes it
    hard to differentiate variables from functions. 
    
    As an aside:
    Prior to the introduction of list initialization, some types of initialization required
    using copy initialization, and other types of initialization required using direct
    initialization. List initialization was introduced to provide a more consistent
    initialization syntax (which is why it is sometimes called “uniform initialization”)
    that works in most cases.   
    Additionally, list initialization provides a way to initialize objects with a list of
    values (which is why it is called “list initialization”).   
    
    Best practice:
    Prefer direct list initialization (or value initialization) for initializating your
    variables.  
    
    Best practice:
    Initialize your variables upon creation.
    */  
    
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is Alex." << std::endl;   
    
    /*
    Tip:
    In the above program, the second std::endl isn’t technically necessary, since the program
    ends immediately afterward. However, it serves a few useful purposes.
    First, it helps indicate that the line of output is a “complete thought” (as opposed to
    partial output that is completed somewhere later in the code). In this sense, it functions
    similarly to using a period in standard English.
    Second, it positions the cursor on the next line, so that if we later add additional lines
    of output (e.g. have the program say “bye!”), those lines will appear where we expect
    (rather than appended to the prior line of output).
    Third, after running an executable from the command line, some operating systems do not
    output a new line before showing the command prompt again. If our program does not end with
    the cursor on a new line, the command prompt may appear appended to the prior line of
    output, rather than at the start of a new line as the user would expect.    
    
    Best practice:
    Output a newline whenever a line of output is complete.

    Best practice:
    Prefer '\n' over std::endl when outputting text to the console.
    */  
    
    /*
    Best practice:
    There’s some debate over whether it’s necessary to initialize a variable immediately
    before you give it a user provided value via another source (e.g. std::cin), since the
    user-provided value will just overwrite the initialization value. In line with our previous
    recommendation that variables should always be initialized, best practice is to initialize
    the variable first.

    For advanced readers:
    The C++ I/O library does not provide a way to accept keyboard input without the user
    having to press enter. If this is something you desire, you’ll have to use a third
    party library. For console applications, we’d recommend pdcurses, FXTUI, cpp-terminal,
    or notcurses. Many graphical user interface libraries have their own functions to do this
    kind of thing.
    */

    /*
    Best practice:
    Avoid implementation-defined and unspecified behavior whenever possible, as they may
    cause your program to malfunction on other implementations.
    */  
    
    /*
    Identifier naming rules:
    1. The identifier cannot be a keyword. Keywords are reserved.
    2. The identifier can only be composed of letters (lower or upper case), numbers, and
    the underscore character. That means the name cannot contain symbols (except the
    underscore) nor whitespace (spaces or tabs).
    3. The identifier must begin with a letter (lower or upper case) or an underscore.
    It cannot start with a number.
    4. C++ is case-sensitive, and thus distinguishes between lower and upper case letters.
    nvalue is different than nValue is different than NVALUE.
    */
    
    // Identifier naming best practices:
    int value; // conventional
    int Value; // unconventional (should start with a lowercase letter)
    int VALUE; // unconventional (should start with a lowercase letter and be in all lowercase)
    int VaLuE; // unconventional

    int my_variable_name;   // conventional (separated by underscores/snake_case)
    int my_function_name(); // conventional (separated by underscores/snake_case)
    int myVariableName;     // conventional (intercapped/CamelCase)
    int myFunctionName();   // conventional (intercapped/CamelCase)
    // int my variable name;   // invalid (whitespace not allowed)
    // int my function name(); // invalid (whitespace not allowed)
    int MyVariableName;     // unconventional (should start with lower case letter)
    int MyFunctionName();   // unconventional (should start with lower case letter)

    /*
    Best practice:
    When working in an existing program, use the conventions of that program (even if
    they do not conform to modern best practices). Use modern best practices when you are
    writing new programs.
    */

    /*
    Best practice:
    Consider keeping your lines to 80 chars or less in length.

    Tip:
    Many editors have a built-in feature (or plugin/extension) that will show a line
    (called a “column guide”) at a given column (e.g. at 80 characters), so you can easily
    see when your lines are getting too long. To see if your editor supports this, do a
    search on your editor’s name + “Column guide”.

    Best practice:
    When working in an existing project, be consistent with whatever style has been already
    adopted.
    */

    /*
    Key insight:
    Literals are values that are inserted directly into the source code. These values usually
    appear directly in the executable code (unless they are optimized out).
    Objects and variables represent memory locations that hold values. These values can be
    fetched on demand.

    For advanced readers:
    For the operators that we call primarily for their return values (e.g. operator+ or
    operator*), it’s usually obvious what their return values will be (e.g. the sum or product
    of the operands).
    For the operators we call primarily for their side effects (e.g. operator= or operator<<),
    it’s not always obvious what return values they produce (if any).
    Both operator= and operator<< (when used to output values to the console) return their
    left operand. Thus, x = 5 returns x, and std::cout << 5 returns std::cout. This is done
    so that these operators can be chained.
    For example, x = y = 5 evaluates as x = (y = 5). First y = 5 assigns 5 to y. This
    operation then returns y, which can then be assigned to x.
    std::cout << "Hello " << "world" evaluates as (std::cout << "Hello ") << "world!".
    This first prints "Hello " to the console. This operation returns std::cout, which can
    then be used to print "world!" to the console as well.
    */

    /*
    Best practice:
    New programmers often try to write an entire program all at once, and then get
    overwhelmed when it produces a lot of errors. A better strategy is to add one piece at
    a time, make sure it compiles, and test it. Then when you’re sure it’s working, move
    on to the next piece.
    
    */

    /*
    Prefer ‘\n’ over std::endl when outputting text to the console.
    std::endl moves the cursor to the next line and flushes the buffer, '\n' does not.
    */  
    
    int x;
    x = 0;  
    
    return 0;
}
