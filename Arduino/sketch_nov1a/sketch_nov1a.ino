#include <WiFi.h>

NetworkServer server = NetworkServer(80);

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

  Serial.println("WiFi connected.");
  server.begin();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
      }
    }
    client.stop();
  }
}
