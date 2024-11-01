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
  request.begin("https://f284-178-128-59-4.ngrok-free.app/ESP_Server/Test?name=Ishara");
  int status = request.GET();

  if (status > 0) {
    if (status == HTTP_CODE_OK) {
      String responseText = request.getString();
      Serial.println(responseText);
    }

  } else {
    Serial.println("Error");
  }

  request.end();
  delay(10000);
}