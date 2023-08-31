# LogbogROA2023

> Dette er Helena Botn Lykstoft's logbog fra Robotter og automatisering. Logbogen blev startet den første time, 21-8-23.

---
### 21-8-23
#### Opstart på ROA og MyFirstNodeMCU projekt
**Hvad lavede vi/jeg?**

I dag havde vi opstart på ROA. Vi fik lært at få LED lys til at lyse på vores NodeMCU'er. Derudover lavede vi ikke så meget andet end at få basis informationer og fik snakket lidt i gruppen om hvilket stort projekt vi vil forsøge at lave.
Jeg fik lavet opgaven "MyFirstNodeMCU", som fik en LED lampe til at tænde og slukke på NodeMCU'en. Derudover fik vi også begge LED lamper til at blinke forskudt af hinanden.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/MyFirstNodeMCU 

---
### 25-8-23
#### Volt og Simple Traffic Light projekt
**Hvad lavede vi/jeg?**

I dag arbejdede vi på strøm. Vi fik snakket om volt og hvor mange volt vores NodeMCU måtte få ( mellem 4.5 og 10 ). Derudover arbejdede vi videre på vores MyFirstNodeMCU projekt, og fik lavet klasser inde i lib, som hedder SimpleLED. Derudover fik vi også en opgave for, som var Trafiklysopgaven.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/SimpleTraficLight

---
### 28-8-23
#### Simple Traffic Light projekt
**Hvad lavede vi/jeg?**

I dag fik jeg startet ordentligt på min trafiklysopgave. Jeg undersøgte hvordan man brugte states, og fandt ud af at man kunne bruge switch cases sammen med states, så det legede jeg lidt med. Jeg endte dog kun med at få de gule og grønne lamper til at lyse uafbrudt, så jeg valgte at vente til at spørge Tobias om hjælp.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/SimpleTraficLight

---
### 29-8-23
#### Knap, pullup, pulldown og ButtonLight projekt
**Hvad lavede vi/jeg?**

I dag arbejdede vi med at få en knap til at virke. Vi fik snakket om pullup og pulldown og fik lavet et lille projekt med en knap. Meningen var at vi skulle få et lys til at blinke, og derfor hedder filen ButtonLight, men vi ændrede det så vi istedet for skulle begynde på et projekt med en ServoMotor som vi begyndte på dagen efter.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/ButtonLight

---
### 30-8-23
#### ServoMachine projekt
**Hvad lavede vi/jeg?**

I dag begyndte jeg på mit ServoMachine projekt. Jeg fandt en kode på nettet, som fik servo motoren til at dreje, som jeg skrev ind i min kode til at starte med: 
Oprindelig kode:
#include <Servo.h>
 
Servo servo;
 
void setup() {
    servo.attach(D1);
    servo.write(0);
    delay(2000);
}
 
void loop() {
    servo.write(0);
    delay(3000);
    servo.write(90);
    delay(3000);
    servo.write(180);
    delay(3000);
}

Fra <https://www.techcoil.com/blog/how-to-control-a-sg90-servo-motor-with-the-esp8266-nodemcu-lua-development-board/> 

Derefter forsøgte jeg at få motoren til at dreje til -90, men det virkede ikke. Den kunne kun dreje 180 grader. Jeg så dog at den ikke helt drejede 180 grader men mere 150, så jeg fik sat ind i servo.attach at den skulle have pin, og så 500,2400. Beregningen fandt Isak og Jamie på en hjemmeside, som en mand fandt ud af fik servoen til at dreje helt til 180 grader.

Jeg arbejdede videre med at få sat det ind i klasser, så koden var opdelt og der ikke stod alt i main. Jeg fik brugt enum til at lave nogle forskellige states i de private variabler i header filen, og derefter fik jeg lavet en cpp fil, som håndterede switch casen så jeg kunne få sat mine states ind. Og det virkede så.

Jeg havde dog stadig delays med i min main, så min næste opgave var at arbejde på at få fjernet delaysne i min main, og få lavet delays i min switch case.

Jeg fik brugt millis og lavede en _lastInputTime som jeg fik til at stige hver gang jeg lavede en case, hvilket gjorde at jeg ikke havde brug for at bruge delay.

> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/ServoStyringMashine

---

### 31-8-23
#### Rettelser til kode og kig på WIFI
**Hvad lavede vi/jeg?**

Vi sad og kiggede lidt på noget wifi, men os der ikke havde lavet lyskryds færdigt skulle lave det færdigt. Jeg fik lavet det semi færdigt ( dvs indtil det lyste semi godt ) og så gik jeg videre til min servo motor opgave, da jeg havde opdaget at der var en fejl. Jeg fik rettet lidt på mine switch case, og fandt ud af, at hvis der ikke ligger en case under min 180 grader case, så kører den slet ikke 180 grader. Jeg ved ikke hvorfor, men jeg finder nok ud af det på et andet tidspunkt når vi skal lege mere med motorer mm.

> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/ServoStyringMashine

--- 

