//Date:2018/5/29
//Author:dylan_xi
//Desc: linear equation Slope

/*
    对于一个直线方程: AX +BY = C,
    斜率 = m = dy / dx = (y2 - y1) / (x2 - x1): 用来描述直线的变化率
    计算斜率的快速方式: m = - A/B
    (笛卡尔坐标系中)
        斜率为正: 直线沿着左下-右上方向延伸
        斜率为负: 直线沿着左上-右下方向延伸
        斜率为0: 直线是一条水平线
        斜率不存在: 直线是一条铅垂线

    两条直线平行: 斜率相等
    两条直线垂直: 斜率相乘,结果总为-1, m1*m2 = -1 , m2 = -1 / m1

    游戏中常用的表示直线的方式
    (1)斜截式:y = mx + b; m 代表斜率, b代表直线在y轴上的截距 , 通过 m值反映直线的倾斜程度, y轴上的截距,很容易直观的想象出
    直线的样子.

    (2)点斜式:(y - y1) = m(x - x1) ,通过直线上的一个点和直线的斜率确定直线方程.
    点斜式比其他两种更有优势的地方在于,根据两个点如何确定直线方程? 两个点算出直线的斜率,然后在带入一个点到点斜式,即可求出直线方程




*/ 

//function: calculate slope between two Points
//input: P1: the first point  (array of two float number)
//       P1: the second point (array of two float number)
//output: the slope between two points
float slopeBetweenPoints(float* P1, float* P2)
{
    return (P1[1] - P2[1])/(P1[0]- P2[0]);
}

//function: calculate perp line 's slope
//input: slope: given line's slope
//output: perp line's slop 
bool perpSlope(float slope)
{
    return -1 / slope; 
}

//function: check two line is perp
//input: slope1: first line's slope
//       slope2: second line's slope
//output: if two line is perp , return true , otherwise , return false 
bool arePerp(float slope1 , float slope2)
{
    return slope1*slope2 == -1; 
}