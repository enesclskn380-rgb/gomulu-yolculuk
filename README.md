# Gömülü Sistemler Yolculuğu 🚀

Bu repo, okulda ve kendi başıma gömülü sistemler, mikrodenetleyiciler üzerine yaptığım denemeleri, projeleri ve aldığım notları içeriyor.

## 📂 Hafta 1: HAL Kütüphanesi ile İlk Proje (LED Blink)

Bu ilk haftada STM32CubeIDE ve HAL kütüphanesi kullanarak en temel uygulama olan LED yakıp söndürme (Blink) projesini yaptım. Amacım sadece kodu yazıp geçmek değil, arka planda olayların nasıl geliştiğini anlamaktı.

### 🛠️ Kullandığım Donanım
* **Geliştirme Kartı:** STM32 NUCLEO-F401RE
* **Kullandığım IDE:** STM32CubeIDE

### 💡 İlk Hafta Neler Öğrendim?
* **HAL Kütüphanesi:** İşlemcinin o karmaşık bellek (register) yapılarını arka planda gizleyip bize kolay fonksiyonlar sunuyor. Bir nevi işleri bizim yerimize hallediyor.
* **`while(1)` Döngüsünün Mantığı:** İşletim sistemi olmadığı için kodun bitmemesi ve cihaz çalıştığı sürece görevini yapması için ana kodlarımızı bu sonsuz döngüye yazmamız gerektiğini test ettim. Döngü olmazsa kod bir kere çalışıp duruyor.
* **Arka Plandaki Ayarlar:** Kod sadece benim yazdığım `TogglePin` ve `Delay` komutlarından ibaret değilmiş. Arka planda `SystemClock_Config` ile işlemcinin saat hızının ayarlandığını ve `MX_GPIO_Init` ile kullanacağım pinlerin sisteme tanıtıldığını gördüm.

### 🔍 Denediğim Fonksiyonlar
* `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);`: Bu fonksiyon pindeki duruma göre tersini yapıyor. Elektrik yoksa veriyor, varsa kesiyor. NUCLEO kartımdaki yeşil LED (LD2), **A Portunun 5. pinine (PA5)** bağlı olduğu için bu parametreleri girdim.
* `HAL_Delay(500);`: Klasik bekleme komutu. 

**Not:** Delay süresini değiştirerek LED'in yanıp sönme hızlarıyla oynadım. 50ms, 500ms ve 3000ms gibi farklı bekleme sürelerini test ettim. Çalışma videolarını da repoya yükledim.

### 📝 Yazdığım Temel Kod
```c
while (1)
{
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Durumu değiştir (Açıksa kapat, kapalıysa aç)
  HAL_Delay(500);                        // 500 milisaniye bekle
}
