#ifndef PersonGorilla_hpp
#define PersonGorilla_hpp

#include "cocos2d.h"

#include "Person.hpp"

class PersonGorilla : public Person
{
    PersonGorilla();
    ~PersonGorilla();
    
    std::string name;
    
    static std::string getImageName();
    static std::string getDisplayName();
};

#endif /* PersonGorilla_hpp */
