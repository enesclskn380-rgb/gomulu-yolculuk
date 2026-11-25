---

## ⚡ Register Çalışmaları (Doğrudan Kayıtçı Erişimi)

HAL kütüphanesini devre dışı bırakıp doğrudan bellek adresleri ve donanım kayıtçıları üzerinden yaptığım çalışmalar:

### Hafta 2: Register ile LED Yakma (PA5)
* **Proje Klasörü:** [register-blink-02](./register-blink-02)
* **Özet:** `RCC->AHB1ENR`, `GPIOA->MODER` ve `GPIOA->ODR` kayıtçılarına bit düzeyinde erişerek (`<<`, `|=`, `&= ~`) ve `volatile` gecikme döngüsü kullanarak Nucleo-F401RE üzerindeki yeşil LED'i yakıp söndürdüm.
