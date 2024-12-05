#include<iostream>
#include<random>
#include<chrono>
using namespace std;
long long bubble(int *vet, int len){
   auto inicio = std::chrono::high_resolution_clock::now();
   for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(vet[j]>vet[j+1]){
                int temp=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=temp;
            }
        }
    }
   auto resultado = std::chrono::high_resolution_clock::now() - inicio;
   long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
   return microseconds;
}


int minimumS(int vet[],int len, int k, int loc){
    loc=k;
    int min=vet[k];
    for(int i=k;i<len;i++)
    {
        if(vet[i]<min)
        {
            min=vet[i];
            loc=i;
        }
    }
    return loc;
}
long long selection(int vet[],int len){
   auto inicio = std::chrono::high_resolution_clock::now();
   int loc=-1,k;
   for(int k=0;k<len-1;k++)
   {
       int loc1=minimumS(vet,len,k,loc);
       int temp=vet[k];
       vet[k]=vet[loc1];
       vet[loc1]=temp;
   }
   auto resultado = std::chrono::high_resolution_clock::now() - inicio;
   long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
   return microseconds;
}


long long insertion(int *vet, int len) {
   auto inicio = std::chrono::high_resolution_clock::now();
   int key, j;
   for(int i = 1; i<len; i++) {
      key = vet[i];//take value
      j = i;
      while(j > 0 && vet[j-1]>key) {
         vet[j] = vet[j-1];
         j--;
      }
      vet[j] = key;   //insert in right place
   }
   auto resultado = std::chrono::high_resolution_clock::now() - inicio;
   long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();
   return microseconds;
}


void Merge(int vet[],int p, int q,int r){
    int n1,n2,i,j,k;       
    n1=q-p+1;
    n2=r-q;             
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=vet[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=vet[q+j+1];
    }
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            vet[k]=L[i++];
        }
        else
        {
            vet[k]=R[j++];
        }
    }
    while(i<n1)             
    {
        vet[k++]=L[i++];
    }
    while(j<n2)
    {
        vet[k++]=R[j++];
    }
}
void MergeSort(int vet[],int p,int r){
   int q;                                
   if(p<r){
       q=(p+r)/2;
       MergeSort(vet,p,q);
       MergeSort(vet,q+1,r);
       Merge(vet,p,q,r);
   }
}

int partition(int *a,int start,int end)
{
    int pivot=a[end];
    //P-index indicates the pivot value index
    
    int P_index=start;
    int i,t; //t is temporary variable
    
    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 
    
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;
    
     //at last returning the pivot value index
     return P_index;
 }
void Quicksort(int *a,int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
    }
}


void embaralhar(int *vet, int len)
{
	for (int i = 0; i < len; i++)
	{
		int r = rand() % len;

		int temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}
int main(){
    int vet[1000], vet1[1000], vet2[1000], vet3[1000], vet4[1000], vet5[1000];
    int tempoAb[5], tempoOrd[5];
    for(int i = 0; i < 1000; ++i){
       vet[i] = i;
    }
    embaralhar(vet, 1000);
    for(int i = 0; i < 1000; i++){
        vet1[i] = vet[i];
    }
    for(int i = 0; i < 1000; i++){
        vet2[i] = vet[i];
    }
    for(int i = 0; i < 1000; i++){
        vet3[i] = vet[i];
    }
    for(int i = 0; i < 1000; i++){
        vet4[i] = vet[i];
    }
    for(int i = 0; i < 1000; i++){
        vet5[i] = vet[i];
    }
    tempoAb[0] = bubble(vet1, 1000);
    tempoAb[1] = insertion(vet2, 1000);
    /* Tempo de Execução merge */
    auto inicio1 = std::chrono::high_resolution_clock::now();
    MergeSort(vet3, 0, 999);
    auto resultado1 = std::chrono::high_resolution_clock::now() - inicio1;
    long long microsecondsMerge = std::chrono::duration_cast<std::chrono::microseconds>(resultado1).count();
    tempoAb[2] = microsecondsMerge;
    /* Tempo de Execução Quick */
    auto inicio2 = std::chrono::high_resolution_clock::now();
    Quicksort(vet4, 0, 999);
    auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
    long long microsecondsQuick = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
    tempoAb[3] = microsecondsQuick;
    tempoAb[4] = selection(vet5, 1000);
    for(int i = 0; i < 5; i++){
        tempoOrd[i] = tempoAb[i];
    }
    bubble(tempoOrd, 5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(tempoOrd[i] == tempoAb[j]){
                switch (j){
                case 0:
                    cout<<"Bubble --> "<<tempoAb[j]<<" microssegundos"<<endl;
                    break;
                case 1:
                    cout<<"Insertion --> "<<tempoAb[j]<<" microssegundos"<<endl;
                    break;
                case 2:
                    cout<<"Merge --> "<<tempoAb[j]<<" microssegundos"<<endl;
                    break;   
                case 3:
                    cout<<"Quick --> "<<tempoAb[j]<<" microssegundos"<<endl;
                    break;
                case 4:
                    cout<<"Selection --> "<<tempoAb[j]<<" microssegundos"<<endl;
                    break;                
                default:
                    break;
                }
            }
        }
    }
    
   return 0;
}