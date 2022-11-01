#include <analogWrite.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wifi network station credentials
#define WIFI_SSID "ORT-IoT"
#define WIFI_PASSWORD "OrtIOTnew22$"

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5378092899:AAEor-_KRMtH3b79qSGTCQChZN_aWmR2riE"
#define CHAT_ID "5277605219"

// Motor A
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 14;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

String formattedDate;
String dayStamp;
String timeStamp;

WiFiClientSecure secured_client;

UniversalTelegramBot bot(BOT_TOKEN, secured_client);

const unsigned long BOT_MTBS = 1000; // mean time between scan messages
unsigned long bot_lasttime; // last time messages' scan has been done

const int ledPin = 2;
bool ledState = LOW;

void handleNewMessages (int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String (numNewMessages));
  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID )
    {
      //bot.sendMessage(chat_id, "Unauthorized user", "");
    }
    else
    {
      String text = bot.messages[i].text;
      String from_name = bot.messages[i].from_name;
      if (from_name == "") {
        from_name = "Guest";
      }
      if (text == "/start") {
        String welcome = "DHTxx sensor readings.\n";
        welcome += "Use the following commands to control your outputs.\n\n";
        welcome += "/led_on to turn GPIO ON \n";
        welcome += "/led_off to turn GPIO OFF \n";
        welcome += "/time para que te de la hora y fecha :) \n";
        welcome += "/state to request current GPIO state \n";
        welcome += "/readings \n";
        bot.sendMessage(chat_id, welcome, "Markdown");
      }
      if (text == "/led_on") {
        bot.sendMessage(chat_id, "LED state set to ON", "");
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
      }
      if (text == "/led_off") {
        bot.sendMessage(chat_id, "LED state set to OFF", "");
        ledState = LOW;
        digitalWrite(ledPin, ledState);
      }
      if (text == "/prender_motor") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(5000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }
      
      if (text == "/Inicio") {
        String mascotas = "Bienvenido al Alimentador de Mascotas del Equipo alfa buena maravilla onda dinamita escuadron lobo.\n";
        mascotas += "Usa los siguientes comandos para elegir su mascota.\n\n";
        mascotas += "/PerroC para perros chicos. \n";
        mascotas += "/PerroM para perros medianos. \n";
        mascotas += "/PerroG para perros grandes. \n";
        mascotas += "/GatoC para gatos chicos. \n";
        mascotas += "/GatoM para gatos medianos. \n";
        mascotas += "/GatoG para gatos grandes. \n";
        
        bot.sendMessage(chat_id, mascotas, "Markdown");
      }
      
      if (text == "/PerroC") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(5000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }

      if (text == "/PerroM") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(8000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }

      if (text == "/PerroG") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(12000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }

      if (text == "/GatoC") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(2000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }

      if (text == "/GatoM") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(5000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }

      if (text == "/GatoG") {
        Serial.println("Moving Forward");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        delay(8000);

        // Stop the DC motor
        Serial.println("Motor stopped");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        delay(1000);

        bot.sendMessage(chat_id, "Comida servida", "");
      }
      /*amarillo out2 negro out|      */
      if (text == "/state") {
        if (digitalRead(ledPin)) {
          bot.sendMessage(chat_id, "LED is ON", "");
        }
        else
        {
          bot.sendMessage(chat_id, "LED is OFF", "");
        }
      }
    }
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Testing DC Motor...");

}

void loop()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    bot_lasttime = millis();
  }
}
