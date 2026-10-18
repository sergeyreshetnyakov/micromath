**Micromath** is an single-header C11 math library for graphics, which I wrote as a study project, when I was learning 3D graphics.

Matrices are stored in a *column-major* format: elements[col][row]


By default, micromath uses <math.h> from C runtime library. If you
want to replace it, you must define MICROMATH_DO_NOT_USE_STDLIB_MATH
before including micromath and write implementation for MM_SQRTF,
MM_SINF and MM_COSF, like so:
```c
#define MICROMATH_DO_NOT_USE_STDLIB_MATH
#define MM_SQRTF my_sqrtf
#define MM_SINF my_sinf
#define MM_COSF my_cosf
#include "micromath.h"
```
