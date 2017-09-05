#include<stdio.h>

int main()
{
    // n - no. of processes
    // exeTime - Burst Time
    int n,exeTime[100],wTime=0,tAT=0;
    int i;
    float awt, atat, _awt = 0, _atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter exe time for process %d: ",i+1);
        scanf("%d",&exeTime[i]);
    }

    printf("Pid \t\t BT \t\t Wt \t\t TAT");
    for(i=0;i<n;i++)
    {
        tAT = exeTime[i]+wTime;
        printf("\n%d \t\t %d \t\t %d \t\t %d",i+1,exeTime[i],wTime,tAT);
       
         _awt += wTime;
        _atat += tAT;

        wTime += exeTime[i];
    }

    awt = _awt/n;
    atat = _atat/n;
  
    printf("\nAverage waiting time: %f",awt);
    printf("\nAverage turn around time: %f\n",atat);

    return 0;
}
