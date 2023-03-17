#ifndef CMENU_H
#define CMENU_H

#include "oop.h"
#define MENU_MAX_LEN 20
#define ITEM_NAME_MAX 64

DECL_CLASS_FUNCS(Menu)
    DECL_CLASS_FUNC(Menu, PrintSelf, void);
    DECL_CLASS_FUNC(Menu, AddItem, void,, char*, float);
END_CLASS_FUNCS(Menu)

DEF_CLASS(Menu)
    // Good coding practice: prefix private variables with underscores, since there is no way to force it
    int _menuLen;
    float _priceList[MENU_MAX_LEN];
    char _nameList[MENU_MAX_LEN][ITEM_NAME_MAX + 1];
END_CLASS_DEF(Menu)

#endif//CMENU_H