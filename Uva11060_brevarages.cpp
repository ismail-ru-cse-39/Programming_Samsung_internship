#include <stdio.h>

#define SZ 105

int Path[SZ][SZ];
char Name[SZ][SZ];
int Arr[SZ];
int L;
int N,M;
int Case;

void print_path()
{
    for(int i = 0; i <= N ; i++)
    {
        for(int j = 0 ; j <= N ; j++)
        {
            printf("%d ",Path[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void init_path()
{
    for(int i = 0 ; i <= N ; i++)
    {
        for(int j = 0; j <= N ; j++)
        {
            Path[i][j] = 0;
        }
    }
}

int string_compare(char st1[], char st2[])
{
    int i = 0;
    for(i = 0 ; st1[i] && st2[i]; i++)
    {
        if(st1[i] != st2[i])
        {
            return 0;
        }
    }

    if(st1[i] != st2[i])
    {
        return 0;
    }

    return 1;
}

int search_string(char st[])
{
    int i;
    for(i = 1 ; i <= N ; i++)
    {
        if(string_compare(st,Name[i]))
        {
            return i;
        }
    }
    return -1;
}

void take_input()
{
    int i;

    for(i = 1; i <= N ; i++)
    {
        scanf("%s",&Name[i]);
    }

    scanf("%d",&M);

    for(i = 0 ; i < M ; i++)
    {
        char name1[SZ];
        char name2[SZ];

        scanf("%s",&name1);
        scanf("%s",&name2);

        int x = search_string(name1);
        int y = search_string(name2);

        Path[x][y] = 1;


    }
}


void count_indegree()
{
    for(int i = 1 ; i<= N ; i++)
    {
        int cnt = 0;
        for(int j = 1 ; j<= N ; j++)
        {
            if(Path[j][i])
            {
                cnt++;
            }
        }

        Path[i][0] = cnt;
    }
}



void solve_case()
{
    count_indegree();
    //int j = 0;
    L = 0;
    for(int k = 0;  k < N ; k++)

    {
        //print_path();

        for(int i = 1 ; i<= N ; i++)
        {
            if(Path[i][0] == 0)
            {
                Arr[L++] = i;

                Path[i][0] -= 1;
                for(int j = 1 ; j <= N ; j++)
                {
                    if(Path[i][j] == 1)
                    {
                        Path[i][j] = 0;
                        Path[j][0] -= 1;
                    }
                }

                break;

            }
        }
    }

}

void print_case()
{
    for(int i = 0; i < L ; i++){
        printf(" %s",Name[Arr[i]]);
    }

    printf(".\n");
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    Case = 1;

    while(scanf("%d",&N) == 1)
    {
        //printf("%d\n",N);
        init_path();
        take_input();
        // print_path();
        //solve_case();
        //count_indegree();
        //print_path();
        solve_case();
        //print_path();

        printf("Case #%d: Dilbert should drink beverages in this order:",Case++);
        print_case();
        printf("\n");


    }

}
