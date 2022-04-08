 #include<stdio.h>

int main()
{
    int i,j,smallest,count=0,time,n;
    double average=0,tt=0,end;

   printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    int a[n],b[n],x[n];
    int waiting[n],turnaround[n],completion[n],p[n];
    for(i=0;i<n;i++)
    {
      printf("\nEnter arrival time of process: ");
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
      printf("\nEnter burst time of process: ");
      scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
     printf("\nEnter priority of process: ");
      scanf("%d",&p[i]);
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    p[n-1]=-1;
    for(time=0; count!=n; time++)
    {
        smallest=n-1;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
     printf("process\tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletion-time\tpriority\n");
    for(i=0; i<n; i++)
    {
         printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,x[i],a[i],waiting[i],turnaround[i],completion[i],p[i]);
        average = average + waiting[i];
        tt = tt + turnaround[i];
    }
   printf("\n\nAverage waiting time =%f\n",average);
   printf("Average Turnaround time =%f\n",tt);
}