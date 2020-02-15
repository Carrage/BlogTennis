#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: dynamic matrix class </summary>
    template<typename T> class matrix<T, 2, 2> {
    public:
        static const unsigned int C = 2;
        static const unsigned int R = 2;
        static const unsigned int S = C * R;

        /// <summary> matrix data </summary>
        union {
            T data[S];
            vector<T, C> rows[R];
            shift2<T, 0, 2> cols[C];
        };

        /// <summary> create matrix </summary>
        matrix() { for (unsigned int i = 0; i < S; i++) data[i] = T{}; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        matrix(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; };

        /// <summary> create matrix </summary>
        /// <param name="a"> matrix </param>
        matrix(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> create matrix </summary>
        /// <param name="a"> vector </param>
        /// <param name="b"> vector </param>
        matrix(const vector<T, 2>& a, const vector<T, 2>& b) { rows[0] = a; rows[1] = b; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        /// <param name="d"> value </param>
        matrix(const T& a, const T& b, const T& c, const T& d)
        {
            data[0] = a; data[1] = b; 
            data[2] = c; data[3] = d;
        };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> value </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; return *this; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> matrix </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

    }; // class matrix

}; // namespace maths

typedef maths::matrix<float, 2, 2> float2x2;
typedef maths::matrix<double, 2, 2> double2x2;
typedef maths::matrix<signed int, 2, 2> int2x2;
typedef maths::matrix<signed char, 2, 2> char2x2;
typedef maths::matrix<signed long, 2, 2> long2x2;
typedef maths::matrix<signed short, 2, 2> short2x2;
typedef maths::matrix<unsigned int, 2, 2> uint2x2;
typedef maths::matrix<unsigned char, 2, 2> uchar2x2;
typedef maths::matrix<unsigned long, 2, 2> ulong2x2;
typedef maths::matrix<unsigned short, 2, 2> ushort2x2;