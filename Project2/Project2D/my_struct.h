/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */

typedef struct {
    double radius;
    double originX;
    double originY;
}Circle;
typedef struct {
    double minX; 
    double maxX;
    double minY;
    double maxY;

}Triangle;
typedef struct {
    double pt1X;
    double pt2X; 
    double minY;
    double maxY;
}Rectangle;

typedef union
{
    Circle c;
    Rectangle r;
    Triangle t;
}ShapeUnion;

struct Shape;
//function tables uses shapes but can't put shapes above because it needs function table to be done 1st
typedef struct {
    //pointers to functions. 
    //void (*multiplier)(int *) multiplier is function pointer and int * is part of function signature. 
    //int (*multiplier)(int); 
    double (*GetArea)(struct Shape *);    
    void (*GetBoundingBox)(struct Shape*, double*);
}FunctionTable;

enum ShapeType{ //do I need a typedef?
    //3 types
    //enums make your own types
    ShapeCircle,
    ShapeRectangle,
    ShapeTriangle
};

struct Shape{
    ShapeUnion su;
    enum ShapeType st;
    FunctionTable ft; 
};









