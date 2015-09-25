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
    Описание схемы: Схема 13 Отправка данных с датчика температуры c помощью облака Intel® IoT Dashboard

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 28.08.2015
*/
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

//This example reads the temperature sensor on the Galileo's
//onboard ADC, AD7298, using the iio (Industrial I/O) subsystem and 
//sends the observed data to the Intel IoTkit Cloud

//Prework:
//You need iotkit-agent installed and running.
//Device should be activated. (by running: iotkit-admin activate ACTIVATION_CODE)
//Following components should be registered (by running: iotkit-admin register NAME TYPE):
//temperature of type temperature.v1.0
//You can also use IoTkitRegisterExample to activate and register new components

/*
    http://www.maxxlife.by
    http://www.shop.maxxlife.by
    http://www.vk.com/cookrobot
    Copyright (c) 2015 Кухня роботов <maxxlife.by> All rights reserved.
    Copyright (c) Maxxlife Робот Maxxlife Robot All rights reserved.

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
    Описание схемы: Схема 13 Отправка данных с датчика температуры c помощью облака Intel® IoT Dashboard
    
    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 26.08.2015

    // Данная программа управляет светодиодом при помощи виртуального актуатора,
    // который зарегистрирован на устройстве

//Начальные Приготовления:
// 1. Устройство должно работать и находится в сети Wi-Fi
// 2. Агент должнен быть запущен
// 3. Компонент с именем "temperature" стандартного типа " temperature.v1.0"
// должен быть зарегистрирован на устройстве
*/

// Подключаем заголовочный файл IoTkit.h чтобы использовать Intel IoT Kit
#include <IoTkit.h>    

// Также необходимые заголовочные файлы
#include <Ethernet.h> 
#include <aJSON.h>

// Создается новый экземпляр iotkit класса IoTkit
IoTkit iotkit;        
int temp;

// Добавляем в программу библиотеку специальных математических функций
#include <math.h>

// Переменная в которой будет храниться значение, считанное с аналогового пина
int sensor_value = 0;

// Переменная в которой будет храниться истинное значение температуры
float temperature;
// Постоянное число термистора, взятое из спецификации данного термистора
int constant = 4300;

// Переменная для хранения значения сопротивление термистора,
// в зависимости от температуры 
float resistance;

void setup() {
  Serial.begin(9600);
  iotkit.begin();
  delay(10500);
}

void loop() {

  Serial.println("Reading temperature");
getTemp(); 
  Serial.print("Temperature is ");
  Serial.print(temperature);
  Serial.println(" degrees celcius.");

  iotkit.send("temperature", temperature);
  delay(2000);
}

// Функция по чтению датчика температуры
void getTemp()
{
 // Читаем аналоговый пин 0
  sensor_value = analogRead(0);

  // Высчитываем сопротивление термистора по специальной формуле
  resistance = (float)(1023 - sensor_value) * 10000 / sensor_value;

  // Находим истинную температуру по формуле, взятой из спецификации термистора
  temperature = 1 / (log(resistance / 10000) / constant + 1 / 298.15) - 273.15;
  // Задержка в 1 секунду перед следующим чтением значений термистора

}
