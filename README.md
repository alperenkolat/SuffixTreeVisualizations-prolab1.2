# prolab1.2

## Kullanım (Linux)
Uygulamanın çalışabilmesi için bilgisayarınızda Allegro5 kütüphanesinin yüklü olması lazım.
Uygulamanın bulunduğu dizinde make all komutu ile derleyebilir ./prolab2 komutu ile uygulamayı başlatabilirsiniz.
Siyah ekran ile karşılaşıldığında aynı anda 'S' ve 'D' tuşlarına 1 saniye basarak ağacı görüntüleyebilir. Bu 2 tuş büyütme 'W' ve 'A' tuşları ile de uzaklaştırma işlemi yapılmaktadır.
Yön tüşları ile ekranda ve ağaç üzerinde gezilebilir.
Aktif pencere ağacın grafiğinin açıldığı pencere iken 'q' tuşuna basılırsa uygulamaya bir kesme sinyali alarak komut arayüzünde (./prolab2 komutunun verildiği yer) bir menü görüntülenir.
Bu menüde 1-2-3 tuşları ile seçim yapılabilir. Seçim yaptıktan sonra menü ekranından çıkmak için (tercihen) 0 girdisi sağlanırsa tekrar grafik arayüzü aktif olacak ve orada gezinme işlemleri yapılabilir hale gelecektir. Menü açıkken grafik arayüzünde herhangi bir işlem yapılamaz.

## Sorunlar
'q' tuşu ile menü açılması ve seçim yapılması sonrası bazen menü arayüzü sürekli 'q' tuşuna basılı olarak kalmakta ve grafik arayüzüne tekrar geçiş yapılmasına izin vermemektedir. Henüz hangi senaryolarda bu sorun başadığı tespit edilemediği için çözülememiştir.

### Tartışma Başlıkları
https://stackoverflow.com/questions/1701728/graphics-library-in-c

https://stackoverflow.com/questions/10355103/finding-the-longest-repeated-substring

https://www.reddit.com/r/C_Programming/comments/qgodbb/6502_emulator_in_c_using_win32_cocoaquartz2d_and/

https://www.reddit.com/r/C_Programming/comments/67ed4a/what_do_the_different_c_graphics_libraries_offer/

https://stackoverflow.com/questions/31615012/are-there-good-tutorials-for-sdl2-0-for-c-programming-not-c/31615389

https://www.quora.com/How-can-I-use-graphics-h-in-a-GCC-compiler

https://stackoverflow.com/questions/10126695/how-to-draw-a-tree-representing-a-graph-of-connected-nodes

https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
### Örnek Kodlar
[longest repeated substring](https://introcs.cs.princeton.edu/java/42sort/LRS.java.html)
### Sars-Cov-2 Genom
https://www.ncbi.nlm.nih.gov/nuccore/NC_045512

### Grafik Kütüphaneleri
https://www.cairographics.org/

https://acry.github.io/SDL2-C.html

https://stephenmeier.net/2014/09/04/sdl-2-0-tutorial-03-metasprites/

https://acry.github.io/SDL2-C.html

https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace

### Faydalı Şeyler
https://visualgo.net/en/suffixtree?slide=1

https://hwv.dk/st.html

https://brenden.github.io/ukkonen-animation/

https://wiki.gnome.org/action/show/Projects/GooCanvas?action=show&redirect=GooCanvas

https://github.com/saubanbinusman/fractalTree






