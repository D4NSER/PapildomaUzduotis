# Papildoma užduotis
Programa, kuri nuskaito vartotojo failą ir suskaičiuoja pasikartojančius žodžius bei atranda tekste esančius internetinių svetainių adresus. Rezultatai atpausdinami į atskirą failą lentelės pavidalu.
## Programos veikimas
Paleidus programą į terminalą išspausdinami programos kataloge esantys ***.txt*** failai ir vartotojas prašomas įvesti norimo nuskaityti failo pavadinimą. Jei vartotojas pavadinimo nenurodo, programa nuskaito numatytąjį ***"text.txt"*** failą. 
*Nepavykus atidaryti nurodyto failo, vartotojui nurodoma įvesti kito failo pavadinimą.*
Kiekviena teksto eilutė yra skaitoma pažodžiui. Pirmiausiai programa patikrina ar aptiktas žodis nėra internetinės svetainės adresas. Jei yra, jį *push_back*'ina į juos saugantį vektorių. Jei nėra, žodį "sutvarko": nuima visus neraidinius simbolius ir padaro, kad žodis būtų sudarytas tik iš mažųjų raidžių (kad tikrinant pasikartojimą didžiosios ir mažosios raidės netrukdytų išvesti tikslaus rezultato).<br>
Nuskaičius failą bei suskaičiavus žodžių pasikartojimus, rezultatai atspausdinami į numatytąjį ***"rezultatai.txt"*** failą. Atspausdinami internetinių svetainių adresai, jų kiekis ir pasikartojantys žodžiai, pasikarotijmų kiekis bei eilutės, kuriose galima aptikti pasikartojančius žodžius. 
