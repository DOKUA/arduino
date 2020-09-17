/*
  Name:		    Telerambot_Bredogenerator.ino
  Created:	    17/09/2020
  Author:	    Andrusevich Alex
  Description: simple "bredogenerator" - generator ideas for painteng
*/
#include "CTBot.h"
CTBot myBot;

String ssid = "DOM";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "0500327997"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "1364109062:AAFhJiRpLOWhQPmGU7bTJTZj6t4Hw5cWEgA";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN


long randNumber;

// who
const char* who[][50] =
{
  {"ангел", "1"},
  {"демон", "1"},
  {"парень", "1"},
  {"девушка", "2"},
  {"дракон", "1"},
  {"маг", "1"},
  {"ведьма", "2"},
  {"гоблин", "1"},
  {"скелет", "1"},
  {"зомби", "3"},
  {"воин", "1"},
  {"вампир", "1"},
  {"привидение", "3"},
  {"оборотень", "1"},
  {"инопланетянин", "1"},
  {"робот", "1"},
  {"киборг", "1"},
  {"рыцарь", "1"},
  {"динозавр", "1"},
  {"орк", "1"},
  {"друид", "1"},
  {"солдат", "1"},
  {"тролль", "1"},
  {"растение", "3"},
  {"осьминог", "1"},
  {"паук", "1"},
  {"обезьяна", "2"},
  {"лиса", "2"},
  {"мышь", "2"},
  {"армия", "2"},
  {"жук", "1"},
  {"черепаха", "2"}
};



//what
const char* what[][50] = {
  {"Большой ", "Большая ", "Большое "},
  {"Стимпанк ", "Стимпанк ", "Стимпанк "},
  {"Военный ", "Военная ", "Военное "},
  {"Киберпанк ", "Киберпанк ", "Киберпанк "},
  {"Бронированный ", "Бронированная ", "Бронированное "},
  {"Трусливый ", "Трусливая ", "Трусливое "},
  {"Маленький ", "Маленькая ", "Маленькое "},
  {"Худой ", "Худая ", "Худое "},
  {"Толстый ", "Толстая ", "Толстое "},
  {"Злой ", "Злая ", "Злое "},
  {"Добрый ", "Добрая ", "Доброе "},
  {"Каменный ", "Каменная ", "Каменное "},
  {"Хитрый ", "Хитрая ", "Хитрое "},
  {"Пугливый ", "Пугливая ", "Пугливое "},
  {"Тупой ", "Тупая ", "Тупое "},
  {"Мерзкий ", "Мерзкая ", "Мерзкое "},
  {"Скользкий ", "Скользкая ", "Скользкое "},
  {"Холодный ", "Холодная ", "Холодное "},
  {"Теплый ", "Теплая ", "Теплое "},
  {"Огненный ", "Огненная ", "Огненное "},
  {"Мокрый ", "Мокрая ", "Мокрое "},
  {"Горячий ", "Горячая ", "Горячее "},
  {"Снежный ", "Снежная ", "Снежное "},
  {"Седой ", "Седая ", "Седое "},
  {"Кисельный ", "Кисельная ", "Кисельное "},
  {"Темный ", "Темная ", "Темное "},
  {"Черный ", "Черная ", "Черное "},
  {"Чешуйчатый ", "Чешуйчатая ", "Чешуйчатое "},
  {"Бурый ", "Бурая ", "Бурое "},
  {"Сизый ", "Сизая ", "Сизое "},
  {"Грубый ", "Грубая ", "Грубое "},
  {"Шершавый ", "Шершавая ", "Шершавое "},
  {"Железный ", "Железная ", "Железное "},
  {"Стеклянный ", "Стеклянная ", "Стеклянное "},
  {"Деревянный ", "Деревянная ", "Деревянное "},
  {"Водянистый ", "Водянистая ", "Водянистое "},
  {"Пьяный ", "Пьяная ", "Пьяное "},
  {"Кибер-", "Кибер-", "Кибер-"},
  {"Гигантский ", "Гигантская ", "Гигантское "},
  {"Глупый ", "Глупая ", "Глупое "},
  {"Супер-", "Супер-", "Супер-"},
  {"Голый ", "Голая ", "Голое "},
  {"Магический ", "Магическая ", "Магическое "},
  {"Мультяшный ", "Мультяшная ", "Мультяшное "},
  {"Влюблённый ", "Влюблённая ", "Влюблённое "}
};

/*
 

 */



// what do
const char* doing[][50] = {
  {"бьющийся", "бьющаяся", "бьющееся"},
  {"бегущий", "бегущая", "бегущее"},
  {"стоящий", "стоящая", "стоящее"},
  {"лежащий", "лежащая", "лежащее"},
  {"сидящий", "сидящая", "сидящее"},
  {"летящий", "летящая", "летящее"},
  {"парящий", "парящая", "парящее"},
  {"падающий", "падающая", "падающее"},
  {"смотрящий", "смотрящая", "смотрящее"},
  {"идущий", "идущая", "идущее"},
  {"ползущий", "ползущая", "ползущее"},
  {"карабкающийся", "карабкающаяся", "карабкающееся"},
  {"продирается", "продирается", "продирается"},
  {"умирающий", "умирающая", "умирающее"},
  {"пылающий", "пылающая", "пылающее"},
  {"дерущийся", "дерущаяся", "дерущееся"},
  {"задумавшийся", "задумавшаяся", "задумавшееся"},
  {"работающий", "работающая", "работающее"},
  {"играющий", "играющая", "играющее"},
  {"прислушивающийся", "прислушивающаяся", "прислушивающееся"},
  {"спящий", "спящая", "спящее"},
  {"рыскающий", "рыскающая", "рыскающее"},
  {"пьющий", "пьющая", "пьющее"},
  {"принимающий пищу", "принимающая пищу", "принимающее пищу"},
  {"перенимающий опыт", "перенимающая опыт", "перенимающее опыт"},
  {"поющий", "поющая", "поющее"},
  {"взаимодействующий со следующей темой", "взаимодействующая со следующей темой", "взаимодействующее со следующей темой"},
  {"мстящий", "мстящая", "мстящее"},
  {"копающий", "копающая", "копающее"},
  {"заблудившийся", "заблудившаяся", "заблудившееся"},
  {"смеющийся", "смеющаяся", "смеющееся"},
  {"воскресающий из мёртвых", "воскресающая из мёртвых", "воскресающее из мёртвых"},
  {"плачущий", "плачущая", "плачущее"},
  {"торгующий", "торгующая", "торгующее"},
  {"двигающийся", "двигающаяся", "двигающееся"},
  {"висящий", "висящая", "висящее"},
  {"кричащий", "кричащая", "кричащее"},
  {"спешащий", "спешащая", "спешащее"},
  {"вертящийся", "вертящаяся", "вертящееся"},
  {"читающий книгу", "читающая книгу", "читающее книгу"},
  {"курящий трубку", "курящая трубку", "курящее трубку"},
  {"гуляющий", "гуляющая", "гуляющее"},
  {"дрожащий", "дрожащая", "дрожащее"},
  {"плывущий", "плывущая", "плывущее"}
};

//where
const char* where[] =
{
  "на ветру",
  "в огне",
  "в воде",
  "в воздухе",
  "на поле боя",
  "в горах",
  "в замке",
  "на берегу моря",
  "в пустыне",
  "на камне",
  "в пещере",
  "зимой",
  "под мостом",
  "под одеялом",
  "на крыше",
  "в лесу",
  "на коне",
  "в автомобиле",
  "на слоне",
  "на похоронах",
  "на дискотеке",
  "в ресторане",
  "в тюрьме",
  "в космосе",
  "на северном олене",
  "за компьютером",
  "в электрических разрядах",
  "в снег",
  "в дождь",
  "в призрачном сиянии",
  "с колбасой",
  "с мешком",
  "над пропастью",
  "в городе",
  "по дороге",
  "утром",
  "ночью",
  "на научном собрании",
  "в фантастических структурах",
  "в крови",
  "на куче золота",
  "в страхе",
  "в детстве",
  "на свадьбе",
  "в цирке",
  "на волнах",
  "под землёй",
  "в пустошах",
  "в лаборатории"
};


void setup() {

  Serial.begin(115200);   // initialize the Serial
  randomSeed(analogRead(0)); // random Seed get from analog
  Serial.println("Starting TelegramBot..."); //echo about telegram bot
  myBot.wifiConnect(ssid, pass);  // connect the ESP8266 to the desired access point
  myBot.setTelegramToken(token); // set the telegram bot token

  if (myBot.testConnection()) // check if all things are ok
    Serial.println("\All ok bro! Telegram bot connected!");
  else
    Serial.println("\I can connect Man!");



}

void loop() {

  TBMessage msg; // a variable to store telegram message data

  if (myBot.getNewMessage(msg)) // if there is an incoming message...
  {
    Serial.println("\I get massage!!");

    int getLengthArrayWho =  sizeof(who) / sizeof(who[0]);
    int getLengthArrayWhat = sizeof(what) / sizeof(what[0]);
    int getLengthArrayDoing = sizeof(doing) / sizeof(doing[0]);
    int getLengthArrayWhere = sizeof(where) / sizeof(where[0]);

    int getRandomFromWho = random(getLengthArrayWho) - 1;
    int getRandomFromWhat = random(getLengthArrayWhat) - 1;
    int getRandomFromDoing = random(getLengthArrayDoing) - 1;
    int getRandomFromWhere = random(getLengthArrayWhere) - 1;

    const char* secondCell = who[getRandomFromWho][1];
    int getIngex = myMultiplyFunction(secondCell);

    Serial.println(who[getRandomFromWho][0]); // 
    Serial.println(what[getRandomFromWhat][getIngex]);
    Serial.println(doing[getRandomFromDoing][getIngex]);
    Serial.println(where[getRandomFromWhere]);



   


    randNumber = random(300);//generate random number
    myBot.sendMessage(msg.sender.id, "Попробуй нарисуй - " +String(what[getRandomFromWhat][getIngex])+" "+ String(who[getRandomFromWho][0])+" "+ String(doing[getRandomFromDoing][getIngex])+" "+ String(where[getRandomFromWhere])); // ...forward it to the sender
    Serial.println("\I send" + String(randNumber));
    delay(500);// wait 500 milliseconds
  }

}

 int myMultiplyFunction(const char* input) {
      int result;
      if (input == "1")
      {
        result = 0;
        return result;
      }
      else if (input == "2")
      {
        result = 1;
        return result;
      }
      else if (input == "3")
      {
        result = 2;
        return result;
      }
    }
