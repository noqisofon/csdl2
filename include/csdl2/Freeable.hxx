#pragma once

#include "csdl2/csdl2_internal.h"

_CSDL2_BEGIN

/*!
 *
 */
template <class _Struct>
class Freeable {
public:
    /*!
    *
    */
    Freeable(_Struct *const ptr)
        : handle_(ptr)
        , freed_(false) {
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
    virtual void free() = 0;

    /*!
    *
    */
    bool isFreed() const {
        return freed_;
    }

protected:
    _Struct *handle_;

    bool freed_;
};

_CSDL2_END