#include <Arduino_JSON.h>

#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "macNaWifi-2.4G";
const char *password = "IshLak@5377.";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
}

void loop() {

  HTTPClient request = HTTPClient();
  request.begin("https://brief-awake-whippet.ngrok-free.app/ESP_Server/Test");
  request.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int status = request.POST("name=Ishara Post requests are working fine");

  if (status > 0) {
    if (status == HTTP_CODE_OK) {
      String responseText = request.getString();

      JSONVar json = JSON.parse(responseText);
      Serial.println(json["x"]);
      Serial.println(json["y"]);
    }

  } else {
    Serial.println("Error");
  }

  request.end();
  delay(10000);
}