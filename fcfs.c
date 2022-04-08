#include <stdio.h>
int waitingTime(int process[], int n,
int burstTime[], int waitTime[]) {
   waitTime[0] = 0;
   for (int i = 1; i < n ; i++ )
   waitTime[i] = burstTime[i-1] + waitTime[i-1] ;
   return 0;
}
int turnaroundtime( int process[], int n,
int burstTime[], int waitTime[], int tat[]) {
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burstTime[i] + waitTime[i];
   return 0;
}
int avgtime( int process[], int n, int burstTime[]) {
   int waitTime[n], tat[n], total_wt = 0, total_tat = 0;
   int i;
   waitingTime(process, n, burstTime, waitTime);
   turnaroundtime(process, n, burstTime, waitTime, tat);
   printf("Process Burst   Waiting Turn around \n");
   for ( i=0; i<n; i++) {
      total_wt = total_wt + waitTime[i];
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, burstTime[i], waitTime[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}
int main() {
   int process[] = { 2,3,4};
   int n = sizeof process / sizeof process[0];
   int burstTime[] = {9,11,14};
   avgtime(process, n, burstTime);
   return 0;
}