#include "MenuLevel.h"



MenuLevel::MenuLevel(){
    pFirst  = nullptr;
    counter = 0;
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
        IMenuItem* last = getLast();

    }
}