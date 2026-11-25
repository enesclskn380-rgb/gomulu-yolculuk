#include "main.h"

int main(void) {

  RCC->AHB1ENR |=
      (1 << 0); // PA5 pinini aktif etmek için önce A portunu aktif ettim

  GPIOA->MODER |= (1 << 10); // PA5 pinini çıkış olarak ayarladım
  while (1) {
    GPIOA->ODR |= (1 << 5); // PA5 pinine 3.3v elektrik gönderdim ve ledi yaktım

    for (volatile int i = 0; i < 500000; i++)
      ; // ledi yarım saniye yakmak için i değişkeninyle sayacı tuttum volatile
        // koyarak optimizasyonu engelledim

    GPIOA->ODR &= ~(1 << 5); // diğer pinşlere dokunmadan 5.pine elektriği
                             // kestim ve ledi söndürdüm
    for (volatile int i = 0; i < 500000; i++)
      ;
  }
}
