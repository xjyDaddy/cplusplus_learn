//Date:2018/5/29
//Author:dylan_xi
//Desc: Point3D struct

/* (1)
the first way:float number array.
*/
//the advantage is fast , simple , and less cost of memery.
//float Point3D[3];

/*(2)
the second way: a struct which contains 3 float number
the advantage is support user-defined function and operator overload
*/
 
struct Point3D
{
    float x , y , z;

    Point3D operator +(const Point3D& point) const
    {
        Point3D temp = {
            this->x + point.x,
            this->y + point.y,
            this->z + point.z,
        };
        return temp;
    };
};
