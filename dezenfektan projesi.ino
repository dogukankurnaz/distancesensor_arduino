#define su_hiz 9  // 9. pine ba?lad???m?z h?z pini
#define su_ileri 10 // ileri - geri pinlerini bilemedi?imiz i�in deneme yan?lma y�ntemiyle �?rendimek i�in
#define su_geri 11
int trigPin = 6;  // mesafe sens�r�n� arduinoya ba?lad???m?z 6-7 numaral? pinler
int echoPin = 7; 
long sure;  //mesafe sens�r�n�n �al?sma mant??? solar bir sinyal g�nderiyor ve o sinyal bir y�zeye �arp?nca geri d�n�yor bunun geri d�n�? s�resi i�in yazd???m?z komut.
long uzaklik; // ayn? sens�r�n uzakl???n? hesaplamam?z i�in gerekli olan k?s?m.
int motorlar_hiz = 200; // pwn'e ba?lam??t?k, motorun �al??ma h?z? bu 0-255 aras? bir de?er alabilir deneme yan?lma ile bulaca??z ortalama de?eri.

void setup(){ //G?R?? �IKI? P?NLER?M?Z...
  pinMode(su_hiz, OUTPUT);
  pinMode(su_ileri, OUTPUT);  
  pinMode(su_geri, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT);  // ECHO pinimiz giri? pini sadece
  Serial.begin(9600); //serial ekran? tan?mlama sebebim ekranda hata var m? ona bakmak i�in tan?mlamasan?z da olur.
    
}
void loop()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  sure = pulseIn(echoPin, HIGH); 
  uzaklik= sure /29.1/2;  
  Serial.println(uzaklik);         
 if(uzaklik<3) {     //E?er uzakl?k 3 cm den yak?nsa su motorunu aktif edip su �ekmeye ba?las?n
digitalWrite(su_ileri, 1);
analogWrite(su_hiz, motorlar_hiz);

 }
 else {
  digitalWrite(su_ileri, 0); //e?er uzakl?k 3 cmden b�y�kse, su motorunu durdur. 
  }  
}