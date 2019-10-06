#include <stdio.h> 
int main()
{ //Initialize most outer loop that brings the program to the main menu.
		int oooloop,rtrn,rptt1=1,rptt2=9; // Initialize variables.
		for (oooloop=0; oooloop<1; oooloop++){  // Initialize loop that will bring program back to main menu if wrong input is entered.
			int ooloop,mm;      
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // Creating User Interface.
			printf("***MAIN MENU***\n\nSingle Player: 1\n\nMultiplayer: 2\n\nHow to play: 3\n\nQuit: 4");
			printf("\n\n\n\n\n\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("\tX\t:\tO\t:\tX\t\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("    -----------------------------------------\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("\tO\t:\tX\t:\tO\t\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("    -----------------------------------------\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("\tX\t:\tO\t:\tX\t\n");
			printf("\t\t:\t\t:\t\t\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Enter your choice: ");
			scanf("%d",&mm);		// Taking input of main menu.
			const int cnst=mm;
			if (mm<1 || mm>4){		// Check if there is any wrong input.
				printf("Wrong input.\n");
				oooloop--;		// Go back to main menu.
				continue;
			}
			if (mm==4){break;}		// Exit Game.
			
			
			// Initializing Game.
			if (mm==2 || mm==1){		// Checks the MAIN MENU option selected by the user and runs Single or Multiplayer game.	
				for (ooloop=0; ooloop<1; ooloop++){
					char chr,ui,uc,X,arry[3][3]={{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}}; 
					// "arry" is a 2-dimentional array which will bear my original "TIC-TAC-TOE ALGORITHM".
					int ctod,loop;
					printf("Select your character (O/X): ");
					scanf("%s",&uc);		// Taking input to select user's character in the game.
					ctod=uc;		
					if (ctod!=120 && ctod!=88 && ctod!=111 && ctod!=79){ //check for wrong input of character.
						printf("Wrong Input.\nYou are given 'X' by default.\n");
						uc='X';		// If user enters wrong input 'X' will be given by default.
						X='O';
					}
					else if (ctod==120 || ctod==88){		// Assigning characters.
						X='O';
						uc='X';
					}
					else {
						X='X';
						uc='O';
					}
					//Characters has been assigned.
					
					
					for (loop=rptt1; loop<=rptt2; loop++){		// This loop is iterating the whole structure.
						int stop=0;		// Check Variable to exit game when array is filled.
						if (loop%2==0 && cnst==2){		// Player 2 turn if Multiplayer game is running.
							chr=X;		// "chr" is the variable which will be printed in game. It will have corresponding characters according to 1st player, 2nd player or computer's turn.
							printf("Player 2 turn: ");
							scanf("%d",&ui);		// Takes input at which point Player 2 has to mark.
						}
						
											
						else if (loop%2==0 && cnst==1){		// Assigning Computer's character to "chr" when singe player game is running.
							chr=X;
							printf("Computer: This is from my side...\n");
							
							// Games's Algorithm starts here.
							int lp;		
							for (lp=1; lp<=2; lp++){
								if (stop>0){break;}
								int ii,jj,k,rslt=9,rslt2=9,rslt3=9,rslt4=3,r2,r3,r4;
								char chkk;
								if (lp==1){chkk=X;}
								if(lp==2){chkk=uc;}
								if (stop>0){break;}
								for (ii=2; ii>=0; ii--){
									if (stop>0){break;}
									r2=2;
									k=0;
									for (jj=0; jj<2; jj++){
										
										if (arry[ii][jj]==arry[ii][k+1] && arry[ii][k+1]==chkk){
											if (arry[ii][r2]=='\0'){
												ui = rslt;
												stop++;
												break;
											}
										}
										if (arry[jj][ii]==arry[k+1][ii] && arry[k+1][ii]==chkk){
											if(arry[r2][ii]=='\0'){
												ui = rslt2;
												stop++;
												break;
											}
										}
										if (ii==2){
											if (arry[jj][jj]==arry[k+1][k+1] && arry[k+1][k+1]==chkk){
												if(arry[r2][r2]=='\0'){
													ui = rslt3;
													stop++;
													break;
												}
											}
										}
										if (k==0){
											jj--;
											k++;
										}
										r2--;
										rslt--;
										rslt2-=3;
										rslt3-=4;
									}	
									rslt2+=8;
								}
								if (arry[2][0]==arry[1][1] && arry[1][1]==chkk){
									if (arry[0][2]=='\0'){stop++; ui = 3;}
								}
								if (arry[2][0]==arry[0][2] && arry[0][2]==chkk){
									if (arry[1][1]=='\0'){stop++; ui = 5;}
								}
								if (arry[0][2]==arry[1][1] && arry[1][1]==chkk){
									if (arry[2][0]=='\0'){stop++; ui = 7;}
								}
							}
							
							
							
							if (stop==0){
								int lp;
								for (lp=1; lp<=4; lp++){
									if (stop>0){break;}
									int ii,jj,k,rslt=9,rslt2=9,rslt3=9,rslt4=3,r2,r3,r4;
									char chkk,chkkk;
									if (lp==1){chkk=X;chkkk='\0';}
									if(lp==2){chkk='\0';chkkk=X;}
									if(lp==3){chkk=uc;chkkk=X;}
									if(lp==4){chkk=X;chkkk=uc;}
									if (stop>0){break;}
									for (ii=2; ii>=0; ii--){
										if (stop>0){break;}
										r2=2;
										k=0;
										for (jj=0; jj<2; jj++){
											if (arry[ii][jj]==chkk && arry[ii][k+1]==chkkk){
												if (arry[ii][r2]=='\0'){
													if (lp==1){ui=((ii*3)+k+2);}
													else{ui = rslt;}
													stop++;
													break;
												}
											}
											if (arry[jj][ii]==chkk && arry[k+1][ii]==chkkk){
												if(arry[r2][ii]=='\0'){
													if (lp==1){ui=(((k+1)*3)+ii+1);}
													else{ui = rslt2;}
													stop++;
													break;
												}
											}
											if (ii==2){
												if (arry[jj][jj]==chkk && arry[k+1][k+1]==chkkk){
													if(arry[r2][r2]=='\0'){
														if (lp==1){ui=(((k+1)*3)+k+2);}
														else{ui = rslt3;}
														stop++;
														break;
													}
												}
											}
											if (k==0){
												jj--;
												k++;
											}
											r2--;
											rslt--;
											rslt2-=3;
											rslt3-=4;
										}	
										rslt2+=8;
									}
									if (arry[2][0]==chkk && arry[1][1]=='\0'){
										if (arry[0][2]=='\0'){stop++; ui = 5;}
									}
									if (arry[0][2]==chkk && arry[1][1]=='\0'){
										if (arry[2][0]=='\0'){stop++; ui = 5;}
									}
									if (arry[2][0]=='\0' && arry[1][1]==chkk){
										if (arry[0][2]=='\0'){stop++; ui = 3;}
									}
									if (arry[2][0]=='\0' && arry[0][2]==chkk){
										if (arry[1][1]=='\0'){stop++; ui = 5;}
									}
									if (arry[0][2]=='\0' && arry[1][1]==chkk){
										if (arry[2][0]=='\0'){stop++; ui = 7;}
									}
								}
							}
						}
										
											
											
											
							else {
							chr=uc;
							if(cnst==1){printf("Your Turn: \n\n\n\n");}
							else {printf("Player 1 turn: \n\n\n\n");}
							scanf("%d",&ui);
						}
						if (ui!=1 && ui!=2 && ui!=3 && ui!=4 && ui!=5 && ui!=6 && ui!=7 && ui!=8 && ui!=9){
							printf("Wrong input.\nInput a number from 0 to 9.\n");
							loop--;
							continue;
						}
						if (ui==1){
							if (arry[0][0]=='\0'){
								arry[0][0]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==2){
							if (arry[0][1]=='\0'){
								arry[0][1]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==3){
							if (arry[0][2]=='\0'){
								arry[0][2]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==4){
							if (arry[1][0]=='\0'){
								arry[1][0]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==5){
							if (arry[1][1]=='\0'){
								arry[1][1]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==6){
							if (arry[1][2]=='\0'){
								arry[1][2]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==7){
							if (arry[2][0]=='\0'){
								arry[2][0]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==8){
							if (arry[2][1]=='\0'){
								arry[2][1]=chr;
							}
							else{
								printf("Already inputed\n");
								loop--;
								continue;
							}
						}
						else if (ui==9){
							if (arry[2][2]=='\0'){
								arry[2][2]=chr;
							}
							else{
								printf("\nAlready inputed\n");
								loop--;
								continue;
							}
						}
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\t\t\t%c\t:\t%c\t:\t%c\t\n",arry[0][0],arry[0][1],arry[0][2]);
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\t\t    -----------------------------------------\n");
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\t\t\t%c\t:\t%c\t:\t%c\t\n",arry[1][0],arry[1][1],arry[1][2]);
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\t\t    -----------------------------------------\n");
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\t\t\t%c\t:\t%c\t:\t%c\t\n",arry[2][0],arry[2][1],arry[2][2]);
						printf("\t\t\t\t:\t\t:\t\t\n");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						if (loop>=3){
							if ((arry[0][0]==arry[0][1] && arry[0][1]==arry[0][2] && arry[0][2]!='\0')||(arry[0][0]==arry[1][0] && arry[1][0]==arry[2][0] && arry[2][0]!='\0')||(arry[0][0]==arry[1][1] && arry[1][1]==arry[2][2] && arry[2][2]!='\0')||(arry[0][1]==arry[1][1] && arry[1][1]==arry[2][1] && arry[2][1]!='\0')||(arry[0][2]==arry[1][2] && arry[1][2]==arry[2][2] && arry[2][2]!='\0')||(arry[0][2]==arry[1][1] && arry[1][1]==arry[2][0] && arry[2][0]!='\0')||(arry[1][0]==arry[1][1] && arry[1][1]==arry[1][2] && arry[1][2]!='\0')||(arry[2][0]==arry[2][1] && arry[2][1]==arry[2][2] && arry[2][2]!='\0')){
								if (loop%2==0){
									if (cnst==1){printf("Computer: I Wins!!\n\n\n\n");}
									else{printf("Player 2 Wins!!\n\n\n\n");}
									X='E';
									break;
								}
								else{
									if (cnst==1){printf("You Win!!\n\n\n\n");}
									else{printf("Player 1 Wins!!\n\n\n\n");}
									X='E';
									break;	
								}
							}
						}
					}
					if (X!='E'){printf("Game Draw!!\n");}
					for (loop=0; loop<1; loop++){
						printf("Replay: 1\nReturn to main menu: 2\nQuit: 3\n");
						printf("Enter your choice: ");
						scanf("%d",&rtrn);
						if (rtrn!=1 && rtrn!=2 && rtrn!=3){
							printf("Wrong input.\n");
							loop-=1;
							continue;
						}
						if (rtrn==1){
							ooloop-=1;
							if (cnst==1){rptt1++;rptt2++;}
						}
						
					}
					if(rtrn==2){oooloop-=1;}
				}
			}
			if (mm==3){
				int loophtp;
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("1-Select your character 'X' or 'O'.\n\n");
				printf("2-If you enter anything other than 'O' or 'X' you will be given 'X' by default.\n\n");
				printf("3-Enter the number of the location where you want to put your character.\n\n");
				printf("Numbers of locations are as follows: \n\n");
				printf("\t\t\t\t:\t\t:\t\t\n");
				printf("\t\t\t1\t:\t2\t:\t3\t\n");
				printf("\t\t\t\t:\t\t:\t\t\n");
				printf("\t\t    -----------------------------------------\n");
				printf("\t\t\t\t:\t\t:\t\t\n");
				printf("\t\t\t4\t:\t5\t:\t6\t\n");
				printf("\t\t\t\t:\t\t:\t\t\n");
				printf("\t\t    -----------------------------------------\n");
				printf("\t\t\t\t:\t\t:\t\t\n");
				printf("\t\t\t7\t:\t8\t:\t9\t\n");
				printf("\t\t\t\t:\t\t:\t\t\n\n");
				printf("4-If you enter a character while entering the number of location game will crash.\n\n");
				printf("5-If you are playing with computer and play a 'replay', Computer will play first turn in 2nd game.\n\n");
				printf("6-If you enter more than one character at a time, game may crash.\n\n");
				printf("7-Not so hard game that you are reading the instructions so carefully.\n\n");
				printf("Go play the game everything will be revealed on you with experience.\n\n");
				printf("Wanna play??...Enter 1..\n");
				printf("Wanna Quit??...Enter 2..\n");
				printf("Choice is the only thing that is yours.");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				for (loophtp=0; loophtp<1; loophtp++){
					printf("Enter your choice: ");
					scanf ("%d",&rtrn);
					if (rtrn!=1 && rtrn!=2){
						printf("Wrong choice.\n\n");
						loophtp--;
					}
					if (rtrn==1){oooloop--;}
				}
			}
		}
}