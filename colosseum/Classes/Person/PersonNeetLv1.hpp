#ifndef PersonNeetLv1_hpp
#define PersonNeetLv1_hpp

#include "cocos2d.h"

#include "Person.hpp"

class PersonNeetLv1 : public Person
{
    PersonNeetLv1();
    ~PersonNeetLv1();
    
    std::string name;
    
    static std::string getImageName();
    static std::string getDisplayName();
};

#endif /* PersonNeetLv1_hpp */
