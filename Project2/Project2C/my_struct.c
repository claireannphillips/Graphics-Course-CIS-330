/* This file should contain the 9 functions defined in prototypes.h */
#include <stdio.h> 
#include <prototypes.h>

void InitializeCircle(Circle * circ, double radius, double originX, double originY){
    circ -> radius = radius;
    circ -> originX = originX;
    circ -> originY = originY; 
}

void InitializeRectangle(Rectangle * rect, double minX, double maxX, double minY, double maxY){
    rect -> pt1X = minX;
    rect -> pt2X = maxX;
    rect -> minY = minY;
    rect -> maxY = maxY;
}

void InitializeTriangle(Triangle * tri, double pt1X, double pt2X, double minY, double maxY){
    tri -> minX = pt1X;
    tri -> maxX = pt2X;
    tri -> minY = minY;
    tri -> maxY = maxY;
}

double GetCircleArea(Circle * circ){
    return (3.14159 * circ->radius * circ->radius);
}

double GetRectangleArea(Rectangle * rec){
   // rec -> maxX = maxX; //double maxX = rec->maxX
    return ((rec->pt2X - rec->pt1X) * (rec->maxY - rec->minY));
}

double GetTriangleArea(Triangle * tri){
    //tri -> maxX = pt2X;
    //tri -> minX = pt1X;
    //tri -> maxY = maxY;
    //tri -> minY = minY;
    //return (pt2X-pt1X)*(maxY-minY)/2
    return ((tri->maxX - tri->minY) * (tri->maxY - tri->minY)/2);
} 

void GetCircleBoundingBox(Circle *circ, double * bbox) {
    bbox[0] = (circ -> originX - circ -> radius);
    bbox[1] = (circ -> originX + circ -> radius);
    bbox[2] = (circ -> originY - circ -> radius);
    //printf("%f\n",bbox[2]);
    bbox[3] = (circ -> originY + circ -> radius);
    //printf("%f\n",bbox[3]);
    //we initilizaed the values so now just have to access them from circle
}
    

void GetRectangleBoundingBox(Rectangle * rect, double * bbox){
    bbox[0] = (rect -> pt1X); 
    bbox[1] = (rect -> pt2X); 
    bbox[2] = (rect -> minY); 
    bbox[3] = (rect -> maxY); 
}

void GetTriangleBoundingBox(Triangle * tri, double * bbox){
    bbox[0] = (tri -> minX);
    bbox[1] = (tri -> maxX);
    bbox[2] = (tri -> minY);
    bbox[3] = (tri -> maxY);
}
