# Register Seviyesinde LED Yakıp Söndürme (PA5 / LD2)

Bu çalışmada STM32 HAL kütüphanesi kullanılmadan, doğrudan mikrodenetleyici kayıtçıları (register) üzerinden **STM32 Nucleo-F401RE** kartındaki dahili yeşil LED (**LD2 / PA5**) kontrol edilmiştir.

## Kullanılan Donanım ve Araçlar
* **Geliştirme Kartı:** STM32 Nucleo-F401RE
* **Hedef Pin:** `PA5` (Dahili Yeşil LED - LD2)
* **IDE:** STM32CubeIDE (macOS)

## Register Adımları ve Çalışma Mantığı
* **`RCC->AHB1ENR |= (1 << 0);`** — Güç tasarrufu için başlangıçta kapalı olan **GPIOA** portunun saat (clock) hattını aktif eder.
* **`GPIOA->MODER |= (1 << 10);`** — Her pin için 2 bit ayrılan `MODER` register'ında `PA5` pinine ait 10. ve 11. bitleri `01` yaparak pini **Çıkış (Output)** moduna ayarlar.
* **`GPIOA->ODR |= (1 << 5);`** — Çıkış veri kayıtçısının 5. bitini `1` yaparak `PA5` pinine **3.3V** gönderir ve LED'i yakar.
* **`GPIOA->ODR &= ~(1 << 5);`** — Diğer pinlerin durumunu bozmadan sadece 5. biti `0` yaparak `PA5` pinini **0V** seviyesine çeker ve LED'i söndürür.
* **`for (volatile int i = 0; i < 500000; i++);`** — Derleyicinin boş bekleme döngüsünü optimizasyonla silmesini engellemek için `volatile` anahtar kelimesi kullanılarak zaman gecikmesi oluşturulur.

