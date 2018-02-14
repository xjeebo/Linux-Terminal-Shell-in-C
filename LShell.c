//Jeeno Doria
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <termios.h>

int getch(void);
int main(){

  /* variables */
  int i,y=0, j,x=0,z=0, historytrig=0,pid,pid2, status, quit = 0, Ntokens=0, pipetrig=0,cnt=0, maxcnt=0, historyrow=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0;            /* pid: process id for fork, status for waitpid */
  int fd[2];
  char *token, *command[256], *command2[256], *xx;      /* Array of pointers for arguments for the tail command */
  char *smalltoken[2], str1[256], merge[256];
  char *buffer = (char *)calloc(256, sizeof(char));
  char *buf = (char*) malloc(100);
  char *str = (char *)calloc(256, sizeof(char));
 
  char *cmdh1 = (char *)calloc(256, sizeof(char));
  char *cmdh2 = (char *)calloc(256, sizeof(char));
  char *cmdh3 = (char *)calloc(256, sizeof(char));
  char *cmdh4 = (char *)calloc(256, sizeof(char));
  char *cmdh5 = (char *)calloc(256, sizeof(char));


  char *mergedfile = (char*) calloc(256, sizeof(char));
  char *trackcommand1 = (char *)calloc(256, sizeof(char)); 
  char *trackcommand2 = (char *)calloc(256, sizeof(char));
  char *trackcommand3 = (char *)calloc(256, sizeof(char));
  char *trackcommand4 = (char *)calloc(256, sizeof(char));
  char *trackcommand5 = (char *)calloc(256, sizeof(char));
  char getcha, currentcha;
  system("clear");             // clear the terminal


for(i=0;i<256;i++){
    str1[i] = '\0';
    merge[i] = '\0';
    }

while(quit!=1){


    getcwd(buf,100);
    printf("%s>", buf); 
    getcha = getch(); // attain the first byte sequence


while(getcha!= '\n'){ // until user hits enter

  if(getcha == 8 || getcha == 126 || getcha == 127){// backspace/delete byte

  if(cnt>0 || cnt<maxcnt){
      printf("\b");
      printf(" ");
      printf("\b");

  for(i = cnt-1; i<maxcnt; i++) // remove the character from the buffer and swap characters with the element ahead
      buffer[i] = buffer[i+1];

      maxcnt--;
      buffer[maxcnt] = ' ';
      cnt--;
      }
}
else if(getcha == 27){      // if the first byte sequence is 27
     getcha = getch(); // second byte sequence (91)
     getcha = getch(); // attain the 3rd sequence for directional keys
/////////////
switch(getcha){
  case 65: 

    if(historyrow>0 )  //command history is cycled through a count called history row. it decrements when user pushes up and increments when down is pushed  
    historyrow--;
    switch(historyrow){ // commands are saved as a strong concatonated in cmd5-1
    case 0: printf("\r%s>", buf);  printf("%s ", cmdh1); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh1);getcha='n';maxcnt=cnt1;cnt=maxcnt;break;
    case 1: printf("\r%s>", buf);  printf("%s ", cmdh2); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh2);getcha='n';maxcnt=cnt2;cnt=maxcnt;break;
    case 2: printf("\r%s>", buf);  printf("%s ", cmdh3); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh3);getcha='n';maxcnt=cnt3;cnt=maxcnt;break;
    case 3: printf("\r%s>", buf);  printf("%s ", cmdh4); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh4);getcha='n';maxcnt=cnt4;cnt=maxcnt;break;
    case 4: printf("\r%s>", buf);  printf("%s ", cmdh5); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh5);getcha='n';maxcnt=cnt5;cnt=maxcnt;break;
    }   
    break; 

    
  case 66: 
    if(historyrow<4)
    historyrow++;  
    switch(historyrow){
    case 0: printf("\r%s>", buf);  printf("%s ", cmdh1); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh1);maxcnt=cnt1;cnt=maxcnt;break;
    case 1: printf("\r%s>", buf);  printf("%s ", cmdh2); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh2);maxcnt=cnt2;cnt=maxcnt;break;
    case 2: printf("\r%s>", buf);  printf("%s ", cmdh3); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh3);maxcnt=cnt3;cnt=maxcnt;break;
    case 3: printf("\r%s>", buf);  printf("%s ", cmdh4); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh4);maxcnt=cnt4;cnt=maxcnt;break;
    case 4: printf("\r%s>", buf);  printf("%s ", cmdh5); printf("                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); strcpy(buffer,cmdh5);maxcnt=cnt5;cnt=maxcnt;break;
    } // down arrow
  case 67: if(cnt<maxcnt){currentcha = buffer[cnt]; printf("%c", currentcha); cnt++;} break; // right arrow
  case 68: if(cnt>0){cnt--;printf("\b");} break; // left arrow
}
/////////////
  }
else{
  printf("%c", getcha);
  buffer[cnt] = getcha;
  cnt++; maxcnt = cnt;
}

getcha = getch();//within while outside ifs

}//endwhile
//_______________________________________________________________

printf("\n");
  

for(i=0; i<256; i++){        // To check whether there are multiple commands by looking for a '|' 
	if(buffer[i] == '|')        //
		pipetrig = 1;		   // if there is a '|' found in the buffer 
}


//Using the buffer to gather tokens that will be placed into command array

//-------------------------------------------------------------------------------
if(pipetrig == 0){               // single commands if pipetrig == 0
 token = strtok(buffer," \n");   // tokenize all items before " \n"
 command[0] = token;            // the  
 Ntokens++;                    //    
                             //
while(token!=NULL){         // keep tokenizing items in the buffer to add them into the command array which gets executed later on until a NULL is found
 token = strtok(NULL," \n");
 command[Ntokens] = token; 
 Ntokens++;
  }
 command[Ntokens] = NULL;      // must always end with a NULL
 j = Ntokens;
 Ntokens = 0;                 // reset the count 
}


//-------------------------------------------------------------------------------
if(pipetrig == 1){
 smalltoken[0] = strtok(buffer,"|");       // get first command token
 smalltoken[1] = strtok(NULL,"|");        //  get second command token
                                        // the first commands output will be the input for the second command
 Ntokens = 0;                           //
 token = strtok(smalltoken[0]," \n");  // grab items from the first long token
 command[0] = token;                  // initialize the first command for the first array of commands
while(command[Ntokens] != NULL){    // tokenize them until we reach null
	Ntokens++;
	command[Ntokens] = strtok(NULL, " \n"); // insert to the command array

}

 command[Ntokens] = NULL;

//--------------------------------------Second section in acquiring pipe commands

 Ntokens = 0;                            // reset the token count
 token = strtok(smalltoken[1]," \n");   // grab items from the second long token
 command2[0] = token;                  //
                                     //
while(command2[Ntokens] != NULL){   // grab tokens that will be inserted to the command array

	Ntokens++;
	command2[Ntokens] = strtok(NULL, " \n");
  }
 command2[Ntokens] = NULL;       // end with null

}


 if(buffer[0] == 'm' && buffer[1]== 'e' && buffer[2] == 'r' && buffer[3] == 'g' && buffer[4] == 'e' ){
   strcpy(mergedfile, "cat ");        //merge command..concatonates the commands all into one string then executes it
   strcat(mergedfile, command[1]);
   strcat(mergedfile," "); 
   strcat(mergedfile, command[2]);
   strcat(mergedfile," ");
   strcat(mergedfile, command[3]);
   strcat(mergedfile, command[4]);
   system(mergedfile);
   free(mergedfile);
   free(buf);
   getcha = 'n';
   }



 if(y<6)    // up to five previous commands are saved into cmdh1-5 any more than that rearranges them. 
   y++;

   switch(historyrow){
   case 0: memset(cmdh1, 0 ,sizeof(cmdh1));for(i = 0; i<j-1; i++){strcat(cmdh1,command[i]);if(i<j-2)strcat(cmdh1," ");} j=0; historyrow++; cnt1=maxcnt; break;
   case 1: memset(cmdh2, 0 ,sizeof(cmdh2));for(i = 0; i<j-1; i++){strcat(cmdh2,command[i]);if(i<j-2)strcat(cmdh2," ");} j=0; historyrow++; cnt2=maxcnt; break;
   case 2: memset(cmdh3, 0 ,sizeof(cmdh3));for(i = 0; i<j-1; i++){strcat(cmdh3,command[i]);if(i<j-2)strcat(cmdh3," ");} j=0; historyrow++; cnt3=maxcnt; break;
   case 3: memset(cmdh4, 0 ,sizeof(cmdh4));for(i = 0; i<j-1; i++){strcat(cmdh4,command[i]);if(i<j-2)strcat(cmdh4," ");} j=0; historyrow++; cnt4=maxcnt; break;
   case 4: memset(cmdh5, 0 ,sizeof(cmdh5));for(i = 0; i<j-1; i++){strcat(cmdh5,command[i]);if(i<j-2)strcat(cmdh5," ");} j=0; historyrow++; cnt5=maxcnt; break;
   case 5:
     strcpy(cmdh1,cmdh2); cnt1=cnt2;
     strcpy(cmdh2,cmdh3); cnt2=cnt3;
     strcpy(cmdh3,cmdh4); cnt3=cnt4;
     strcpy(cmdh4,cmdh5); cnt4=cnt5;
     memset(cmdh5, 0 ,sizeof(256));
     for(i = 0; i<j-1; i++){strcat(cmdh5,command[i]);if(i<j-2)strcat(cmdh5," ");} j=0; cnt5=maxcnt;  
     break;
   }

  

   //if user enters pause



if(buffer[0] == 'p' && buffer[1]== 'a' && buffer[2] == 'u' && buffer[3] == 's' && buffer[4] == 'e' ){
   printf("\nSystem paused, hit enter to resume: "); 
   getcha = getch();
   while(getcha != '\n')  
     getcha = getch();
   printf("\n");
   getcha = 'n';
   }
// if user enters quit. 

if(buffer[0] == 'q' && buffer[1]== 'u' && buffer[2] == 'i' && buffer[3] == 't' ){
   printf("Quit?[y/n]: ");
   getcha = getch();
   if(getcha=='y')
   quit = 1;  
   else if (getcha=='n')
   printf("Quit Cancelled\n");
 else{
   printf("Invalid input\n");
   getcha = 'n';
 }
 }


// if user changes directories

if(buffer[0] == 'c' && buffer[1] == 'd'){
   i = 3; j = 1;
   str[0] = '/';
while(i != 256){
   str1[j] = buffer[i];
   i++; j++;
   }       
    
   i = 1; j = 1;
while(str1[i]!='\0'){
   str[j] = str1[i];
   i++;j++;
   }

   strcat(buf,str);

   chdir(buf);
if(chdir(buf)<0)
   perror(NULL);
   getcha = 'n';
   }



if(getcha!='n'){
  pid = fork(); /* 0 passed to child, child'd pid passed to parent */ //FORK() will create a child and parent process, which means two process of the same program will run in parallel



if (pid > 0){//------------------------------------//*Parent process*//------------------------------------------------------------------------------------
  
  waitpid(pid, &status, WUNTRACED);        // wuntraced is used to make the parent process wait for the child process to end
 
  if(pipetrig==1){quit=0;
    pipetrig=0; quit=0;
    x= 0;    
  }



 }

 else if(pid == 0){//-----------------------------//*child process*//------------------------------------------------------------------------------------
  

 if(pipetrig == 0 && quit!=1){                // if it is not a piped command the child process will execute the commands, but if there are multiple commands the child will process the commands first followed by the parent process

  execvp(command[0], command); //
  perror(NULL);               //check for commands that do not exist
  exit(0);
  quit = 0;
 }
 else if(quit==1){
  printf("Program Terminated\n");
  exit(0); 
  }

  else if(pipetrig == 1 && quit !=1){

    pipe(fd);
    pid2 = fork();                                //the main parent will wait while the new parent childs run until it terminates to keep the program running 

    if(pid2>0){
      waitpid(pid2, &status, WUNTRACED);
      close(0);
      dup(fd[0]);
      close(fd[1]);

      if(execvp(command2[0], command2)<0)
	  perror(NULL); 
      pipetrig=0;
      exit(0);
    }
    else if(pid2 == 0){

      close(1);
      dup(fd[1]);
      close(fd[0]);
      if( execvp(command[0], command)<0)// execute first command
      perror(NULL); 
      exit(0);


    }

  quit=0;
  }
 }//---------------------------------------------//*child process*//------------------------------------------------------------------------------------
 


 else           /* Error with fork process */
  printf("Error encountered.\n");
 
  }
  getcha = ' ';
  memset(buffer, 0 ,256); 
  cnt = 0; maxcnt = 0;
  memset(buf, 0 , sizeof(buf));
  memset(str, 0 , sizeof(str));
  memset(command, 0 , sizeof(command));
  memset(command2, 0 , sizeof(command2));
  pipetrig=0;
  Ntokens=0;
  }

  return 0;
  }



int getch(void){
int chr;
struct termios original;
struct termios temp;
tcgetattr(STDIN_FILENO, &original);               // store current settings 
temp = original;                                 // copy the current settings to the new one
temp.c_lflag &= ~(ICANON | ECHO);                // local mode...disable echo...non-canonical mode: input is made without hitting enter 
tcsetattr(STDIN_FILENO, TCSANOW, &temp);       // set the parameters from above..TCSANOW to immediately change the params
chr = getchar();                                // acquire the character input immediately
tcsetattr(STDIN_FILENO, TCSANOW, &original); // bring the original settings back
return chr;                                   // return the character input 
}                                          // stdin_fileno is a file descriptor refers to STDIN
