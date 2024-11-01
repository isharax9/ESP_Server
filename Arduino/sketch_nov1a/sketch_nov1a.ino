#include <WiFi.h>

NetworkServer server = NetworkServer(80);

const char *ssid = "macNaWifi-2.4G";
const char *password = "IshLak@5377.";


void setup() {
  Serial.begin(115200);

  pinMode(13, OUTPUT);

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

    String requestText = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        requestText += c;

        if (c == '\n') {
          Serial.println(requestText);

          if (requestText.startsWith("GET /?status=1")) {
            digitalWrite(13, HIGH);
          } else {
            digitalWrite(13, LOW);
          }
          break;
        }
      }
    }
    client.stop();
  }
}
