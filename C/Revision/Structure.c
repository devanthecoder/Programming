#include <stdio.h>
typedef struct{
    double x;
    double y;
}Point;
typedef struct{
    Point centre;
    double radius;
}Circle;
int PisinC(Point point, Circle circle){
    if((point.x-circle.centre.x)*(point.x-circle.centre.x)+(point.y-circle.centre.y)*(point.y-circle.centre.y)<circle.radius*circle.radius)return 1;
    else return 0;
}
int main(){
    Point P;
    printf("Enter coordinates for point P: ");
    scanf("%lf %lf",&(P.x),&(P.y));
    Circle C;
    printf("Enter coordinates for centre and radius of circle C: ");
    scanf("%lf %lf %lf",&(C.centre.x),&(C.centre.y),&(C.radius));
    if(PisinC(P,C))printf("Point P is inside Circle C.");
    else printf("Point P is not inside Circle C.");
}