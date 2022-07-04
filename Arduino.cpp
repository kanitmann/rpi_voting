// Arduino based EVM Code

#define sw1 15
#define sw2 16
#define sw3 17
#define sw4 18
#define sw5 3
int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;
void setup()

{
    Serial.begin(9600);
    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
    pinMode(sw3, INPUT);
    pinMode(sw4, INPUT);
    pinMode(sw5, INPUT);
    Serial.println("Voting Machine");
    delay(3000);
    digitalWrite(sw1, HIGH);
    digitalWrite(sw2, HIGH);
    digitalWrite(sw3, HIGH);
    digitalWrite(sw4, HIGH);
    digitalWrite(sw5, HIGH);
}

void loop()

{
    if (digitalRead(sw1) == 0)
    {
        Serial.println("Vote Counted. Thanks for voting.");
        vote1++;
        delay(1000);
    }
    while (digitalRead(sw1) == 0)
        ;
    if (digitalRead(sw2) == 0)
    {
        Serial.println("Vote Counted. Thanks for voting.");
        vote2++;
        delay(1000);
    }
    while (digitalRead(sw2) == 0)
        ;
    if (digitalRead(sw3) == 0)
    {
        Serial.println("Vote Counted. Thanks for voting.");
        vote3++;
        delay(1000);
    }
    while (digitalRead(sw3) == 0)
        ;
    if (digitalRead(sw4) == 0)
    {
        Serial.println("Vote Counted. Thanks for voting.");
        vote4++;
        delay(1000);
    }
    while (digitalRead(sw4) == 0)
        ;
    if (digitalRead(sw5) == 0)
    {
        Serial.println("Results: ");
        int vote = vote1 + vote2 + vote3 + vote4;
        if (vote > 1)
        {
            if ((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
            {

                Serial.println("BJP Wins");
                delay(2000);
            }
            else if ((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
            {

                Serial.println("INC Wins");
                delay(2000);
            }
            else if ((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
            {

                Serial.println("AAP Wins");
                delay(2000);
            }
            else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
            {
                Serial.println("OTH Wins");
                delay(2000);
            }

            else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
            {
                Serial.println("OTH Wins");
                delay(2000);
            }
            else
            {

                Serial.println("   Tie Up Or   ");
                Serial.println("   No Result   ");
                delay(1000);
            }
        }
        else
        {

            Serial.println("No Voting....");
            delay(1000);
        }
        vote1 = 0;
        vote2 = 0;
        vote3 = 0;
        vote4 = 0, vote = 0;
    }
}