
#include <avr/pgmspace.h>
int datapin0=11;
int datapin1=10;
int datapin2=9;
int datapin3=7;
int datapin4=6;
int datapin5=5;
int datapin6=4;
int datapin7=3;
int shiftpin=12;
int showpin=8;
/*
const prog_uint8_t digits[8][8] = { 
{B11111111, B11111111, B11111111, B01111111, B11111111, B11111111, B11111111, B11111111},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
};
*/

const prog_uint8_t digits[8][8] = { 
{B00100010, B11100011, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B01100110, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B10101010, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00100010, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00100010, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00100010, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00100010, B10010100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00100010, B01100011, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
};

void setup() {                

DDRC = B00000111;
PORTC = B00000000;
pinMode(datapin0,OUTPUT);
pinMode(datapin1,OUTPUT);
pinMode(datapin2,OUTPUT);
pinMode(datapin3,OUTPUT);
pinMode(datapin4,OUTPUT);
pinMode(datapin5,OUTPUT);
pinMode(datapin6,OUTPUT);
pinMode(datapin7,OUTPUT);
pinMode(showpin,OUTPUT);
pinMode(shiftpin,OUTPUT);
digitalWrite(datapin0,LOW);
digitalWrite(datapin1,LOW);
digitalWrite(datapin2,LOW);
digitalWrite(datapin3,LOW);
digitalWrite(datapin4,LOW);
digitalWrite(datapin5,LOW);
digitalWrite(datapin6,LOW);
digitalWrite(datapin7,LOW);
digitalWrite(showpin,LOW);
digitalWrite(shiftpin,LOW);
}

void loop() {

    
for (byte x = 0; x < 8; x++)  {
 
digitalWrite(showpin,LOW);
byte val0 = digits[x][0];
byte val1 = digits[x][1];
byte val2 = digits[x][2];
byte val3 = digits[x][3];
byte val4 = digits[x][4];
byte val5 = digits[x][5];
byte val6 = digits[x][6];
byte val7 = digits[x][7];
  for(int i=0; i<8; i++) {
    	digitalWrite(datapin2, !!(val0 & (1 << 7-i)));
   	  digitalWrite(datapin1, !!(val1 & (1 << 7-i)));
      digitalWrite(datapin0, !!(val2 & (1 << 7-i)));
      digitalWrite(datapin3, !!(val3 & (1 << 7-i)));
   	  digitalWrite(datapin4, !!(val4 & (1 << 7-i)));
      digitalWrite(datapin5, !!(val5 & (1 << 7-i)));
      digitalWrite(datapin6, !!(val6 & (1 << 7-i)));
   	  digitalWrite(datapin7, !!(val7 & (1 << 7-i)));
	    digitalWrite(shiftpin, HIGH);
	    digitalWrite(shiftpin, LOW);		
  }
digitalWrite(showpin,HIGH);
 PORTC=x;


}

void gadachocheba() {
  int mda[8][8] = {0};
  for (int i = 0 ; i < 8; i++ ){
    for (int j = 0; j < 8; j++) {
      byte x = digits[i][j];
      digits[i][j] = x/2;
      if(x%2 == 1){
        mda[i][(j+1)%8] = 1;
      }
    }
  }
   for (int i = 0 ; i < 8; i++ ){
      for (int j = 0; j < 8; j++) {
        if(mda[i][j] == 1) {
          digits[i][j] += 128;
        }
      }
   }
}
  

void loop() {
  for(int i=0; i<70;i++){
    doJob(HIGH,digits);
  }
  gadachocheba();
}

}
