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
![Example screenshot](./img/screenshot.png)
<!-- If you have screenshots you'd like to share, include them here. -->


## Setup
What are the project requirements/dependencies? Where are they listed? A requirements.txt or a Pipfile.lock file perhaps? Where is it located?

Proceed to describe how to install / setup one's local environment / get started with the project.


## Usage
How does one go about using it?
Provide various use cases and code examples here.

`write-your-code-here`


## Project Status
Project is: _in progress_ / _complete_ / _no longer being worked on_. If you are no longer working on it, provide reasons why.


## Room for Improvement
Include areas you believe need improvement / could be improved. Also add TODOs for future development.

Room for improvement:
- Improvement to be done 1
- Improvement to be done 2

To do:
- Feature to be added 1
- Feature to be added 2


## Acknowledgements
Give credit here.
- This project was inspired by...
- This project was based on [this tutorial](https://www.example.com).
- Many thanks to...


## Contact
Created by [@flynerdpl](https://www.flynerd.pl/) - feel free to contact me!


<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
