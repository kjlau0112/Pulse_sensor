//unsigned long data type: only computer data type that capable to store 32 bit of positive only integer.Min number is 0,max number of this variable is equal 2 power of 32

unsigned long startmillis=0; // declare startmillis in unsigned long data type, initial at zero
unsigned long lastmillis=0; // declare lastmililis in unsigned long data type, initial at zero
unsigned long calmillis=0; // declare calmillis in unsigned long data type, initial at zero
float BPM = 0; // delcare BPM in float data type , intial at 0 
const int pin =2;
bool state = false;
void setup() 
{
    Serial.begin(115200); // initial serial monitor at baud rate of 115200.For effectiveserial communication 
}

void loop()
{

// the easy pulse sensor output connect to digital pin to display digital output
/* As sensor output >> particular threshold let say 512, the digital pin will count as 1
else will count as 0 */

/*millis() library function--> a counter that count how many milisecond has passed once serial monitor start */

    //as output equal to 1, last millis = startmillis. at intial =0. If dtect another logic high lastmililis wil store previous logic low millis() value
    while(digitalRead(2)==1) 
    { 
        state = true;
        lastmillis=startmillis;
    }

    // startmilis() store value of millis() once it detect logic low(heart beat)
    while(digitalRead(2)==0) 
    {   
        state = false;
        startmillis=millis();
    }


    calmillis=startmillis-lastmillis; // different of these 2 variable correpond to heartbeat interval
    BPM=60000/calmillis;              // relation between BPM and heartbeat interval

    /*This serial arrangemnet is outputing variable in one dimension data type*/
    Serial.print(state);
    Serial.print(",");
    Serial.print(startmillis);
    Serial.print(",");
    Serial.print(lastmillis);
    Serial.print(",");
    Serial.print(calmillis);
    Serial.print(","); 
    Serial.println(BPM);

    delay_x(5); // delay 5 milisecond
}

void delay_x(uint32_t millis_delay)
{
    uint16_t micros_now = (uint16_t)micros();

    while (millis_delay > 0) 
    {
        if (((uint16_t)micros() - micros_now) >= 1000)
        {
            millis_delay--;
            micros_now += 1000;
        }
    }
}
