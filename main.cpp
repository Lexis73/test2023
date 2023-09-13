

#include "TXLib.h"
#include "fstream"
using namespace std;
string getTag(string htmlTag, string name)
{

    char nChar='>';
    char endChar='<';
    char endChar2='/';
    int n=2;

    if (name=="tag")
    {
        nChar='<';
        endChar='>';
        endChar2=' ';
        n=1;
    }

    if (name=="src")
    {
    int i=0;
    int nom=-1;
    while (htmlTag[i])
     {
     if (htmlTag[i]=='s'&&
           htmlTag[i+1]=='r'&&
            htmlTag[i+2]=='c')
            nom=i+5;
     i++;

     }
     if (nom>-1)
     {
         string src="";
         while (htmlTag[nom]!='"'&&htmlTag[nom])
            {
                src=src+htmlTag[nom];
            }
         return src;
     }

    }

    int i=0;
    int nBegin;
    int nEnd;
     return htmlTag;
    while (htmlTag[i]!=nChar) i++;
    nBegin=i+1;

    i=0;
    while (htmlTag[i]!=endChar&&htmlTag[i+1]!=endChar2)
    i++;

    nEnd=i-n;
   // cout<<nBegin<< " "<<nEnd;

    string newTag="";

    for (int i=nBegin; i<=nEnd;i++)
    newTag=newTag+htmlTag[i];

    return newTag;

}




int main()
    {

   

// íàñòðîéêè
    txCreateWindow (1300, 750);
    int inputLine=1;
    string http="";
 ifstream f1;
// îñíîâíîé öèêë ïðîãðàììû

    while (1)
    {

    txSetFillColor(TX_WHITE);
     txSetColor(TX_BLACK);
     txClear();
     txSetColor(TX_GRAY,2);
     txRectangle(25,5,1255,45);
     txSetColor(TX_GRAY,8);
     txLine(0,56,1300,56);
     txSetColor(TX_BLACK,1);





     if(txMouseButtons()==2)
     {
     http="";

      char c;


      while (!txGetAsyncKeyState(VK_RETURN))
      {
       c = getch() ;
       int n;
       n=c;
       //cout<<n;
       //--- óäàëåíèå ñèìâîëà
       if (n==8&&http!="") http.erase(http.end()-1);
       else  http=http+c;
       txSetFillColor(TX_WHITE);
       txRectangle(25,5,1255,45);

       txTextOut(30,8,http.c_str());

       }
       }







     //cout<<http;
     //txBegin();
     txTextOut(30,8,http.c_str());


     int x=0,y=100;



     // ïîäêëþ÷åíèå ôàéëà

     string fileName="index.html";

     if (http!="") fileName=http;

     f1.open(fileName) ;
     string htmlTag;

  //-------   ÷òåíèå èç ôàéëà
   while (f1.good())  // èçìåíèòü while (
   {
   f1>>htmlTag;
   cout<<"=="<<htmlTag;
   int a;

      int step;
      string newTag=getTag(htmlTag,"tag");


      if (newTag=="h1")
      {
          string tagSourse=getTag(htmlTag,"s");
          txSelectFont("Arial",26);
          step=26;
          txTextOut(x,y,tagSourse.c_str());
      }

      if (newTag=="h2")
      {
          string tagSourse=getTag(htmlTag,"s");
          txSelectFont("Arial",18);
          step=18;
          txTextOut(x,y,tagSourse.c_str());
      }

      /*if (newTag=="img")
      {
                string tagCoupse = getTag(htmlTag, "s");
                HDC getImage;
                int x1=100, y1=100;

                getImage = txLoadImage(tagCoupse.c_str());
                txBitBlt(txDC(),x,y,x1,y1,getImage);




       }
       */

 cin>>a;
 if (a==1)
 {

f1.seekg (0,ios::beg);
}
    y=y+step;
    }



   // txEnd();


 f1.close();
    }

    return 0;
}

