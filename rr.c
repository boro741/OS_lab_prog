#include<stdio.h>

int main()
{
    char pname[25][25];
    int bt[25],st[25],ft[25],wt[25],n,quantum,roundno=1;
    int i;
    static int totalBT,temp = 0;
    
    printf("How many processes are there: ");
    scanf("%d",&n);
    
    printf("Enter the processes and their burst time: ");
    for(i=0;i<n;i++)
    {
        scanf("%s %d",pname[i],&bt[i]);
        totalBT += bt[i];
    }
    
    printf("Enter Time quantum per round: ");
    scanf("%d",&quantum);
    
    printf("Before starting");
    printf("\n\nprocess\t rt\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%d\n",pname[i],bt[i]);
    }
    
    
    while(temp < totalBT)
    {
        printf("\nWhen Round %d ends\n",roundno++);
        printf("\nProcess \t rem time \t st \t ft\n");
        
        for(i=0;i<n;i++)
        {
            // Burst time greater ho to minus karte jao
            if(bt[i] > quantum)
            {
                // Setting the Starting and Final time
                // also the next starting time
                st[i] = temp;            // starting time
                bt[i] = bt[i] - quantum; // Remaining time 
                temp = temp + quantum;  // final time
                st[i+1] = ft[i] = temp;
            } 
            else{
                st[i] = temp;
                temp = temp + bt[i];
                bt[i] = 0;
                ft[i] = temp;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(st[i] != ft[i])
            {
                printf("%s \t\t %d \t\t %d \t%d\n",pname[i],bt[i],st[i],ft[i]);
            }
        }
    }
    
    return 0;

}