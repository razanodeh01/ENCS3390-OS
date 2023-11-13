#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int PID;
    int BurstTime;
    int ArrivalTime;
    int RemainingTime;
    int ready;
    int priority;
    int IsStarted;
} process;


typedef struct
{
    double averageWaitingTime;
    double averageTurnaroundTime;
    double averageResponseTime;
} Values;


//Functions used in our operating system.
void Menu();
void copyProcesses(process[], process[],int);
void RoundRobinAlgorithm(process[],int,double*,double*,double*);
void FirstComeFirstSerive(process[],int,double*,double*,double*);
void priorityScheduling(process[],int,double*,double*,double*);
void prioritySchedulingNonPreemptive(process[],int,double*,double*,double*);
void ShortestJopFirst(process[],int,double*,double*,double*);
void ShortestRemainingJopFirst(process[],int,double*,double*,double*);
Values findMinValue(Values[],int);



int main()
{
    //Start our program.
    printf("Welcome to our program Dr.Bashar ...\n\n");

    //Define a variable to save the number of processes.
    int n;
    printf("Please enter the number of processes to be executed:\n");
    //Check if the n is valid or not.
    while (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Please enter a valid number of processes!\n");

        // Clear input buffer.
        while (getchar() != '\n');
    }

    //Declare an array of processes.
    process p[n];

    //A loop to take all the process information from the user.
    for (int i = 0; i < n; i++)
    {
        printf("\nInformation for the %d process.\n", i + 1);
        printf("Please enter the ID of the process:\n");
        while (scanf("%d", &p[i].PID) != 1 || p[i].PID < 0)
        {
            printf("Please enter a valid ID for the process!\n");
            while (getchar() != '\n');  // Clear input buffer
        }

        printf("Please enter the CPU burst time:\n");
        while (scanf("%d", &p[i].BurstTime) != 1 || p[i].BurstTime <= 0)
        {
            printf("Please enter a valid burst CPU time!\n");
            while (getchar() != '\n');  // Clear input buffer
        }

        printf("Please enter the arrival time for the process:\n");
        while (scanf("%d", &p[i].ArrivalTime) != 1 || p[i].ArrivalTime < 0)
        {
            printf("Please enter a valid arrival time!\n");
            while (getchar() != '\n');  // Clear input buffer
        }

        printf("Please enter the priority of the process:\n");
        while (scanf("%d", &p[i].priority) != 1 || p[i].priority < 0)
        {
            printf("Please enter a valid value of the priority!\n");
            while (getchar() != '\n');  // Clear input buffer
        }

        p[i].RemainingTime = p[i].BurstTime;
        p[i].ready = 0;
        p[i].IsStarted=0;

        printf("------------------------------------------------------------------------------------------------------------------\n");
    }

    printf("***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t", p[i].PID, p[i].priority, p[i].ArrivalTime, p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }


    process copiedProcesses[n];
    char option[2];//Create a temporary variable.
    Values v[6],result;
    result.averageResponseTime=0;
    result.averageTurnaroundTime=0;
    result.averageWaitingTime=0;
    // Do-While loop unless the user did not select 7th option.
    do
    {
        Menu();//Call the menu function to print options for user.
        printf("\nOption number:\n");
        scanf("%s",option);//Scan the option number.
        if(strlen(option)>1) // Make sure that the user enter a valid number.(option number from one digit).
            strcpy(option,"0");
        else
        {
            switch(atoi(option))//To know which option the user enter.
            {
            case 1://if option 1 selected.
                copyProcesses(p,copiedProcesses,n);
                FirstComeFirstSerive(copiedProcesses,n,&v[0].averageResponseTime,&v[0].averageTurnaroundTime,&v[0].averageWaitingTime);
                break;
            case 2://if option 2 selected.
                copyProcesses(p,copiedProcesses,n);
                RoundRobinAlgorithm(copiedProcesses,n,&v[1].averageResponseTime,&v[1].averageTurnaroundTime,&v[1].averageWaitingTime);
                break;
            case 3://if option 3 selected.
                copyProcesses(p,copiedProcesses,n);
                priorityScheduling(copiedProcesses, n,&v[2].averageResponseTime,&v[2].averageTurnaroundTime,&v[2].averageWaitingTime);
                break;
            case 4://if option 4 selected.
                copyProcesses(p,copiedProcesses,n);
                prioritySchedulingNonPreemptive(copiedProcesses,n,&v[3].averageResponseTime,&v[3].averageTurnaroundTime,&v[3].averageWaitingTime);
                break;
            case 5://if option 5 selected.
                copyProcesses(p,copiedProcesses,n);
                ShortestJopFirst(copiedProcesses,n,&v[4].averageResponseTime,&v[4].averageTurnaroundTime,&v[4].averageWaitingTime);
                break;
            case 6://if option 6 selected.
                copyProcesses(p,copiedProcesses,n);
                ShortestRemainingJopFirst(copiedProcesses,n,&v[5].averageResponseTime,&v[5].averageTurnaroundTime,&v[5].averageWaitingTime);
                break;
            case 7://if option 7 selected.
                result=findMinValue(v,n);
                for(int i=0 ; i<=5 ; i++)
                {
                    if(result.averageResponseTime==v[i].averageResponseTime)
                    {
                        printf("The most efficient algorithm which has the minimum value for average response time(%.2f) is:\n",v[i].averageResponseTime);
                        switch(i)
                        {
                        case 0:
                            printf("First come first severe.\n");
                            break;
                        case 1:
                            printf("Round robin algorithm.\n");
                            break;
                        case 2:
                            printf("Priority algorithm.\n");
                            break;
                        case 3:
                            printf("Priority non-preemptive algorithm.\n");
                            break;
                        case 4:
                            printf("Shortest job first algorithm.\n");
                            break;
                        case 5:
                            printf("Shortest remaining job algorithm.\n");
                            break;

                        }
                    }
                }
                printf("\n");
                for(int i=0 ; i<=5 ; i++)
                {
                    if(result.averageTurnaroundTime==v[i].averageTurnaroundTime)
                    {
                        printf("The most efficient algorithm which has the minimum value for average turnaround time(%.2f) is:\n",v[i].averageTurnaroundTime);
                        switch(i)
                        {
                        case 0:
                            printf("First come first severe.\n");
                            break;
                        case 1:
                            printf("Round robin algorithm.\n");
                            break;
                        case 2:
                            printf("Priority algorithm.\n");
                            break;
                        case 3:
                            printf("Priority non-preemptive algorithm.\n");
                            break;
                        case 4:
                            printf("Shortest job first algorithm.\n");
                            break;
                        case 5:
                            printf("Shortest remaining job algorithm.\n");
                            break;

                        }
                    }

                }
                printf("\n");
                for(int i=0 ; i<=5 ; i++)
                {
                    if(result.averageWaitingTime==v[i].averageWaitingTime)
                    {
                        printf("The most efficient algorithm which has the minimum value for average waiting time(%.2f) is:\n",v[i].averageWaitingTime);
                        switch(i)
                        {
                        case 0:
                            printf("First come first severe.\n");
                            break;
                        case 1:
                            printf("Round robin algorithm.\n");
                            break;
                        case 2:
                            printf("Priority algorithm.\n");
                            break;
                        case 3:
                            printf("Priority non-preemptive algorithm.\n");
                            break;
                        case 4:
                            printf("Shortest job first algorithm.\n");
                            break;
                        case 5:
                            printf("Shortest remaining job algorithm.\n");
                            break;

                        }
                    }
                }

                break;
            case 8:
                printf("***********************************************************************\n");
                printf("Hope you enjoy using our operating system, we love you Dr.Beshoooooo.\n");
                printf("***********************************************************************\n");
                exit(0);
                break;
            default :
                printf("Please enter a valid number from 1-8.\n");
                break;
            }
        }
    }
    while(atoi(option) != 8);


    return 0;
}

//Function used to copy the original information of the set of processes.
void copyProcesses(process source[], process destination[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

// A menu contain the available operations in our OPEARTING SYSTEM.
void Menu()
{

    printf("************************************************* Menu ********************************************************");
    printf("\n Please enter an option you would to run it from this menu:");
    printf("\n 1. First come first serve algorithm.");
    printf("\n 2. Round robin algorithm.");
    printf("\n 3. Priority algorithm.");
    printf("\n 4. Priority -Non preemptive- algorithm.");
    printf("\n 5. Shortest job first algorithm.");
    printf("\n 6. Remaining shortest job algorithm.");
    printf("\n 7. Find the most efficient algorithm.");
    printf("\n 8. Exit.");

}

void RoundRobinAlgorithm(process p[],int n,double *a,double *b,double *c)
{

    int quantum, completed = 0, currentTime = 0;
    printf("Please enter the quantum for the algorithm:\n");
    scanf("%d", &quantum);
    while (quantum <= 0)
    {
        printf("Please enter a valid value for the quantum!\n");
        scanf("%d", &quantum);
    }

    // Sort the processes based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].ArrivalTime > p[j + 1].ArrivalTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

     //Print the processes after order them.
    printf("\n***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }


    while (completed < n)
    {
        int processExecuted = 0; // Flag to track if a process is executed in the current time step

        for (int i = 0; i < n; i++)
        {
            if (p[i].RemainingTime > 0 && p[i].ready == 0 && p[i].ArrivalTime <= currentTime)
            {

                if (p[i].RemainingTime <= quantum)
                {
                    if(p[i].IsStarted==0)
                    {
                        int responseTime = currentTime - p[i].ArrivalTime;
                        *a += responseTime;
                        p[i].IsStarted=1;
                    }
                    currentTime += p[i].RemainingTime;
                    p[i].RemainingTime = 0;
                    p[i].ready = 1;
                    completed++;
                    processExecuted = 1;
                    int waitingTime = currentTime - p[i].ArrivalTime - p[i].BurstTime;
                    *c += waitingTime;
                    int turnaroundTime = currentTime - p[i].ArrivalTime;
                    *b += turnaroundTime;
                    printf("The process %d is complete executed at time %d.\n", p[i].PID, currentTime);
                }
                else
                {
                    if(p[i].IsStarted==0)
                    {
                        int responseTime = currentTime - p[i].ArrivalTime;
                        *a += responseTime;
                        p[i].IsStarted=1;
                    }
                    currentTime += quantum;
                    p[i].RemainingTime -= quantum;
                    processExecuted = 1;
                    printf("The process %d is still running at time %d.\n", p[i].PID, currentTime);
                }

            }
        }

        if (processExecuted == 0)
        {
            currentTime++;
            printf("Until time %d, there are no processes arrived 'IDLE'.\n", currentTime);
        }
    }

    *a = *a / n;
    *c =  *c / n;
    *b = *b / n;

    printf("\nAverage Response Time: %.2f.\n",*a);
    printf("Average Waiting Time: %.2f.\n",*c);
    printf("Average Turnaround Time: %.2f.\n",*b);

}

void FirstComeFirstSerive(process p[],int n,double *a,double *b,double *c)
{
    int currentTime=0,completed=0;

    // Sort the processes based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].ArrivalTime > p[j + 1].ArrivalTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    //Print the processes after order them.
    printf("\n***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }


    while(completed<n)
    {
        for(int i=0 ; i<n ; i++)
        {
            if(p[i].ArrivalTime<=currentTime && p[i].ready==0)
            {
                if(p[i].IsStarted==0)
                {
                    int responseTime = currentTime - p[i].ArrivalTime;
                    *a += responseTime;
                    p[i].IsStarted=1;
                }
                currentTime+=p[i].RemainingTime;
                *c += currentTime - p[i].ArrivalTime - p[i].BurstTime;
                *b += currentTime - p[i].ArrivalTime;
                p[i].ready=1;
                completed++;
                printf("The process %d is complete executed at time %d.\n",p[i].PID,currentTime);
            }
            else
            {
                currentTime++;
                printf("Until time %d, there no processes arrived 'IDLE'.\n",currentTime);
                i=i-1;
            }

        }
    }



    *c = *c / n;
    *b = *b / n;
    *a = *a / n;

    printf("\nAverage Response Time: %.2f.\n",*a);
    printf("Average Waiting Time: %.2f\n",*c);
    printf("Average Turnaround Time: %.2f\n",*b);


}

void priorityScheduling(process p[],int n,double *a,double *b,double *c)
{
    int completed=0;
    int currentTime=0;

    // Sort the processes based on arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].ArrivalTime > p[j + 1].ArrivalTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\n***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }



    int currentProcess = -1;  // Variable to track the currently executing process

    while (completed < n)
    {
        int selectedProcess = -1;
        int highestPriority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].ArrivalTime <= currentTime && p[i].ready == 0 && p[i].priority < highestPriority)
            {
                highestPriority = p[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess != -1)
        {
            if(p[selectedProcess].IsStarted==0)
            {
                int responseTime = currentTime - p[selectedProcess].ArrivalTime;
                *a += responseTime;
                p[selectedProcess].IsStarted=1;

            }
            if (currentProcess != -1 && p[selectedProcess].priority < p[currentProcess].priority)
            {

                // Preempt the current process.
                printf("The process %d is preempted at time %d.\n", p[currentProcess].PID, currentTime);

                p[currentProcess].ready = 0;  // Mark the preempted process as not completed
            }

            currentProcess = selectedProcess;  // Update the current process
            currentTime++;
            p[currentProcess].RemainingTime--;

            if (p[currentProcess].RemainingTime == 0)
            {
                // The current process has completed execution
                completed++;
                *c += currentTime - p[selectedProcess].ArrivalTime - p[selectedProcess].BurstTime;
                *b += currentTime - p[selectedProcess].ArrivalTime;
                p[currentProcess].ready = 1;
                printf("The process %d is complete executed at time %d.\n", p[currentProcess].PID, currentTime);
                currentProcess = -1;  // Reset the current process
            }
        }
        else
        {
            currentTime++;
            printf("Until time %d, there's no processes arrived 'IDEL'.\n",currentTime);
        }
    }
    *a = *a / n;
    *c = *c / n;
    *b = *b / n;
    printf("\nAverage Response Time: %.2f.\n", *a);
    printf("Average Waiting Time: %.2f.\n", *c);
    printf("Average Turnaround Time: %.2f.\n", *b);
}

void prioritySchedulingNonPreemptive(process p[],int n,double *a,double *b,double *c)
{

    int currentTime=0;
    // Sort the processes based on CPU burst time.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority > p[j + 1].priority)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nThe order of processes become like this:\n");
    printf("***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }

    for(int i=0 ; i<n ; i++)
    {
        if(p[i].IsStarted==0)
        {
            int responseTime = currentTime;
            *a += responseTime;
            p[i].IsStarted=1;
        }
        currentTime+=p[i].RemainingTime;
        *c += currentTime - p[i].BurstTime;
        *b += currentTime;
        printf("The process %d is complete executed at time %d.\n",p[i].PID,currentTime);
    }
    *c=*c / n;
    *b=*b / n;
    *a=*a / n;

    printf("\nAverage Response Time: %.2f.\n", *a);
    printf("Average Waiting Time: %.2f\n", *c);
    printf("Average Turnaround Time: %.2f\n", *b);


}

void ShortestJopFirst(process p[],int n,double *a,double *b,double *c)
{

    int completed=0,currentTime=0;
    // Sort the processes based on CPU burst time.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].BurstTime > p[j + 1].BurstTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nThe order of processes become like this:\n");
    printf("***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].RemainingTime > 0 && p[i].ready == 0)
            {
                if(p[i].IsStarted==0)
                {
                    int responseTime = currentTime;
                    *a += responseTime;
                    p[i].IsStarted=1;
                }
                currentTime += p[i].RemainingTime;
                p[i].RemainingTime=0;
                p[i].ready = 1;
                completed++;
                *c += currentTime - p[i].BurstTime;
                *b += currentTime;
                printf("The process %d is complete executed at time %d.\n",p[i].PID,currentTime);
            }
        }
    }
    *c=*c / n;
    *b=*b / n;
    *a=*a / n;
    printf("\nAverage Waiting Time: %.2f\n", *c);
    printf("Average Turnaround Time: %.2f\n", *b);
    printf("Average Response Time: %.2f.\n", *a);

}

void ShortestRemainingJopFirst(process p[],int n,double *a,double *b,double *c)
{

    int completed=0,currentTime=0;
    // Sort the processes based on CPU burst time.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].BurstTime > p[j + 1].BurstTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("\nThe order of processes become like this:\n");
    printf("***********************************************************************************************************************\n");
    printf("         PID\t\tPriority\t\t Arrival Time\t\t CPU burst time\t\t\n");
    printf("***********************************************************************************************************************\n");
    for(int i=0; i<n ; i++)
    {
        printf("\n         %d\t\t%d\t\t            %d\t\t              %d\t\t",p[i].PID,p[i].priority,p[i].ArrivalTime,p[i].BurstTime);
        printf("\n***********************************************************************************************************************\n");
    }

    int currentProcess = -1;  // Variable to track the currently executing process

    while (completed < n)
    {
        int selectedProcess = -1;
        int highestRemaining = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].ArrivalTime <= currentTime && p[i].ready == 0 && p[i].BurstTime < highestRemaining)
            {
                highestRemaining = p[i].BurstTime;
                selectedProcess = i;
            }
        }

        if (selectedProcess != -1)
        {
            if(p[selectedProcess].IsStarted==0)
            {
                int responseTime = currentTime - p[selectedProcess].ArrivalTime;
                *a += responseTime;
                p[selectedProcess].IsStarted=1;
            }
            if (currentProcess != -1 && p[selectedProcess].BurstTime < p[currentProcess].BurstTime)
            {
                // Preempt the current process.
                printf("The process %d is preempted at time %d.\n", p[currentProcess].PID, currentTime);
                //currentTime += p[selectedProcess].RemainingTime;

                p[currentProcess].ready = 0;  // Mark the preempted process as not completed
            }

            currentProcess = selectedProcess;  // Update the current process
            currentTime++;
            p[currentProcess].RemainingTime--;

            if (p[currentProcess].RemainingTime == 0)
            {
                // The current process has completed execution
                completed++;
                p[currentProcess].ready = 1;
                *c += currentTime - p[selectedProcess].ArrivalTime - p[selectedProcess].BurstTime;
                *b += currentTime - p[selectedProcess].ArrivalTime;
                printf("The process %d is complete executed at time %d.\n", p[currentProcess].PID, currentTime);
                currentProcess = -1;  // Reset the current process
            }
        }
        else
        {
            currentTime++;
            printf("Until time %d, there's no processes arrived 'IDEL'.\n",currentTime);
        }
    }

    *a=*a / n;
    *c=*c / n;
    *b=*b / n;
    printf("\nAverage Response Time: %.2f.\n", *a);
    printf("Average Waiting Time: %.2f.\n",*c);
    printf("Average Turnaround Time: %.2f.\n",*b);

}

Values findMinValue(Values v[],int n)
{
    Values result=v[0];
    for (int i = 1; i < 5; i++)
    {
        if (v[i].averageResponseTime < result.averageResponseTime)
        {
            result.averageResponseTime = v[i].averageResponseTime;  // Update the minimum average response time.
        }
    }

    for (int i = 1; i < 5; i++)
    {
        if (v[i].averageTurnaroundTime < result.averageTurnaroundTime)
        {
            result.averageTurnaroundTime = v[i].averageTurnaroundTime;  // Update the minimum average turnaround time.
        }
    }

    for (int i = 1; i < 5; i++)
    {
        if (v[i].averageWaitingTime < result.averageWaitingTime)
        {
            result.averageWaitingTime = v[i].averageWaitingTime;  // Update the minimum average waiting time.
        }
    }

    return result;
}
