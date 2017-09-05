#include<stdio.h>

int main()
{
    int totMemSize,noPartition,eachPartition,noProcess;
    int mReqProcess[4],i,f,f1=0,f2=0,intFrag,fra2,s1,remMem;
    
    printf("Enter the memory size: ");
    scanf("%d",&totMemSize);
    
    printf("Enter the no. of partitions: ");
    scanf("%d",&noPartition);
    
    eachPartition = totMemSize/noPartition;
    
    printf("Each partition size is: %d",eachPartition);
    
    printf("\nEnter the no of processes: ");
    scanf("%d",&noProcess);
    
    remMem = totMemSize;
    
    for (i=0; i<noProcess; i++) {
        if(remMem < eachPartition)
        {
            printf("\nThere is no further memory for process %d",i+1);
            mReqProcess[i] = 0;
            break;
        }
        else{
            printf("\nEnter the memory required for process %d:",i+1);
            scanf("%d",&mReqProcess[i]);
            
            if (mReqProcess[i] <= eachPartition) {
                printf("\nProcess is allocated in partition %d",i+1);
                
                intFrag = eachPartition - mReqProcess[i];
                
                printf("\nInternal Fragmentation for process is: %d",intFrag);
                
                f1 = f1+intFrag;
                remMem = remMem - eachPartition;
            }
            // if the mReqProcess size is more than partition size then error
            else{
                printf("\nProcess not allocated in partition %d",i+1);
                s1 = mReqProcess[i];
                
                while (s1 > eachPartition) {
                    s1 = s1 - eachPartition;
                    remMem = remMem - eachPartition;
                }
                
                remMem = remMem - eachPartition;
                fra2 = eachPartition - s1;
                f2 = f2 + fra2;
                
                printf("\nExternal Fragmentation for this process is: %d",fra2);
                
            }
            
        }
    }
    
    printf("\nProcess \t alloted memory");
    
    for (i=0; i<noProcess; i++) {
        printf("\n %5d\t%5d",i+1,mReqProcess[i]);
    }
    
    f = f1 + f2;
    printf("\nThe total no of fragmentation is: %d",f);
    
    return 0;
}