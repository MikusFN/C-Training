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
 * You can call free on a nullptr because it wont do nothing 
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
 * ##############################################################################################
 * static var inside of class -> it will be shared by all instances of the class in which is declared
 * Example Code:
  
  #include <iostream>
  
  struct entity {
  // This makes them part of the entity namespace even though they are inside the class/struct
  // They still obey the class acess rules like being private or public but they do not belong to any instance
      static int x, y;
  
  
  // Static methods cannot acess non static variables
  // because a class method receives an instance of the class that belongs to -> void Print(entity e) {} 
  // and a static method doesnt so it cannot know a instanced dependent variable
  
      static void Print() {
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
      }
  };
  
  // Defining the scope of the static variables
  int entity::x;
  int entity::y;
  
  int main() {
  
      
      entity e1;
      
      entity::x = 7;
      entity::y = 7;
  
      entity e2;
  
      // Class alias for the static var      
      e2.x = 6;
      e2.y = 9;
  
      e1.Print();
  
  
      std::cin.get();
  }
 */

/**
/**
 * Enums
 * 
 * Enumeration of values --> A way to name an integer
 * 
 * The values will increment from the last value placed
 * 
  #include <iostream>
  
  enum Letters { 
      A = 7, B, C, D
  };
  
  int main() {
  
      Letters letter = Letters::B;
  
      std::cout << "Print letter: " << letter << std::endl;
  
      std::cin.get();
  }
  
*/

/**

 * Constructors
 * 
 * Method that runs when a class instantiates
 * 
 * 
#include <iostream>

class entity
{
    
public:
    // If we dont want a default contrutor, like when we want a static only class
    entity() = delete;

    entity() {
        x = 6;
        y = 9;
    }

    void Print() {
        std::cout << "Printing X: " << x << std::endl;
        std::cout << "Printing Y: " << y << std::endl;
    }

private:
    int x, y;
};


int main() {

    entity e1;
    
    e1.Print();
    
    std::cin.get();
}
*/


/**
 * Destructor
 * 
 * Method called when a class instance is destroyed
 * 
 * Note than even when calling the destructor explicitly it will be run again when the application dies

#include <iostream>

class entity
{
public:
    static int s_Counter;

    entity() {
        
        ++s_Counter;
        m_Id = s_Counter;

        std::cout << "An entity class instance[" << m_Id <<"] has been CREATED!" << std::endl;
    }
    ~entity() {
        --s_Counter;
        std::cout << "An entity class instance[" << m_Id <<"] has been DESTROYED!" << std::endl;
    }
private:
    int m_Id = 0;
};

int entity::s_Counter;

int main() {

    // Since this is stack allocatted the destructor will only be called when the application ends
    entity e1;

    entity e2;

    e2.~entity();

    std::cin.get();
}
*/

/**
 * Inheritance
 * 
 * Allows common logic to be shared from a base class to its children
 * Avoids code repetition
 * 
#include <iostream>

class Entity {

    protected:
        void Move(float deltaX, float deltaY) {
            m_posX += deltaX;
            m_posY += deltaY;
        }

        float m_posX, m_posY;
};

// Player is now player and entity (both types)
class Player : public Entity {

    public:
        void SetName(const char* name) {
            m_name = name;
        }

        void PrintName() {
            std::cout << 
            "Entity name - " << m_name 
            << " at position [ X : " << m_posX  << " Y : " << m_posY << " ]"
            << std::endl;   
        }

        void MoveEntity(float deltaX, float deltaY) {
            Move(deltaX, deltaY);
        }
    private:
        const char* m_name;
};

int main() {

    std::cout << "size of Entity = " << sizeof(Entity) << std::endl;
    std::cout << "size of Player = " << sizeof(Player) << std::endl;
    std::cout << "size of Char = " << sizeof(char) << std::endl;
    std::cout << "size of Char* = " << sizeof(char*) << std::endl;

    Player _player;
    _player.SetName(("My Player"));
    _player.MoveEntity(3, 7);
    _player.PrintName();

    std::cin.get();
}

*/

/**
 * Virtual Functions
 * 
 * Dynamic dispatch - Implemented as a V-table [map of virtual functions inside the base class which will be done at runtime] by the compiler

#include <iostream>
#include <memory>

class Entity {
    public:
        void SetName(const char* name) {
            m_name = name;
        }
        // Tell the compiler to create a V-Table for this function so it can be overritten
        virtual void PrintName() {
               std::cout << 
               "Entity name - " << m_name 
               << std::endl;   
        }
    protected:
        // Sharing variable with children
        const char* m_name = "DEFAULT ENTITY";

};

// Player is now player and entity (both types)
class Player : public Entity {

    public:
        void SetName(const char* name) {
            m_name = name;
        }

        // The key word override (introduced C11) is optional
        void PrintName() override {
               std::cout << 
               "Player name - " << m_name 
               << std::endl;   
        }
    private:
        const char* m_name = "DEFAULT PLAYER";
    
};

void Print(Entity* entity)  {
    entity->PrintName();
}

int main() {
    Entity _entity;
    _entity.SetName("My Entity");
    _entity.PrintName();

    Player _player;
    _player.SetName("My Player");
    _player.PrintName();

    //std::unique_ptr<Player> _playerUnique = std::make_unique<Player>(_player);
    Print(&_player); 

    Entity* _entity2 = &_player;
    _entity2->PrintName();

    std::cin.get();
}

*/

/**
 * Pure Virtual Functions
 * 
 * Like a abstract class / Interface from other languages
 * Is a virtual function that demands the child class to define what this function is
 * If a sub class does not implement all pure virtual then it can not be instantiated 
 
#include <iostream>
#include <memory>

class Printable {
    public:
        virtual void PrintName() = 0;
        virtual void SetName(const char* name) = 0;

};

class Entity : public Printable {
    public:

        void SetName(const char* name) {};

        void PrintName() override {
               std::cout << 
               "Entity name - " << m_name 
               << std::endl;   
        }
        
    protected:
        // Sharing variable with children
        const char* m_name = "DEFAULT ENTITY";

};

// Player is now player and entity (both types)
class Player : public Entity{

    public:
        void SetName(const char* name) {
            m_name = name;
        }

        // The key word override (introduced C11) is optional
        void PrintName() override {
               std::cout << 
               "Player name - " << m_name 
               << std::endl;   
        }
    private:
        const char* m_name = "DEFAULT PLAYER";
    
};

void Print(Printable* printable)  {
    printable->PrintName();
}

int main() {
    //You need to use a class with the implementation of the virtual functions
    Entity* _entity = new Player();
    _entity->SetName("My Entity");
    
    // Even though this class is a sub class of Printable it does not implement printable
    // Making it unsuable for the Print method
    //Print(_entity);

    Player _player;
    _player.SetName("My Player");
    _player.PrintName();

    //std::unique_ptr<Player> _playerUnique = std::make_unique<Player>(_player);
    Print(&_player);
    Print(_entity);

    Entity _entityPlayer = *dynamic_cast<Entity*>(_entity);
    _entityPlayer.PrintName();

    Print(&_entityPlayer);
    
    std::cin.get();
}

*/

/**
 *  Vector
 * 
 *  In stack you only have about 1 MB of space so be aware on what you want in the stack
 *  std::vector<...> => allocates in the stack the vector strcuture but the object data is on the heap, and when the vector desctrutor is called the data will be deleted form the heap
 * 
 *  std::vector<int> (stack and no need to delete) vs int* = new (raw pointer will be heap allocated with the need of deleting it) 
 **/