#include <stdio.h>

#define SZ 1000

int Stalls[SZ];
int N,Cows;
int Mx;
int Test_cases, Case;


void take_input()
{
    scanf("%d %d", &N, &Cows);

    for(int i = 0; i < N ; i++){
        scanf("%d", &Stalls[i]);
    }

}


void print_stalls()
{
    for(int i =0 ; i < N ; i++){
        printf("%d ",Stalls[i]);
    }

    printf("\n");
}


void merge_stalls(int l, int m, int r)
{
    int i,j,k,p;
    int tmp[l+r-1];

    for(i = l , j = l , k = m+1, p = 0; i <= r ; i++,p++)
    {
        if(j == m+1){
            tmp[p] = Stalls[k++];
        }

        else if(k == r){
            tmp[p] = Stalls[j++];
        }

        else if(Stalls[k] < Stalls[j]){
            tmp[p] = Stalls[k++];
        }

        else{
            tmp[p] = Stalls[j++];
        }
    }


    for(i = l , p = 0; i <= r ; i++,p++){
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
    merge_sort(mid+1, r);

    merge_stalls(l,mid,r);
}


int Check(int m)
{
    int pos = Stalls[0];
    int cnt = 1;

    for(int i = 1 ; i < N ; i++){
        if(Stalls[i] - pos >= m){
            cnt++;
            pos = Stalls[i];

            if(cnt == Cows){
                return 1;
            }
        }
    }


    return 0;
}


void binarySearch()
{
    int l = 0,h = Stalls[N-1];

    while(h > l){
        int mid = (l+h) / 2;

        if(Check(mid) == 1){
            if(mid > Mx){
                Mx = mid;
                //printf("---> %d\n",Mx);
            }
            l = mid+1;
        }

        else{
            h = mid;
        }
    }
}


void solve()
{
    merge_sort(0,N-1);

    Mx = -1;

    binarySearch();
}


void print_output()
{
    printf("#%d %d\n",Case, Mx);
}


int main()
{
    freopen("in_cow.txt", "r", stdin);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();

       // print_stalls();
    }
}
