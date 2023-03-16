#include "oop.h"

#include "CBase.h"
#include "CExtending.h"

int main(void) {
    // Create class variable and instantiate it.
    CExtending class;
    CONSTRUCT_CLASS(class, Extending);

    // Set instance variable of super class.
    class.CVARACCESS.VSUPER.instVar = 42069;

    // Get extended class to print variable info.
    class.CFUNCACCESS->PrintVar(&class);

    return 0;
}