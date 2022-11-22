/** Notes for vars
 * 
 * char -> 1 byte;
 * bool -> 1 byte; (could be a bit but we can only acess bytes not bits)
 * short -> 2 byte;
 * int -> 4 byte;
 * float -> 4 byte (needs a f attached to be a true float);
 * double -> 8 byte;
 * long -> 4 byte (Depending on the compiler);
 * long long-> 8 byte (Depending on the compiler);
 * Can be determined by sizeof
*/

/** Notes for headers
 * 
 * #pragma once -> include guard to only include the header once in a cpp file
 * #ifndef then #define (included code) #endif
 * <> include form one of the include directories (everything)
 * "" compiler include paths
 * Files without .h extension are from the c++ standard lib (with .h are from the c standard lib)
*/

/** Notes for if statements
 * 
 * if checks if what it receives is zero or not
 * comparisson checks if every bit in each side if the comparision is the same in a == 
 * so when it enters an if statement it only checks if the comparision is zero or not 
 * a nullptr is zero, thats is why you can check if pointer is null or not by just inserting into an if
 * (NULL is zero and nullptr is a prvalue of type nullptr_t which evaluates to zero when converted to a literal type (void*)0)
 *
 * Loops
 * 
 * While and for are the same but thing but one is more structured to iterate and the other to run inside a condition
 * do while run first the until the given condition stays true
*/

/** Notes for pointers
 * 
 * Int that stores an adress for all types
 * Types are just to tell the compiler what data is stored in the pointer
 * 
#include <iostream>
#include <string.h>

int main() {
    void* ptr = 0; 
    void* ptr1 = NULL; 
    void* ptr2 = nullptr;

    int var = 8;
 
    ptr2 = &var;
    
    void* ptr3 = &var;
    int* ptr4 = &var;
    double* ptr5 = (double*)&var;

    char chars[] = {0, 0, 0, 0, 0, 0, 0, 0};
    char* chars2 = new char[7];
    memset(chars, 7, sizeof(chars));

    char** addChars = &chars2;

    std::cin.get();
    delete[] chars2;
}
 * 
*/

/**
 * References 
 * 
 * Syntax sugar for pointers
 * references can point to nullptr, needs a variable
 * 
#include <iostream>
#include <string.h>

//BOTH FUNCTIONS DO THE SAME BECAUSE REFERENCES ARE JUST AN ALIAS
void inc(int& val){
    val++;
}

void inc2(int* val){
    //by order of operations it would increment first and then deref 
    //(incressing the memvalue)
    (*val)++;
}

int main() {
    int a = 3;
    int b = 8;
    //Alias to a
    int& refA = a;
    refA = b;   // a = 8

    refA = 2;

    inc(a);
    inc2(&a);
    inc(refA);

    std::cin.get();
}

 * 
*/

/**
 * Classes 
 * 
 * Allows the grouping of data and methods to manipulate that data
 * Variable made from class are objects and a new object variable is an instance of said object
 * Classes makes everything private by default
 * functions inside classes are called methods 
 * when writing a class it is usefull to right as youre going to use it
 * Classes in c++ are just functions that receive a param with the class name
 * ##################################################################
 * 
 * 
 * Structs
 * 
 * Same as classes but by default members are public
 * Used to maintain retro compatibility with c language
 * Usually used for simpler structure types
 * #define struct class -> would change the keyword struct per class and everything 
*/

/**
 * Static
 * 
 * static ouside of class -> present in declared translation unit
 * A global static var will be linked to that translation unit (it will be a private member of that file)
 * you can mark it as extern in the files outside its declaration file and then it will look for it
 * 
 * External linking -> making it look in another translation unit for this variable
 * extern int s_var;
 * 
 * ###############################################
 * static inside of class -> it will be shared by all instances of the class in which is declared
 * 
*/