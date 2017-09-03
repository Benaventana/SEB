/*
 Ronaldo Sena
 ronaldo.sena@outlook.com
 September 2017
 Use it as you please. If we meet some day, and you think
 this stuff was helpful, you can buy me a beer

 Primeiro projeto da disciplina Sinais e Sistemas em Engenharia Biomédica
 */

//Suppose the pins goes like this
//    a
//    _
//  f|_|b 
//  e|_|c
//    d

#define pinA 3
#define pinB 4
#define pinC 5
#define pinD 6
#define pinE 7
#define pinF 8
#define pinG 9

uint32_t currentTime;
uint32_t eventTime;
int8_t number = 0;
uint16_t interval = 300;
uint8_t bitMask = 0x01; //B00000001
//This way I can store all ten digits using
//only 10 bytes of memory
//each bit correspond the led in the display
uint8_t pinArray[] = {
	0x3F, //B00111111  digit 0
	0x06, //B00000110  digit 1
	0x5B, //B01011011  digit 2
	0x4F, //B01001111  digit 3
	0x66, //B01100110  digit 4
	0x6D, //B01101101  digit 5
	0x7C, //B01111100  digit 6
	0x07, //B00000111  digit 7
	0x7F, //B01111111  digit 8
	0x67  //B01100111  digit 9
};

void setup()
{
	//setting as outputs
	for (int8_t i = pinA; i <= pinG; i++)
		pinMode(i, OUTPUT);
}

void loop()
{	
	//Guardinha da ufu's algorithm
	currentTime = millis();
	if (currentTime - eventTime >= interval)
	{
		display(number);
		number >= 9 ? number = 0 : number++;
		eventTime = currentTime;
	}
}

void display(int8_t numToDisplay)
{
	bitMask = 0x01;
	for(int8_t i = pinA; i <= pinG; i++)
	{
		//as the display is common cathode, 
		//to light it, one must set it to ground

		//bitwise operation 00000001 AND the number to display
		if((bitMask & pinArray[numToDisplay]) == 0) 
			digitalWrite(i, HIGH); 

		else 
			digitalWrite(i, LOW);

		//Shifting the bit in the bitmask
		bitMask = bitMask << 1;
	}
}


/* Or you could just do this: (which is better?)
#define pinA 3
#define pinB 4
#define pinC 5
#define pinD 6
#define pinE 7
#define pinF 8
#define pinG 9

int counter = 0;
long currentTime;
long eventTime;
long interval = 300;

void setup()
{
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);
	pinMode(pinE, OUTPUT);
	pinMode(pinF, OUTPUT);
	pinMode(pinG, OUTPUT);
}

void loop()
{
	currentTime = millis();
	if (currentTime - eventTime >= interval)
	{
		if (counter > 9)
			counter = 0
		else
			counter = counter + 1;

		eventTime = currentTime;

		switch (counter)
		{
			case 0:		
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, HIGH);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, LOW);
	            break;

	        case 1:
	            digitalWrite(pinA, LOW);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, LOW);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, LOW);
	            digitalWrite(pinG, LOW);
	                break;

	        case 2:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, LOW);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, HIGH);
	            digitalWrite(pinF, LOW);
	            digitalWrite(pinG, HIGH);
	            break;

	        case 3:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, LOW);
	            digitalWrite(pinG, HIGH);
	            break;

			case 4:
	            digitalWrite(pinA, LOW);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, LOW);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, HIGH);
	            break;

			case 5:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, LOW);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, HIGH);
	            break;

	        case 6:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, LOW);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, HIGH);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, HIGH);
	            break;

	        case 7:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, LOW);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, LOW);
	            digitalWrite(pinG, LOW);
	            break;

			case 8:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, HIGH);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, HIGH);
	            break;

	        case 9:
	            digitalWrite(pinA, HIGH);
	            digitalWrite(pinB, HIGH);
	            digitalWrite(pinC, HIGH);
	            digitalWrite(pinD, HIGH);
	            digitalWrite(pinE, LOW);
	            digitalWrite(pinF, HIGH);
	            digitalWrite(pinG, HIGH);
	            break;

	        default:
	            break;

	     }
	}
}
//But where is the fun in that?
*/