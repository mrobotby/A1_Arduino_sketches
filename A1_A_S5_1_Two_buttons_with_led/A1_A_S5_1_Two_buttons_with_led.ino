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
    Описание схемы: Схема 5.1 Включение и выключение светодиода при помощи двух кнопок

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 14.08.2015
*/

//Переменная с номером цифрового пина внешнего светодиода
int led_pin = 13;
//Переменная с номером цифрового пина кнопки
int button_pin_1 = 4;
int button_pin_2 = 3;

//Переменная в которой хранится состояние кнопки
int button_state = 0;

// Переменная типа bool, которая изменяет свое значение,
// в зависимости от того, какая кнопка была включена.
// Благодаря этой переменной циклы if могут принимать верные решения
bool mark = 0;

void setup()
{
  // Данная строка говорит нам о том, что цифровой пин настроен на выход
  // Для удобства работы цифра с номером пина занесена в переменную
  pinMode(led_pin, OUTPUT);

  // Данная строка говорит нам о том, что цифровой пин настроен на вход
  pinMode(button_pin_1, INPUT);
  pinMode(button_pin_2, INPUT);

  // Данная строка означает инициализацию
  // последовательного порта на скорости 9600 бод
  Serial.begin(9600);
}

void loop()
{
  // Читаем состояние цифрового пина одновременно принимая решение
  if ((digitalRead(button_pin_1) == HIGH) && (mark == 0))
  {
    //В другом случае выключаем светодиод
    digitalWrite(led_pin, HIGH);
    Serial.println("Led is ON");
    mark = 1;
  }
  if ((digitalRead(button_pin_2) == HIGH) && (mark == 1))
  {
    mark = 0;
    //В другом случае выключаем светодиод
    digitalWrite(led_pin, LOW);
    Serial.println("Led is OFF");
  }
  delay(100);
  //Конец цикла.
  //Возврат в Начало программы.

}
