/*
*@Author: Ashutosh Mishra
*@Title: WLAN HOTSPOT MANAGER
*@Project STARTED: 02/03/2015
*@Date Completed: 06/03/2015
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

using namespace std;
  //Global Variables.
  char *msg, *cmd, ch_rewrite, flag='Y';
  int status;
  FILE *fp;
  string SSID, KEY="12345678";

//TEMPLATES
void errorSound() /* Beep a sound when error occur. */{
    _beep(1300,60);
    _beep(600,70);
    _beep(1300,60);
}

int errorMsg(int code, char *msg){

    {system("color 4"); /*Red Color Code 4*/}

    char *str="";
    int loop=0,asc_val=220,asc_val2=219;
    cout << "\n\n\n\n\t";
    for(loop=0;loop<=20;loop++){ cout << char (asc_val);  } cout <<char(asc_val)<< endl << "\t";
    cout << char(asc_val2) <<" OPERATION FEEDBACK  " << char(31) <<char(30); cout << endl << "\t";
    for(loop=0;loop<=50;loop++){ cout << char (asc_val2);  } cout << endl << "\t";

    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" CODE: %-42d",code);  cout << char (asc_val2) << "\n\t"; str="____________________";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",msg);  cout << char (asc_val2) << "\n\t"; str="_________________________________";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="            PRESS ANY KEY TO LEAVE ...";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";

    for(loop=0;loop<=50;loop++){ cout << char (asc_val2);  } cout << endl << "\t";
    errorSound();
    //getch();
    return 0;
    return 0;
}

int upperFrame(char *title){
    //Designing Top Border
        system("cls");
        for(int i=0;i<80;i++){ cout << char(220); }
        //for menu //30chars
        for(int i=0;i<52;i++){
                if(i==0 || i==51){cout << char(219);}
                else if(i==24){ printf("%29s", title);}
                else{cout << char(177);}
        }
        //for menu underline design.
        for(int i=0;i<80;i++){if(i==0 || i==79){cout << char(219);} else cout << char(223);  }
 return 0;
}

int lowerFrame(){
     //Designing Bottom Border
        cout <<endl;
        for(int i=0;i<80;i++){if(i==0 || i==79){cout << char(219);}else cout << char(220); }
 return 0;
}

int menuDesign(char option, char *str){
    int loop;
    cout <<"\t\t\t";
    cout <<"\t"<< char(218);    for(loop=1;loop<=24;loop++){cout <<char(196) ;}  cout << char(191)<< endl;
    cout <<"\t\t\t";
    cout <<char(219)<<" "<< option << " "; for(loop=1;loop<=4;loop++){cout <<char(196) ;} cout <<char(221); printf("%-24s",str); cout<<char(180)<<endl;
    cout <<"\t\t\t";
    cout <<"\t"<< char(192);    for(loop=1;loop<=24;loop++){cout <<char(196) ;}  cout << char(217)<< endl ;
    return 0;
}

int menu_toAbout(void){

     //upper frame.
       upperFrame("WLAN HOTSPOT MGR [About] ");
     //About.
        cout <<"\n\t\t\t.----------------------------.";
        cout <<"\n\t\t\t| Author   : Ashutosh Mishra |";
        cout <<"\n\t\t\t| Devoloped: 03/03/2014      |";
        cout <<"\n\t\t\t| Version  : v1.00           |";
        cout <<"\n\t\t\t| CodeBlock CPP Plateform.   |";
        cout <<"\n\t\t\t'----------------------------'\n";
     //lower frame.
     lowerFrame();
     //end
     cout << "PRESS ANY KEY...";
     getch();
     return 0;
}//End o function.

int splash(void){
            char choice;
            system("CLS");
            system("TITLE WLAN HOTSPOT MANAGER");

            fp=fopen("log.txt","r");
            if(fp!=NULL){cout<<"Log Found.";}
            else{ fp=fopen("log.txt","w"); if(fp!=NULL){cout<<"Log Created.";} else{cout<<"Log could not Created.";} }

                //system("cls");
                msg="[ WLAN HOTSPOT MANAGER ] ";
            //Splash with confirmation
                printf("\n\n\n\n\n\t");
                for(int i=0;i<60;i++){if(i==0 || i==59){cout << char(219);}else cout << char(223); }
                printf("\n\n\t\t\t   %s\n\t", msg);
                cout << "\n\t\t THIS PROGRAM MUST BE RUN AS ADMINISTRATOR.";
                printf("\n\n\t\t\t   (P)ROCEED    (E)XIT \n\n\t");
                for(int i=0;i<60;i++){if(i==0 || i==59){cout << char(219);}else cout << char(220); } //for line.
                cout<< "\n\t\t\t::> ";
                choice=getche();

                //debugging
                    cout<<"::=";
            //Validating.

                    if(choice=='p' || choice=='P'){/*do next*/ return 0; }
                    else if(choice=='e' || choice=='E'){ exit(0);}
                    else{ errorSound(); splash();}


    return 0;
}

int menu_toHelp(){
    //upper frame.
      upperFrame("WLAN HOTSPOT [HELP]  ");
    //MIDDLE
      cout<<" \n\t 1-ALWAYS RUN THIS PROGRAM WITH ADMINISTRATOR PRIVILEGE. ";
      cout<<" \n\t 2-YOUR PASSWORD SHOULD BE 8 TO 63 LONG. ";
      cout<<" \n\t 3-FOLLOW ALL INSTRUCTION TO AVOID ERRORS.\n\n";
      cout<<" \n\t\t\t\t PRESS ANY KEY...";
    //LOWER
      lowerFrame();
      getch();
return 0;
}

int method_WriteLog(char *msg){
 fp=fopen("log.txt","a+");
 if(fp!=NULL){
    fprintf(fp,"%s\n",msg);
    fclose(fp);
 }
 else{
    errorMsg(10,"Unable to write log. Can't access file.");
 }
 return 0;
}


int menu_toLog(){
    char c;
    method_WriteLog("Accessing log file.\n");
    //upper frame.
       upperFrame("WLAN HOTSPOT [LOG]  ");
    //middle.
       fp=fopen("log.txt","r");
       if(fp!=NULL){
           c=getc(fp);
           while(c!=EOF){
               printf("%c",c);
               c=getc(fp);
           }
           fclose(fp);
       }
       else{
           cout <<"\nUnable to access the file, Can't not read the log.";
       }
       cout <<"\n";
    //lower frame.
       lowerFrame();
       getch();
return 0;
}

/*methods start*/
int WriteLog(char *msg){
 fp=fopen("log.txt","a+");
 if(fp!=NULL){
    fprintf(fp,"Executing Command: %s\n",msg);
    fclose(fp);
 }
 else{
    errorMsg(10,"Unable to write log. Can't access file.");
 }
 return 0;
}

int method_Input(void){
     system("CLS");
    //upper frame
       upperFrame("WLAN HOTSPOT [INPUT]  ");
    //MIDDLE PART.
       cout<<"\n\t Wanna Exit? Type: 'EXIT' for the SSID input value.\n";
       cout<<"\n\t\t ENTER HOTSPOT NAME <No Space>[SSID] :";
       cin>>SSID;
       //checking SSID value for command for cancel creation of new hotspot.
            if(SSID.length()==4){
                if(SSID[0]=='E' && SSID[1]=='X' && SSID[2]=='I' && SSID[3]=='T'){
                    cout<< "\n\n You have given a command to exit from here. Exiting...\n";
                    flag='N';
                    return 0;
                }
            }
       cout<<"\n\t\t ENTER PASSWORD <No Space>[KEY] :";
       cin>>KEY;

       //Checking key length of WiFi Hot spot
        if((KEY.length())>=1 && (KEY.length())<=7){
            method_WriteLog("Key length is less than 8. UnSuccessful\n");
            errorMsg(8,"KEY LENGTH SHOULD BE 8 TO 63 LONG.");
            getch();
            method_Input();
        }
    //LOWER FRAME.
       lowerFrame();


    return 0;
}

int method_Create(){

    method_Input();
    system("cls");

    //upper frame
                upperFrame("WLAN HOTSPOT [NEW HOTSPOT] ");

    //MIDDLE PART.
    //if in input there is no any command to stop this operation.
        if(flag!='N'){
            string COMMD="NETSH WLAN SET HOSTEDNETWORK MODE=ALLOW SSID=";
                COMMD+=SSID;
                COMMD+=" KEY=";
                COMMD+=KEY;

            char commd[90];

            for(int i=0;i<COMMD.length();i++){
                    commd[i]=COMMD.at(i);
            }

            cout <<"\n\n";
            if((status=system(commd))!=0){
                    cout << "\n\t\t Privilege Problem, You Should Run the program as Administrator..";
                    method_WriteLog("Key length is less than 8. UnSuccessful\n");
                    WriteLog(commd);

            }
            else{
                    method_WriteLog("New Hotspot created. Successful.");
            }
        }
        // If user don't want create hotspot.
        else{
            cout << "\n\t\t\t User Exited from there using a command.\n";
        }
    //LOWER FRAME.
    lowerFrame();
    cout <<"Press Any Key...";
    getch();
return 0;
}

int method_Start(){
    //upper frame
       upperFrame("INPUT [START HOTSPOT]  ");
       cmd="NETSH WLAN START HOSTEDNETWORK";
    //MIDDLE PART.
       cout <<"\n\n";
       if((status=system(cmd))!=0){
            cout << "\n\t\t Privilege Problem, You Should Run the program as Administrator..";
            method_WriteLog("Hotspot Start, Privilege Problem.");
       }
       else{
            method_WriteLog("Hotspot Started, Successful.");
       }

    //LOWER FRAME.
       lowerFrame();
       getch();
return 0;
}

int method_Stop(){
    //upper frame
       upperFrame("INPUT [START HOTSPOT]  ");
       cmd="NETSH WLAN STOP HOSTEDNETWORK";
    //MIDDLE PART.
       cout <<"\n\n";
       if((status=system(cmd))!=0){
            cout << "\n\t\t Privilege Problem, You Should Run the program as Administrator..";
            method_WriteLog("Hotspot Stop, Privilege Problem.");
       }
       else{
            method_WriteLog("Hotspot Stopped. Successful.");
       }

    //LOWER FRAME.
       lowerFrame();
       getch();
return 0;
}

int method_View(){
    //upper frame
       upperFrame("INPUT [START HOTSPOT]  ");
       cmd="NETSH WLAN SHOW HOSTEDNETWORK";
    //MIDDLE PART.
       cout <<"\n\n";
       if((status=system(cmd))!=0){
            cout << "\n\t\t Privilege Problem, You Should Run the program as Administrator..";
            method_WriteLog("HotSpot Status Inquiry. Privilege Problem.");
       }
       else{
            method_WriteLog("Status Inquiry. Successful.");
       }
    //LOWER FRAME.
       lowerFrame();
       getch();
return 0;
}

/*methos ends.*/

int menu_toOption(void){

    char choice;
         //upper frame;
           upperFrame("WLAN HOTSPOT MANAGER [OPTION]");
           menuDesign('H',"HELP");
           menuDesign('A',"ABOUT");
           menuDesign('L',"LOG FILES");
         //LOWER FRAME
           lowerFrame();
         //input.
            choice=getch();
            switch(choice){
                       case 'h':
                       case 'H': menu_toHelp(); break;
                       case 'a':
                       case 'A': menu_toAbout(); break;
                       case 'l':
                       case 'L': menu_toLog(); break;
                       default: errorSound();

            }
return 0;
}

int menu_toMain(void){
           system("cls");
           system("COLOR 7");
         //upper frame;
           upperFrame("WLAN HOTSPOT MANAGER  ");
         //MIDDLE PART;
           menuDesign('C',"CREATE NEW HOTSPOT");
           menuDesign('S',"START HOTSPOT");
           menuDesign('T',"STOP  HOTSPOT");
           menuDesign('V',"VIEW STATUS");
           menuDesign('O',"OPTION");
           menuDesign('Q',"QUIT");
         //LOWER FRAME
           lowerFrame();

return 0;
}

int start()
{
    char choice;
    //cout << "Hello world!" << endl;
    splash();
          while(choice!='q' || choice!='Q'){
             menu_toMain();
             choice=getch();
             switch(choice){
                   case 'C':
                   case 'c': method_Create(); break;
                   case 'S':
                   case 's': method_Start(); break;
                   case 'T':
                   case 't': method_Stop(); break;
                   case 'V':
                   case 'v': method_View(); break;

                   case 'O':
                   case 'o': menu_toOption(); break;
                   case 'Q':
                   case 'q':    cout<<"\n\n\t\t Exiting...\n";
                                method_WriteLog("Exiting. Successful.");
                                cout<< "\n\t\t Log Written successfully.\n";
                                _beep(800,2000);
                                exit(0);

                   default: errorSound();

             }
          }

    return 0;
}

int main(){
        //splash(); /*Extra function call.*/
        start();
 return 0;
}
