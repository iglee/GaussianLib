/*
 * Scale.h
 * 
 * This file is part of the "GaussianLib" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __GS_SCALE_H__
#define __GS_SCALE_H__


#include "Decl.h"


namespace Gs
{


namespace Details
{


template <typename M, typename T>
void Scale3x3(M& m, const Vector3T<T>& v)
{
    static_assert(
        M::rows >= 3 && M::columns >= 3,
        "scale requires a matrix with at least 3 rows and 3 columns"
    );

    m(0, 0) *= v.x;
    m(0, 1) *= v.y;
    m(0, 2) *= v.z;

    m(1, 0) *= v.x;
    m(1, 1) *= v.y;
    m(1, 2) *= v.z;

    m(2, 0) *= v.x;
    m(2, 1) *= v.y;
    m(2, 2) *= v.z;
}


} // /namespace Details


//! Translates the specified 4x4 matrix 'm' by the vector 'v'.
template <typename T>
void Scale(Matrix<T, 4, 4>& m, const Vector3T<T>& v)
{
    /* Scale left-upper 3x3 matrix */
    Details::Scale3x3(m, v);

    /* Also scale 4th row */
    m(3, 0) *= v.x;
    m(3, 1) *= v.y;
    m(3, 2) *= v.z;
}

//! Translates the specified 3x3 matrix 'm' by the vector 'v'.
template <typename T>
void Scale(Matrix<T, 3, 3>& m, const Vector3T<T>& v)
{
    Details::Scale3x3(m, v);
}

//! Computes the inverse of the specified sparse 4x4 matrix 'm'.
template <typename T>
void Scale(SparseMatrix4T<T>& m, const Vector3T<T>& v)
{
    Details::Scale3x3(m, v);
}


} // /namespace Gs


#endif



// ================================================================================
