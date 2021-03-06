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
    Описание: Схема 9 Создание музыкального инструмента

    Программа создана и протестирована разработчиком:
    Имя: Максим Массальский,amperka.ru
    Ник: maxxlife
    E-mail: maxxliferobot@gmail.com
    Дата разработки: 22.08.2015
*/

// Переменная с номером аналогового пина фоторезистора
int photores_pin = 0;
// Переменная с номером цифрового пина пьезоэлемента
int speaker_pin = 9;

// Переменная в которой будет храниться значение, считанное с аналогового пина
int sensor_value;

// Значение звука пьезоэлемента
int frequency;

void setup()
{
  // Цифровой пин c пьезоэлементом настроен на выход
  pinMode(speaker_pin, OUTPUT);
}

void loop()
{
  // Читаем аналоговый пин 0
  sensor_value = analogRead(photores_pin);

  // Рассчитываем частоту звучания пищалки в герцах (ноту),
  // используя функцию проекции map. Она отображает
  // значение из одного диапазона на другой, строя пропорцию.
  // В нашем случае [0; 1023] -> [261; 523].  
  // Так мы получим частоту от 261 Гц до 523 Гц,
  // что соответствует ноте До первой октавы и ноте До второй октавы
  // Диапазон можно расширять. Например от 2000 до 3000.
  // Экспериментируй
  frequency = map(sensor_value, 0, 1023, 261,523);

  // Заставляем пин с пищалкой «вибрировать», т.е. звучать
  // (англ. tone) на заданной частоте 20 миллисекунд. При
  // cледующих циклах, функция tone будет вызвана снова и снова,
  // и на самом деле мы услышим непрерывный звук тональности, которая
  // зависит от количества света, падающего на фоторезистор.
  tone(speaker_pin, frequency, 20);
  
}
