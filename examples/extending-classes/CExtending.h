#ifndef CEXTENDING_H
#define CEXTENDING_H

#include "oop.h"
#include "CBase.h"

DECL_CLASS_FUNCS_EXTENDS(Extending, Base)
    DECL_CLASS_FUNC(Extending, PrintVar, void);
END_CLASS_FUNCS(Extending)

DEF_CLASS(Extending)
    // make sure to declare super variables!
    DECL_SUPER_VARS(Base);
END_CLASS_DEF(Extending)

#endif