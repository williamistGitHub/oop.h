#include "CMenu.h"
#include <string.h>
#include <stdio.h>

void CMenu__Construct(CMenu* self) {
    self->CVARACCESS._menuLen = 0;
}

void CMenu__PrintSelf(CMenu* self) {
    for (int i = 0; i < self->CVARACCESS._menuLen; i++) {
        printf(" %s - $%.2f\n", self->CVARACCESS._nameList[i], self->CVARACCESS._priceList[i]);
    }
}

void CMenu__AddItem(CMenu* self, char newItemName[ITEM_NAME_MAX + 1], float newItemPrice) {
    if (self->CVARACCESS._menuLen == MENU_MAX_LEN) return; // don't want a buffer overflow now, do we?
    memcpy(self->CVARACCESS._nameList[self->CVARACCESS._menuLen], newItemName, ITEM_NAME_MAX + 1);
    self->CVARACCESS._priceList[self->CVARACCESS._menuLen] = newItemPrice;
    self->CVARACCESS._menuLen++;
}

DEF_CFUNC_IMPLEMENTATIONS(Menu)
    CMenu__Construct,
    CMenu__PrintSelf,
    CMenu__AddItem
END_CFUNC_IMPLS(Menu)