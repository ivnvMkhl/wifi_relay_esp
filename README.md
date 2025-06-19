# WIFI Relay on ESP-01

Прошика для контроллера ESP-01 для создания WIFI реле

Контроллер ESP-01 - [DataSheet](https://academy.cba.mit.edu/classes/networking_communications/ESP8266/esp01.pdf)

Реле модуль для ESP-01 - [DataSheet](https://cdck-file-uploads-europe1.s3.dualstack.eu-west-1.amazonaws.com/arduino/original/3X/1/e/1e40ca822608d35e41de63f73112c4a2624720bc.pdf)

# Project

Версия Python >= 3

При клонировании репозитория создайте новое Python окружение:

```bash
python3 -m venv venv
```

Переключитесь на окручение:

```bash
source venv/bin/activate
```

Установите зависимости из requirements.txt:

```bash
pip install -r requirements.txt
```

Установите зависимости PlatformIO

```bash
pio lib install
```

Билд проекта и запись в устройство

```bash
./build.sh
```

Если запись не проходит то требуется доступ до порта

```bash
sudo chmod 666 /dev/ttyUSB0
```
