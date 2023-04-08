#include "../includes/misc.h"


Point2I initPoint2I(int x, int y) {
    Point2I var;
    var.x = x;
    var.y = y;

    return var;
}

Point2F initPoint2F(float x, float y) {
    Point2F var;
    var.x = x;
    var.y = y;

    return var;
}

Point3F initPoint3F(float x, float y, float z) {
    Point3F var;
    var.x = x;
    var.y = y;
    var.z = z;

    return var;
}
