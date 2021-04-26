#pragma once

#include "csdl2/csdl2_internal.h"

_CSDL2_BEGIN

/*!
 *
 */
template <class _Struct>
class Handle {
public:
    /*!
    *
    */
    Handle(_Struct *const ptr)
        : handle_(ptr)
        , created_(false)
        , destroied_(false) {
    }

    /*!
    *
    */
    _Struct *getHandle() const {
        return handle_;
    }

    /*!
    *
    */
    virtual bool create() = 0;

    /*!
    *
    */
    virtual void destroy() = 0;

    /*!
    *
    */
    bool isCreated() const {
        return created_;
    }

    /*!
    *
    */
    bool isDestroied() const {
        return destroied_;
    }

protected:
    _Struct *handle_;

    bool created_;
    bool destroied_;
};

_CSDL2_END