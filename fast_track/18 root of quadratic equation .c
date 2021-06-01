#include <stdio.h>
#include<math.h>

struct complex
{
    float r;
    float i;
};


float input()
{
    float a;
        scanf("%f",&a);
        return a;
}
int quad(float a,float b,float c,struct complex *root1,struct complex *root2)
{   
    float d;
        d = b*b - 4*a*c;
        if (d > 0) 
        {
            root1->r = (-b + sqrt(d)) / (2 * a);
            root2->r = (-b - sqrt(d)) / (2 * a);
            root1->i = root2->i = 0.0;
        }
        else if (d == 0)
        {
            root1->r = root2->r = -b / (2 * a);
            root1->i = root2->i = 0.0;
        }
        else 
        {
            root1->r = root2->r = -b / (2 * a);
            root1->i = sqrt(-d) / (2 * a);
            root2->i = -(sqrt(-d) / (2 * a));
    }
    return 0;
}
void output(struct complex root1,struct complex root2)
{
       printf("root1 = %f+%fi and root2 = %f%fi \n", root1.r, root1.i,root2.r, root2.i);
       
}
int main()
{
    struct complex root1, root2;
    float a,b,c;
        printf("Enter coefficients a, b and c: \n");
            a=input();
            b=input();
            c=input();
            quad(a,b,c,&root1,&root2);
            output(root1,root2);
            return 0;
}
