/* This file should contain the 9 functions defined in prototypes.h */
#include <stdio.h> 
#include <prototypes.h>

void InitializeCircle(struct Shape* circ, double radius, double originX, double originY){
    circ -> su.c.radius = radius;
    circ -> su.c.originX = originX;
    circ -> su.c.originY = originY;
    circ -> ft.GetArea = GetCircleArea;
    circ -> ft.GetBoundingBox = GetCircleBoundingBox;
    //circ -> radius = radius;
    //circ -> originX = originX;
    //circ -> originY = originY; 
}

void InitializeRectangle(struct Shape * rect, double minX, double maxX, double minY, double maxY){
    rect -> su.r.pt1X = minX;
    rect -> su.r.pt2X = maxX;
    rect -> su.r.minY = minY;
    rect -> su.r.maxY = maxY;
    rect -> ft.GetArea = GetRectangleArea;
    rect -> ft.GetBoundingBox = GetRectangleBoundingBox;
    //rect -> pt1X = minX;
    //rect -> pt2X = maxX;
    //rect -> minY = minY;
    //rect -> maxY = maxY;
}

void InitializeTriangle(struct Shape * tri, double pt1X, double pt2X, double minY, double maxY){
    tri -> su.t.minX = pt1X;
    tri -> su.t.maxX = pt2X;
    tri -> su.t.minY = minY;
    tri -> su.t.maxY = maxY;
    tri -> ft.GetArea = GetTriangleArea;
    tri -> ft.GetBoundingBox = GetTriangleBoundingBox;
    //tri -> minX = pt1X;
    //tri -> maxX = pt2X;
    //tri -> minY = minY;
    //tri -> maxY = maxY;
}

double GetCircleArea(struct Shape * circ){
    return (3.14159 * (circ->su.c.radius) * (circ->su.c.radius));
}

double GetRectangleArea(struct Shape  * rec){
   // rec -> maxX = maxX; //double maxX = rec->maxX
    return (((rec->su.r.pt2X) - (rec->su.r.pt1X)) * ((rec->su.r.maxY) - (rec->su.r.minY)));
}

double GetTriangleArea(struct Shape * tri){
    //tri -> maxX = pt2X;
    //tri -> minX = pt1X;
    //tri -> maxY = maxY;
    //tri -> minY = minY;
    //return (pt2X-pt1X)*(maxY-minY)/2
    return (((tri->su.t.maxX) - (tri->su.t.minY)) * ((tri->su.t.maxY) - (tri->su.t.minY))/2);
} 

void GetCircleBoundingBox(struct Shape *circ, double * bbox) {
    bbox[0] = (circ -> su.c.originX) - (circ -> su.c.radius);
    bbox[1] = (circ -> su.c.originX) + (circ -> su.c.radius);
    bbox[2] = (circ -> su.c.originY) - (circ -> su.c.radius);
    //printf("%f\n",bbox[2]);
    bbox[3] = (circ -> su.c.originY) + (circ -> su.c.radius);
    //printf("%f\n",bbox[3]);
    //we initilizaed the values so now just have to access them from circle
}

void GetRectangleBoundingBox(struct Shape *rect, double * bbox){
    bbox[0] = (rect -> su.r.pt1X);
    bbox[1] = (rect -> su.r.pt2X);
    bbox[2] = (rect -> su.r.minY);
    bbox[3] = (rect -> su.r.maxY);
}

void GetTriangleBoundingBox(struct Shape *tri, double * bbox){
    bbox[0] = (tri -> su.t.minX);
    bbox[1] = (tri -> su.t.maxX);
    bbox[2] = (tri -> su.t.minY);
    bbox[3] = (tri -> su.t.maxY);
}

