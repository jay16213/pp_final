#include "filter.h"
#include <fstream>
#include <cstdlib>
using namespace std;

void load_filter(const char *filename, int *num_filters, int ***filter_mat, int **filter_size)
{
    ifstream inFile(filename);

    if(!inFile.is_open()) {
        printf("Error: can not open %s\n", filename);
        return;
    }

    inFile >> *num_filters;

    *filter_size = new int [*num_filters * sizeof(int)];
    *filter_mat = new int* [*num_filters * sizeof(int*)];

    for(int i = 0; i < *num_filters; i++)
    {
        inFile >> (*filter_size)[i];
        (*filter_mat)[i] = new int [(*filter_size)[i] * sizeof(int)];

        for(int j = 0; j < (*filter_size)[i] * (*filter_size)[i]; j++)
        {
            inFile >> (*filter_mat)[i][j];
            printf("%d\n", (*filter_mat)[i][j]);
        }
    }

    inFile.close();
    return;
}

void print_filter(int *filter_mat, int filter_size)
{
    for(int i = 0; i < filter_size; i++)
    {
        for(int j = 0; j < filter_size; j++)
            printf("%3d ", filter_mat[i*filter_size + j]);

        printf("\n");
    }

    return;
}

void free_filter(int num_filters, int **filter_mat, int *filter_size)
{
    for(int i = 0; i < num_filters; i++)
        delete [] filter_mat[i];

    delete [] filter_mat;
    delete [] filter_size;
    return;
}
