   /*
    x+y+2z=4
    2x-y+3z=9
    3x-y-z=2
    */



 //Gauss Elimination
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int i,j,k;
    cout.precision(4);        //set precision
    cout.setf(ios::fixed);
    float a[3][3+1],x[3];
    //initializtion of array
    a[0][0]=1;a[0][1]=1;a[0][2]=2;a[0][3]=4;
    a[1][0]=2;a[1][1]=-1;a[1][2]=3;a[1][3]=9;
    a[2][0]=3;a[2][1]=-1;a[2][2]=-1;a[2][3]=2;

           //declare an array to store the elements of augmented-matrix
    cout<<"\Below  the elements of the augmented-matrix row-wise:\n";
    for (i=0;i<3;i++){
        for (j=0;j<=3;j++){
            cout<<a[i][j]<<"  "; }cout<<endl;}   //input the elements of array
    for (i=0;i<3;i++)                    //Pivotisation
        for (k=i+1;k<3;k++)
            if (a[i][i]<a[k][i])
                for (j=0;j<=3;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    cout<<"\nThe matrix after Pivotisation is:\n";
    for (i=0;i<3;i++)            //print the new matrix
    {
        for (j=0;j<=3;j++)
            cout<<a[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=0;i<3-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<3;k++)
            {
                double t=a[k][i]/a[i][i];
                for (j=0;j<=3;j++)
                    a[k][j]=a[k][j]-t*a[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }

    cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i=0;i<3;i++)            //print the new matrix
    {
        for (j=0;j<=3;j++)
            cout<<a[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=3-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        x[i]=a[i][3];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=0;j<3;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout<<"\nThe values of the variables are as follows:\n";
    for (i=0;i<3;i++)
        cout<<x[i]<<endl;            // Print the values of x, y,z,....
    return 0;
}
