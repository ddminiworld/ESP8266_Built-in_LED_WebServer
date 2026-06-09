#include <ESP8266WiFi.h>

const char* ssid = "electronics";      // Your WiFi Name
const char* password = "electronics";  // Your WiFi Password

const int LED = 2;   // Built-in LED (GPIO2 / D4)

WiFiServer server(80);

int ledState = LOW;

void setup()
{
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  // Built-in LED is Active LOW
  digitalWrite(LED, HIGH);   // LED OFF

  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  server.begin();
  Serial.println("Server Started");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Open Browser: http://");
  Serial.println(WiFi.localIP());
}

void loop()
{
  WiFiClient client = server.available();

  if (!client)
  {
    return;
  }

  Serial.println("New Client Connected");

  while (!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Handle LED Control
  if (request.indexOf("/LED=ON") != -1)
  {
    digitalWrite(LED, LOW);   // Built-in LED ON
    ledState = HIGH;
    Serial.println("LED ON");
  }

  if (request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(LED, HIGH);  // Built-in LED OFF
    ledState = LOW;
    Serial.println("LED OFF");
  }

  // Send Web Page
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>ESP8266 LED Control</title>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");

  client.println("<style>");
  client.println("body {");
  client.println("  font-family: Arial, sans-serif;");
  client.println("  text-align: center;");
  client.println("  background-color: #f4f4f4;");
  client.println("  margin-top: 50px;");
  client.println("}");

  client.println("h1 {");
  client.println("  color: #333;");
  client.println("}");

  client.println(".led {");
  client.println("  width: 120px;");
  client.println("  height: 120px;");
  client.println("  border-radius: 50%;");
  client.println("  margin: 20px auto;");
  client.println("}");

  client.println(".on {");
  client.println("  background-color: red;");
  client.println("  box-shadow: 0 0 40px red;");
  client.println("}");

  client.println(".off {");
  client.println("  background-color: #777;");
  client.println("}");

  client.println(".btn {");
  client.println("  width: 140px;");
  client.println("  height: 55px;");
  client.println("  font-size: 20px;");
  client.println("  border: none;");
  client.println("  border-radius: 8px;");
  client.println("  cursor: pointer;");
  client.println("  margin: 10px;");
  client.println("}");

  client.println(".onBtn {");
  client.println("  background-color: green;");
  client.println("  color: white;");
  client.println("}");

  client.println(".offBtn {");
  client.println("  background-color: red;");
  client.println("  color: white;");
  client.println("}");
  client.println("</style>");

  client.println("</head>");
  client.println("<body>");

  client.println("<h1>ESP8266 LED Control</h1>");

  if (ledState == HIGH)
  {
    client.println("<div class='led on'></div>");
    client.println("<h2 style='color:red;'>LED STATUS : ON</h2>");
  }
  else
  {
    client.println("<div class='led off'></div>");
    client.println("<h2 style='color:gray;'>LED STATUS : OFF</h2>");
  }

  client.println("<br>");

  client.println("<a href='/LED=ON'>");
  client.println("<button class='btn onBtn'>ON</button>");
  client.println("</a>");

  client.println("<a href='/LED=OFF'>");
  client.println("<button class='btn offBtn'>OFF</button>");
  client.println("</a>");

  client.println("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client Disconnected");
}