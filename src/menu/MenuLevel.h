#if !defined(MENULEVEL_H)
#define MENULEVEL_H

#include <Arduino.h>

class MenuLevel{
private:
    class IMenuItem{
    public:
        String name;
        IMenuItem* pNext;
    };

    class MenuSubItem:IMenuItem{
    public:
        MenuLevel* pNextLevel;
        MenuSubItem(String name, MenuLevel* pNextLevel);
    };

    class MenuHandler:IMenuItem{
    public:
        void (*handler)();
        MenuHandler(String name, void (*handler));
    };

    IMenuItem* getLast();
    IMenuItem* pFirst;
    uint8_t    counter;
    
public:
    MenuLevel();

    void addMenuItem   (String name, MenuLevel* pNextLevel);
    void addMenuHandler(String name, void (*handler)      );


    // operator


};

#endif // MENULEVEL_H
