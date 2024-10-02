#include <iostream>
#include <cstdlib>

int main()
{
    /*
    Warning:
    Do not forget to include parentheses () after the function's name when making a function
    call.
    
    As an aside:
    “foo” is a meaningless word that is often used as a placeholder name for a function or
    variable when the name is unimportant to the demonstration of some concept. Such words
    are called metasyntactic variables (though in common language they’re often called
    “placeholder names” since nobody can remember the term “metasyntactic variable”).
    Other common metasyntactic variables in C++ include “bar”, “baz”, and 3-letter
    words that end in “oo”, such as “goo”, “moo”, and “boo”).
    */

    /*
    Tip:
    When a function returns a value, the caller may decide to use that value in an expression
    or statement (e.g. by using it to initialize a variable, or sending it to std::cout)
    or ignore it (by doing nothing else). If the caller ignores the return value, it is
    discarded (nothing is done with it).

    Best practice:
    Your main function should return the value 0 if the program ran normally.

    For advanced users:
    The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, and
    EXIT_FAILURE. 0 and EXIT_SUCCESS both mean the program executed successfully.
    EXIT_FAILURE means the program did not execute successfully.
    If you want to maximize portability, you should only use 0 or EXIT_SUCCESS to indicate
    a successful termination, or EXIT_FAILURE to indicate an unsuccessful termination.
    
    As an aside:
    C does allow main() to be called explicitly, so some C++ compilers will allow this for
    compatibility reasons.

    Best practice:
    Make sure your functions with non-void return types return a value in all cases.
    Failure to return a value from a value-returning function will cause undefined
    behaviour.

    Best practice:
    Follow the DRY best practice: “don’t repeat yourself”. If you need to do something more
    than once, consider how to modify your code to remove as much redundancy as possible.
    Variables can be used to store the results of calculations that need to be used more than
    once (so we don’t have to repeat the calculation). Functions can be used to define a
    sequence of statements we want to execute more than once. And loops can be used to execute
    a statement more than once.
    
    As an aside:
    The opposite of DRY is WET ("write everything twice").
    */
    
    // EXIT_SUCCESS and EXIT_FAILURE are preprocessor macros defined in the <cstdlib> header:
    // return EXIT_SUCCESS;

    /*
    Best practice:
    Do not put a return statement at the end of a non-value returning function.

    Tip:
    Some statements require values to be provided, and others do not.
    When we have a statement that consists of just a function call (e.g. the first printHi()
    in the above example), we’re calling a function for its behavior, not its return value.
    In this case, we can call either a non-value returning function, or we can call a
    value-returning function and just ignore the return value.
    When we call a function in a context that requires a value (e.g. std::cout), a value
    must be provided. In such a context, we can only call value-returning functions.
    */

    /*
    For advanced readers:
    The above rules around creation, initialization, and destruction are guarantees. That is,
    objects must be created and initialized no later than the point of definition, and
    destroyed no earlier than the end of the set of the curly braces in which they are
    defined (or, for function parameters, at the end of the function).
    In actuality, the C++ specification gives compilers a lot of flexibility to determine when
    local variables are created and destroyed. Objects may be created earlier, or destroyed
    later for optimization purposes. Most often, local variables are created when the
    function is entered, and destroyed in the opposite order of creation when the function
    is exited.
    
    Key insight:
    Names used for function parameters or variables declared in a function body are only
    visible within the function that declares them. This means local variables within a
    function can be named without regard for the names of variables in other functions.
    This helps keep functions independent.
    
    Best practice:
    Define your local variables as close to their first use as reasonable.

    As an aside:
    Due to the limitations of older, more primitive compilers, the C language used to require
    all local variables be defined at the top of the function.
    This style is suboptimal for several reasons:
    1. The intended use of these variables isn’t apparent at the point of definition. You
    have to scan through the entire function to determine where and how each are used.
    2. The intended initialization value may not be available at the top of the function
    (e.g. we can’t initialize sum to its intended value because we don’t know the value of
    x and y yet).
    3. There may be many lines between a variable’s initializer and its first use. If we
    don’t remember what value it was initialized with, we will have to scroll back to the
    top of the function, which is distracting.
    This restriction was lifted in the C99 language standard.
    */

    /*
    Best practice:
    When addressing compilation errors or warnings in your programs, resolve the first issue
    listed and then compile again.

    Best practice:
    Keep the parameter names in your function declarations.

    Tip:
    You can easily create function declarations by copy/pasting your function's header
    and adding a semicolon.

    The one definition rule (or ODR for short) is a well-known rule in C++. The ODR has
    three parts:
    1. Within a file, each function, variable, type, or template can only have one definition.
    Definitions occurring in different scopes (e.g. local variables defined inside different
    functions, or functions defined inside different namespaces) do not violate this rule.
    2. Within a program, each function or variable can only have one definition. This
    rule exists because programs can have more than one file. Functions and variables not
    visible to the linker are excluded from this rule
    3. Types, templates, inline functions, and inline variables are allowed to have duplicate
    definitions in different files, so long as each definition is identical.
    
    Violating part 1 of the ODR will cause the compiler to issue a redefinition error.
    Violating ODR part 2 will cause the linker to issue a redefinition error.
    Violating ODR part 3 will cause undefined behavior.

    For advanced readers:
    Functions that share an identifier but have different sets of parameters are also
    considered to be distinct functions, so such definitions do not violate the ODR.
    */

    /*
    Best practice:
    When you add new code files to your project, give them a .cpp extension.

    The limited visibility and short memory is intentional, for a few reasons:
    1. It allows the source files of a project to be compiled in any order.
    2. When we change a source file, only that source file needs to be recompiled.
    3. It reduces the possibility of naming conflicts between identifiers in different files.

    Key insight:
    When an identifier is used in an expression, the identifier must be connected to its
    definition.
    1. If the compiler has not yet seen either a forward declaration nor a definition for the
    identifier in the file being compiled, it will error at the point where the identifier is
    used.
    2. Otherwise, if a definition exists in the same file, the compiler will connect the use
    of the identifier to its definition.
    3. Otherwise, if a definition exists in a different file (and is visible to the linker),
    the linker will connect the use of the identifier to its definition.
    4. Otherwise, the linker will issue an error indicating that it couldn’t find a
    definition for the identifier.
    */

    /*
    Key insight:
    A name declared in a namespace won’t be mistaken for an identical name declared in another
    scope.

    Key insight:
    Only declarations and definitions can appear in a namespace.

    Key insight:
    When you use an identifier that is defined inside a namespace (such as the std namespace),
    you have to tell the compiler that the identifier lives inside the namespace.

    Best practice:
    Use explicit namespace prefixes to access identifiers defined in a namespace.

    Warning:
    Avoid using-directives (such as using namespace std;) at the top of your program or in
    header files. They violate the reason why namespaces were added in the first place.
    */

    /*
    Key insight:
    A translation unit contains both the processed code from the code file, as well as the
    processed code from all of the #included files.
    
    
    */

    return 0;
}