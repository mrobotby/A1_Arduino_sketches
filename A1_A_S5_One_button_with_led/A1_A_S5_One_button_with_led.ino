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
    Описание схемы: Схема 5 Включение и выключение светодиода при помощи кнопки

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 14.08.2015
*/

//Переменная с номером цифрового пина внешнего светодиода
int led_pin = 13;
//Переменная с номером цифрового пина кнопки
int button_pin = 4;

//Переменная в которой хранится состояние кнопки
int button_state = 0;

void setup()
{
  // Данная строка говорит нам о том, что цифровой пин настроен на выход
  // Для удобства работы цифра с номером пина занесена в переменную
  pinMode(led_pin, OUTPUT);

  // Данная строка говорит нам о том, что цифровой пин настроен на вход
  pinMode(button_pin, INPUT);

  // Данная строка означает инициализацию последовательного порта на скорости 9600 бод
  Serial.begin(9600);
}

void loop()
{
  // Читаем состояние цифрового пина 
  button_state = digitalRead(button_pin);

  // В структуре if else ниже реализуется  следующее.
  // Если в переменной значение 1, то есть HIGH, то включить светодиод.
  // В другом случае выключить
  if (button_state == HIGH)
  {
    // Включаем светодиод
    digitalWrite(led_pin, HIGH);

    // Выводим в монитор порта строку
    Serial.println("Led is ON");
  }
  else
  {
    // В другом случае выключаем светодиод
    digitalWrite(led_pin, LOW);

    // Выводим в монитор порта строку
    Serial.println("Led is OFF");
  }
  // Задержка перед следующим циклом программы 50 мс
  delay(50);
  //Конец цикла.
  //Возврат в Начало программы.
}
