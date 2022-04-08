#include<stdio.h>
struct process
{
    int id,wt,arrivalTime,burstTime,tat,priority;
};
struct process a[10];

void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

int main()
{
    int n,check_ar=0;
    int Cmp_time=0;
    float Total_wt=0,Total_tat=0,avg_wt,avg_tat;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the Arrival time: ");
        scanf("%d",&a[i].arrivalTime);
        printf("Enter the Burst time: ");
        scanf("%d",&a[i].burstTime);
        printf("Enter the  priorityiority: ");
        scanf("%d",&a[i].priority);
        a[i].id=i+1;
       
        if(i==0)
         check_ar=a[i].arrivalTime;
         
        if(check_ar!=a[i].arrivalTime )
         check_ar=1;
        
    }
    
    if(check_ar!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j].arrivalTime>a[j+1].arrivalTime)
                {
                      swap(&a[j].id,&a[j+1].id);
                      swap(&a[j].arrivalTime,&a[j+1].arrivalTime);
                      swap(&a[j].burstTime,&a[j+1].burstTime);
                      swap(&a[j].priority,&a[j+1].priority);
                }
            }
        }
    }
   
    if(check_ar!=0)
    {
        a[0].wt=a[0].arrivalTime;
        a[0].tat=a[0].burstTime-a[0].arrivalTime;
       
        Cmp_time=a[0].tat;
        Total_wt=Total_wt+a[0].wt;
        Total_tat=Total_tat+a[0].tat;
        for(int i=1;i<n;i++)
        {
            int min=a[i].priority;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j].priority && a[j].arrivalTime<=Cmp_time)
                {
                      min=a[j].priority;
                      swap(&a[i].id,&a[j].id);
                      swap(&a[i].arrivalTime,&a[j].arrivalTime);
                      swap(&a[i].burstTime,&a[j].burstTime);
                      swap(&a[i].priority,&a[j].priority);
                      
                }
                
            }
            a[i].wt=Cmp_time-a[i].arrivalTime;
            Total_wt=Total_wt+a[i].wt;
          
            Cmp_time=Cmp_time+a[i].burstTime;
            
            a[i].tat=Cmp_time-a[i].arrivalTime;
            Total_tat=Total_tat+a[i].tat;
            
        }
    }
    
    else
    {
        for(int i=0;i<n;i++)
        {
            int min=a[i].priority;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j].priority && a[j].arrivalTime<=Cmp_time)
                {
                    min=a[j].priority;
                      swap(&a[i].id,&a[j].id);
                      swap(&a[i].arrivalTime,&a[j].arrivalTime);
                      swap(&a[i].burstTime,&a[j].burstTime);
                       swap(&a[i].priority,&a[j].priority);
                }
                
            }
            a[i].wt=Cmp_time-a[i].arrivalTime;
            
           
            Cmp_time=Cmp_time+a[i].burstTime;
            
           
            a[i].tat=Cmp_time-a[i].arrivalTime;
            Total_wt=Total_wt+a[i].wt;
            Total_tat=Total_tat+a[i].tat;
            
        }
        
    }
    
    avg_wt=Total_wt/n;
    avg_tat=Total_tat/n;

    printf("\nAvg waiting time is: %f\n",avg_wt);
    printf("Avg turn around time is: %f",avg_tat);
    return 0;
}
