Türkçe

Bu projede, Deneyap Kart 1A kullanılarak TEA5767 FM radyo modülü, Deneyap OLED ekran ve bir potansiyometre ile dinamik frekans ayarlama sistemi geliştirilmiştir. Potansiyometreden analogRead() fonksiyonu ile okunan 0–1023 arası değer, map() fonksiyonu ile 87.5 MHz–108.0 MHz aralığındaki FM yayın bandına ölçeklendirilir. Hesaplanan yeni frekans değeri, son ayarlanan frekanstan en az 0.1 MHz farklıysa, FM radyo modülü radio.setFrequency() fonksiyonu ile güncellenir, OLED ekran temizlenerek yeni frekans bilgisi ekrana yazdırılır ve aynı anda seri monitöre aktarılır. Sistem, OLED ekran ve TEA5767 modülüyle I2C protokolü üzerinden haberleşmekte olup, potansiyometre okuması sürekli tekrarlanarak kullanıcı müdahalesine bağlı gerçek zamanlı frekans değişimi sağlanmaktadır. Ses çıkışı için kablolu kulaklık veya harici hoparlör bağlantısı desteklenmektedir.

English

In this project, a dynamic frequency adjustment system was developed using the Deneyap Kart 1A, the TEA5767 FM radio module, the Deneyap OLED display, and a potentiometer. The value read from the potentiometer via the analogRead() function, ranging from 0 to 1023, is scaled to the FM broadcast band between 87.5 MHz and 108.0 MHz using the map() function. If the newly calculated frequency value differs by at least 0.1 MHz from the last set frequency, the FM radio module is updated using the radio.setFrequency() function, the OLED screen is cleared, and the new frequency information is displayed on the screen and simultaneously transmitted to the serial monitor. The system communicates with both the OLED display and the TEA5767 module via the I2C protocol, and by continuously reading the potentiometer, real-time frequency changes based on user input are enabled. Wired headphone or external speaker connections are supported for audio output.


![radioDevre](https://github.com/user-attachments/assets/db5168c6-13e5-4bce-a84f-c3060717dd1e)

![IMG_9421](https://github.com/user-attachments/assets/65c5f8ef-8747-4ef2-af31-d81e388ef28b)
