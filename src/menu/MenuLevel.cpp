#include "MenuLevel.h"



MenuLevel::MenuLevel(){
    pFirst  = nullptr;
    size = 0;
}

MenuLevel::IMenuItem* MenuLevel::getLast(){
    if(pFirst == nullptr)
        return nullptr;
    
    IMenuItem* current = pFirst;
    while(current->pNext != nullptr ){
        current = current->pNext;
    }
    return current;
}


void MenuLevel::addMenuHandler(String name, void (*handler)){
    if(pFirst  == nullptr){
        pFirst = new MenuHandler(name, handler);
    }
    else{
        IMenuItem* curent = getLast();
        curent->pNext = new MenuHandler(name, handler);
    }
    size++;
}

void MenuLevel::addMenuItem(String name, MenuLevel* pNextLevel){
    if(pFirst  == nullptr){
    #ifdef DEBUG
        Serial.print("Create first menu item: ");
        Serial.println(name);
    #endif
        pFirst = new MenuSubItem(name, pNextLevel);
    }
    else{
        IMenuItem* curent = getLast();
        // curent->pNext = new MenuSubItem(name, pNextLevel);
    #ifdef DEBUG
        Serial.print("Create not first menu item: ");
        Serial.println(name);
    #endif
    }
    size++;
}


uint8_t MenuLevel::getSize(){
    return size;
}