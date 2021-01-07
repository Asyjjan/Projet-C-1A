#include <stdio.h>

double conversion(double francs)
{
    double euros = 0;
    
    euros = francs/6.55957;
    return euros;
}    

int main(int argc, char *argv[])
{    
    printf("65 francs = %feuro\n", conversion(65.595700));
    
    return 0;
}