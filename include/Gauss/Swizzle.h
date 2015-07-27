/*
 * Swizzle.h
 * 
 * This file is part of the "GaussianLib" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __GS_SWIZZLE_H__
#define __GS_SWIZZLE_H__


#include "Decl.h"
#include "Config.h"


#define __GS_SWIZZLE_REF2__(v0, v1) \
    Vector2T<T> v0##v1() const      \
    {                               \
        return Vector2T<T>(v0, v1); \
    }

#define __GS_SWIZZLE_REF3__(v0, v1, v2) \
    Vector3T<T> v0##v1##v2() const      \
    {                                   \
        return Vector3T<T>(v0, v1, v2); \
    }

#define __GS_SWIZZLE_REF4__(v0, v1, v2, v3) \
    Vector4T<T> v0##v1##v2##v3() const      \
    {                                       \
        return Vector4T<T>(v0, v1, v2, v3); \
    }


#endif



// ================================================================================
