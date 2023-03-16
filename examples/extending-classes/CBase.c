#include "CBase.h"

void CBase__Construct(CBase* self) {
    self->CVARACCESS.instVar = 0;
}

DEF_CFUNC_IMPLEMENTATIONS(Base)
    CBase__Construct
END_CFUNC_IMPLS(Base)