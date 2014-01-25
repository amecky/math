# Math

This is a C++ template based math library include Vector and Matrix classes.
It is a header only version.

# Motivation

After reading the following http://www.reedbeta.com/blog/2013/12/28/on-vector-math-libraries/ I got
inspired to write my own math library trying to follow any idea found in the article.

# How to use it

Just include "Vector.h" in your code and you are ready to go.

## Predefined types

| Name    | Size | type  |
| ------- |:----:| ----- |
|Vector2i |   2  | int   |
|Vector2f |   2  | float |
|Vector3i |   3  | int   |
|Vector3f |   3  | float |

In case you need something else you can of course define your own like
<pre>
typedef Vector<4,float> Vector4f
</pre>
