/*
Copyright (c) 2015, Intel Corporation

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
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
    Описание схемы: Схема 12 Управление светодиодом с помощью облака Intel® IoT Dashboard

    // Данная программа управляет светодиодом при помощи виртуального актуатора,
    // который зарегистрирован на устройстве

//Начальные Приготовления:
// 1. Устройство должно работать и находится в сети Wi-Fi
// 2. Агент должнен быть запущен
// 3. Компонент с именем "power" стандартного типа "powerswitch.v1.0"
// должен быть зарегистрирован на устройстве
// Когда отправляется от сервиса IoT Dashboard из раздела Control команда с величиной 0,
// светодиод выключается.
// Когда отправляется от сервиса IoT Dashboard из раздела Control команда с величиной 1,
// светодиод включается.

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 26.08.2015

*/
// Подключаем заголовочный файл IoTkit.h чтобы использовать Intel IoT Kit
#include <IoTkit.h>    

// Также необходимые заголовочные файлы
#include <Ethernet.h>  
#include <aJSON.h>
#include <stdio.h>

// Создается новый экземпляр iotkit класса IoTkit
IoTkit iotkit;

void setup() {
  Serial.begin(115200);
  
// Вызываем запуск метода экземпляра iotkit,
// перед тем как вызывать другие методы
  iotkit.begin();
  // Обязательная задержка, что дать время на инициализацию
  delay(10500);
// Тестовая отправка значения, сигнализирующее об успешной инициализации
  iotkit.send("power", 1);
}

void loop() 
{
   //Полностью рабочая версия 260815
  iotkit.receive(callback);
  delay(5000);
}

void callback(char* json) {
  Serial.println(json);
  aJsonObject* parsed = aJson.parse(json);
  if (&parsed == NULL) {
    // invalid or empty JSON
    Serial.println("recieved invalid JSON");
    return;
  }

  aJsonObject* component = aJson.getObjectItem(parsed, "component");
  aJsonObject* command = aJson.getObjectItem(parsed, "command");
  aJsonObject* argv = aJson.getObjectItem(parsed, "argv");
  aJsonObject* argvArray = argv->child;
  aJsonObject* name = argvArray->child; // name : on
  aJsonObject* value = name->next; // value: 1/0

  if ((component != NULL)) {
    if (strcmp(component->valuestring, "power") == 0) {
      if ((command != NULL)) {
        if (strcmp(command->valuestring, "LED.v1.0") == 0 && strcmp(value->valuestring, "0") == 0) {
          Serial.println("Light OFF!");
          pinMode(13, OUTPUT);
          digitalWrite(13, false);
        }
        if (strcmp(command->valuestring, "LED.v1.0") == 0 && strcmp(value->valuestring, "1") == 0) {
          Serial.println("Light ON!");
          pinMode(13, OUTPUT);
          digitalWrite(13, true);
        }
      }
    }
  }
}
