#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef char str[128];
typedef char push[3000];
void gotoxy(int x, int y);

halo

int main() {
	const int xbb=82, ybb=19, jml_M=3, xm = 20, ym = 9;
	int x, y, now, p, key, r, rr = 1, ry, rx, rot = 0, t, a, map = 1;
	push out, m_out;
	str temp;
	int ax = 1, ay = 1, tempx;
	int arr[xbb][ybb];
	int maze[xm][ym];
	
	
	srand(time(NULL));
	printf("\033[?25l");
	fflush(stdout);
	
	do{
		key = getch();
		switch(key){
//			case 97: //a
//				switch(rot){
//					case 0: if(ay>1){ay--;};break;
//					case 1: if(ax>1){ax--;};break;
//					case 2: if(ay<ybb-2){ay++;};break;
//					case 3: if(ax<xbb-2){ax++;};break;
//				}
//				break;
//			case 100: // d
//				switch(rot){
//					case 2: if(ay>1){ay--;};break;
//					case 3: if(ax>1){ax--;};break;
//					case 0: if(ay<ybb-2){ay++;};break;
//					case 1: if(ax<xbb-2){ax++;};break;
//				}
//				break;
			case 115: // s
				switch(rot){
					case 3: ay--;if(maze[ax][ay]!=-1){ay++;};break;
					case 2: ax++;if(maze[ax][ay]!=-1){ax--;};break;
					case 1: ay++;if(maze[ax][ay]!=-1){ay--;};break;
					case 0: ax--;if(maze[ax][ay]!=-1){ax++;};break;
				}
				break;
			case 119: // w
				switch(rot){
					case 1: ay--;if(maze[ax][ay]!=-1){ay++;};break;
					case 0: ax++;if(maze[ax][ay]!=-1){ax--;};break;
					case 3: ay++;if(maze[ax][ay]!=-1){ay--;};break;
					case 2: ax--;if(maze[ax][ay]!=-1){ax++;};break;
				}
				break;
			case 100: // d
				rot--;
				if(rot<0){
					rot=3;
				}
				break;
			case 97: // a
				rot++;
				if(rot>3){
					rot=0;
				}
				break;
			case 109: // m
				if(map == 1){
					map = 0;
				}else{
					map = 1;
				}
				break;
			default:
				break;
		}
		
		switch(rot){
			case 0:
				ry = -1; 
				rx = 1;
				break;
			case 1:
				ry = -1; 
				rx = -1;
				break;
			case 2:
				ry = 1; 
				rx = -1;
				break;
			case 3:
				ry = 1; 
				rx = 1;
				break;
		}
		for(x=0;x<xm;x++){
			for(y=0;y<ym;y++){
				if(x==0||x==xm-1||y==0||y==ym-1){
					maze[x][y]=1;
				}else if(x==ax&&y==ay){
					maze[x][y]=0;
				}else if((x==17||x==12)&&y==2){
					maze[x][y]=-1;
				}else if((x==3||x==8||x==18)&&y==4){
					maze[x][y]=-1;
				}else if((x==18||x==14||x==11)&&y==6){
					maze[x][y]=-1;
				}else if((x==5||x==15||x==10)&&y==5){
					maze[x][y]=7;
				}else if(x==1&&y==7){
					maze[x][y]=6;
				}else if(x==13&&y==7){
					maze[x][y]=7;
				}else if(x%3!=0&&y%2==0){
					maze[x][y]=3;
				}else if(x%3==0&&y%2==0){
					maze[x][y]=5;
				}else if(x==ax+2&&y==ay&&rot==0){
					maze[x][y]=-2;
				}else if(x==ax&&y==ay-2&&rot==1){
					maze[x][y]=-2;
				}else if(x==ax-2&&y==ay&&rot==2){
					maze[x][y]=-2;
				}else if(x==ax&&y==ay+2&&rot==3){
					maze[x][y]=-2;
				}else {
					maze[x][y]=-1;
				}
			}
		}
		
		for(x=0;x<xbb;x++){
			for(y=0;y<ybb;y++){
				if(x==0||x==xbb-1||y==0||y==ybb-1){
					arr[x][y]=1;
				}else if(x<=9&&x>1&&y<=ybb-3&&y>=2){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax][ay+(1*ry)];
					}else{
						arr[x][y]=maze[ax+(1*ry)][ay];
					}
				}else if(x<=18&&x>10&&y<=ybb-4&&y>=3){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(1*rx)][ay+(1*ry)];
					}else{
						arr[x][y]=maze[ax+(1*ry)][ay+(1*rx)];
					}
				}else if(x<=25&&x>19&&y<=ybb-5&&y>=4){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(2*rx)][ay+(1*ry)];
					}else{
						arr[x][y]=maze[ax+(1*ry)][ay+(2*rx)];
					}
				}else if(x<=31&&x>26&&y<=ybb-6&&y>=5){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(3*rx)][ay+(1*ry)];
					}else{
						arr[x][y]=maze[ax+(1*ry)][ay+(3*rx)];
					}
				}else if(x>=xbb-32&&x<xbb-27&&y<=ybb-6&&y>=5){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(3*rx)][ay-(1*ry)];
					}else{
						arr[x][y]=maze[ax-(1*ry)][ay+(3*rx)];
					}
				}else if(x>=xbb-26&&x<xbb-20&&y<=ybb-5&&y>=4){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(2*rx)][ay-(1*ry)];
					}else{
						arr[x][y]=maze[ax-(1*ry)][ay+(2*rx)];
					}
				}else if(x>=xbb-19&&x<xbb-11&&y<=ybb-4&&y>=3){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax+(1*rx)][ay-(1*ry)];
					}else{
						arr[x][y]=maze[ax-(1*ry)][ay+(1*rx)];
					}
				}else if(x>=xbb-10&&x<xbb-2&&y<=ybb-3&&y>=2){
					if(rot == 0 || rot == 2){
						arr[x][y]=maze[ax][ay-(1*ry)];
					}else{
						arr[x][y]=maze[ax-(1*ry)][ay];
					}
				}else{
					arr[x][y]=-1;
				}
				for(p=1;p<5;p++){
					r = 4-p;
					if (r==0){
						t = 0;
					}else if (r==1){
						t = 6;
					}else if (r==2){
						t = 13;
					}else if (r==3){
						t = 22;
					}
					if(x<=xbb-34+t&&x>32-t&&y<=ybb-7+r&&y>=6-r){
						if(rot == 0 || rot == 2){
							if(maze[ax+(p*rx)][ay]<=0){
								continue;
							}
							arr[x][y]=maze[ax+(p*rx)][ay];
							if(maze[ax+(p*rx)][ay]>=0){
								break;
							}
						}else{
							if(maze[ax][ay+(p*rx)]<=0){
								continue;
							}
							arr[x][y]=maze[ax][ay+(p*rx)];
							if(maze[ax][ay+(p*rx)]>=0){
								break;
							}
						}
					}
				}
			}
		} 
		p=0;
		for(y=0;y<ybb;y++){
			for(x=0;x<xbb;x++){
				now = arr[x][y];
				switch(now){
					case 0: sprintf(out+p, "@"); break;
					case 1: sprintf(out+p, "-"); break;
					case 2: sprintf(out+p, "$"); break;
					case 3: sprintf(out+p, "#"); break;
					case 4: sprintf(out+p, "X"); break;
					case 5: sprintf(out+p, "+"); break;
					case 6: sprintf(out+p, "!"); break;
					case 7: sprintf(out+p, "\\"); break;
					case 8: sprintf(out+p, "8"); break;
					case 9: sprintf(out+p, "9"); break;
					case 10: sprintf(out+p, "0"); break;
					case -1: sprintf(out+p, " "); break;
					default: sprintf(out+p, "?"); break;
				}
				p++;
			}
			sprintf(out+p, "\n");
			p++;
		} 
		
		p=0;
		for(y=0;y<ym;y++){
			sprintf(temp, "\033[s");
			tempx=strlen(temp);
			sprintf(m_out+p, "\033[s");
			p+=tempx;
			for(x=0;x<xm;x++){
				now = maze[x][y];
				if(map==0){
					sprintf(m_out+p, " ");
				}else{
					
				switch(now){
					case 0: sprintf(m_out+p, "@"); break;
					case 1: sprintf(m_out+p, "-"); break;
					case 2: sprintf(m_out+p, "$"); break;
					case 3: sprintf(m_out+p, "#"); break;
					case 4: sprintf(m_out+p, "x"); break;
					case 5: sprintf(m_out+p, "+"); break;
					case 6: sprintf(m_out+p, "!"); break;
					case 7: sprintf(m_out+p, "\\"); break;
					case 8: sprintf(m_out+p, "8"); break;
					case 9: sprintf(m_out+p, "9"); break;
					case 10: sprintf(m_out+p, "0"); break;
					case -1: sprintf(m_out+p, " "); break;
					case -2: sprintf(m_out+p, "x"); break;
					default: sprintf(m_out+p, "?"); break;
				}}
				p++;
			}
			sprintf(temp, "\033[u\033[B");
			tempx=strlen(temp);
			sprintf(m_out+p, "\033[u\033[B");
			p+=tempx;
		} 
		
		printf(out);
		gotoxy(xbb+2,0);
		printf(m_out);
		gotoxy(xbb+2,10);
		printf("[A] Turn Left");
		gotoxy(xbb+2,11);
		printf("[D] Turn Right");
		gotoxy(xbb+2,12);
		printf("[W] Go Forward");
		gotoxy(xbb+2,13);
		printf("[S] Go Backward");
		printf("\033[H");
	
	

	}while(key!='0');
	
	
	return 0;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

