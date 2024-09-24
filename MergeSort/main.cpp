#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array)
{
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    //indices
    int i = 0;
    int l = 0;
    int r = 0;

    while(l < leftSize && r < rightSize)
        //cuando validamos que nuestro elemento de la izquierda es menor lo almacenamos en nuestro nuevo arreglo
            //y el itereador de la izquierda avanza una posicion y el iterador principal avanza otra
    {
        if(leftArray[l] < rightArray[r])
        {
            array[i] = leftArray[l];
            i++;
            l++;
        }else
        {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }

    while(l < leftSize )
    {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while(r < rightSize)
    {
        array[i] = rightArray[r];
        i++;
        r++;
    }


}

void mergeSort(vector<int>& array)
{
    int n = array.size();
    if(n <= 1) return; // caso base
    int center = n / 2;

    vector<int> leftArray(center);
    vector<int> rightArray(n - center);

    //crear arreglo izquierdo y derecho con el size inicial basado en el lenght del areglo
    for(int i=0; i<n; i++)
    {
        if(i < center){
            leftArray[i] = array[i];
        }else{
            rightArray[i - center] = array[i];

        }
    }
    mergeSort(leftArray);
    mergeSort(rightArray);

    //conquer
    merge(leftArray, rightArray, array);
}


int main()
{
    vector<int> array ={12,3,7,9,14,6,11,2};

    mergeSort(array);

    for(int num : array)
    {
        cout<<num<<",";
    }

    return 0;
