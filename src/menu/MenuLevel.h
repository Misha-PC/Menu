#if !defined(MENULEVEL_H)
#define MENULEVEL_H

#define DEBUG


#include <Arduino.h>

class MenuLevel{
private:
// public:
    enum itemType{
        SUBITEM, HANDLER
    };
    class IMenuItem{
    public:
        String name;
        IMenuItem* pNext;
        virtual itemType getType();
    };

    class MenuSubItem:public IMenuItem{
    public:
        MenuSubItem(String name, MenuLevel* pNextLevel);
        MenuLevel* pNextLevel;
        itemType getType() override{
            return itemType::SUBITEM;
        }
    };

    class MenuHandler:public IMenuItem{
    public:
        MenuHandler(String name, void (*handler));
        void (*handler)();
        itemType getType() override{
            return itemType::HANDLER;
        }
    };

    IMenuItem* getLast();
    IMenuItem* pFirst;
    uint8_t    size;
    
public:
    MenuLevel();

    void    addMenuItem   (String name, MenuLevel* pNextLevel);
    void    addMenuHandler(String name, void (*handler)      );
    uint8_t getSize();


    // operator


};

#endif // MENULEVEL_H
