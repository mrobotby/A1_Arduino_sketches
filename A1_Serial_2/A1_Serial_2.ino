void setup()
{
  // Инициализируем последовательный порт на скорости 9600 бод.
  Serial.begin(9600);
}

void loop()
{
  /* Создаем целочисленную переменную под названием peremenaya типа int */
  int peremenaya = 19;

  /* Выводим на экран значение переменной и переходим на новую строку */
  Serial.println(peremenaya);

  /* delay(1000) создает задержку в 1 секунду либо 1000мс. Функция принимает значения только миллисекундах */
  delay(1000);
}
