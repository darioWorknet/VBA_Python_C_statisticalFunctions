#include <stdio.h>
#include <math.h>


double CholeskyDecomposition (int size, double (*result)[size], double R[][size]){
   double a [size][size];
   double M [size][size];
   double U;

   for (int i=0; i<size; i++){
      for (int j=0; j<size; j++){
         a[i][j] = R[i][j];
         result[i][j] = 0;
         if (i == j){
            result[i][j] = 1;
         }
      }
   }

   for (int i=0; i<size; i++){
      for (int j=0; j<size; j++){
         U = a[i][j];
         for (int h=0; h<i; h++){
            U = U - result[i][h] * result[j][h];
         }
         if (j==i){
            result[i][i] = sqrt(U);
         } else {
            result[j][i] = U / result[i][i];
         }
      }
   }

}




int main() {

   // double input[3][3] = {
   //     {0.1, 0.2, 0.3},
   //     {0.4, 0.5, 0.6},
   //     {0.7, 0.8, 0.9}
   // };

   double input[3][3] = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}
   };

   int sizeX = sizeof(*input) / sizeof(**input);

   double CDecomposition [sizeX][sizeX];

   CholeskyDecomposition (sizeX, CDecomposition, input);

   for(int i = 0; i < sizeX; i++) {
      for(int j = 0; j < sizeX; j++) {
         printf("%f ", CDecomposition[i][j]);
      }
      printf("\n");
   }

   return 0;
}




