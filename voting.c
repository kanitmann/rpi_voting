
// ***** CSE2006 Microprocessors and Interfacing *****
// Kanit Mann 19BCE2040
// Rishabh Jain 19BCE0240
// Tanmay Kumari 19BCE2146
// Shaurya Singhal 19BCE2268


#include <wiringPi.h>

#include <stdio.h>

#define RS 11

#define EN 10

#define D4 6

#define D5 5

#define D6 4

#define D7 1

#define led1 26

#define led2 27

#define led3 28

#define led4 29

#define led5 14

#define buzz 13

#define in1 21

#define in2 22

#define in3 23

#define in4 24

#define in5 25

int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0;

int i = 0;

char vote[5];

void compare();

void show();

void lcdcmd(unsigned char ch)

{

    int temp = 0x80;

    digitalWrite(D4, temp & ch << 3);

    digitalWrite(D5, temp & ch << 2);

    digitalWrite(D6, temp & ch << 1);

    digitalWrite(D7, temp & ch);

    digitalWrite(RS, LOW);

    digitalWrite(EN, HIGH);

    delay(10);

    digitalWrite(EN, LOW);

    digitalWrite(D4, temp & ch << 7);

    digitalWrite(D5, temp & ch << 6);

    digitalWrite(D6, temp & ch << 5);

    digitalWrite(D7, temp & ch << 4);

    digitalWrite(RS, LOW);

    digitalWrite(EN, HIGH);

    delay(10);

    digitalWrite(EN, LOW);
}

void write(unsigned char ch)

{

    int temp = 0x80;

    digitalWrite(D4, temp & ch << 3);

    digitalWrite(D5, temp & ch << 2);

    digitalWrite(D6, temp & ch << 1);

    digitalWrite(D7, temp & ch);

    digitalWrite(RS, HIGH);

    digitalWrite(EN, HIGH);

    delay(10);

    digitalWrite(EN, LOW);

    digitalWrite(D4, temp & ch << 7);

    digitalWrite(D5, temp & ch << 6);

    digitalWrite(D6, temp & ch << 5);

    digitalWrite(D7, temp & ch << 4);

    digitalWrite(RS, HIGH);

    digitalWrite(EN, HIGH);

    delay(10);

    digitalWrite(EN, LOW);
}

void clear()

{

    lcdcmd(0x01);
}

void setCursor(int x, int y)

{

    int set = 0;

    if (y == 0)

        set = 128 + x;

    if (y == 1)

        set = 192 + x;

    lcdcmd(set);
}

void print(unsigned char *str)

{

    while (*str)

    {

        write(*str);

        str++;
    }
}

void begin(int x, int y)

{

    lcdcmd(0x02);

    lcdcmd(0x28);

    lcdcmd(0x06);

    lcdcmd(0x0e);

    lcdcmd(0x01);
}

void setup()

{

    if (wiringPiSetup() == -1)

        printf("ERROR");

    pinMode(led1, OUTPUT);

    pinMode(led2, OUTPUT);

    pinMode(led3, OUTPUT);

    pinMode(led4, OUTPUT);

    pinMode(led5, OUTPUT);

    pinMode(buzz, OUTPUT);

    pinMode(RS, OUTPUT);

    pinMode(EN, OUTPUT);

    pinMode(D4, OUTPUT);

    pinMode(D5, OUTPUT);

    pinMode(D6, OUTPUT);

    pinMode(D7, OUTPUT);

    pinMode(in1, INPUT);

    pinMode(in2, INPUT);

    pinMode(in3, INPUT);

    pinMode(in4, INPUT);

    pinMode(in5, INPUT);

    digitalWrite(in1, HIGH);

    digitalWrite(in2, HIGH);

    digitalWrite(in3, HIGH);

    digitalWrite(in4, HIGH);

    digitalWrite(in5, HIGH);

    begin(16, 2);
}

void buzzer()

{

    digitalWrite(buzz, HIGH);

    delay(1000);

    digitalWrite(buzz, LOW);
}

void wait()

{

    digitalWrite(led5, LOW);

    delay(3000);
}

void main()

{

    setup();

    print("Electronic Votng");

    setCursor(0, 1);

    print("Machine with RPI");

    delay(2000);

    clear();

    print("Circuit Digest");

    setCursor(0, 1);

    print("Welcomes You");

    delay(2000);

    clear();

    show();

    while (1)

    {

        digitalWrite(led5, HIGH);

        digitalWrite(in3, HIGH);

        if (digitalRead(in1) == 0)

        {

            vote1++;

            show();

            digitalWrite(led1, HIGH);

            buzzer();

            digitalWrite(led1, LOW);

            wait();
        }

        else if (digitalRead(in2) == 0)

        {

            vote2++;

            show();

            digitalWrite(led2, HIGH);

            buzzer();

            digitalWrite(led2, LOW);

            wait();

            while (digitalRead(in2) == 0)
                ;
        }

        else if (digitalRead(in3) == 0)

        {

            vote3++;

            show();

            digitalWrite(led3, HIGH);

            buzzer();

            digitalWrite(led3, LOW);

            wait();

            while (digitalRead(in3) == 0)
                ;
        }

        else if (digitalRead(in4) == 0)

        {

            vote4++;

            show();

            digitalWrite(led4, HIGH);

            buzzer();

            digitalWrite(led4, LOW);

            wait();

            while (digitalRead(in4) == 0)
                ;
        }

        else if (digitalRead(in5) == 0)

        {

            compare();

            while (digitalRead(in5) == 0)
                ;
        }
    }
}

void show()

{

    setCursor(0, 0);

    print("BJP Cong AAP Ex");

    setCursor(1, 1);

    sprintf(vote, "%d", vote1);

    print(vote);

    setCursor(6, 1);

    sprintf(vote, "%d", vote2);

    print(vote);

    setCursor(10, 1);

    sprintf(vote, "%d", vote3);

    print(vote);

    setCursor(14, 1);

    sprintf(vote, "%d", vote4);

    print(vote);

    delay(100);
}

void compare()

{

    clear();

    print("Please Wait....");

    wait();

    if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4)

    {

        digitalWrite(led1, HIGH);

        for (i = 0; i < 2; i++)

        {

            clear();

            setCursor(0, 0);

            print("Congrates.......");

            setCursor(0, 1);

            print("BJP Won election");

            delay(2000);

            clear();

            setCursor(0, 0);

            print("BJP Cong AAP Ex");

            setCursor(1, 1);

            sprintf(vote, "%d", vote1);

            print(vote);

            setCursor(6, 1);

            sprintf(vote, "%d", vote2);

            print(vote);

            setCursor(10, 1);

            sprintf(vote, "%d", vote3);

            print(vote);

            setCursor(14, 1);

            sprintf(vote, "%d", vote4);

            print(vote);

            delay(2000);
        }

        digitalWrite(led1, LOW);
    }

    else if (vote2 > vote1 && vote2 > vote3 && vote2 > vote4)

    {

        digitalWrite(led2, HIGH);

        for (i = 0; i < 2; i++)

        {

            clear();

            setCursor(0, 0);

            print("Congrates.......");

            setCursor(0, 1);

            print("Cong Won election");

            delay(2000);

            clear();

            setCursor(0, 0);

            print("BJP Cong AAP Ex");

            setCursor(1, 1);

            sprintf(vote, "%d", vote1);

            print(vote);

            setCursor(6, 1);

            sprintf(vote, "%d", vote2);

            print(vote);

            setCursor(10, 1);

            sprintf(vote, "%d", vote3);

            print(vote);

            setCursor(14, 1);

            sprintf(vote, "%d", vote4);

            print(vote);

            delay(2000);
        }

        digitalWrite(led2, LOW);
    }

    else if (vote3 > vote2 && vote3 > vote1 && vote3 > vote4)

    {

        digitalWrite(led3, HIGH);

        for (i = 0; i < 2; i++)

        {

            clear();

            setCursor(0, 0);

            print("Congrates.......");

            setCursor(0, 1);

            print("AAP Won election");

            delay(2000);

            clear();

            setCursor(0, 0);

            print("BJP Cong AAP Ex");

            setCursor(1, 1);

            sprintf(vote, "%d", vote1);

            print(vote);

            setCursor(6, 1);

            sprintf(vote, "%d", vote2);

            print(vote);

            setCursor(10, 1);

            sprintf(vote, "%d", vote3);

            print(vote);

            setCursor(14, 1);

            sprintf(vote, "%d", vote4);

            print(vote);

            delay(2000);
        }

        digitalWrite(led3, LOW);
    }

    else if (vote4 > vote2 && vote4 > vote3 && vote4 > vote1)

    {

        digitalWrite(led4, HIGH);

        for (i = 0; i < 2; i++)

        {

            clear();

            setCursor(0, 0);

            print("Congrates.......");

            setCursor(0, 1);

            print("Ex Won elections");

            delay(2000);

            clear();

            print("BJP Cong AAP Ex");

            setCursor(1, 1);

            sprintf(vote, "%d", vote1);

            print(vote);

            setCursor(6, 1);

            sprintf(vote, "%d", vote2);

            print(vote);

            setCursor(10, 1);

            sprintf(vote, "%d", vote3);

            print(vote);

            setCursor(14, 1);

            sprintf(vote, "%d", vote4);

            print(vote);

            delay(2000);
        }

        digitalWrite(led4, LOW);
    }

    else

    {

        for (i = 0; i < 2; i++)

        {

            clear();

            setCursor(0, 0);

            print("Tie Between Two ");

            setCursor(0, 1);

            print("or more Parties ");

            delay(2000);

            clear();

            print("BJP Cong AAP Ex");

            setCursor(1, 1);

            sprintf(vote, "%d", vote1);

            print(vote);

            setCursor(6, 1);

            sprintf(vote, "%d", vote2);

            print(vote);

            setCursor(10, 1);

            sprintf(vote, "%d", vote3);

            print(vote);

            setCursor(14, 1);

            sprintf(vote, "%d", vote4);

            print(vote);

            delay(2000);
        }
    }

    vote1 = 0;

    vote2 = 0;

    vote3 = 0;

    vote4 = 0;

    clear();

    show();
}