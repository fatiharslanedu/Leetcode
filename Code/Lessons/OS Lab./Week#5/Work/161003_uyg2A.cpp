/*
@Author = Fatih Arslan
Lesson = Operating System Lab.
*/


#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <sys/wait.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void createTree(int);


int main(int argc, char **argv)
{
    char *dvalue = NULL;
    int keep;
    int res = 0;
    string no = "152120161003";
    string name = "Fatih Arslan";

    /* Create a log file */
    ofstream logfile;

    /* ios_base give append permission.*/
    logfile.open("161003_uyg2A_logAll.log", ios_base::app);

    /* Define the time variables. */ 
    time_t rTime;
    struct tm *timeDef;
    char array[100];
    time(&rTime);
    timeDef = localtime(&rTime);
    strftime(array, sizeof(array), "%d-%m-%Y %H:%M:%S", timeDef);
    string str(array);
    cout << "\n\nThis program run after 2 seconds.\n" << str << endl;
    logfile << "\n\n" << str << endl;
    logfile << "-------------------------------------------------\n";
    logfile.close();

    /*
    id: -> 'i' cannot get number but 'd' can get number
    like '-d 5' after ./execfile
    */
    while ((keep = getopt(argc, argv, "id:")) != -1)
        switch (keep)
        {
            /* Info case */
        case 'i':
            cout << no << ", " << name << endl;
            break;

        case 'd': /* this case get double the entered number. */
            dvalue = optarg;
            /*
                atoi function means, we can enter a value with the given characters.
             */
            res = atoi(dvalue);
            res = res * 2;
            if (res == 1 || res == 0)
            {
                cout << "You cant enter the 0 and 1, you must be enter number which is greater than the 0 and 1." << endl;
            }
            break;
        case '?':
            cout << "You need the check operator (-i, -d) or after the d operator, you need to enter a number. " << endl;
            break;
        default:
            abort();
        }

    for (int i = optind; i < argc; i++)
    {
        res = atoi(argv[i]);
    }

    createTree(res);
    
    return 0;
}

void createTree(int depthTree)
{
    int parPid = getpid();
    int crrPid;
    ofstream logfile;
    logfile.open("161003_uyg2A_logAll.log", ios_base::app);
    sleep(2);

    cout << "PID: " << parPid << ", Depth: " << depthTree << "\n\n";
    logfile << "PID: " << parPid << ", Depth: " << depthTree << "\n\n";
    for (int i = 0; i < depthTree; i++)
    {
        crrPid = fork();

        /* if process not working.*/
        if (crrPid < 0)
        {
            cout << "Process not working." << endl;
            exit(0);
        }
        
        else if (crrPid == 0) 
        {
            /*Child Process*/
            cout << "PID: " << getpid() << " | PPID: " << getppid() << endl;
            logfile << "PID: " << getpid() << " | PPID: " << getppid() << endl;
        }


    }
   
        char mychar[100];
        char mychar2[100];
        /* Special system command for pstree */
        sprintf(mychar, "pstree -p -U %d", parPid);
        sprintf(mychar2, "pstree -p -U %d >> 161003_uyg2A_logAll.log", parPid);
        system(mychar);
        system(mychar2);
    

    logfile.close();
}
