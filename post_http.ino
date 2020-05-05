#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() {
 
  Serial.begin(115200);                                  //Serial connection
  WiFi.begin("albasha", "0502458347");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;    //Declare object of class HTTPClient
 
   http.begin("http://192.168.100.8:5000/deviceTestInfo/add");      //Specify request destination
   http.addHeader("Content-Type", "application/json");

 
   int httpCode = http.POST("{\"national_id\":\"111\",\"body_temperature\":\"40\",\"blood_pressure\":{\"systolic_pressure\":\"111\",\"diastolic_pressure\":\"40\"},\"oxygen_percentage\":\"24.25\",\"pulse\":\"49.54\"}");   //Send the request
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  //Send a request every 30 seconds
 
}
