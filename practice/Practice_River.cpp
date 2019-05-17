#include <stdio.h>

int P1,M1,P2,M2,P3,M3;
int Ans = 0;
int Test_cases,Case;


void take_input()
{
    scanf("%d %d", &P1,&M1);
    scanf("%d %d",&P2, &M2);
    scanf("%d %d", &P3,&M3);
}

int absdif(int a, int b)
{

    if(a > b){
        return a-b;
    }

    return b-a;
}


int max_num(int a, int b)
{
    if(a > b){
        return a;
    }

    return b;
}

void solve()
{
    int i,j,k;
    int left,right;
    int dist1, dist2, dist3;
    int mx = 0;

    Ans = 30;

    for(i = 1; i+M1+M2+M3-1 <= 30 ; i++){
        left = absdif(i,P1);
        right = absdif(P1,i+M1-1);

        dist1 = max_num(left,right);

        for(j = i+M1; j+M2+M3-1 <= 30 ; j++){
            left = absdif(j,P2);
            right = absdif(P2, j+M2-1);

            dist2 = max_num(left,right);

            for(k = j+M2 ; k+M3-1<=30 ; k++){
                left = absdif(k,P3);
                right = absdif(P3, k+M3-1);

                dist3 = max_num(left,right);

                mx = max_num(dist1,dist2);
                mx = max_num(mx,dist3);

                if(mx < Ans ){
                    Ans = mx;
                }
            }
        }
    }
}


void print_output()
{
    printf("#%d %d\n",Case,Ans);
}

int main()
{
    freopen("in_river.txt", "r", stdin);
    freopen("out_river.txt", "w", stdout);

    scanf("%d", &Test_cases);

    for(Case = 1; Case <= Test_cases; Case++){
        take_input();
        solve();
        print_output();
    }
}
