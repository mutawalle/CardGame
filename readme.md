# Object Oriented Card Game
> Tugas Besar Mata Kuliah IF2210 Pemrograman Berorientasi Objek ITB. Built by Kelompok Cumlaude - CUM

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)
<!-- * [License](#license) -->


## General Information
  Permainan kartu diterapkan menggunakan konsep OOP.Konsep OOP yang digunakan antara lain Inheritance, Polymorphism, Function dan Operator Overloading, Abstract Class dan Virtual Function, Generic Function, serta Standard Template Library (STL). Permainan Kartu ini memiliki alur bermain 
  Alur permainan pada permainan ini adalah sebagai berikut:
  1. Terdapat 7 pemain yang akan berpartisipasi dalam permainan.
  2. Setiap pemain akan memberikan nama atau nickname mereka.
  3. Pada awal permainan, setiap pemain akan memiliki 0 poin dan akan diberikan poin hadiah awal sejumlah 64.
  4. Pada setiap ronde permainan, pemain akan melakukan putaran dengan mengambil kartu.
  5. Pada akhir ronde ke-6, poin hadiah akan diberikan ke pemain yang menang dan pemain lain tidak akan mendapatkan poin.
  6. Jika seorang pemain memiliki poin lebih dari sama dengan 2^32 poin, maka permainan akan berakhir dan pemain tersebut menjadi pemenang.
  7. Jika belum ada pemain yang mencapai 2^32 poin, maka permainan akan dilanjutkan dari ronde awal lagi dengan kartu yang dikembalikan dan setiap pemain akan diberikan kartu kemampuan acak pada setiap ronde ke-2 dan seterusnya.
  8. Selama permainan, pemain dapat memilih perintah Double, Next, Half, atau Ability (kemampuan).


<!-- You don't have to answer all the questions - just the ones relevant to your project. -->


## Technologies Used
- C++ 17 


## Features
- Next

  Perintah yang memiliki arti pemain tidak melakukan apa-apa (tidak Half, tidak Double, dan tidak mengeluarkan kartu ability). Giliran akan diserahkan kepada pemain berikutnya.

- Re-Roll

    Perintah yang memiliki arti pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru. Perintah ini hanya bisa dilakukan ketika pemain memiliki kartu kemampuan Re-Roll dan belum pernah digunakan. Setelah perintah dilakukan, giliran diberikan ke pemain selanjutnya.
    
- Double

   Perintah yang memiliki arti pemain akan menaikkan total poin hadiah pada permainan menjadi dua kali lipat.
   
- Quadruple

  Perintah yang memiliki arti pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali lipat. Quadruple hanya bisa digunakan apabila pemain memiliki kartu Ability yang sesuai.
  
- Half

  Perintah yang memiliki arti pemain akan menurunkan total poin hadiah pada permainan menjadi setengah.
  
- Quarter

  Perintah yang memiliki arti pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat nilai awal. 
  
- Reverse

  Perintah yang memiliki arti untuk memutar arah giliran eksekusi perintah oleh pemain
  
- Swap Card

  Perintah yang memiliki arti menukar satu kartu pemain lain dengan satu kartu pemain yang lain.
  
- Switch

  Perintah yang memiliki arti pemain akan menukar kartu main deck miliknya dengan kartu main deck milik pemain lain. Kartu yang ditukar tidak bisa dipisah-pisah alias harus 2 kartu sekaligus dan penukarannya juga hanya boleh melibatkan 1 pemain lain.
  
- Abilityless

  Perintah yang memiliki arti pemain akan mematikan kemampuan kartu lawan. Jika lawan yang dipilih sudah menggunakan kartu abilitynya, maka kartu ini tidak akan melakukan efek apapun, sehingga penggunaan kartu ini perlu diperhatikan. 
  
  


## Screenshots
[![image](https://www.linkpicture.com/q/messageImage_1678976908140.jpg)](https://www.linkpicture.com/view.php?img=LPic6413291a9f7861774130743)
[![image](https://www.linkpicture.com/q/messageImage_1678976933756.jpg)](https://www.linkpicture.com/view.php?img=LPic6413291a9f7861774130743)
[![image](https://www.linkpicture.com/q/messageImage_1678976957220.jpg)](https://www.linkpicture.com/view.php?img=LPic6413291a9f7861774130743)



## Setup
Untuk memainkan permainan, dibutuhkan g++, make, dan sistem operasi Linux. Untuk menggunakan program, Anda harus melakukan proses kompilasi terhadap program tersebut. Langkah-langkahnya adalah dengan men-download atau menyalin repository, dan memastikan bahwa Anda menggunakan sistem operasi Linux (atau WSL) yang sudah terinstall g++ dan make.

Setelah itu gunakan command `make clean` untuk membersihkan folder bin dan command `make` untuk meng-compile program


## Usage
Untuk menggunakan program yang telah di-_compile_:
- Gunakan salah satu _command_
```
./main
./main.exe
```
- Program juga dapat menerima input file


## Project Status
Project ini selesai 


## Room for Improvement
- Program mengunakan Command line Interface sehingga dapat ditingkatkan lagi dengan menggunakan GUI
- Mungkin terdapat kesalahan penggunaan konsep OOP sehingga dapat diperiksa lagi
- Terdapat beberapa kode yang redundant sehingga dapat diperbaiki dan direfactor


## Acknowledgements
- Terima kasih kepada seluruh dosen pengajar mata kuliah IF2210 dan asisten lab programming
- Projek ini dikerjakan untuk memenuhi tugas besar mata kuliah IF2210 Pemrograman Berorientasi Objek


## Contact
Created by:
- [@fajarmhrwn](https://github.com/fajarmhrwn)
- [@vierifirdaus](https://github.com/vierifirdaus)
- [@zakia215](https://github.com/zakia215)
- [@mutawalle](https://github.com/mutawalle)
- [@Ulung32](https://github.com/Ulung32)


<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
