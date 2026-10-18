/*
    Micromath is an single-header math library for graphics, which
    I wrote as a study project, when I was learning 3D graphics.

    Matrices are stored in a column-major format: elements[col][row]

    Micromath requires C11.
    
    By default, micromath uses <math.h> from C runtime library. If you
    want to replace it, you must define MICROMATH_DO_NOT_USE_STDLIB_MATH
    before including micromath and write implementation for MM_SQRTF,
    MM_SINF and MM_COSF, like so:

        #define MICROMATH_DO_NOT_USE_STDLIB_MATH
        #define MM_SQRTF my_sqrtf
        #define MM_SINF my_sinf
        #define MM_COSF my_cosf
        #include "micromath.h"
    
*/

#ifndef MICROMATH_H
#define MICROMATH_H

#ifndef MICROMATH_DO_NOT_USE_STDLIB_MATH
#  include <math.h>
#  ifndef MM_SQRTF
#   define MM_SQRTF sqrtf
#  endif
#  ifndef MM_SINF
#    define MM_SINF sinf
#  endif 
#  ifndef MM_COSF
#    define MM_COSF cosf
#  endif
#endif

#ifdef MICROMATH_DO_NOT_USE_STDLIB_MATH
#  ifndef MM_SQRTF
#    error "MM_SQRTF must be defined before including micromath.h when MICROMATH_DO_NOT_USE_STDLIB_MATH is set"
#  endif
#  ifndef MM_SINF
#    error "MM_SINF must be defined before including micromath.h when MICROMATH_DO_NOT_USE_STDLIB_MATH is set"
#  endif
#  ifndef MM_COSF
#    error "MM_COSF must be defined before including micromath.h when MICROMATH_DO_NOT_USE_STDLIB_MATH is set"
#  endif
#endif

#define MM_PI_F 3.14159265358979323846f

typedef union {
    struct { float x, y; };
    struct { float u, v; };
    struct { float width, height; };
    float elements[2];
} mm_vec2;

typedef union {
    struct { float x, y, z; };
    struct { float r, g, b; };
    float elements[3];
} mm_vec3;

typedef union {    
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };
    float elements[4];
} mm_vec4;

typedef union {
    float elements[2][2];
    mm_vec2  column[2];
} mm_mat2;

typedef union {
    float elements[3][3];
    mm_vec3  column[3];
} mm_mat3;

typedef union {
    float elements[4][4];
    mm_vec4  column[4];
} mm_mat4;


// some helpers

static inline float mm_deg_to_rad(float deg) {
    return deg * (MM_PI_F / 180.0f);
}

static inline float mm_rad_to_deg(float rad) {
    return rad * (180.0f / MM_PI_F);
}

static inline float mm_minf(float a, float b) {
    if (a < b) return a;
    return b;
}

static inline float mm_maxf(float a, float b) {
    if (a > b) return a;
    return b;
}

static inline float mm_clampf(float a, float low, float high) {
    if      (a > high) return high;
    else if (a < low)  return low;
    return a;
}

static inline float mm_lerpf(float a, float b, float t) {
    return a + (b - a) * t;
}


// vectors

static inline mm_vec2 mm_vec2_add(mm_vec2 a, mm_vec2 b) {
    return (mm_vec2){
        .x = a.x + b.x,
        .y = a.y + b.y
    };
}

static inline mm_vec3 mm_vec3_add(mm_vec3 a, mm_vec3 b) {
    return (mm_vec3){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

static inline mm_vec4 mm_vec4_add(mm_vec4 a, mm_vec4 b) {
    return (mm_vec4){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
        .w = a.w + b.w
    };
}


static inline mm_vec2 mm_vec2_addf(mm_vec2 a, float b) {
    return (mm_vec2){
        .x = a.x + b,
        .y = a.y + b
    };
}

static inline mm_vec3 mm_vec3_addf(mm_vec3 a, float b) {
    return (mm_vec3){
        .x = a.x + b,
        .y = a.y + b,
        .z = a.z + b
    };
}

static inline mm_vec4 mm_vec4_addf(mm_vec4 a, float b) {
    return (mm_vec4){
        .x = a.x + b,
        .y = a.y + b,
        .z = a.z + b,
        .w = a.w + b
    };
}


static inline mm_vec2 mm_vec2_sub(mm_vec2 a, mm_vec2 b) {
    return (mm_vec2){
        .x = a.x - b.x,
        .y = a.y - b.y
    };
}

static inline mm_vec3 mm_vec3_sub(mm_vec3 a, mm_vec3 b) {
    return (mm_vec3){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

static inline mm_vec4 mm_vec4_sub(mm_vec4 a, mm_vec4 b) {
    return (mm_vec4){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
        .w =a.w - b.w
    };
}


static inline mm_vec2 mm_vec2_subf(mm_vec2 a, float b) {
    return (mm_vec2){
        .x = a.x - b,
        .y = a.y - b
    };
}

static inline mm_vec3 mm_vec3_subf(mm_vec3 a, float b) {
    return (mm_vec3){
        .x = a.x - b,
        .y = a.y - b,
        .z = a.z - b
    };
}

static inline mm_vec4 mm_vec4_subf(mm_vec4 a, float b) {
    return (mm_vec4){
        .x = a.x - b,
        .y = a.y - b,
        .z = a.z - b,
        .w = a.w - b
    };
}


static inline mm_vec2 mm_vec2_mul(mm_vec2 a, mm_vec2 b) {
    return (mm_vec2){
        .x = a.x * b.x,
        .y = a.y * b.y
    };
}

static inline mm_vec3 mm_vec3_mul(mm_vec3 a, mm_vec3 b) {
    return (mm_vec3){
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z
    };
}

static inline mm_vec4 mm_vec4_mul(mm_vec4 a, mm_vec4 b) {
    return (mm_vec4){
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z,
        .w = a.w * b.w
    };
}


static inline mm_vec2 mm_vec2_mulf(mm_vec2 a, float b) {
    return (mm_vec2){
        .x = a.x * b,
        .y = a.y * b
    };
}

static inline mm_vec3 mm_vec3_mulf(mm_vec3 a, float b) {
    return (mm_vec3){
        .x = a.x * b,
        .y = a.y * b,
        .z = a.z * b
    };
}

static inline mm_vec4 mm_vec4_mulf(mm_vec4 a, float b) {
    return (mm_vec4){
        .x = a.x * b,
        .y = a.y * b,
        .z = a.z * b,
        .w = a.w * b
    };
}


static inline mm_vec2 mm_vec2_negate(mm_vec2 a) {
    return (mm_vec2){ .x = -a.x, .y = -a.y };
}

static inline mm_vec3 mm_vec3_negate(mm_vec3 a) {
    return (mm_vec3){ .x = -a.x, .y = -a.y, .z = -a.z };
}

static inline mm_vec4 mm_vec4_negate(mm_vec4 a) {
    return (mm_vec4){ .x = -a.x, .y = -a.y, .z = -a.z, .w = -a.w };
}


static inline float mm_vec2_len_sq(mm_vec2 a) {
    return a.x * a.x + a.y * a.y;
}

static inline float mm_vec3_len_sq(mm_vec3 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

static inline float mm_vec4_len_sq(mm_vec4 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

static inline float mm_vec2_len(mm_vec2 a) {
    return MM_SQRTF(mm_vec2_len_sq(a));
}

static inline float mm_vec3_len(mm_vec3 a) {
    return MM_SQRTF(mm_vec3_len_sq(a));
}

static inline float mm_vec4_len(mm_vec4 a) {
    return MM_SQRTF(mm_vec4_len_sq(a));
}


static inline float mm_vec2_dot(mm_vec2 a, mm_vec2 b) {
    return a.x * b.x + a.y * b.y;
}

static inline float mm_vec3_dot(mm_vec3 a, mm_vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float mm_vec4_dot(mm_vec4 a, mm_vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;   
}


static inline float mm_vec2_cross(mm_vec2 a, mm_vec2 b) {
    return a.x * b.y - a.y * b.x;    
}

static inline mm_vec3 mm_vec3_cross(mm_vec3 a, mm_vec3 b) {
    return (mm_vec3){
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x
    };
}


static inline mm_vec2 mm_vec2_normalize(mm_vec2 a) {
    float len = mm_vec2_len(a);

    if (len > 0.0f) {
        return mm_vec2_mulf(a, 1.0f / len);
    } else {
        return a;
    }
}

static inline mm_vec3 mm_vec3_normalize(mm_vec3 a) {
    float len = mm_vec3_len(a);

    if (len > 0.0f) {
        return mm_vec3_mulf(a, 1.0f / len);
    } else {
        return a;
    }
}

static inline mm_vec4 mm_vec4_normalize(mm_vec4 a) {
    float len = mm_vec4_len(a);

    if (len > 0.0f) {
        return mm_vec4_mulf(a, 1.0f / len);
    } else {
        return a;
    }
}


static inline mm_vec2 mm_vec2_clamp(mm_vec2 a, float low, float high) {
    return (mm_vec2){
        .x = mm_clampf(a.x, low, high),    
        .y = mm_clampf(a.y, low, high)    
    };
}

static inline mm_vec3 mm_vec3_clamp(mm_vec3 a, float low, float high) {
    return (mm_vec3){
        .x = mm_clampf(a.x, low, high),    
        .y = mm_clampf(a.y, low, high),    
        .z = mm_clampf(a.z, low, high)    
    };
}

static inline mm_vec4 mm_vec4_clamp(mm_vec4 a, float low, float high) {
    return (mm_vec4){
        .x = mm_clampf(a.x, low, high),    
        .y = mm_clampf(a.y, low, high),    
        .z = mm_clampf(a.z, low, high),    
        .w = mm_clampf(a.w, low, high)    
    };
}


static inline mm_vec2 mm_vec2_lerp(mm_vec2 a, mm_vec2 b, float t) {
    return (mm_vec2){
        .x = mm_lerpf(a.x, b.x, t),    
        .y = mm_lerpf(a.y, b.y, t)    
    };
}

static inline mm_vec3 mm_vec3_lerp(mm_vec3 a, mm_vec3 b, float t) {
    return (mm_vec3){
        .x = mm_lerpf(a.x, b.x, t),    
        .y = mm_lerpf(a.y, b.y, t),    
        .z = mm_lerpf(a.z, b.z, t)    
    };
}

static inline mm_vec4 mm_vec4_lerp(mm_vec4 a, mm_vec4 b, float t) {
    return (mm_vec4){
        .x = mm_lerpf(a.x, b.x, t),    
        .y = mm_lerpf(a.y, b.y, t),    
        .z = mm_lerpf(a.z, b.z, t),    
        .w = mm_lerpf(a.w, b.w, t)    
    };
}


// matrices

static inline mm_mat2 mm_mat2_add(mm_mat2 a, mm_mat2 b) {
    mm_mat2 res = { 0 };
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.elements[i][j] = a.elements[i][j] + b.elements[i][j];
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_add(mm_mat3 a, mm_mat3 b) {
    mm_mat3 res = { 0 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.elements[i][j] = a.elements[i][j] + b.elements[i][j];
        }
    }
    
    return res;
}

static inline mm_mat4 mm_mat4_add(mm_mat4 a, mm_mat4 b) {
    mm_mat4 res = { 0 };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res.elements[i][j] = a.elements[i][j] + b.elements[i][j];
        }
    }
    
    return res;
}


static inline mm_mat2 mm_mat2_addf(mm_mat2 a, float b) {
    mm_mat2 res = { 0 };
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.elements[i][j] = a.elements[i][j] + b;
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_addf(mm_mat3 a, float b) {
    mm_mat3 res = { 0 };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.elements[i][j] = a.elements[i][j] + b;
        }
    }
    
    return res;
}

static inline mm_mat4 mm_mat4_addf(mm_mat4 a, float b) {
    mm_mat4 res = { 0 };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res.elements[i][j] = a.elements[i][j] + b;
        }
    }
    
    return res;
}


static inline mm_mat2 mm_mat2_sub(mm_mat2 a, mm_mat2 b) {
    mm_mat2 res = { 0 };
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.elements[i][j] = a.elements[i][j] - b.elements[i][j];
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_sub(mm_mat3 a, mm_mat3 b) {
    mm_mat3 res = { 0 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.elements[i][j] = a.elements[i][j] - b.elements[i][j];
        }
    }
    
    return res;
}

static inline mm_mat4 mm_mat4_sub(mm_mat4 a, mm_mat4 b) {
    mm_mat4 res = { 0 };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res.elements[i][j] = a.elements[i][j] - b.elements[i][j];
        }
    }
    
    return res;
}


static inline mm_mat2 mm_mat2_subf(mm_mat2 a, float b) {
    mm_mat2 res = { 0 };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.elements[i][j] = a.elements[i][j] - b;
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_subf(mm_mat3 a, float b) {
    mm_mat3 res = { 0 };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.elements[i][j] = a.elements[i][j] - b;
        }
    }
    
    return res;
}

static inline mm_mat4 mm_mat4_subf(mm_mat4 a, float b) {
    mm_mat4 res = { 0 };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res.elements[i][j] = a.elements[i][j] - b;
        }
    }
    
    return res;
}

static inline mm_mat2 mm_mat2_mul(mm_mat2 a, mm_mat2 b) {
    mm_mat2 res = { 0 };

    for(int col = 0; col < 2; col++) {
        for(int row = 0; row < 2; row++) {
            res.elements[col][row] = (
                a.elements[0][row] * b.elements[col][0] +
                a.elements[1][row] * b.elements[col][1]
            ); 
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_mul(mm_mat3 a, mm_mat3 b) {
    mm_mat3 res = { 0 };

    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 3; row++) {
            res.elements[col][row] = (
                a.elements[0][row] * b.elements[col][0] +
                a.elements[1][row] * b.elements[col][1] +
                a.elements[2][row] * b.elements[col][2]
            );
        }
    }
         
    return res;
}

static inline mm_mat4 mm_mat4_mul(mm_mat4 a, mm_mat4 b) {
    mm_mat4 res = { 0 };

    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            res.elements[col][row] = (
                a.elements[0][row] * b.elements[col][0] +
                a.elements[1][row] * b.elements[col][1] +
                a.elements[2][row] * b.elements[col][2] +
                a.elements[3][row] * b.elements[col][3]
            );
        }
    }
    
    return res;
}


static inline mm_mat2 mm_mat2_mulf(mm_mat2 a, float b) {
    mm_mat2 res = { 0 };
    
    for (int col= 0; col < 2; col++ ) {
        for (int row = 0; row < 2; row++) {
            res.elements[col][row] = a.elements[col][row] * b;
        }
    }
    
    return res;
}

static inline mm_mat3 mm_mat3_mulf(mm_mat3 a, float b) {
    mm_mat3 res = { 0 };
    
    for (int col= 0; col < 3; col++ ) {
        for (int row = 0; row < 3; row++) {
            res.elements[col][row] = a.elements[col][row] * b;
        }
    }
    
    return res;
}

static inline mm_mat4 mm_mat4_mulf(mm_mat4 a, float b) {
    mm_mat4 res = { 0 };
    
    for (int col= 0; col < 4; col++ ) {
        for (int row = 0; row < 4; row++) {
            res.elements[col][row] = a.elements[col][row] * b;
        }
    }
    
    return res;
}


static inline mm_vec2 mm_mat2_mulv(mm_mat2 a, mm_vec2 b) {
    mm_vec2 res = { 0 };
  
    for (int i = 0; i < 2; i++) {
        res.elements[i] = a.elements[0][i] * b.x + a.elements[1][i] * b.y;
    }
    
    return res;
}

static inline mm_vec3 mm_mat3_mulv(mm_mat3 a, mm_vec3 b) {
    mm_vec3 res = { 0 };

    for(int i = 0; i < 3; i++) {
        res.elements[i] = (a.elements[0][i] * b.x + a.elements[1][i] * b.y +
                           a.elements[2][i] * b.z);
    }
    
    return res;
}

static inline mm_vec4 mm_mat4_mulv(mm_mat4 a, mm_vec4 b) {
    mm_vec4 res = { 0 };

    for(int i = 0; i < 4; i++) {
        res.elements[i] = (a.elements[0][i] * b.x + a.elements[1][i] * b.y +
                           a.elements[2][i] * b.z + a.elements[3][i] * b.w);
    }
    
    return res;
}


static inline mm_mat2 mm_make_mat2_identity(void) {
    mm_mat2 res = { 0 };

    for(int i = 0; i < 2; i++) {
        res.elements[i][i] = 1.0f;
    }
    
    return res;
}

static inline mm_mat3 mm_make_mat3_identity(void) {
    mm_mat3 res = { 0 };

    for(int i = 0; i < 3; i++) {
        res.elements[i][i] = 1.0f;
    }
    
    return res;
}

static inline mm_mat4 mm_make_mat4_identity(void) {
    mm_mat4 res = { 0 };

    for(int i = 0; i < 4; i++) {
        res.elements[i][i] = 1.0f;
    }
    
    return res;
}


// transformations

static inline mm_mat4 mm_make_mat4_scale(mm_vec3 scale) {
    mm_mat4 res = mm_make_mat4_identity();

    res.elements[0][0] = scale.x;
    res.elements[1][1] = scale.y;
    res.elements[2][2] = scale.z;
    
    return res;
}

static inline mm_mat4 mm_make_mat4_translate(mm_vec3 translation) {
    mm_mat4 res = mm_make_mat4_identity();

    res.elements[3][0] = translation.x;
    res.elements[3][1] = translation.y;
    res.elements[3][2] = translation.z;
    
    return res;
}


static inline mm_mat4 mm_make_mat4_rotate_x(float angle_in_radians) {
    mm_mat4 res = mm_make_mat4_identity();

    const float sine = MM_SINF(angle_in_radians);
    const float cosine = MM_COSF(angle_in_radians);

    res.elements[1][1] = cosine;
    res.elements[1][2] = sine;

    res.elements[2][1] = -sine;
    res.elements[2][2] = cosine;
    
    return res;
}

static inline mm_mat4 mm_make_mat4_rotate_y(float angle_in_radians) {
    mm_mat4 res = mm_make_mat4_identity();

    const float sine = MM_SINF(angle_in_radians);
    const float cosine = MM_COSF(angle_in_radians);
    
    res.elements[0][0] = cosine;
    res.elements[0][2] = -sine;
    
    res.elements[2][0] = sine;
    res.elements[2][2] = cosine;
    
    return res;
}

static inline mm_mat4 mm_make_mat4_rotate_z(float angle_in_radians) {
    mm_mat4 res = mm_make_mat4_identity();

    const float sine = MM_SINF(angle_in_radians);
    const float cosine = MM_COSF(angle_in_radians);

    res.elements[0][0] = cosine;
    res.elements[0][1] = sine;

    res.elements[1][0] = -sine;
    res.elements[1][1] = cosine;
    
    return res;
}

#endif // #ifndef MICROMATH_H
