#include <bits/stdc++.h>
using namespace std;
struct student
{
    char Name[30];
    int Age;
    char Department[50];
    int Year;
};
namespace first
{
    void ReadStudentData(struct student s[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << "Enter the Name of Student : \n";
            getchar();
            scanf("%[^\n]s", s[i].Name);
            cout << "Enter the age of the Student : \n";
            cin >> s[i].Age;
            cout << "Enter the Department : \n";
            getchar();
            scanf("%[^\n]s", s[i].Department);
            cout << "Enter the Year : \n";
            cin >> s[i].Year;
            cout << "\n";
        }
    }
    void ReadStudentData(struct student arr[], FILE *fp, int i)
    {
        if (fp == NULL)
        {
            cout << "error";
        }
        else
        {
            while (1)
            {
                if (feof(fp))
                {
                    break;
                }
                fscanf(fp, "%s %d %s %d", arr[i].Name, &arr[i].Age, arr[i].Department, &arr[i].Year);
                i++;
            }
        }
    }
    void PrintStudentData(struct student s[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << "Name: ";
            cout << s[i].Name << "\n";
            cout << "Age: ";
            cout << s[i].Age << "\n";
            cout << "Department: ";
            cout << s[i].Department << "\n";
            cout << "Year: ";
            cout << s[i].Year << "\n"
                 << "\n";
        }
    }
}
int main()
{
    int n, x;
    cout << "Press 1 for Standard Input and 2 for Some existing file :";
    cin >> x;
    if (x == 1)
    {
        cout << "Enter the Number of Students : ";
        cin >> n;
        struct student *s;
        s = new struct student[n];
        first::ReadStudentData(s, n);
        first::PrintStudentData(s, n);
    }
    else if (x == 2)
    {
        int i = 0;
        struct student s[3];
        FILE *fp;
        fp = fopen("Ques1.txt", "r");
        first::ReadStudentData(s, fp, 0);
        first::PrintStudentData(s, 3);
    }
    return 0;
}
