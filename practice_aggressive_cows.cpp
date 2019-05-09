#include <stdio.h>

#define SZ 100000+10

int Stalls[SZ];
int Cows,N;
int Mx;
int Test_cases, Case;


void print_sorted()
{
    for(int i =0 ; i < N ; i++)
    {
        printf("%d ",Stalls[i]);
    }

    printf("\n\n");
}

void take_input()
{
    scanf("%d %d", &N,&Cows);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&Stalls[i]);
    }
}

void merge_arr(int l, int mid, int r)
{
    int tmp[r-l+1];
    int i,j,k,p;

    for(i = l, j = l , k = mid+1, p = 0; i <= r ; i++,p++)
    {

        if(j == mid+1)
        {
            tmp[p] = Stalls[k++];
        }
        else if(k == r+1)
        {
            tmp[p] = Stalls[j++];
        }
        else if(Stalls[k] < Stalls[j])
        {
            tmp[p] = Stalls[k++];
        }
        else
        {
            tmp[p] = Stalls[j++];
        }
    }

    for(i = l , p = 0; i <= r ; i++,p++)
    {
        Stalls[i] = tmp[p];
    }
}

void merge_sort(int l, int r)
{
    if(l == r)
    {
        return;
    }

    int mid = (l+r)/2;

    merge_sort(l, mid);
    merge_sort(mid+1,r);
    merge_arr(l, mid, r);
}


int chek(int m)
{
    int pos = Stalls[0];
    int cnt  = 1;

    for(int i = 1 ; i < N ; i++ )
    {
        if(Stalls[i] - pos >= m)
        {
            pos = Stalls[i];
            cnt++;
            if(cnt == Cows)
            {
                return 1;
            }
        }
    }

    return 0;
}

void binarySearch()
{
    int l = 0,h = Stalls[N-1];


    while(h > l)
    {
        int mid = (h+l)/2;

        if(chek(mid) == 1)
        {
            if(mid > Mx)
            {
                Mx = mid;
            }

            l = mid+1;
        }

        else
        {
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
    printf("#%d %d\n", Case,Mx);
}

int main()
{
    freopen("in.txt", "r", stdin);

    scanf("%d",&Test_cases);

    for(Case = 1 ; Case <= Test_cases ; Case++)
    {
        take_input();
        //print_sorted();
        solve();
        //print_sorted();

        print_output();
    }
}
