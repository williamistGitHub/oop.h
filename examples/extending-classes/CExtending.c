#include "CExtending.h"

#include <stdio.h>

void CExtending__Construct(CExtending* self) {
    CONSTRUCT_BASE_CLASS(); // dont forget to call this if you are extending!
}

void CExtending__PrintVar(CExtending* self) {
    printf("Current variable value: %i\n", self->CVARACCESS.VSUPER.instVar);
}

DEF_CFUNC_IMPLEMENTATIONS_EXTENDS(Extending, Base)
    CExtending__Construct,
    CExtending__PrintVar
END_CFUNC_IMPLS(Extending)