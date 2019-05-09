#include <stdio.h>

#define SZ 100000+10

int Stalls[SZ];
int N,C;
int Test_cases,Case;

void Merge(int l, int m, int r)
{
    int tmp[r-l+1];
    int i,j,k,p;

    for(i = l, j = l , k = m+1,p = 0; i <= r ; i++,p++){
        if(j == m +1){
            tmp[p] = Stalls[k++];
        }
        else if(k == r+1){
            tmp[p] = Stalls[j++];
        }
        else if(Stalls[k] < Stalls[j]){
            tmp[p] = Stalls[k++];
        }
        else{
            tmp[p] = Stalls[j++];
        }
    }

    for(i = l , p = 0 ;  i <= r ; i++,p++){
        Stalls[i] = tmp[p];
    }
}

void merge_sort(int l, int r)
{
    if(l == r){
        return;
    }

    int mid = (l+r)/2;

    merge_sort(l,mid);
    merge_sort(mid+1,r);
    Merge(l,mid,r);
}

int check(int mid)
{

     int pos = Stalls[0];
     int cows = 1;

     for(int i = 1; i < N ; i++){
        if(Stalls[i] - pos >= mid){
            pos = Stalls[i];
            cows++;

            if(cows == C){
                return 1;
            }
        }
     }

     return 0;
}

int binarySearch()
{

    int low = 0, high = Stalls[N-1], mx = -1;

    while(high > low)
    {
        int mid = (high+low)/2;

        if(check(mid) == 1){
            if(mid > mx){
                mx = mid;
            }
            low =mid+1;
        }

        else{
            high = mid;
        }
    }

    return mx;
}

void print_stalls()
{

    for(int i =0 ; i <N  ; i++){
        printf("%d ",Stalls[i]);

    }

    printf("\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        scanf("%d %d",&N,&C);

        for(int i = 0; i < N ; i++){
            scanf("%d",&Stalls[i]);
        }
        //print_stalls();

        merge_sort(0,N-1);
       // print_stalls();
        int res = binarySearch();

        //printf("#%d %d\n",Case, res);
        printf("%d\n",res);
    }
}
