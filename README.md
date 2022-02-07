# suffix tree /prolab1.2

## Kullanım 
Uygulamanın çalışabilmesi için bilgisayarınızda Allegro5 kütüphanesinin yüklü olması gerekmektedir.

Çizilmesini istediğiniz katarı string.txt dosyasına ekleyiniz.

Uygulamanın bulunduğu dizinde make all komutu ile derleyebilir ./prolab2 komutu ile uygulamayı başlatabilirsiniz. (Linux)

Verilen stringin sonek ağacı çizilemeyecek ise programı başlattıktan sonra komut satırından uyarı verir.

Uygulama açılıp siyah ekran ile karşılaşıldığında aynı anda 'S' ve 'D' tuşlarına 1 saniye basılı tutarak ağaç görüntülenebilir. Bu 2 tuş büyütme, 'W' ve 'A' tuşları ile de uzaklaştırma işlemi yapılmaktadır.

Yön tüşları ile ekranda ve ağaç üzerinde gezilebilir.

Aktif pencere ağacın grafiğinin açıldığı pencere iken 'q' tuşuna basılırsa uygulamaya bir kesme sinyali alarak komut arayüzünde (./prolab2 komutunun verildiği yer) bir menü görüntülenir.

Bu menüde 1-2-3 tuşları ile seçim yapılabilir. Seçim yaptıktan sonra menü ekranından çıkmak için (tercihen) 0 girdisi sağlanırsa tekrar grafik arayüzü aktif olacak ve orada gezinme işlemleri yapılabilir hale gelecektir. Menü açıkken grafik arayüzünde herhangi bir işlem yapılamaz.

![Ekran görüntüsü 2021-12-06 14-49-48](https://user-images.githubusercontent.com/30952126/144866982-90fc1705-1e6c-474d-ab76-fd0c69f33e93.png)


![Ekran görüntüsü 2021-12-06 14-55-13](https://user-images.githubusercontent.com/30952126/144867074-d79378c9-dc3d-401f-abd6-697849eca699.png)


#### İster 2

Sonek ağacı oluşturulan bir s katarı içinde p katarı geçiyor mu, geçiyorsa ilk bulunduğu yerin başlangıç pozisyonu nedir, kaç kez tekrar etmektedir?

![Ekran görüntüsü 2021-12-06 14-55-40](https://user-images.githubusercontent.com/30952126/144867052-7397c28a-722b-418a-94a3-55c82555a6da.png)

#### İster 3

Sonek ağacı oluşturulan bir s katarı içinde tekrar eden en uzun altkatar nedir, kaç kez tekrar etmektedir?

![Ekran görüntüsü 2021-12-06 14-56-40](https://user-images.githubusercontent.com/30952126/144867136-dc42ded0-7af3-4e0e-a83b-79a5f514fca0.png)

#### İster 4

Sonek ağacı oluşturulan bir s katarı içinde en çok tekrar eden altkatar nedir, kaç kez tekrar etmektedir?

![Ekran görüntüsü 2021-12-06 14-57-11](https://user-images.githubusercontent.com/30952126/144867203-571464bc-e6aa-4f6f-86a3-0f3e87c4a90b.png)

## Sorunlar
'q' tuşu ile menü açılması ve seçim yapılması sonrası bazen menü arayüzü sürekli 'q' tuşuna basılı olarak kalmakta ve grafik arayüzüne tekrar geçiş yapılmasına izin vermemektedir. Henüz hangi senaryolarda bu sorunun yaşandığı tespit edilemediği için çözülememiştir.

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

https://lazyfoo.net/tutorials/SDL/

https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace

### Faydalı Şeyler
https://visualgo.net/en/suffixtree?slide=1

https://hwv.dk/st.html

https://brenden.github.io/ukkonen-animation/

https://wiki.gnome.org/action/show/Projects/GooCanvas?action=show&redirect=GooCanvas

https://github.com/saubanbinusman/fractalTree






