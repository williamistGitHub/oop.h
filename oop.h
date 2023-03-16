/**
 * oop.h version beta 1.0
 * copyright 2023 williamist
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef OOP_H
// Version of library being used as a signed float (major.minor). Negative for betas.
// Minor updates dont break the api, major ones do.
#define OOP_H -1.0f

// Start declaring class functions for a class without a base class.
#define DECL_CLASS_FUNCS(className) typedef struct _C##className C##className; typedef struct _vt_C##className { \
  void* _vbase; \
  void (*_construct)(struct _C##className *self);
// Start declaring class functions for a class with a base class.
#define DECL_CLASS_FUNCS_EXTENDS(className, baseClassName) typedef struct _C##className C##className; typedef struct _vt_C##className { \
  struct _vt_C##baseClassName *_vbase; \
  void (*_construct)(struct _C##className *self);
// Declare a class function for a class with a name, return value, and optional parameters.
// Add an extra comma after return value if you are adding parameters.
#define DECL_CLASS_FUNC(className, funcName, retVal, ...) retVal (*funcName)(struct _C##className *self __VA_ARGS__)
// Stop declaring class functions.
#define END_CLASS_FUNCS(className) } vt_C##className ; extern struct _vt_C##className _dv_C##className;

// Start declaring class instance variables.
#define DEF_CLASS(className) struct _id_C##className {
// Declare super class instance variables.
#define DECL_SUPER_VARS(superClassName) struct _id_C##superClassName _super
// Stop declaring class instance variables.
#define END_CLASS_DEF(className) }; \
  typedef struct _C##className { \
    struct _vt_C##className *_vtable; \
    struct _id_C##className _vars; \
  } C##className; \
  extern struct _C##className _d_C##className;

// The following macros should not be used in header files.

// Start declaring implementations of class functions for a class without a base class.
// The first one is ALWAYS the constructor.
#define DEF_CFUNC_IMPLEMENTATIONS(className) struct _vt_C##className _dv_C##className = { (void*)0,
// Start declaring implementations of class functions for a class with a base class.
// The first one is ALWAYS the constructor.
#define DEF_CFUNC_IMPLEMENTATIONS_EXTENDS(className, baseClassName) struct _vt_C##className _dv_C##className = { &_dv_C##baseClassName ,
// Stop declaring function implementations for a class.
#define END_CFUNC_IMPLS(className) }; struct _C##className _d_C##className = {&_dv_C##className };

// Construct a class into a stack variable.
#define CONSTRUCT_CLASS(classVar, className) classVar = _d_C##className ; classVar._vtable->_construct(&classVar)
// Construct a class into a pointer variable.
#define CONSTRUCT_CLASS_PTR(classPtr, className) *classVar = _d_C##className ; classVar->_vtable->_construct(classVar)
// Construct the base class of this class. Call at the start of constructor on a sub class.
#define CONSTRUCT_BASE_CLASS() self->_vtable->_vbase->_construct((void*)self)

// Access class functions from an instance. Always a pointer.
#define CFUNCACCESS _vtable
// Access instance variables from an instance. Never a pointer.
#define CVARACCESS _vars
// Access the super class functions from a CFUNCACCESS. Always a pointer, 0 if the class doesnt have a super.
#define FSUPER _vbase
// Access the super instance variables from a CVARACCESS. Never a pointer.
#define VSUPER _super

#endif // OOP_H