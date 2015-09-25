/*
    http://www.mrobot.by
    http://www.maxxlife.by
    http://www.vk.com/cookrobot
    Copyright (c) Кухня роботов <maxxlife.by> All rights reserved.
    Copyright (c) Макслайф Робот Maxxlife Robot All rights reserved.

    Наши лаборатории по робототехнике:
    Ленинская РОС ДОСААФ, ул. Рокоссовского 63/2, Минск, Беларусь
    Подробнее в нашей группе Вконтакте http://www.vk.com/cookrobot
    И на сайте http://www.maxxlife.by

    ****************************************************
    Мы всегда рады новым членам нашего сообщества Кухня Роботов.
    У нас есть бесплатные вводные курсы, где мы объясняем
    как работать с нашими образовательными наборами по робототехнике и электронике.
    ****************************************************

    Название набора: Набор Роботов А1
    Описание:

    Программа создана и протестирована разработчиком:
    Имя1: Tom Igoe
    Имя2: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 18.09.2015
*/
#include <WiFi.h>


//*************************************************************//
// ЗДЕСЬ УСТАНАВЛИВАЕТСЯ ИМЯ СЕТИ  И ПАРОЛЬ
/* Это пример. 
Допустим имя твоей сети WORLD 
А пароль от твоей сети 12345678
Тогда в коде это будет выглядеть так
char ssid[] = "WORLD";  //  Имя (SSID) твоей сети Wi-Fi (двойные кавычки не относятся к имени)
char pass[] = "12345678";  // Пароль от твоей сети Wi-Fi(двойные кавычки не относятся к сети)
*/
// Поставь между двойных кавычек имя своей сети и пароль
char ssid[] = "";  //  Имя (SSID) твоей сети Wi-Fi (двойные кавычки не относятся к имени)
char pass[] = "";  // Пароль от твоей сети Wi-Fi(двойные кавычки не относятся к сети)
//*************************************************************//

int keyIndex = 0; // Key index твоей сети( нужен только для WEP)

int status = WL_IDLE_STATUS;

// Номер порта на плате, к которому будет идти обращение
WiFiServer server(69);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  // Попытка подключения к сети Wi-Fi
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // Вывод в монитор последовательного порта имя сети(SSID);

    // Покдлючение к WPA/WPA2 сети
    status = WiFi.begin(ssid, pass);
    // Ожидание 10 секунд для подключения к сети
    delay(10000);
  }
  // Запуск веб-сервера на 69 порту
  server.begin();

  // После того как ты подключен к сети
  // Вызывается функция, которая выводит на экран все данные про сеть Wi-Fi
  // Это имя подключеной сети, IP-адрес, уровень сигнал
  printWifiStatus();

}

void loop() {
  // Слушаем порт на наличие новых клиентов
  WiFiClient client = server.available();

  // Если получен новых клиент
  if (client) {
    // Выводится сообщение на экран о наличии нового клиента    // if you get a client,
    Serial.println("new client");
    // Создание строки для хранения входящей информации от клиента
    String currentLine = "";
    // While==loop Создание бесконечного цикла до тех пор пока клиент подключен
    while (client.connected()) {
      // Если  существует входящая информация от клиента в виде байтов
      if (client.available()) {
        // То читаешь первый байт
        char c = client.read();
        // Потом выводится принятый символ на экран
        Serial.write(c);
        // Если принятый символ является символом новой строки \n
        if (c == '\n') {
          // Если текущая строка пустая, то ты получил два символа новой строки подряд.

          // Это конец HTTP запроса клиента, поэтому посылай ответ
          if (currentLine.length() == 0) {

            // HTTP заголовки всегда начинаются с ответного кода (HTTP/1.1 200 OK)
            // и типа-контента (Content-type:text/html), чтобы клиент знал, какая информация приходит
            // а потом отправляется пустая строка
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // Контент HTTP ответа всегда следует за заголовком
            // Это ссылки при помощи которых можно управлять светодиодом
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 13 on<br>"); // Включение светодиода
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 13 off<br>"); // Выключение светодиода


            // HTTP ответ заканчивается пустой строкой
            client.println();
            // Преывай бесконечный цикл командой break, тем самым ты выходишь из while
            break;
          }
          else {
            // Если ты получил новую строку, тогда очищай переменную currentLine
            // чтобы можно было записать новую строку.
            currentLine = "";
          }
        }
        else if (c != '\r') {    // Если ты получил другой символ, но не символ возврата каретки \r
          currentLine += c;      // Добавляй данный символ к строке
        }

        // Проверка, что запрос клиента оканчивается на "GET /H" или "GET /L"
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(13, HIGH); // Включение светодиода
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(13, LOW); // Выключение светодиода
        }

      }
    }
    // Завершение соединения
    client.stop();
    Serial.println("client disonnected");
  }
}

// Функция по выводу статуса Wi-Fi
void printWifiStatus()
{
  // Вывод на экран SSID сети
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Вывод на экран IP-адреса платы
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // Вывод на экран уровня сигнала
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // Вывод на экран адреса, который необходимо открыть в браузере
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
