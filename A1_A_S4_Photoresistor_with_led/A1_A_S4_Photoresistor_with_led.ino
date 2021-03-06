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
    Описание: Схема 4 Прототип умного дома при помощи светодиода и фоторезистора

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 06.08.2015
*/

// Переменная с номером цифрового пина внешнего светодиода
int led_pin = 13; 

// Переменная с номером аналогового пина фоторезистора
int photo_res = 0; 

void setup()
{
  // Данная строка говорит нам о том, что цифровой пин настроен на выход
  // Для удобства работы цифра с номером пина занесена в переменную
  pinMode(led_pin, OUTPUT);
  
  // Данная строка означает инициализацию последовательного порта на скорости 9600 бод
  Serial.begin(9600);
}

void loop() 
{  
  // В структуре if else ниже реализуется  следующее.
  // Если показатель освещенности меньше 700, включаем светодиод, 
  // если выше, то выключаем. 
  // Попробуй менять данный параметр от 400 до 1024. 
  if (analogRead(photo_res) < 700) //Менять показатель освещенности здесь
  {
    digitalWrite(led_pin, HIGH); //Включаем светодиод
    // Выводим в монитор порта строку 
    Serial.println("Night");
    // Задержка в 100 милисекунд
    delay(100);
  }
  else
  {
    digitalWrite(led_pin, LOW); // В другом случае выключаем светодиод
    // Выводим в монитор порта строку
    Serial.println("Day");
    // Задержка в 100 милисекунд
    delay(100);
  }
  // Конец цикла.
  // Возврат в Начало программы.
}
