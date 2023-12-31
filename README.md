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

![370244699_629194982619261_677028939690871015_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/482b0c28-b5e9-401b-bbf1-ebeb34dabebb)

![387578393_1013941186486639_150111337501593315_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/fa268a4d-fcd0-45d6-a648-1dfad29c89a8)


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
> Video ligger inde i projektmappen

---

### 31-8-23
#### Rettelser til kode og kig på WIFI
**Hvad lavede vi/jeg?**

Vi sad og kiggede lidt på noget wifi, men os der ikke havde lavet lyskryds færdigt skulle lave det færdigt. Jeg fik lavet det semi færdigt ( dvs indtil det lyste semi godt ) og så gik jeg videre til min servo motor opgave, da jeg havde opdaget at der var en fejl. Jeg fik rettet lidt på mine switch case, og fandt ud af, at hvis der ikke ligger en case under min 180 grader case, så kører den slet ikke 180 grader. Jeg ved ikke hvorfor, men jeg finder nok ud af det på et andet tidspunkt når vi skal lege mere med motorer mm.

> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/ServoStyringMashine


---

### 5-9-23
#### 3D Printer og vores egen lille figur
**Hvad lavede vi/jeg?**

I dag fik vi kigget på Tobias' nye 3D printer, fik sat den op og fik set den printe et par ting. Resten af timen arbejdede vi med JavaCSG, og fik gjort et forsøg i at lave vores egen lille figur ved hjælp af Java og OpenSCAD. Tobias' havde lavet et java projekt som omsatte java til OpenSCAD, så man vha. java som vi kender, kunne lave forskellige figurer mm. ( Jeg tror jeg ved en fejl har slettet projektet desværre )

---
### 7-9-23
#### Mere 3D print og opsætning med JitPack
**Hvad lavede vi/jeg?**

I dag fik vi kigget på 3D print, og fik sat vores projekt op med JitPack, så det er nemmere at lave projekter i fremtiden. Vi fik lavet en lille "holder" til vores NodeMCU som vi kan 3D printe hvis vi vil. Derudover arbejdede vi lidt videre med vores egen lille figur.

---
### 12-9-23
#### Togskinnesnak og første modellering på vores clicker
**Hvad lavede vi/jeg?**

I dag fik vi snakket om vores fremtidige projekt, nemlig togprojektet. Vi skal samlet i klassen lave et projekt, hvor vi designer en togbane og et tog. I dag fik vi snakket om projektet og startet på modellering af en clicker til togsystemet, så man kan sætte forskellige dele sammen. 

---
### 15-9-23
#### Mere modellering af clicker
**Hvad lavede vi/jeg?**

I dag sad vi og designede vores clicker og fik sat de rigtige mål på. Vi fik indblik i at det tager lang tid at 3D printe den helt rigtige, da man skal printe og rette til indtil man får det færdige produkt. Vi fik lavet en clicker med de rette mål.

---
### 19-9-23
#### Interface design af upscaling af clicker
**Hvad lavede vi/jeg?**

I dag skulle vi sidde og designe et interface, så det er muligt at upscale vores clicker.

---
### 22-9-23
#### Snak om vores projekt
**Hvad lavede vi/jeg?**

Vi er gruppen Jamie, Isak, Lucas, Matias og Marcus. Drengene havde fået en ide, om at tog-projektet skulle have en togstation, hvorpå der er en maskine, som automatisk hælder en øl op i et glas. Så det sad vi og modellerede hele denne time, men fandt så ud af at tog-projektet blev skrottet.
Derfor fandt vi på en ny ide: Vi ville lave en automatisk maskine, der kan få vin ud af papvine. Vi begyndte at tegne på tavlen og snakke om funktionaliteter og skrev ned hvilke dele vi ville have med.

---
### 26-9-23
#### Design af NodeMCU holder og lidt design af klo'en
**Hvad lavede vi/jeg?**

I dag fik vi designet vores NodeMCU holder med clicker huller i, som vi fik 3D printet. Derudover startede vi også på at få designet klo'en, som vi så skulle arbejde videre på på fredag.

![370310352_850192706808958_8156313519454143636_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/6232b5f6-4183-44a9-86a4-c4c29e6df213)


---
### 29-9-23
#### Design på vores projekt
**Hvad lavede vi/jeg?**

I dag sad jeg og lavede en holder til vores moist sensor. Jeg arbejdede denne dag, med at lave en lille holder der kan sættes i vores kopholder, hvor man også kan sætte en clicker i, som sidder på moist sensor holdere.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/MoistSensorHolder 

![387594608_859254502103019_4809025313250454214_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/3d4ac504-f5a4-45e9-bfc2-24823a90e0b2)


---
### 3-10-23
#### Design af moist sensor holder
**Hvad lavede vi/jeg?**

I dag sad jeg og designede selve holderen til moist sensoren. Jeg fik lavet flere versioner, så vores sensor kan sidde i den uden at kunne bevæge sig særlig meget.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/MoistSensorHolder

![387506975_882031683490264_4979207042801969898_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/32d6f6d8-fe18-406d-a60c-e7e23e1ef249)


---
### 6-10-23
#### Interface design af upscaling af clicker
**Hvad lavede vi/jeg?**

I dag lavede jeg nogle små konfigurationer til vores holder. Vi fandt blandt andet ud af at selve clickeren skulle sidde længere oppe, så moist sensoren var langt nok nede i koppen så den kan måle ordentligt.
> https://github.com/HelenaLykstoft/LogbogROA2023/tree/main/MoistSensorHolder

![385507106_274078234946738_2224950459691850403_n](https://github.com/HelenaLykstoft/LogbogROA2023/assets/99395714/85eb1402-be42-4d45-9ef0-b53dc0b9a005)


---
### 10-10-23
#### Liste over alle delene i vores projekt
**Hvad lavede vi/jeg?**

I dag arbejdede vi videre på projektet, og jeg sad imens og arbejdede på en liste over alle de små dele vi har med i projektet. Derudover fik jeg også sat billeder ind, så vi alle har et dokument med beskrivelse af alle de ting vi har printet og kodet.

---
### 13-10-23
#### Samling af projekt og finishing touches
**Hvad lavede vi/jeg?**

I dag arbejdede jeg videre med at lave listen over alle smådelene. Vi fik set på vores top til vin boxen, og fik snakket om hvordan vi kunne forbedre diverse ting på vores projekt. Derudover fik vi sendt vores dokumenter til hinanden, så alle havde de forskellige dokumenter.
Siden det var den sidste dag på projektet, besluttede vi os for at vi kun lige kunne nå at printe en mindre version af vores spole. 
Efter spolen var printet, fandt vi ud af at den godt kunne trække vingerne på tappen op, så det eneste vi manglede i projektet var, at lave en holder der holder tappen nede.

https://docs.google.com/document/d/1Qdy9rymkQDqa-A6k5qWYjjIZJg-isTXW7hQO67arWY4/edit?usp=sharing
