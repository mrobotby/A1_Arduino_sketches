void setup()
{
  // Инициализируем последовательный порт на скорости 9600 бод.
  Serial.begin(9600);
}

void loop()
{
  /* Выводим на экран строку с текстом Hello World и переходит на новую строку */
  Serial.println("Hello World");

  /* delay(1000) создает задержку в 1 секунду либо 1000мс. Функция принимает значения только миллисекундах */
  delay(1000);
}

