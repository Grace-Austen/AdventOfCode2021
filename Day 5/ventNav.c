

#include <stdio.h>
#include <math.h>

void dangerVentsSimple(void);
void dangerVentsAdvanced(void);

int main(void)
{
    dangerVentsAdvanced();
    dangerVentsSimple();
}

void dangerVentsAdvanced(void)
{
    //File pointers
    FILE* inFile = fopen("input2.txt", "r");

    //Temporary input storage
    int inX1, inX2, inY1, inY2 = 0;

    //for loop iterators
    int x, y = 0;

    //Seafloor array
    char floor[1000][1000];
    for(x = 0; x < 1000; x++)
    {
        for(y = 0; y < 1000; y++)
        {
            floor[x][y] = 0;
        }
    }

    //Vent counter
    int dangerVents = 0;

    //File input
    while(!feof(inFile))
    {
        fscanf(inFile, "%d,%d -> %d,%d", &inX1, &inY1, &inX2, &inY2);
        if(inX1 == inX2)
        {
            if(inY1 < inY2)
            {
                for(y = inY1; y <= inY2; y++)
                {
                    floor[inX1][y]++;
                }
            }
            else
            {
                for(y = inY2; y <= inY1; y++)
                {
                    floor[inX1][y]++;
                }
            }
        }
        else if(inY1 == inY2)
        {
            if(inX1 < inX2)
            {
                for(x = inX1; x <= inX2; x++)
                {
                    floor[x][inY1]++;
                }
            }
            else
            {
                for(x = inX2; x <= inX1; x++)
                {
                    floor[x][inY1]++;
                }
            }
        }
        else
        {
            for(x = fmin(inX1, inX2); x < fmax(inX1, inX2); x++)
            {
                y = fmin(inY1, inY2);
                floor[x][y]++;
            }
        }
    }

    fclose(inFile);

    //Check floor data
    for(x = 0; x < 1000; x++)
    {
        for(y = 0; y < 1000; y++)
        {
            if(floor[x][y] > 1)
            {
                dangerVents++;
            }
        }
    }

    for(x = 0; x < 10; x++)
    {
        for(y = 0; y < 10; y++)
        {
            printf("%d ",floor[x][y]);
        }
        puts("");
    }

    printf("Dangerous Vents: %d\n", dangerVents);

}



void dangerVentsSimple(void)
{
    //File pointers
    FILE* inFile = fopen("input.txt", "r");

    //Temporary input storage
    int inX1, inX2, inY1, inY2 = 0;

    //for loop iterators
    int x, y = 0;

    //Seafloor array
    char floor[1000][1000];
    for(x = 0; x < 1000; x++)
    {
        for(y = 0; y < 1000; y++)
        {
            floor[x][y] = 0;
        }
    }

    //Vent counter
    int dangerVents = 0;

    //File input
    while(!feof(inFile))
    {
        fscanf(inFile, "%d,%d -> %d,%d", &inX1, &inY1, &inX2, &inY2);
        if(inX1 == inX2)
        {
            if(inY1 < inY2)
            {
                for(y = inY1; y <= inY2; y++)
                {
                    floor[inX1][y]++;
                }
            }
            else
            {
                for(y = inY2; y <= inY1; y++)
                {
                    floor[inX1][y]++;
                }
            }
        }
        if(inY1 == inY2)
        {
            if(inX1 < inX2)
            {
                for(x = inX1; x <= inX2; x++)
                {
                    floor[x][inY1]++;
                }
            }
            else
            {
                for(x = inX2; x <= inX1; x++)
                {
                    floor[x][inY1]++;
                }
            }
        }
    }

    fclose(inFile);

    //Check floor data
    for(x = 0; x < 1000; x++)
    {
        for(y = 0; y < 1000; y++)
        {
            if(floor[x][y] > 1)
            {
                dangerVents++;
            }
        }
    }

    printf("Dangerous Vents: %d\n", dangerVents);

}