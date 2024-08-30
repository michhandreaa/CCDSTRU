#include <stdio.h>
int NextPlayerMove (int turn,int OrdP, int nNum, int nFlagH, int nFlagW, int
nFlagOrd)
{
if(turn && nFlagH==0 && nNum==1)
{
return 1;
/*Tells the position in the double array*/
}
if(!turn && OrdP<3 && nNum==1)
{
return 2;
}
if(!turn && OrdP==3 && nFlagOrd==1)
{
return 3;
}
else
{
return 0;
}
}
int GameOver(int nFlagW1, int nFlagW2, int nFlagW3, int nFlagW4, int nFlagH1)
{
if(nFlagW1==3)
{
return 1;
}
else if(nFlagW2==3)
{
return 1;
}
else if(nFlagW3==3)
{
return 1;
}
else if(nFlagW4==3)
{
return 1;
}
else if(nFlagH1==0)
{
return 2;
}
else
{
return 0;
}
}
int main(void)
{
int funcVal=0;
int nFlag=0,nFlagH=0,nFlagW=0,nFlagOrd=0;
int nFlagW1,nFlagW2,nFlagW3,nFlagW4,nFlagH1;
int nWin=0;
int ChaP=0,OrdP=0,FreeP;
int pos[2];
int x=0,y=0,z=0;
int Ord[100][2];
int Cha[100][2];
int A;
int P[16][2]={{1,1},{1,2},{1,3},{1,4},{2,1},{2,2},{2,3},{2,4},{3,1},{3,2},{3,3},
{3,4},{4,1},{4,2},{4,3},{4,4}};
int B; /*0 for false, 1 for true*/
int H[5][2]= {{1, 1},{1, 2},{1, 3},{2, 1},{3, 1}};
int W[4][3][2]= {{{1, 4},{2, 4},{3, 4}}, {{2, 2},{3, 3},{4, 4}}, {{2, 3},{3, 2},
{4, 1}}, {{4, 2},{4, 3},{4, 4}}};
int turn = 1;
int Free[16][2];
int over;
for(x=0;x<16;x++)
{
Ord[x][0]=0;
Ord[x][1]=0;
Cha[x][0]=0;
Cha[x][1]=0;
}
do
{
if(turn==1)
{
printf("\n\nCha's turn\n");
}
else if(turn==0)
{
printf("\n\nOrd's turn\n");
}
printf("Cha= ");
for(x=0;x<ChaP;x++)
{
printf("(%d,%d)",Cha[x][0],Cha[x][1]);
}
printf("\n");
printf("Ord= ");
for(x=0;x<OrdP;x++)
{
printf("(%d,%d)",Ord[x][0],Ord[x][1]);
}
printf("\n");
FreeP=0;
for(x=0;x<16;x++)
{
Free[x][0]=P[x][0];
Free[x][1]=P[x][1];
FreeP++;
}
for(x=0;x<16;x++)
{
for(z=0;z<OrdP;z++)
{
if(Free[x][0]==Ord[z][0] && Free[x][1]==Ord[z][1] && Ord[z][0]!=0)
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<16;x++)
{
for(z=0;z<ChaP;z++)
{
if(Free[x][0]==Cha[z][0] && Free[x][1]==Cha[z][1] && Cha[z][0]!=0)
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<FreeP;x++)
{
for(z=0;z<OrdP;z++)
{
if(Free[x][0]==Ord[z][0] && Free[x][1]==Ord[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<FreeP;x++)
{
for(z=0;z<ChaP;z++)
{
if(Free[x][0]==Cha[z][0] && Free[x][1]==Cha[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
printf("Free=");
for(x=0;x<FreeP;x++)
{
printf("(%d,%d) ",Free[x][0],Free[x][1]);
}
printf("\n");
x=0;
funcVal=0;
while(x==0)
{
printf("Horizontal [1-4]: ");
scanf("%d",&A);
if(A>=1 && A<=4)
{
pos[0]=A;
x++;
}
else
{
printf("Please select a number from 1 to 4\n");
}
}
y=0;
while(y==0)
{
printf("Vertical [1-4]: ");
scanf("%d",&A);
if(A>=1 && A<=4)
{
pos[1]=A;
y++;
}
else
{
printf("Please select a number from 1 to 4\n");
}
}
nFlagH=0;
nFlagW=0;
for(x=0;x<5;x++)/*Checker to see if pos is not an element of H*/
{
if(pos[0]==H[x][0] &&pos[1]==H[x][1])
{
nFlagH++;
}
}
nFlag=0;
for(x=0;x<FreeP;x++)
{
if(pos[0]==Free[x][0] && pos[1]==Free[x][1])
{
printf("nFlag=%d",nFlag);
nFlag++;
}
}
nFlagOrd=0;
for(x=0;x<OrdP;x++)
{
if(pos[0]==Ord[x][0] && pos[1]==Ord[x][1])
{
nFlagOrd++;
}
}
funcVal=NextPlayerMove(turn,OrdP,nFlag,nFlagH,nFlagW,nFlagOrd);
if(funcVal==1) /*Cha move any except w*/
{
Cha[ChaP][0]=pos[0];
Cha[ChaP][1]=pos[1];
turn=!turn;
ChaP++;
printf("Cha=");
for(x=0;x<ChaP;x++)
{
printf("(%d,%d) ",Cha[x][0],Cha[x][1]);
}
printf("\n");
}
else if (funcVal==2) /*Ord move any as long as cardinality > 4*/
{
Ord[OrdP][0]=pos[0];
Ord[OrdP][1]=pos[1];
OrdP++;
turn=!turn;
printf("Ord=");
for(x=0;x<OrdP;x++)
{
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
}
printf("\n");
}
else if(funcVal==3) /*Ord move any as long as cardinality > 4*/
{
for(x=0;x<OrdP;x++)
{
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
if(Ord[x][0]==pos[0] && Ord[x][1]==pos[1])
{
for(y=x;y<OrdP;y++)
{
Ord[y][0]=Ord[y+1][0];
Ord[y][1]=Ord[y+1][1];
}
OrdP--;
}
}
printf("Ord=");
for(x=0;x<OrdP;x++)
{
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
}
}
FreeP=0;
for(x=0;x<16;x++)
{
Free[x][0]=P[x][0];
Free[x][1]=P[x][1];
FreeP++;
}
for(x=0;x<16;x++)
{
for(z=0;z<OrdP;z++)
{
if(Free[x][0]==Ord[z][0] && Free[x][1]==Ord[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<16;x++)
{
for(z=0;z<ChaP;z++)
{
if(Free[x][0]==Cha[z][0] && Free[x][1]==Cha[z][1]){
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
}
printf("\n");
}
else if(funcVal==3) /*Ord move any as long as cardinality > 4*/
{
for(x=0;x<OrdP;x++)
{
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
if(Ord[x][0]==pos[0] && Ord[x][1]==pos[1])
{
for(y=x;y<OrdP;y++)
{
Ord[y][0]=Ord[y+1][0];
Ord[y][1]=Ord[y+1][1];
}
OrdP--;
}
}
printf("Ord=");
for(x=0;x<OrdP;x++)
{
printf("(%d,%d) ",Ord[x][0],Ord[x][1]);
}
}
FreeP=0;
for(x=0;x<16;x++)
{
Free[x][0]=P[x][0];
Free[x][1]=P[x][1];
FreeP++;
}
for(x=0;x<16;x++)
{
for(z=0;z<OrdP;z++)
{
if(Free[x][0]==Ord[z][0] && Free[x][1]==Ord[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<16;x++)
{
for(z=0;z<ChaP;z++)
{
if(Free[x][0]==Cha[z][0] && Free[x][1]==Cha[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<FreeP;x++)
{
for(z=0;z<OrdP;z++)
{
if(Free[x][0]==Ord[z][0] && Free[x][1]==Ord[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
for(x=0;x<FreeP;x++)
{
for(z=0;z<ChaP;z++)
{
if(Free[x][0]==Cha[z][0] && Free[x][1]==Cha[z][1])
{
for(y=x;y<FreeP;y++)
{
Free[y][0]=Free[y+1][0];
Free[y][1]=Free[y+1][1];
}
FreeP--;
}
}
}
/*Cha wins if any element of W:{(1, 4),(2, 4),(3, 4)} {(2, 2),(3, 3),(4, 4)}
{(2, 3),(3, 2),(4, 1)} {(4, 2),(4, 3),(4, 4)}*/
nFlagW1=0;
nFlagW2=0;
nFlagW3=0;
nFlagW4=0;
for(x=0;x<ChaP;x++)
{
if((Cha[x][0]==1 && Cha[x][1]==4) || (Cha[x][0]==2 && Cha[x][1]==4) ||
(Cha[x][0]==3 && Cha[x][1]==4))
{
nFlagW1++;
}
else if((Cha[x][0]==2 && Cha[x][1]==2) || (Cha[x][0]==3 && Cha[x][1]==3) ||
(Cha[x][0]==4 && Cha[x][1]==4))
{
nFlagW2++;
}
else if((Cha[x][0]==2 && Cha[x][1]==3) || (Cha[x][0]==3 && Cha[x][1]==2) ||
(Cha[x][0]==4 && Cha[x][1]==1))
{
nFlagW3++;
}
else if((Cha[x][0]==4 && Cha[x][1]==2) || (Cha[x][0]==4 && Cha[x][1]==3) ||
(Cha[x][0]==4 && Cha[x][1]==4))
{
nFlagW4++;
}
}
/*Ord wins if all FreeP is outside {(1, 1),(1, 2),(1, 3),(2, 1),(3, 1)}*/
nFlagH1=0;
for(x=0;x<FreeP;x++)/*For Free[x][0-1]*/
{
if(Free[x][0]!=H[0][0] || Free[x][1]!=H[0][1])
{
if(Free[x][0]!=H[1][0] || Free[x][1]!=H[1][1])
{
if(Free[x][0]!=H[2][0] || Free[x][1]!=H[2][1])
{
if(Free[x][0]!=H[3][0] || Free[x][1]!=H[3][1])
{
if(Free[x][0]!=H[4][0] || Free[x][1]!=H[4][1])
{
nFlagH1++;
}
}
}
}
}
/*checks if h is not in free*//* You need to check if free is not in H (!
mean not) ~Denise*/
}
/*win*/
nWin = GameOver(nFlagW1, nFlagW2, nFlagW3, nFlagW4, nFlagH1);
}while(nWin==0 && FreeP>0);
/*Write who wins based on the value of nWin*/
if(nWin==1)
{
printf("\nCha wins!");
}
else if(nWin==2)
{
printf("\nOrd Wins!");
}
else
{
printf("Try Again!");
}
return 0;
}