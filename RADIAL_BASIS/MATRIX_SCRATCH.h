#include<math.h>
namespace MATRIX_OPS
{
   void MATRIX_MUL(float** MAT_A
                   ,int num_of_row_A
                   ,int num_of_col_A
                   ,float** MAT_B
                   ,int num_of_row_B
                   ,int num_of_col_B
                   ,float** result)
{
    if(num_of_col_A!=num_of_row_B)
    {
        return;
    }

    //initialize result to 0;
    for(int i=0; i<num_of_row_A; i++)
    {
        for(int j=0; j<num_of_col_B; j++)
        {
            result[i][j]=0;
        }
    }
    //multiplication
    for(int i = 0; i < num_of_row_A; ++i)
        for(int j = 0; j < num_of_col_B; ++j)
            for(int k = 0; k < num_of_col_A; ++k)
            {
                result[i][j] += MAT_A[i][k] * MAT_B[k][j];
            }
}
void MATRIX_ADD(float** MAT_A
                ,int num_of_row_A
                ,int num_of_col_A
                ,float** MAT_B
                ,int num_of_row_B
                ,int num_of_col_B
                ,float** result)
{
    if(num_of_row_A!=num_of_row_B || num_of_col_A!=num_of_col_B)
    {
        return;
    }
    for(int i = 0; i < num_of_row_A; ++i)
        for(int j = 0; j < num_of_col_A; ++j)
            result[i][j]=MAT_A[i][j]+MAT_B[i][j];

}
void MATRIX_SUB(float** MAT_A
                ,int num_of_row_A
                ,int num_of_col_A
                ,float** MAT_B
                ,int num_of_row_B
                ,int num_of_col_B
                ,float** result)
{
    if(num_of_row_A!=num_of_row_B || num_of_col_A!=num_of_col_B)
    {
        return;
    }
    for(int i = 0; i < num_of_row_A; ++i)
        for(int j = 0; j < num_of_col_A; ++j)
            result[i][j]=MAT_A[i][j]-MAT_B[i][j];
}


void MATRIX_Transpose(float** A
                      ,int num_of_row_A
                      ,int num_of_col_A
                      ,float** R)
{

for(int i=0;i<num_of_row_A;i++)
    for(int j=0;j<num_of_col_A;j++)
        R[j][i]=A[i][j];

}
void MATRIX_Constant_Multiply(float** A,int num_of_row_A,int num_of_col_A,float X)
{
for(int i=0;i<num_of_row_A;i++)
    for(int j=0;j<num_of_col_A;j++)
        A[i][j]=X*A[i][j];
}

//for neural network special
void MATRIX_SIGMOID_TRANSFORM(float **MAT_A,int num_of_row_A,int num_of_col_A,int k)
{
for(int i=0; i<num_of_row_A; i++)
    {
        for(int j=0; j<num_of_col_A; j++)
        {
            MAT_A[i][j]=1.0/(1+pow(2.718,-1*k*MAT_A[i][j]));
        }
    }
}

//radial basis special
void DISTANCE_SQUARED_CALCULATION(float** MAT_A
                   ,int num_of_row_A
                   ,int num_of_col_A
                   ,float** MAT_B
                   ,int num_of_row_B
                   ,int num_of_col_B
                   ,float** result)
{
    if(num_of_col_A!=num_of_row_B)
    {
        return;
    }

    //initialize result to 0;
    for(int i=0; i<num_of_row_A; i++)
    {
        for(int j=0; j<num_of_col_B; j++)
        {
            result[i][j]=0;
        }
    }
    //multiplication
    for(int i = 0; i < num_of_row_A; ++i)
        for(int j = 0; j < num_of_col_B; ++j)
            for(int k = 0; k < num_of_col_A; ++k)
            {
                result[i][j] += pow(MAT_A[i][k] - MAT_B[k][j],2);
            }
}

void MATRIX_GAUSIAN_TRANSFORM(float **MAT_A,int num_of_row_A,int num_of_col_A)
{
for(int i=0; i<num_of_row_A; i++)
    {
        for(int j=0; j<num_of_col_A; j++)
        {
            MAT_A[i][j]=(pow(2.718,-1*MAT_A[i][j]));
        }
    }
}

}
