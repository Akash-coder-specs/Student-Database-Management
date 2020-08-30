#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
int main()
{
	top:
    FILE *fp, *ft;
    char another;
    int choice,a=1;

    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        char section[20];
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("Record.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("Record.txt","wb+");
    }
    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit   Program";
        fflush(stdin);
        cout<<"\n\n\t\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1 :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case 2:
            system("cls");
            rewind(fp);
            cout << "=== The records ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<a<<'.'<<"Name: " << e.first_name <<" "<< e.last_name;
                cout <<"\nCourse: " <<e.course <<"\nsection: "<< e.section;
                a++; 
				cout<<"\n";             
            }
            cout<<"\n";
            system("pause");
            break;
        case 3 :
        	last_name:
            system("cls");
            another='y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the first name of the student : ";
                cin >> xfirst_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.first_name,xfirst_name) == 0)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> e.course;
                        cout << "Enter new the Section   : ";
                        cin >> e.section;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                    	{
                    		cout<<"\n\n\t\t\tRecord is not found.";
                    		fordelay(10000);
                    		goto last_name;
						}						
            }
                cout << "\n Modify Another Record (Y/N): ";
                cin>>another;           
                fflush(stdin);
            }
            break;


        case 4:
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the first name of the student to delete : ";
                cin >> xfirst_name;

                ft = fopen("temp.txt", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.first_name,xfirst_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("Record.txt");
                rename("temp.txt","Record.txt");
                fp=fopen("Record.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case 5:
            fclose(fp);
            system("cls");
            fordelay(1000000);
            cout << "\n\n\t\t\t     THANK YOU FOR USING THIS SOFTWARE";
            exit(0);
        	break;
		}
        
    }
    system("pause");
    return 0;
}
