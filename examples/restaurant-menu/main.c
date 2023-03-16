#include "oop.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "CMenu.h"

int main(void) {
    bool running = true;
    CMenu menu;
    CONSTRUCT_CLASS(menu, Menu);
    unsigned char choice;
    while (running) {
        printf("Current menu:\n");
        menu.CFUNCACCESS->PrintSelf(&menu);
        printf("\nPlease choose: \n 1. Add an item\n 2. Quit the app\n\n> ");
        choice = getchar() - 48;
        if (choice == 1) {
            printf("\nEnter item name > ");
            char newItemName[ITEM_NAME_MAX + 1];
            getchar(); // flush newline from stdin
            fgets(newItemName, ITEM_NAME_MAX, stdin);
            newItemName[strcspn(newItemName, "\n")] = 0; // remove trailing newline from item name

            printf("Enter price for '%s' > ", newItemName);
            char itemPriceStr[11];
            fgets(itemPriceStr, 10, stdin); 
            // gotta convert price to float!
            float itemPrice = strtof(itemPriceStr, NULL);

            menu.CFUNCACCESS->AddItem(&menu, newItemName, itemPrice);
        } else if (choice == 2) {
            running = false;
        } else {
            printf("\nThat choice is not on the list!\n");
        }
    }
    printf("\nThanks for trying this example of oop.h!\n");
}