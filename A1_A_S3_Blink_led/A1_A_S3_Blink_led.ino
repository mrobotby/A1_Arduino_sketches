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
    Описание: Схема 3 Моргание внешним светодиодом

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 31.07.2015
*/

// Функция setup() выполняется каждый раз, когда будет перезапущена подача питания
// или будет произведена перезагрузка платы IntelEdison
void setup()
{
  // Данная строка говорит нам о том, что 13 цифровой пин (D13) настроен на выход
  pinMode(13, OUTPUT);
  // Данная строка означает инициализацию последовательного порта на скорости 9600 бод
  Serial.begin(9600);
}

void loop()
{
  // Начало программы

  // Это говорит нам о том, что на цифровой пин 13 подано напряжение +5В,
  // он принял значение HIGH
  digitalWrite(13, HIGH);

  // Выводим в монитор порта строку
  Serial.println("Light is ON");

  // delay(1000) создает задержку в 1 секунду либо 1000мс.
  // Функция принимает значения только миллисекундах
  // На протяжении одной секунды светодиод будет гореть.
  delay(1000);

  // А это говорит нам о том, что на цифровом пине под номером 13 напряжения нет,
  // он принял значение LOW 
  digitalWrite(13, LOW);

  // Выводим в монитор порта строку
  Serial.println("Light is OFF");

  // На протяжении одной секунды светодиод будет НЕ гореть.
  delay(1000);

  // Конец цикла.
  // Возврат в Начало программы.
}