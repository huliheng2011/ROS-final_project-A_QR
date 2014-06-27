#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>


float x = 0;
float y = 0;
float x_last = 0;
float y_last = 0;
float ready = 0;
int count = 0;
int readyCountX = 0;
int readyCountY = 0;

float getPositionX() {
	if(x_last == x)
		readyCountX++;
	else
		x_last = x;
    return x;
}

float getPositionY() {
	if(y_last == y)
		readyCountY++;
	else
		y_last = y;
    return y;
}

//To tell turtlebot if QR get the right position.
float getReady() {
	if(readyCountX > 3  && readyCountY >3)
		ready = 1;
    return ready;
}

//Produce a delay to let the read speed lower than write speed.
void Delay(float time) {
  int ctime = (int)(time * 1000);
  clock_t now = clock();
  while(clock() - now < ctime);
}

//Case one
//Get data from file
/*void ReadPoint() {
    std::ifstream infile("data.txt", std::ios::in);

	if(infile) {
		std::string strBufferX, strBufferY;
		int k = 0;
		while(k<count) {
			infile >> strBufferX;
			infile >> strBufferY;
			Delay(0.5);
			size_t nFlagX = strBufferX.find('x');
			size_t nFlagY = strBufferY.find('y');
			
			if(nFlagX != -1) {
				std::string strOutX = strBufferX.substr(2, 8);
				x = atof(strOutX.c_str());
			}
			if(nFlagY != -1) {
				std::string strOutY = strBufferY.substr(2,8);
				y = atof(strOutY.c_str());
			}
			k++;
		}
		count++;
	infile.close();		
    }
    else
    	x = 2.0;
}*/

//Case two
//Get data from keyboard
void ReadPoint() {
    if(ready == 0) {
        std::cin>>x>>y;
        ready = 1;
    }
}

	

                    
