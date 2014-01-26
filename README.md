# Math

This is a C++ template based math library include Vector and Matrix classes.
It is a header only version.

# Motivation

After reading the following http://www.reedbeta.com/blog/2013/12/28/on-vector-math-libraries/ I got
inspired to write my own math library trying to follow any idea found in the article.

# Operators

The following list contains all operators that are currently implemented:

- +=
- -=
- *=
- /=
- ==
- !=
- +
- -
- *
- /

# Functions

The Vector header files also contains all necessary functions on vectors. They
are not part of the vector struct itself.

The following functions mainly work on all sizes. Only the cross function is limited
to Vectors of size 3. Also the lerp function is limited to the type float. 
| Name       | Description                                     |
| ---------- | ----------------------------------------------- |
| vec_min    | min of two vectors                              |
| vec_max    | max of two vectors                              |
| lerp       | linear interpolation between to vectors         |
| clamp      | Clamps a given vector in the range of two other |
| saturate   | Clamps a given vector in the range of 0 to 1    |
| dot        | dot product of two vectors                      |
| cross      | cross product of two vectors                    |
| length     | length of a vector                              |
| sqr_length | the square length of a vector                   |
| distance   | the distance from one vector to another         |
| normalize  | normalized vector                               |

# How to use it

Just include "Vector.h" in your code and you are ready to go.

## Predefined types

| Name    | Size | type  |
| ------- |:----:| ----- |
|Vector2i |   2  | int   |
|Vector2f |   2  | float |
|Vector3i |   3  | int   |
|Vector3f |   3  | float |
|Vector4f |   4  | float |

In case you need something else you can of course define your own like
<pre>
typedef Vector<4,float> Vector4f
</pre>

# Versions

## 0.1

This is the current version.

# Notes

The code is released under the BSD license. This means you can do whatever you like.
In case you want to contact me send a mail to amecky@gmail.com. I am open to any
discussion. If you want to contribute code then please feel free to contact me
or just fork the code.

