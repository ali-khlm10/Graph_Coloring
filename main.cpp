#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
 int N,M,_N_,Counter=0,MaxCounter=0;
 int Matrix[1000][1000];
 string C[1000];
 string ForCName[1000];
 int Rand[1000][1000];
 int SecondRand[1000][1000];
 int CounterArray[1000];
 int CounterArrayIntermediatePopulation[1000];
 int ColorNumber;
 int AnswerArray[1000][1000];
 int TempArray[1000][1000];
///////////////////////////////////////////////////////////////////////////////////////
void enter()
{
    int vertex;
    cout<< endl <<" Enter number of vertex : \t";
    lable:
    cin>>vertex;
    if(vertex<=1)
    {
        system("cls");
        cout<<endl<<" The Number of vertexes must be more than 1 vertex !!"
        <<endl<<endl<<" \t\t\tPlease Enter Again \t";
        goto lable;
    }
    N=vertex;
    cout<<endl;
}

void TopTriangularGraph()
{
    system("cls");
     int i,j;
     MaxCounter=0;
     cout<<"\t\t\t Top Triangular Graph "<<endl<<endl;
    for(i=0 ;i<N;i++)
      for(j=0 ;j<N;j++)
    Matrix[i][j]=0;

    for(i=0 ;i<N;i++)
      for(j=0 ;j<N;j++)

        if(i==j)
        Matrix[i][j]=0;

     else if(i>j)
        Matrix[i][j]=Matrix[j][i];

      else
      {
        cout<<endl<<" Connection Among  "<<i+1<<"  And  "<<j+1<<"  (Enter 0 Or 1) : ";
        lable:
        cin>>Matrix[i][j];
        if(Matrix[i][j]==1)
            MaxCounter++;
        if(Matrix[i][j]<0 || Matrix[i][j]>1)
        {

        cout<<endl<<" Please Enter One Number Among  0  And  1 : ";
            goto lable;
        }

      }

}

int CreateConnection(int first_vertex, int seconde_vertex)
{
    int i,j;

        Matrix[first_vertex][seconde_vertex]=1;
        Matrix[seconde_vertex][first_vertex]=1;

    for(i=0 ;i<N;i++)
      { cout<<endl<<endl;
        for(j=0 ;j<N;j++)
        {
         cout<<"  "<<Matrix[i][j]<<"\t";
        }

      }
 cout<<endl<<endl;
  }

void GraphConnections()
{
  system("cls");
  int vertex1,vertex2,i,j;
  char select;
  cout<<"\t\t\t Connections "<<endl<<endl;
  MaxCounter=0;
  lable:
  cout<<" Enter A Connection (For Example 1 2):\t";
  cin>>vertex1>>vertex2;

  if(vertex1==vertex2)
  cout<<" A Vertex Can not Be Neighbor With Itself "<<endl;

  else if (vertex1<1 || vertex2<1 || vertex1>N || vertex2>N)
    cout<<" Invalid Connection"<<endl;

  else
  {
    CreateConnection(vertex1-1,vertex2-1);
  MaxCounter++;
  }
  getch();
  system("cls");
  cout<<" Is There Another Connection?"<<endl<<endl;
  lable1:
  cout<<" 1.Yes"<<endl<<endl<<" 2.No"<<endl<<endl;
  select=getch();
  if(select=='1' || select=='2')
  switch(select)
  {
  case '1':
      system("cls");
    goto lable;
    break;
  case '2':
      system("cls");
    //return;
  }
else
  {
      system("cls");
     cout<<" Please Select An Option From Options 1 And 2"<<endl<<endl;
     goto lable1;

  }


}

struct Color
{
  string colorName[1000];

}CName;

void colors(string ForCNameArray[])
{
    struct Color CName;
    system("cls");
    int NumberOfcolor,i;
    cout<<endl<<" Enter number of colors : ";
    cin>>NumberOfcolor;
    ColorNumber=NumberOfcolor;
    M=NumberOfcolor;
    cout<<endl<<endl;
    for( i=0;i<M;i++)
    {
        cout<<" What is Color "<<i+1<<" : ";
        cin>>CName.colorName[i];
        ForCNameArray[i]=CName.colorName[i];
        cout<<endl;
    }

   if(M==N || M>N)
    {
    cout<<"\t\t\t\tError !"<<endl<<endl<<endl<<" \t\tThere Is No Need For An Evolutionary Algorithm "<<endl<<endl
    <<"\t\t\t\t We Will have the answer"<<endl<<endl;
            exit(0);
    }

        return ;
}



void GrafInformation()
{
    system("cls");
    char option;
    lable:
    cout<<"\t\t\t Graph"<<endl<<endl;
    cout<< " Select An Option To Create A Graph :"<<endl<<endl;
    cout<<" 1.Top Triangular Graph "<<endl<<endl<<" 2.Graph Connections "<<endl;
    option=getch();
    if(option=='1' || option=='2')
    switch(option)
    {
    case '1':
       TopTriangularGraph();
       break;
    case '2':
        GraphConnections();


    }

else
{
    system("cls");
    goto lable;
}
}


string NumberToColorName(int Number)
{
    struct Color CName ;
  return ForCName[Number];
}

void InitialPopulation(int C)
{
    system("cls");
    int i,j;
    cout<<"\t\t\t Create Initial Population"<<endl;
    _N_ =C*N;
    srand(time(NULL));
    for(i=0;i<_N_;i++)
         for(j=0;j<N;j++)
       Rand[i][j]= rand()%M+1;
    system("cls");

 cout<<"\t\t\t\tInitial Population "<<endl;

        for(i=0;i<_N_;i++)
        {
            cout<<endl<<endl;
            for(j=0;j<N;j++)
                cout<<"  "<<Rand[i][j]<<"\t";

        }
          cout<<endl<<endl;

          cout<<" \t\t\t Press Any Key To Continue ...    ";
          //getch();
}


int ObjectiveFunction2(int i)
{
    int j,k,flag=0,Count=0,MinimumeColorList[1000];

         for(j=0;j<N;j++)
         {
            for(k=0;k<N;k++)
             if(MinimumeColorList[k]==Rand[i][j])
             flag=1;
             if(flag=0)
             {
                 MinimumeColorList[Count]==Rand[i][j];
                 Count++;
             }

         }

     return Count;
}


int CounterComputing( int i)
{
    system("cls");
    int j,k;
          for(j=0;j<N;j++)
         for(k=j+1;k<N;k++)
            if(Matrix[j][k]==1 && Rand[i][j]==Rand[i][k])
         Counter++;


        return Counter+ObjectiveFunction2(i);
}

void ObjectiveFunction(int Array[])
{
    int i;
    for(i=0;i<_N_;i++)
    {
        Array[i]=CounterComputing(i);
        Counter=0;
    }
   return;
}
 void PrintSecondRand();
 void PrintRand();
void Selection(int tournamentSize )
{
    int i,j,Min=MaxCounter+1,X[_N_];
    system("cls");
    cout<<" \t\t\t\t Selection "<<endl<<endl;
    int R[tournamentSize];
    srand(time(NULL));
    for(i=0;i<_N_;i++)
    {
        Min=MaxCounter+1;
       for(j=0;j<tournamentSize;j++)
     {
        R[j]=rand()%_N_+1;
        cout<<endl<<" Rand Number "<<j+1<< " : \t "<<R[j]<<endl;
        cout<<" Number Of Conflict For This Chromosome Is : \t "<<CounterArray[R[j]-1]<<endl;
        if(CounterArray[R[j]-1]<Min)
        {
        Min=CounterArray[R[j]-1];
        X[i]=R[j];
        }

     }
       cout<<endl<<" The Least Conflict : \t"<<Min<<endl<<endl;
       cout<<" Chromosome Selected : \t";
       for(int s=0;s<N;s++)
       {

           SecondRand[i][s]=Rand[X[i]-1][s];
         cout<<SecondRand[i][s]<<"  ";
       }

       cout<<endl;
    }
   // getch();
    system("cls");
    cout<<" \t\t\t Intermediate Population"<<endl<<endl;
    PrintSecondRand();
    //getch();
}


void Crossover()
{
    int i,j,Pt,temp;
    float Pc=0.8,PrRand,Pr;
    cout<<" \t\t\t\t Crossover "<<endl<<endl;
    srand(time(NULL));
    for(i=0;i<_N_-1;i=i+2)
    {
        PrRand=rand()%100;
        Pr=PrRand/100;
        cout<<" Rand Number Between 0 & 1 : \t"<<Pr<<endl<<endl;
        if(Pr<=Pc)
        {
        Pt=rand()%N+1;
        cout<<" Cut Point : \t"<<Pt<<endl<<endl;
        for(j=Pt;j<N;j++)
            {
               temp=SecondRand[i][j];
               SecondRand[i][j]=SecondRand[i+1][j];
               SecondRand[i+1][j]=temp;
            }
            cout<<endl;
        }


    }

cout<<endl<<" \t\t Intermediate Population After Crossover  "<<endl<<endl;
 PrintSecondRand();
 //getch();
}

 void Mutation()
 {
     system("cls");
     float Pm=0.1,PrRand,Pr;
     int i ,j,RandNum1,RandNum2;
    cout<<" \t\t\t\t Mutation "<<endl<<endl;
     srand(time(NULL));
    for(i=0;i<_N_;i++)
    {
        PrRand=rand()%100;
        Pr=PrRand/100;
        cout<<" Rand Number Between 0 & 1 Is : \t"<<Pr<<endl<<endl;
        if(Pr<=Pm)
        {
        RandNum1=rand()%N+1;
          cout<<" Be Changed Chromosome : \t"<<RandNum1<<endl<<endl;
          lable:
        RandNum2=rand()%M+1;
        if(RandNum2==SecondRand[i][RandNum1-1])
            goto lable;
            else
               SecondRand[i][RandNum1-1]= RandNum2;
        }


    }

cout<<endl<<" \t\t Intermediate Population After Mutation  "<<endl<<endl;
PrintSecondRand();
//getch();

 }


 void PrintRand()
 {
     int i,j;
            cout<<endl<<endl;
        for(i=0 ;i<_N_;i++)
            {
            for(j=0 ;j<N;j++)
                cout<<" "<<Rand[i][j]<<" \t";
                cout<<endl<<endl;
            }
            //getch();
 }

 void PrintSecondRand()
 {
     int i,j;
            cout<<endl<<endl;
        for(i=0 ;i<_N_;i++)
            {
            for(j=0 ;j<N;j++)
                cout<<" "<<SecondRand[i][j]<<" \t";
                cout<<endl<<endl;
            }
           // getch();
 }


 void Replacement()
 {
     system("cls");
     int i,j,k=0,s=0,minimum1=MaxCounter+1,minimum2=MaxCounter+1;
     cout<<"\t\t\t Initial population "<<endl;
     PrintRand();
     cout<<endl<<endl;
     //getch();
     cout<<"\t\t\t Intermediate population "<<endl;
     PrintSecondRand();
     cout<<endl<<endl;
     //getch();

    for(i=0 ;i<_N_;i++)
        for(j=0 ;j<N;j++)
    {
        TempArray[i][j]=Rand[i][j];
        Rand[i][j]=SecondRand[i][j];
    }

   for(i=0 ;i<_N_;i++)
    CounterArrayIntermediatePopulation[i]=0;

ObjectiveFunction(CounterArrayIntermediatePopulation);


    for(i=0 ;i<_N_;i++)
        for(j=0 ;j<N;j++)
    {
        SecondRand[i][j]=Rand[i][j];
        Rand[i][j]=TempArray[i][j];
    }

///////////////////////////////////////////////////////////
     cout<< endl<< " Conflict For Initial Population :\t";
     for(i=0 ;i<_N_;i++)
     {
          cout<<CounterArray[i]<<"  ";
          if(CounterArray[i]<minimum1)
          {
             minimum1=CounterArray[i];
             k=i;
          }
     }
cout<<endl<<endl;
//////////////////////////////////////////////////////
   cout<< endl<< " Conflict For Intermediate Population :\t";
    for(i=0 ;i<_N_;i++)
     {
          cout<<CounterArrayIntermediatePopulation[i]<<"  ";
          if(CounterArrayIntermediatePopulation[i]<minimum2)
          {
             minimum2=CounterArrayIntermediatePopulation[i];
             s=i;
          }
     }
     cout<<endl<<endl;
     ////////////////////////////////////////////////////////////
     cout<<endl<< " \t\t\t\t Later Replacement"<<endl<<endl;

         for(i=0 ;i<_N_;i++)
            if(CounterArrayIntermediatePopulation[i]<CounterArray[i])
                    for(j=0 ;j<N;j++)
                     Rand[i][j] =SecondRand[i][j] ;
                        cout<<endl<<endl;
     ///////////////////////////////////////////////////////////
     PrintRand();
     cout<<endl<<endl;
     //PrintSecondRand();
     cout<<endl<<endl;


      //getch();
 }

/////////////////////////////////////////////////////////////////////////

HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    int i,j,c,b=1,Generation,flag=0,TournamentSize,GlobalMinimume,f=0;
    char Selector;
    cout<<endl<<"\t\t  ///////////// Welcome //////////////"<<endl<<endl<<endl
    <<"\t\t     Press Any Key To Continue ... \t";
    getch();
    system("cls");
    enter();
    GrafInformation();
    system("cls");
    cout<<endl<<"\t\t\t\t Adjacent Matrix "<<endl<<endl;
    for(i=0 ;i<N;i++)
      { cout<<endl<<endl;
        for(j=0 ;j<N;j++)
        cout<<"  "<<Matrix[i][j]<<"\t";
      }
 cout<<endl<<endl<<endl<<"\t\t\t Press Any Key For Continue ...   ";
    getch();

    colors(ForCName);

        system("cls");
        cout<<endl<<" Enter The Number Of Generations For Graph Coloring : \t";
        cin>>Generation;
        cout<<endl<<" Enter C For Calculate The Population Size : \t";
        cin>>c;
        cout<<endl<<endl<<" \t\t\t\t Selection "<<endl<<endl;
        cout<<" Enter Number Of Tournament Size For Selection Action : \t";
    lable:
       cin>>TournamentSize;

       if(TournamentSize<=1 || TournamentSize>=c*N )
       {
          cout<<endl<<" Enter Again : \t";
          goto lable;
       }
        InitialPopulation(c);
            for(int m=0;m<Generation;m++)
            {
        ObjectiveFunction(CounterArray);
                Selection(TournamentSize);
                Crossover();
                Mutation();
                Replacement();


                }
                GlobalMinimume=MaxCounter+M;

        for(int s=0 ;s<_N_;s++)
               if(CounterArray[s]<GlobalMinimume)
             {
               GlobalMinimume=CounterArray[s];
               f=s;
             }
            system("cls");
              if(GlobalMinimume==0)
             {
                 cout<<" Answer Found Is :  "<<endl;
              for(int d=0 ;d<N;d++)
              {
                  SetConsoleTextAttribute(hConsole,7);
                  cout<<"\t\t\t\tVertex"<<d+1<<":";
                         SetConsoleTextAttribute(hConsole,Rand[f][d]+10);
                   cout<<" Color"<<Rand[f][d] <<endl<<endl;

              }
             }

             else
                cout<<" Answer Not Fond !!"<<endl;



            cout<<endl<<endl;

      getch();


        for(i=0 ;i<N;i++)
           for(j=0 ;j<N;j++)

            Matrix[i][j]=0;



    return 0;
}
