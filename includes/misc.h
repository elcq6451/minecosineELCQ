#ifndef FOLDER_MISC_H
#define FOLDER_MISC_H


typedef struct Point2I {
    int x;
    int y;
}Point2I;

typedef struct Point2F {
    float x;
    float y;
}Point2F;

typedef struct Point3F {
    float x;
    float y;
    float z;
}Point3F;

Point2I initPoint2I(int x, int y);
Point2F initPoint2F(float x, float y);
Point3F initPoint3F(float x, float y, float z);
#endif //FOLDER_MISC_H
